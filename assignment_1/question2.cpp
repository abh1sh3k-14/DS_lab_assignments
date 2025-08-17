#include <iostream>
#include<cstdlib>
using namespace std;

int main() {
    int n;
    cout<<"enter the length of the array you want to create: ";
    cin>>n;
    int* arr=(int*) malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        cout<<"enter the value of element "<<(i+1)<<": ";
        cin>>arr[i];
    }
    int counter=0;
    int index;
    int arr1[70];
    arr1[0]=0;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<counter;j++){
            if(arr[i]==arr1[j]){
                count++;
                break;
            }
        }
        cout<<counter<<endl;
        cout<<count<<endl;
        if (count==0){
            arr1[counter]=arr[i];
            counter++;
        }
    }
    cout<<"the new array is: "<<endl;
    for(int i=0;i<counter;i++){
        cout<<arr1[i]<<" ";
    }
    free(arr);
    return 0;
}