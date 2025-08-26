#include <iostream>
using namespace std;
int main() {
    char s1[100];
    char s2[100];
    int i=0;
    int j=0;
    cout<<"enter first string: ";
    cin.getline(s1,100);
    cout<<"enter second string: ";
    cin.getline(s2,100);
    while(s1[i]!='\0'){
        i++;
    }
    while(s2[j]!='\0'){
        s1[i]=s2[j];
        j++;
        i++;
    }
    s1[i]='\0';
    cout<<s1;
    return 0;
}
