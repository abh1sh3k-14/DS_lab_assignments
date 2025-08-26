#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"enter the length of the array you want to create: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the value of element "<<(i+1)<<": ";
        cin>>arr[i];
    }
    int count=0;
    for(int i=0;i<n;i++){
        while(arr[i]==arr[i+1]){
            i++;
        }
        count++;
    }
    cout<<"thus the total number of distinct elements in our array are: "<<count<<endl;
    return 0;
}