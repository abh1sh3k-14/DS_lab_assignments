#include <iostream>
using namespace std;
class Stack{
    int top;
    int n;
    bool empty,full;
    public:
    int* arr;
    Stack(int x){
        n=x;
        arr[n];
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
    int peek(void){
        return arr[top];    
    }
};

int main() {
    Stack s(5);
    bool truth;
    int n=1,x,val;
    while(n==1){
        cout<<"WELCOME TO OUR MENU DRIVEN PROGRAM!!!"<<endl;
        cout<<"ENTER 1 FOR PUSH, 2 FOR POP, 3 TO CHECK IF THE STACK IS EMPTY, 4 TO CHECK IF IT IS FULL,5 TO DISPLAY THE STRING AND 6 TO PEEK"<<endl;
        cout<<"enter operation:";
        cin>>x;
        switch(x){
            case 1:
                cout<<"enter the value you want to enter: ";
                cin>>val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                truth=s.isEmpty();
                if(truth){
                    cout<<"stack is empty"<<endl;
                }
                else{
                    cout<<"stack is not empty"<<endl;
                }
                break;
            case 4:
                truth=s.isFull();
                if(truth){
                    cout<<"stack is full"<<endl;
                }
                else{
                    cout<<"stack is not full"<<endl;
                }
                break;
            case 5:
                s.display();
                break;
            case 6:
                val=s.peek();
                cout<<"the value at the top of the stack is "<<val<<endl;
                break;
        }
        cout<<"enter 1 to continue 0 to end: ";
        cin>>n;
    }
    return 0;
}
