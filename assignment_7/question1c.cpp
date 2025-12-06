#include <iostream>
using namespace std;
void bubble_sort(int* arr,int n){
    bool swapped=false;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swapped=true;
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        if(!swapped){
            cout<<"array alread sorted\n";
            break;
        }    
    }
    return;
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
    bubble_sort(arr,6);
    print_arr(arr,6);
    return 0;
}