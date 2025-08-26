#include <iostream>
using namespace std;

int main() {
    cout<<"enter the dimensions of the diagonal matrix you want to create: ";
    int n,m;
    cin>>n>>m;
    if(n!=m){
        cout<<"enter the correct dimensions, a non square matrix cannot be a diagonal matrix";
        return 0;
    }
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"enter value of element in column "<<(j+1)<<" and row "<<(i+1)<<": ";
            cin>>a[i][j];
        }
    }
    cout<<"the diagonal matrix is: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int d[n];
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==j){
                d[count++]=a[i][j];
            }
        }
    }
    cout<<"the new method of storing the diagonal matrix is in a 1D array that is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<d[i]<<" ";
    }
    return 0;
}