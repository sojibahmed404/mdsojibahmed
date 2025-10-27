#include<iostream>
#include<algorithm>
using namespace std;

void inputarray(int arr[], int size){
    cout<<"Enter "<<size<<" Numbers: "<<endl;
    for(int i = 0;i < size;i++){
        cin>>arr[i];
    }
}

void displayarray(int arr[],int size){
    cout<<"Array Numbers are: "<<endl;
    for(int i = 0;i < size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sortarray(int arr[], int size){
    sort(arr,arr+size);
    cout<<"Sorted array is: "<<endl;
    for(int i = 0;i < size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void index(int arr[], int size, int n){
    int index = -1;
    for(int i = 0;i < size;i++){
        if(arr[i] == n){
            index = i;
            cout<<"Index number is: "<<index<<endl;
            break;
        }
    } if(!index){
        cout<<"Number not found"<<endl;
    }
}

void count(int arr[],int size,int n){
    int count = 0;
    for(int i = 0;i < size;i++){
        if(arr[i] == n){
            count++;
        }
    }
    cout<<count<<" Similar number found"<<endl;
}

void linearsearch(int arr[], int size, int n){
    bool result = false;
    for(int i = 0;i < size;i++){
        if(arr[i] == n){
            result = true;
            cout<<"In linear search: "<<boolalpha<<result<<endl;
            break;
        }
    }if(!result){
        cout<<"In linear search: "<<boolalpha<<result<<endl;
    }
}

void binarysearch(int arr[], int size, int n){
    bool result = false;
    int first = 0, last = size - 1, mid;
    while(first <= last){
        mid = (first + last) / 2;
        if(arr[mid] == n){
            result = true;
            cout<<"In binary search: "<<boolalpha<<result<<endl;
            break;
        }else if(arr[mid] < n){
            first = mid + 1;
        }else{
            last = mid -1;
        }
    }if(!result){
       cout<<"In binary search: "<<boolalpha<<result<<endl;
    }
}

int main()
{
    int size;
    int arr[1000];
    int n;
    char choice;

    while(1){
        cout<<"\n1. Input Array. "<<endl;
        cout<<"2. Display Array. "<<endl;
        cout<<"3. Sort Array. "<<endl;
        cout<<"4. Find Index of an Number. "<<endl;
        cout<<"5. Count Occurrences of an Number. "<<endl;
        cout<<"6. Linear Search. "<<endl;
        cout<<"7. Binary Search. "<<endl;
        cout<<"8. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<endl;

        switch(choice){
            case '1':
            cout<<"\nEnter size of aray: "<<endl;
            cin>>size;
            inputarray(arr , size);
            break;

            case '2':
            displayarray(arr , size);
            break;

            case '3':
            sortarray(arr , size);
            break;

            case '4':
            cout<<"\nEnter number to find index: "<<endl;
            cin>>n;
            index(arr , size , n);
            break;

            case '5':
            cout<<"\nEnter number to count its occurrences: "<<endl;
            cin>>n;
            count(arr , size , n);
            break;

            case '6':
            cout<<"\nEnter number to search (Linear search): "<<endl;
            cin>>n;
            linearsearch(arr , size , n);
            break;

            case '7':
            cout<<"\nEnter number to search (Binary Search): "<<endl;
            cin>>n;
            binarysearch(arr , size , n);
            break;

            case '8':
            exit(0);
            break;

            default:
            cout<<"\nInvalid choice! Try again."<<endl;

        }
    }


    return 0;
}
