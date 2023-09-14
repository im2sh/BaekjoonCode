#include<iostream>

using namespace std;

int main(){
    long long n,m,k,d;
    long long casearr[4];
    long long caseksize[4];
    cin >> d;
    cin >> n >> m >> k;
    
    long long n2 = n%d;
    long long m2 = m%d;

    long long maxsize = (n+m+k)/d;

    casearr[0] = n/d + m/d + k/d;
    caseksize[0] = k;
    casearr[1] = (n + (d-n2))/d + m/d + (k-(d-n2))/d;
    caseksize[1] = k-(d-n2);
    casearr[2] = n/d + (m + (d-m2))/d + (k-(d-m2))/d;
    caseksize[2] = k - (d-m2);
    casearr[3] = (n + (d-n2))/d + (m + (d-m2))/d + (k-(d-n2) - (d-m2))/d;
    caseksize[3] = k - (d-n2) - (d-m2);

    long long min = 0;
    long long result = 0;
   
    for(int i=0; i<4; i++){
        if(caseksize[i] > result & casearr[i] == maxsize){
            result = caseksize[i];
        }
    }

    cout << result;

    return 0;
}