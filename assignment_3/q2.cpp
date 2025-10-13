#include <iostream>
using namespace std;
class Stack{
    int top;
    int n;
    bool empty,full;
    public:
    char arr[100];
    Stack(){
        top=-1;
        empty=true;
        full=false;
    }
    void push(int a){
        if (isFull()){
            cout<<"OVERFLOW CONDITION"<<endl;
        }
        else{
            top++;
            arr[top]=a;
        }
    }
    void pop(void){
        if (isEmpty()){
            cout<<"UNDERFLOW"<<endl;
        }
        else{
            top--;
        }
    }
    bool isEmpty(){
        if(top==-1){
            empty=true;
            return empty;
        }
        else{
            empty=false;
            return empty;
        }
    }
    bool isFull(){
        if(top==(n-1)){
            full=true;
            return full;
        }
        else{
            full=false;
            return full;
        }
    }
    void display(void){
        cout<<"the stack is: ";
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    char peek(void){
        return arr[top];    
    }
};
int main() {
    Stack s;
    char c;
    string s1="DataStructure";
    int n=0;
    c=s1[n];
    for(int i=0;i<s1.size();i++){
        s.push(c);
        c=s1[++n];
    }
    for(int i=0;i<n;i++){
        cout<<s.peek();
        s.pop();
    }
    cout<<endl;
    return 0;
}