#include <iostream>
using namespace std;

int main() {
    char v[10]={'A','E','I','O','U','a','e','i','o','u'};
    char s1[100];
    char s2[100];
    cout<<"enter the string from which you want to remove vowels: ";
    cin.getline(s1,100);
    int x=0;
    while(s1[x]!='\0'){
        x++;
    }
    int s_length=0;
    for(int i=0;i<x;i++){
        bool val=false;
        for(int j=0;j<10;j++){
            if(v[j]==s1[i]){
                val=true;
            }
        }
        if (val==false){
            s2[s_length]=s1[i];
            s_length++;
        }
    }
    s2[s_length]='\0';
    cout<<"the string with removed vowels is: "<<s2<<endl;    
    return 0;

}