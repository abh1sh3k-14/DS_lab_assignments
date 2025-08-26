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
    for(int i =0;i<(n-2);i++){
        if (arr[i+1]!=arr[i]+1){
            cout<<"the missing number is "<<arr[i]+1<<endl;
            break;
        }
    }
    return 0;
}
