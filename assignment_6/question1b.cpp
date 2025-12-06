#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node():data(0),next(nullptr),prev(nullptr){}
    Node(int n):data(n),next(nullptr),prev(nullptr){}
    Node(int n,Node* ne,Node* pr):data(n),next(ne),prev(pr){}
};
Node* insert_at_beginning(Node* head,int n){
    if(head==nullptr){
        Node* newnode=new Node(n);
        head=newnode;
        return head;
    }
    Node* newnode=new Node(n);
    Node* curr=head;
    curr->prev=newnode;
    newnode->next=curr;
    head=newnode;
    return head;
}
Node* insert_at_end(Node* head, int n){
    if(head==nullptr){
        Node* newnode=new Node(n);
        head=newnode;
        return head;
    }
    Node* curr=head;
    Node* newnode=new Node(n);
    while(curr->next!=nullptr){
        curr=curr->next;
    }
    curr->next=newnode;
    // newnode->next=nullptr;
    newnode->prev=curr;
    return head;
}
Node* insert_after(Node* head,int after,int n){
    Node* newnode=new Node(n);
    Node* curr=head;
    while(curr->data!=after && curr->next!=nullptr){
        curr=curr->next;
    }
    if(curr->data!=after && curr->next==nullptr){
        cout<<"specified node not found in DLL\n";
        return head;
    }
    if(curr->data==after && curr->next==nullptr){
        curr->next=newnode;
        newnode->prev=curr;
        return head;
    }
    Node* temp=curr->next;
    curr->next=newnode;
    newnode->prev=curr;
    newnode->next=temp;
    temp->prev=newnode;
    return head;
}
Node* deletenode(Node* head,int n){
    Node* curr=head;
    // Node* prev=nullptr;
    while(curr!=nullptr && curr->data!=n){
        // prev=curr;
        curr=curr->next;
    }
    if(curr==nullptr){
        cout<<"node not found\n";
        return head;
    }
    if(curr!=head && curr->next!=nullptr){
        Node* temp=curr;
        Node* t=curr->prev;
        curr=curr->next;
        curr->prev=t;
        t->next=curr;
        // prev->next=curr;
        delete temp;
    }
    else if(curr!=head && curr->next==nullptr){
        Node* temp=curr;
        curr=curr->prev;
        curr->next=nullptr;
        delete temp;
    }
    else if(curr==head && curr->next==nullptr){
        delete curr;
        return nullptr;
    }
    else if(curr==head && curr->next!=nullptr){
        head=head->next;
        head->prev=nullptr;
        delete curr;
        return head;
    }
    return head;
}
int searchnode(Node* head,int n){
    int count=0;
    Node* curr=head;
    while(curr->data!=n && curr!=nullptr){
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
        Node* temp=curr;
        curr=curr->next;
        curr->prev=temp;
    }
    // curr->next=head;
    return head;
}
void list_traverse(Node* head){
    Node* curr=head;
    cout<<"list: ";
    while(curr->next!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
int main() {
    Node* head = nullptr;
    int choice, n, after;
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    head = array_to_linked_list(arr, size);
    while(true){
        cout << "\n====== DOUBLY LINKED LIST MENU ======\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Delete a Node\n";
        cout << "5. Search a Node\n";
        cout << "6. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> n;
                head = insert_at_beginning(head, n);
                cout << "Node inserted.\n";
                break;

            case 2:
                cout << "Enter value to insert at end: ";
                cin >> n;
                head = insert_at_end(head, n);
                cout << "Node inserted.\n";
                break;

            case 3:
                cout << "Enter value after which to insert: ";
                cin >> after;
                cout << "Enter value to insert: ";
                cin >> n;
                head = insert_after(head, after, n);
                break;

            case 4:
                cout << "Enter value to delete: ";
                cin >> n;
                head = deletenode(head, n);
                break;

            case 5:
                cout << "Enter value to search: ";
                cin >> n;
                searchnode(head, n);
                break;

            case 6:
                cout << "Current List: ";
                list_traverse(head);
                break;

            case 0:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}

