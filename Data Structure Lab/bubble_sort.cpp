#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j;
    int arr[]={1,12,13,2,4,5,9,3,10,6,8,7,11};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(i = 0; i < n -1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout<<"Sorted array: ";
    for(i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}
