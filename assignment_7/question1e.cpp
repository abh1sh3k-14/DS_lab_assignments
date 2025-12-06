#include <iostream>
using namespace std;
int f(int*arr,int low,int high){
    int pivot=low;
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<arr[pivot] && i<=high){
            i++;
        }
        while(arr[j]>arr[pivot] && j>=low){
            j--;
        }
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[pivot];
    arr[pivot]=arr[j];
    arr[j]=temp;
    return j;
}
void quick_sort(int* arr,int low,int high){
    if(low<high){
        int pivot=f(arr,low,high);
        quick_sort(arr,low,pivot-1);
        quick_sort(arr,pivot+1,high);
    }
}
void print_arr(int* arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main() {
    int arr[]={5,2,9,1,7,3};
    print_arr(arr,6);
    quick_sort(arr,0,5);
    print_arr(arr,6);
    return 0;
}