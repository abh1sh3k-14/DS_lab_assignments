#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node():data(0),next(nullptr){}
    Node(int n):data(n),next(nullptr){}
    Node(int n,Node* ne):data(n),next(ne){}
};
Node* insert_at_beginning(Node* head,int n){
    Node* newnode=new Node(n);
    if(head==nullptr){
      newnode->next=newnode;
      return newnode;
    }
    Node* curr=head;
    while(curr->next!=head){
        curr=curr->next;
    }
    curr->next=newnode;
    newnode->next=head;
    head=newnode;
    return head;
}
Node* insert_at_end(Node* head, int n){
    Node* curr=head;
    Node* newnode=new Node(n);
    while(curr->next!=head){
        curr=curr->next;
    }
    curr->next=newnode;
    newnode->next=head;
    return head;
}
Node* insert_after(Node* head,int after,int n){
    Node* newnode=new Node(n);
    Node* curr=head;
    while(curr->data!=after){
        curr=curr->next;
    }
    Node* temp=curr->next;
    curr->next=newnode;
    newnode->next=temp;
    return head;
}
Node* deletenode(Node* head,int n){
    if(head==nullptr) return nullptr;
    Node* curr=head;
    Node* prev=nullptr;
    while(curr->data!=n && curr->next!=head){
        prev=curr;
        curr=curr->next;
    }
    Node* temp=curr;
    curr=curr->next;
    prev->next=curr;
    delete temp;
    return head;
}
Node* deletenode(Node* head,int n){
    if(head==nullptr) return nullptr;
    Node* curr=head;
    Node* prev=nullptr;
    if(curr->data == n){
        while(curr->next!=head) curr=curr->next;
        if(curr==head){
            delete head;
            return nullptr;
        }
        curr->next = head->next;
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    curr=head;
    do{
        prev=curr;
        curr=curr->next;
        if(curr->data==n) break;
    }while(curr!=head);
    if(curr->data!=n){
        cout<<"Node not found\n";
        return head;
    }
    prev->next=curr->next;
    delete curr;
    return head;
}
int searchnode(Node* head,int n){
    int count=0;
    Node* curr=head;
    while(curr->data!=n && curr->next!=head){
        curr=curr->next;
        count++;
    }
    if(curr->data!=n){
        cout<<"node not found\n";
        return -1;
    }
    cout<<"the node is "<<count<<" places away from the head of the node\n";
    return count;
}
Node* array_to_linked_list(int* arr,int n){
    Node* head=new Node(arr[0]);
    Node* curr=head;
    for(int i=1;i<n;i++){
        Node* t=new Node(arr[i]);
        curr->next=t;
        curr=curr->next;
    }
    curr->next=head;
    return head;
}
void list_traverse(Node* head){
    if(head==nullptr){
      cout<<"list is empty\n";
      return;
    }
    Node* curr=head;
    cout<<"list: ";
    do{
        cout<<curr->data<<" ";
        curr=curr->next;
    }while(curr!=head)
    cout<<endl;
}
int main() {
    int choice;
    int n,after;
    int arr[]={20,100,40,80,60};
    Node* head=array_to_linked_list(arr,5);
    while(true){
        cout<<"WELCOME TO THE MENU DRIVEN PROGRAM FOR OPERATING ON SLL!!!\n";
        cout<<"ENTER 1 TO INSERT AT BEGINNING,2 TO INSERT AT END, 3 TO INSERT AFTER A SPECIFIC NODE, 4 TO DELETE A SPECIFIC NODE";
        cout<<", ENTER 5 TO SEARCH A NODE, ENTER 6 TO DISPLAY ALL NODES";
        cout<<"ENTER 0 TO STOP PROGRAM\n";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"enter the number you want to insert at beginning: ";
                cin>>n;
                head=insert_at_beginning(head,n);
                break;
            case 2:
                cout<<"enter the number you want to insert at end: ";
                cin>>n;
                head=insert_at_end(head,n);
                break;
            case 3:
                cout<<"enter the number after which you want to insert a node: ";
                cin>>after;
                cout<<"enter the number that you want to insert in the list: ";
                cin>>n;
                head=insert_after(head,after,n);
                break;
            case 4: 
                cout<<"enter the node that you want to delete: ";
                cin>>n;
                head=deletenode(head,n);
                break;
            case 5:
                cout<<"enter the node that you want to search: ";
                cin>>n;
                searchnode(head,n);
                break;
            case 6:
                list_traverse(head);
                break;
            case 0:
                cout<<"exiting....\n";
                return 0;
            default:
                cout<<"enter proper input\n";
        }
    }
    return 0;
}
