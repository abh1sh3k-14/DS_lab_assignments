#include <iostream>
using namespace std;
void insertion_sort(int* arr,int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
}
void print_arr(int* arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main() {
    // int arr[]={5, 2, 9, 1, 7, 3};
    int arr[]={12, 3, 19, 0, -4, 8, 7};
    print_arr(arr,6);
    insertion_sort(arr,6);
    print_arr(arr,6);
    return 0;
}