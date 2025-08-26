#include <iostream>
using namespace std;

int main() {
    char s[100];
    cout<<"enter the string: ";
    cin.getline(s,100);
    int l=0;
    while(s[l]!='\0'){
        l++;
    }
    for(int i=0;i<l;i++){
        if(s[i]>='A' && s[i]<='Z'){
            s[i]=s[i]+32;
        }
    }
    cout<<"the modified string is: "<<s<<endl;
    return 0;
}