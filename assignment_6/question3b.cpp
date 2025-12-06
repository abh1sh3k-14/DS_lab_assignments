#include <iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int n){
        next=nullptr;
        val=n;
    }
};
int find_size(Node* head){
    Node* curr=head;
    int count=0;
    while(curr->next!=head){
        curr=curr->next;
        count++;
    }
    cout<<"size of circular singly linked list is "<<count+1<<endl;
    return (count+1);
}
Node* array_to_linked_list(int* arr, int n){
    Node* head=new Node(arr[0]);
    Node* curr=head;
    for(int i=1;i<n;i++){
        Node* newnode=new Node(arr[i]);
        curr->next=newnode;
        curr=curr->next;
    }
    curr->next=head;
    return head;
}
int main() {
    int arr[]={1,2,3,4,5,6};
    Node* head=array_to_linked_list(arr,6);
    find_size(head);
    return 0;
}

