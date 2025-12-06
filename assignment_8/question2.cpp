#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};
Node* insertNode(Node* root, int val){
    if(root == nullptr)
        return new Node(val);

    if(val < root->data)
        root->left = insertNode(root->left, val);
    else if(val > root->data)
        root->right = insertNode(root->right, val);

    return root;
}

Node* searchRecursive(Node* root, int key){
    if(root == nullptr || root->data == key)
        return root;

    if(key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

Node* searchIterative(Node* root, int key){
    while(root != nullptr){
        if(root->data == key) return root;
        else if(key < root->data) root = root->left;
        else root = root->right;
    }
    return nullptr;
}

Node* findMax(Node* root){
    if(root == nullptr) return nullptr;
    while(root->right != nullptr)
        root = root->right;
    return root;
}

Node* findMin(Node* root){
    if(root == nullptr) return nullptr;
    while(root->left != nullptr)
        root = root->left;
    return root;
}

Node* inorderSuccessor(Node* root, Node* x){
    if(x->right)
        return findMin(x->right);
    Node* successor = nullptr;
    while(root){
        if(x->data < root->data){
            successor = root;
            root = root->left;
        }
        else if(x->data > root->data){
            root = root->right;
        }
        else break;
    }
    return successor;
}

Node* inorderPredecessor(Node* root, Node* x){
    if(x->left)
        return findMax(x->left);
    Node* predecessor = nullptr;
    while(root){
        if(x->data > root->data){
            predecessor = root;
            root = root->right;
        }
        else if(x->data < root->data){
            root = root->left;
        }
        else break;
    }
    return predecessor;
}

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main(){
    Node* root = nullptr;
    int arr[] = {20,10,5,15,30,25,40};
    for(int x : arr)
        root = insertNode(root, x);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    int key = 15;
    cout << "\nSearching " << key << " Recursively: "
         << (searchRecursive(root, key) ? "Found" : "Not Found") << endl;

    cout << "Searching " << key << " Iteratively: "
         << (searchIterative(root, key) ? "Found" : "Not Found") << endl;

    cout << "\nMinimum: " << findMin(root)->data << endl;
    cout << "Maximum: " << findMax(root)->data << endl;

    Node* node = searchIterative(root, 20);
    Node* succ = inorderSuccessor(root, node);
    Node* pred = inorderPredecessor(root, node);

    cout << "\nIn-order Successor of " << node->data << ": "
         << (succ ? to_string(succ->data) : "None") << endl;

    cout << "In-order Predecessor of " << node->data << ": "
         << (pred ? to_string(pred->data) : "None") << endl;

    return 0;
}
