#include <iostream>
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

Node* insertNode(Node* root, int val){
    if(root == nullptr)
        return new Node(val);

    if(val < root->data)
        root->left = insertNode(root->left, val);
    else if(val > root->data)
        root->right = insertNode(root->right, val);
    else
        cout << "Duplicate value " << val << " ignored.\n";

    return root;
}

Node* findMin(Node* root){
    while(root && root->left)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key){
    if(root == nullptr) return nullptr;

    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }
        else if(root->left == nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // node with two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int maxDepth(Node* root){
    if(root == nullptr) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root){
    if(root == nullptr) return 0;
    if(root->left == nullptr)
        return 1 + minDepth(root->right);
    if(root->right == nullptr)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
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
    int arr[] = {50,30,70,20,40,60,80};
    for(int x: arr)
        root = insertNode(root, x);

    cout << "\nInorder Traversal of BST: ";
    inorder(root);
    cout << "\n";
    root = deleteNode(root, 30);

    cout << "After deleting 30: ";
    inorder(root);
    cout << "\n";

    cout << "Maximum Depth: " << maxDepth(root) << endl;
    cout << "Minimum Depth: " << minDepth(root) << endl;

    return 0;
}
