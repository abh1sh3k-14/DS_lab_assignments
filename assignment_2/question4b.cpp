#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"enter the length of the string you want to enter: ";
    cin>>n;
    char s[n+1];
    cout<<"enter the string you want to reverse: ";
    cin>>s;
    int x=0;
    while(s[x]!='\0'){
        x++;
    }
    for(int i=0;i<x/2;i++){
        char temp;
        temp=s[i];
        s[i]=s[x-i-1];
        s[x-i-1]=temp;
    }
    cout<<"reversed string is "<<s<<endl;
    return 0;
}