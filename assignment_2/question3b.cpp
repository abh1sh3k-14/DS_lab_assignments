#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"enter the length of the array in which you want to create elements from 1 to n: ";
    cin>>n;
    int arr[n-1];
    for(int i =0;i<(n-1);i++){
        cout<<"enter value of element "<<(i+1)<<": ";
        cin>>arr[i];
    }
    int low=0;
    int  high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==(mid+1)){
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    cout<<"the missing number is "<<(low+1)<<endl;
    return 0;
}