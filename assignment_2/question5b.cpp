#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"enter the dimension of the tridiagonal matrix you want to create: ";
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"enter the element in column "<<(j+1)<<" and row "<<(i+1)<<": ";
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j || i==(j+1) || j==(i+1)){
                continue;
            }
            else{
                if(a[i][j]!=0){
                    cout<<"enter the correct matrix for tridiagonal matrix";
                    return 0;
                }
            }
        }
    }

    cout<<"the tridiagonal matrix is: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int m=3*n-2;
    int a1[m];
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j || i==(j+1) || j==(i+1)){
                a1[count++]=a[i][j];
            }
        }
    }
    cout<<"the new method of storing the tridiagonal matrix is in a 1D array that is:"<<endl;
    for(int i=0;i<m;i++){
        cout<<a1[i]<<" ";
    }
    return 0;
}