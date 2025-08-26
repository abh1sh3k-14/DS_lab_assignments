#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the length of the array you want to create: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the value of element "<<(i+1)<<": ";
        cin>>arr[i];
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=(i+1);j<n;j++){
            if(i<j){
                if(arr[i]>arr[j]){
                    count++;
                }
            }
        }
    }
    cout<<"the number of inversions in the array are "<<count<<endl;
    return 0;
}