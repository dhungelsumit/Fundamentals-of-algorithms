#include <iostream>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
};

struct Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
};

void inorder(Node* root){
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
     }
}

void preorder(Node* root){
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
     }
}

void postorder(Node* root){
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";        
     }
}

void BFS_tree(Node* root){



}

void all_root_to_leaves(Node* root){



}
//This is extra credit. Only turn it in after completing other questions
void sumPath(Node* root, int k){
    
}

int main(){
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    inorder(root);
    cout << endl;    
    preorder(root);
    cout << endl;    
    postorder(root);
    cout << endl;    
//    BFS_tree(root);
//    all_root_to_leaves(root);
//    sumPath(root, 11);
}
