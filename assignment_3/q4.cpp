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
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}
int main() {
    string s1;
    Stack s;
    string postfix_expression="";
    cout<<"enter the expression: ";
    getline(cin,s1);
    s1=s1+")";
    int n = s1.size();
    s.push('(');
    for(int i =0;i<n;i++){
        if(65<=s1[i] && s1[i]<=90){
            postfix_expression+=s1[i];
        }
        else if (s1[i]==')'){
            if(s1[i]==')'){
                while(!s.isEmpty() && s.peek()!='('){
                    postfix_expression+=s.peek();
                    s.pop();
                }
                s.pop();
            }
        }
        else if (s1[i]=='('){
            s.push(s1[i]);
        }
        else { // operator
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(s1[i])) {
                postfix_expression += s.peek();
                s.pop();
            }
            s.push(s1[i]);
        }
        
    }
    cout<<postfix_expression<<endl;
    return 0;
}