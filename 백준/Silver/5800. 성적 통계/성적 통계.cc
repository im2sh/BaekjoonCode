#include <iostream>
#include <algorithm>

using namespace std;

int K, N;
int arr[51];

int main(){
    cin>>K;

    for(int k = 1; k<=K; k++){ 
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }      

        sort(arr, arr+N, greater<int>()); 
        
        cout << "Class " << k << endl;
        cout << "Max " << arr[0] << ", ";
        cout << "Min " << arr[N - 1] << ", ";     

        int gap, largest = 0; 
        for(int i = 1; i < N; i++){
            gap = arr[i - 1] - arr[i];
            if(largest < gap)
                largest = gap;
        }
        cout << "Largest gap " << largest << '\n';
    }

    return 0;
}