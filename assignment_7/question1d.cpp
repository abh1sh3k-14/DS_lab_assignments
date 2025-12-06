#include <iostream>
using namespace std;
void merge(int* arr,int low,int mid,int high){
    int* temp=new int[high-low+1];
    int i=0;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp[i++]=arr[left++];
        }
        else{
            temp[i++]=arr[right++];
        }
    }
    while(left<=mid){
        temp[i++]=arr[left++];
    }
    while(right<=high){
        temp[i++]=arr[right++];
    }
    for(int j=low;j<=high;j++){
        arr[j]=temp[j-low];
    }
    delete[] temp;
}
void merge_sort(int* arr,int low,int high){
    if(low>=high)
        return;
    int mid=(low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
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
    merge_sort(arr,0,5);
    print_arr(arr,6);
    return 0;
}