#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"enter the dimension of the triangular matrix you want to create: ";
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"enter the element in column "<<(j+1)<<" and row "<<(i+1)<<": ";
            cin>>a[i][j];
        }
    }
    //checking if the matrix entered by user is actually upper triangular or not
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (j<i){
                if(a[i][j]!=0){
                    cout<<"This is not an upper triangular matrix";
                    return 0;
                }
            }
        }
    }
    //printing the matrix
    cout<<"the upper triangular matrix is: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int m=n*(n+1)/2;
    int d[m];//creating 1D array
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>=i){
                d[count++]=a[i][j];
            }
        }
    }
    cout<<"the new method of storing the upper triangular matrix is in a 1D array that is:"<<endl;
    for(int i=0;i<m;i++){
        cout<<d[i]<<" ";
    }
    return 0;
}