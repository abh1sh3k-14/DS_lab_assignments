#include<iostream>
using namespace std;

int main(){
	int arr[7]={64,34,25,12,22,11,90};
	int n=7;
	cout<<"original array: ";
	for(int i=0;i<7;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<(n-i-1);j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
	cout<<"sorted array: ";
	for(int i=0;i<7;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
