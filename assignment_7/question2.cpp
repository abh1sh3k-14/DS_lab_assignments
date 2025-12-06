#include <iostream>
using namespace std;
void selection_sort(int* arr, int n){
    for(int i=0;i<n/2;i++){
        int max=i,min=i;
        for(int j=i;j<=n-i-1;j++){
            if(arr[j]<arr[min]) min=j;
            if(arr[j]>arr[max]) max=j;
        }
        
        swap(arr[i],arr[min]);
        if(max==i) max=min;

        swap(arr[n-i-1],arr[max]);
    }
}
int main() {
    int arr[]={10,5,3,8,6,2,9};
    int n=7;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    selection_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}