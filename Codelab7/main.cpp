#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
};

struct Node* NewNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
};

void InOrder(Node* root){
    if (root) {
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
     }
}

void PreOrder(Node* root){
    if (root) {
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
     }
}

void PostOrder(Node* root){
    if (root) {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ";        
     }
}

void BfsTree(Node* root){
    queue<Node*> bfs;
        if (root) {
            bfs.push(root);
        }
        while (!bfs.empty())
        {
            const Node * const temp_node = bfs.front();
            bfs.pop();
            cout<< temp_node->data << " ";
            if (temp_node->left) {
                bfs.push(temp_node->left);
            }
            if (temp_node->right) {
                bfs.push(temp_node->right);
            }
        }
    }

void AllRootHelper(Node* root, vector<int> path)
    {
        if( root == NULL) return; 
        if (root->left == NULL && root->right == NULL){
            for (int i=0; i<path.size(); i++) {
                cout<<path.at(i) << " ";
            }
            cout << root->data << endl;
            return;
        }
        path.push_back(root->data);
        AllRootHelper(root->left, path);
        AllRootHelper(root->right, path);
 }

void AllRootToLeaves(Node* root){
    vector<int> path;
    AllRootHelper(root, path);
}

void SumHelper(Node* root, vector<int> path, int k){
    if( root == NULL) return; 
    vector<int> sum;
    if (root->left == NULL && root->right == NULL){
        for (int i=0; i<path.size(); i++) {
            sum.push_back(path.at(i));
        }
        sum.push_back(root->data);
        int total = 0;
        for (int i=0; i < sum.size(); i++){
            total+=sum.at(i);
        }
        if (total == k){
            for (int i=0; i < sum.size(); i++){
                cout<<sum.at(i) << " ";
            }
        }
        return;
    }
    path.push_back(root->data);
    SumHelper(root->left, path, k);
    SumHelper(root->right, path, k);
}

//This is extra credit. Only turn it in after completing other questions
void SumPath(Node* root, int k){
    vector<int> path;
    SumHelper(root, path, k);
}

int main(){
    struct Node *root = NewNode(1);
    root->left = NewNode(2);
    root->right = NewNode(3);
    root->left->left = NewNode(4);
    root->left->right = NewNode(5);
    root->right->left = NewNode(6);
    root->right->right = NewNode(7);
    cout << "Inorder: ";
    InOrder(root);
    cout << endl;   
    cout << "Preorder: ";
    PreOrder(root);
    cout << endl;  
    cout << "Postorder: ";
    PostOrder(root);
    cout << endl;   
    cout << "Levelorder: ";
    BfsTree(root);
    cout << endl;       
    cout << "Root to leaves path: " << endl;
    AllRootToLeaves(root);
    cout << "Sum equalling to 11: " << endl;
    SumPath(root, 11);
    cout << endl;
}
