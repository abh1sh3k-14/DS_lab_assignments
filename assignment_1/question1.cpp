#include <iostream>
#include <cstdlib>
using namespace std;
int* create(int length){
    int* a= (int*) malloc(length * sizeof(int));
    for(int i=0;i<length;i++){
        cout<<"enter the value of element "<<(i+1)<<": ";
        cin>>a[i];
    }
    return a;
}
void display(int* arr,int length){
    cout<<"the array is: ";
    for(int i=0;i<length;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int* insert(int* arr,int length,int index, int value){
    int* arr1=(int*) malloc((length+1)*sizeof(int));
    for(int i=0;i<(length+1);i++){
        if(i<index){
            arr1[i]=arr[i];
        }
        else if (i==index){
            arr1[i]=value;
        }
        else{
            arr1[i]=arr[i-1];
        }
    }
    free(arr);
    return arr1;
}
int* del(int* arr,int length,int index){
    int* arr1=(int*) malloc((length-1)*sizeof(int));
    for(int i=0;i<length;i++){
        if(i<index){
            arr1[i]=arr[i];
        }
        else if (i==index){
            continue;
        }
        else{
            arr1[i-1]=arr[i];
        }
    }
    free(arr);
    return arr1;
}
void linear_search(int* arr,int value,int length){
    for(int i=0;i<length;i++){
        if (arr[i]==value){
            cout<<"value found at index "<<i<<endl;
            return;
        }
    }
    cout<<"value not found in the array"<<endl;
    return;
}

int main() {
    int index,value,choice,ch=1,length;
    int* arr=NULL;
    while(ch==1){
        printf("WELCOME TO OUR MENU DRIVEN PROGRAM\n__MENU__\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n");
        printf("enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("enter the length of the array you want to create: ");
            scanf("%d",&length);
            if (arr!=NULL){
                free(arr);
            }
            arr=create(length);
            break;
        case 2:
            display(arr,length);
            break;
        case 3:
            printf("enter the value that you want to insert in the array: ");
            scanf("%d",&value);
            printf("enter the index at which you want to insert the value: ");
            scanf("%d",&index);
            arr=insert(arr,length,index,value);
            length++;
            break;
        case 4:
            printf("Enter the index whose value you want to delete: ");
            scanf("%d",&index);
            arr=del(arr,length,index);
            length--;
            break;
        case 5:
            printf("enter the value that you want to search for in the array: ");
            scanf("%d",&value);
            linear_search(arr,value,length);
            break;
        case 6:
            ch++;
        }
    }

    return 0;
}
