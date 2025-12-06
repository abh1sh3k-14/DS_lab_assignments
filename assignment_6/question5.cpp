#include <iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int n){
        val=n;
        next=nullptr;
    }
};
Node* array_to_linked_list(int* arr,int n){
    Node* head=new Node(arr[0]);
    Node* curr=head;
    for(int i=1;i<n;i++){
        Node* temp=new Node(arr[i]);
        curr->next=temp;
        curr=curr->next;
    }
    curr->next=head;
    return head;
}
bool isCircular(Node* head){
    Node* curr=head;
    while(curr!=nullptr && curr->next!=head){
        curr=curr->next;
    }
    if(curr==nullptr){
        return false;
    }
    else{
        return true;
    }
}
int main() {
    int arr[]={1,2,3,4,5,6};
    Node* head=array_to_linked_list(arr,6);
    cout<<isCircular(head)<<endl;
    return 0;

}
