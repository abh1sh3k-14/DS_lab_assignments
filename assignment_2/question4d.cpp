#include <iostream>
using namespace std;
char toLower(char c){
    if (c>= 'A' && c<='Z'){
        return (c+32);
    }
    return c;
}
int main() {
    char s[100];
    cout<<"enter the string you want to sort in alphabetical order: ";
    cin.getline(s,100);
    int l=0;
    while(s[l]!='\0'){
        l++;
    }
    //using character bubblesort here
    for(int i=0;i<(l-1);i++){
        for(int j=0;j<(l-i-1);j++){
            if (toLower(s[j])>toLower(s[j+1])){
                char temp=s[j+1];
                s[j+1]=s[j];
                s[j]=temp;
            }
        }
    }
    cout<<"the sorted array is "<<s<<endl;
    return 0;
}