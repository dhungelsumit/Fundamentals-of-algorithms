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
    
}

void preorder(Node* root){


}

void postorder(Node* root){



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
// The calls for the above incomplete functions commented out purposefully. Please uncomment after you have completed all the above methods.
//    inorder(root);
//    preorder(root);
//    postorder(root);
//    BFS_tree(root);
//    all_root_to_leaves(root);
//    sumPath(root, 11);
}
