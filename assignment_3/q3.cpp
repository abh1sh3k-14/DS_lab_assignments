#include <iostream>
using namespace std;
class Stack{
    int top;
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
        if(top==(99)){
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
        if(isEmpty()){
            return -1;
        }
        return arr[top];    
    }
};
int main() {
    string s1;
    Stack s;
    int n;
    cout<<"enter the expression: ";
    getline(cin,s1);
    n=s1.size();
    for(int i=0;i<n;i++){
        if(s1[i]=='('){
            s.push(s1[i]);
        }
        else{
            if (s.isEmpty()){
                cout<<"the expression has imbalanced parenthesis"<<endl;
                return 0;
            }
            else{
                s.pop();
            }
        }
    }
    if(s.peek()!=-1){
        cout<<"the expression has imbalanced parenthesis"<<endl;
    }
    else{
        cout<<"the expression has balanced parenthesis!!"<<endl;
    }
    return 0;
}