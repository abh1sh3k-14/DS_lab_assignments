#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"enter the length of the array you want to create: ";
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cout<<"enter the value of element "<<(i+1)<<": ";
        cin>>arr[i];
    }
    for(int i=0;i<n/2;i++){
        int temp=arr[n-i-1];
        arr[n-i-1]=arr[i];
        arr[i]=temp;
    }
    cout<<"the reversed array is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}