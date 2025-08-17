#include <iostream>
using namespace std;

int main() {
    int n,m,x,y;
    cout<<"enter the dimensions of the first matrix: ";
    cin>>n>>m;
    cout<<"enter the dimensions of the second matrix: ";
    cin>>x>>y;
    if(m!=x){
        cout<<"matrix multiplication not possible with such dimension of matrices, please enter correct dimensions"<<endl;
        return 0;
    }
    int arr1[n][m];
    int arr2[x][y];
    cout<<"enter values in matrix 1"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"enter element in row "<<(i+1)<<" and column "<<(j+1)<<": ";
            cin>>arr1[i][j];
        }
    }
    cout<<"enter the values in matrix 2"<<endl;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<"enter element in row "<<(i+1)<<" and column "<<(j+1)<<": ";
            cin>>arr2[i][j];
        }
    }
    cout<<"Matrix 1"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Matrix 2"<<endl;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }
    int prod_arr[n][y];
    for(int i=0;i<n;i++){
        for(int j=0;j<y;j++){
            int prod=0;
            for(int k=0;k<x;k++){
                prod+=arr1[i][k]*arr2[k][j];
            }
            prod_arr[i][j]=prod;
        }
    }
    cout<<"Product Matrix"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<y;j++){
            cout<<prod_arr[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}