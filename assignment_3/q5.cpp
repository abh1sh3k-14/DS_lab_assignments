#include <iostream>
#include<cmath>
using namespace std;
class Stack{
    int top;
    bool empty,full;
    public:
    int arr[100];
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
    int peek(void){
        if(isEmpty()){
            return -1;
        }
        return arr[top];    
    }
};
int main() {
    Stack s;
    int result;//result
    string s2="34+52-*";
    int n= s2.size();
    for(int i=0;i<n;i++){
        if(s2[i]!='+' && s2[i]!='-' && s2[i]!='*' && s2[i]!='/' && s2[i]!='^'){
            s.push(int(s2[i]-'0'));
        }
        else{
            int t1=s.peek();
            s.pop();
            int t2=s.peek();
            s.pop();
            switch(s2[i]){
                case '+':
                    result=t2+t1;
                    break;
                case '-':
                    result=t2-t1;
                    break;
                case '*':
                    result=t2*t1;
                    break;
                case '/':
                    result=t2/t1;
                    break;
                case '^':
                    result=pow(t2,double(t1));
                    break;
            }
            s.push(result);
        }
    }
    cout<<"result: "<<s.peek()<<endl;

    return 0;
}