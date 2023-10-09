#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
 
int n; 
string arr[50];

int s(string str){
    int sum = 0;
    for(int i = 0; i < str.size(); i++)
        if(str[i] >= 48 && str[i] <= 57)   
            sum += str[i] - 48;
    return sum;
}
 
bool cmp(string a, string b){
    int len1 = a.size();
    int len2 = b.size();
    if(len1 == len2){  
        int s1 = s(a), s2 = s(b);
        if(s1 == s2) 
            return a < b;  
        else 
            return s1 < s2;    
    }else 
        return len1 < len2; 
}
 
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    sort(arr, arr + n, cmp);
    for(int i = 0; i < n; i++) 
        cout << arr[i] << "\n";
    return 0;
}