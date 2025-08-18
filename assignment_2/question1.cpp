#include<iostream>
using namespace std;
int main(){
	int high,low,mid,n;
	int index;
	cout<<"enter the length of array you want to create: ";
	cin>>n;
	int arr[n];
	cout<<"enter elements into the array(in sorted order)"<<endl;
	for(int i=0;i<n;i++){
		cout<<"enter the value of element "<<(i+1)<<": ";
		cin>>arr[i];
	}
	low=0;
	high=n-1;
	mid=(low+high)/2;
	int value;
	cout<<"enter the value you want to search in the array: ";
	cin>>value;
	cout<<"trying with binary search first"<<endl;
	while(arr[mid]!=value){
		if(arr[mid]<value){
			low=mid;
			mid=(low+high)/2;
		}
		else if(arr[mid]>value){
			high=mid;
			mid=(low+high)/2;
		}
	}
	cout<<"the value was found at index "<<mid<<" of the array"<<endl;
	cout<<"trying with linear search now"<<endl;
	for(int i=0;i<n;i++){
		if(arr[i]==value){
			index=i;
			break;
		}
	}
	cout<<"the value was found at index "<<index<<" of the array"<<endl;
	return 0;
}
