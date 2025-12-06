#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node():data(0),next(nullptr){}
    Node(int n):data(n),next(nullptr){}
    Node(int n,Node* ne):data(n),next(ne){}
};
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
void display(Node* head){
    Node* curr=head;
    while(curr->next!=head){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<curr->data<<" ";
    cout<<curr->next->data<<" ";
    cout<<endl;
}
int main() {
    int arr[]={20,100,40,80,60};
    Node* head=array_to_linked_list(arr,5);
    display(head);
    return 0;
}