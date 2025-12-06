#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node():data(0),next(nullptr),prev(nullptr){}
    Node(int n):data(n),next(nullptr),prev(nullptr){}
    Node(int n,Node* pr,Node* ne):data(n),next(ne),prev(pr){}
};
Node* array_to_linked_list(int* arr,int n){
    Node* head=new Node(arr[0]);
    Node* curr=head;
    for(int i=1;i<n;i++){
        Node* temp=new Node(arr[i]);
        curr->next=temp;
        temp->prev=curr;
        curr=curr->next;
    }
}
int list_size(Node* head){
    Node* curr=head;
    int count=0;
    while(curr!=nullptr){
        curr=curr->next;
        count++;
    }
    cout<<"the size of the linked list is "<<count<<endl;
    return count;
}
int main() {
    int arr[]={20,100,40,60,80};
    Node* head=array_to_linked_list(arr,5);
    int n=list_size(head);
    
    return 0;
}

