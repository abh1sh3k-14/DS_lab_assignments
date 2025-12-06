#include <iostream>
using namespace std;
#define MAXLEN 10
class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int n){
        data=n;
        right=left=nullptr;
    }
};
class Queue{
    public:
    Node* arr[MAXLEN];
    int count=0;
    int f,r;
    Queue(){
        f=r=-1;
        count=0;
    }
    void enqueue(Node* n){
        if(count==0){
            f=r=0;
            arr[r]=n;
        }
        else{
            if(r==MAXLEN-1){
                cout<<"queue is full\n";
                return;
            }
            r++;
            arr[r]=n;
        }
        count++;
    }
    void dequeue(){
        if(count==0){
            cout<<"queue is empty\n";
            return;
        }
        else if(count==1){
            f=r=-1;
            count--;
            return;
        }
        for(int i=0;i<count-1;i++){
            arr[i]=arr[i+1];
        }
        count--;
        r--;
    }
    int size(){
        return count;
    }
    Node* front(){
        return arr[f];
    }
};
static int idx=-1;
Node* array_to_tree(int* arr,int n){    
    idx++;
    if(idx>=n || arr[idx]==-1)
        return nullptr;
    Node* newnode= new Node(arr[idx]);
    newnode->left=array_to_tree(arr,n);
    newnode->right=array_to_tree(arr,n);
    return newnode;
}
void preorder(Node* r){
    Node* root=r;
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* r){
    Node* root=r;
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node* r){
    Node* root=r;
    if(root==nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void levelorder(Node* r){
    Node* root=r;
    Queue q;
    q.enqueue(root);
    q.enqueue(nullptr);
    while(q.size()>0){
        Node* curr=q.front();
        q.dequeue();
        if(curr==nullptr){
            if(q.size()!=0){
                cout<<endl;
                q.enqueue(nullptr);
                continue;
            }
            else{
                break;
            }
        }
        cout<<curr->data<<" ";
        if(curr->left!=nullptr)
            q.enqueue(curr->left);
        if(curr->right!=nullptr)
            q.enqueue(curr->right);
    }
}
int main() {
    int arr[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=array_to_tree(arr,13);
    cout<<"preorder: ";
    preorder(root);
    cout<<endl;
    cout<<"inorder: ";
    inorder(root);
    cout<<endl;
    cout<<"postorder: ";
    postorder(root);
    cout<<endl;
    cout<<"levelorder: ";
    levelorder(root);
    return 0;
}
