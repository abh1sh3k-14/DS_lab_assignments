#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

bool isBSTUtil(Node* root, int minVal, int maxVal){
    if(root == nullptr) return true;

    if(root->data <= minVal || root->data >= maxVal)
        return false;

    return  isBSTUtil(root->left, minVal, root->data) &&
            isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root){
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

Node* insert(Node* root, int val){ 
    if(!root) return new Node(val);
    if(val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

int main(){
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    if(isBST(root))
        cout << "The tree is a BST." << endl;
    else
        cout << "The tree is NOT a BST." << endl;

    return 0;
}
