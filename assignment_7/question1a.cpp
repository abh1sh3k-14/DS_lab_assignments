#include <iostream>
using namespace std;
void selection_sort(int *arr,int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i;j<n;j++){
            if(arr[min]>arr[j]) min=j;
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}
void print_arr(int* arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main() {
    int arr[]={5, 2, 9, 1, 7, 3};
    print_arr(arr,6);
    selection_sort(arr,6);
    print_arr(arr,6);
    return 0;
}
