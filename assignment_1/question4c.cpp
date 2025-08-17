#include <iostream>
using namespace std;

int main() {
    int n,m;
    cout<<"enter the dimension of the matrix you want to create: ";
    cin>>n>>m;
    int arr[n][m];
    int t[m][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"enter the value of element in row "<<(i+1)<<" and column "<<(j+1)<<": ";
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            t[j][i]=arr[i][j];
        }
    }
    cout<<"matrix"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"transposed matrix"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}