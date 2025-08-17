#include <iostream>
using namespace std;

int main() {
    int n,m;
    cout<<"enter the dimension of the matrix you want to create: ";
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"enter the value of element in row "<<(i+1)<<" and column "<<(j+1)<<": ";
            cin>>arr[i][j];
        }
    }
    cout<<"matrix"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"sum of all rows"<<endl;
    for(int i=0;i<n;i++){
        int sum=0;
        cout<<"sum of row "<<(i+1)<<": ";
        for(int j=0;j<m;j++){
            sum+=arr[i][j];
        }
        cout<<sum;
        cout<<endl;
    }
    cout<<"sum of all columns"<<endl;
    for(int i=0;i<m;i++){
        int sum=0;
        cout<<"sum of column "<<(i+1)<<": ";
        for(int j=0;j<n;j++){
            sum+=arr[j][i];
        }
        cout<<sum;
        cout<<endl;
    }
    return 0;
}