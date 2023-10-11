#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int ret = 1 ;
int N ,L;

int main()
{
    cin >> N >> L;

    for(int i = 0 ;  i < N ; i++ )
        cin >> arr[i];
    
    sort(arr,arr+N);
    
    int st =arr[0];

    for(int i= 1 ; i< N ;i++)
    {

        if(arr[i] - st +1  > L)
        {
            ret++;
            st = arr[i];
        }

    }
    
    cout << ret;
    return 0;
}