#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = right = NULL;
        }
};

static int idx = -1;
Node* buildTree(vector<int> preorder){ // pass by reference & TC: O(N)
    idx++;
    if(preorder[idx] == -1){
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder); // return Left Subtree
    root->right = buildTree(preorder); // return Right Subtree

    return root;
}

void preOrder(Node* root){
    if(root == NULL){
        cout<<-1<<" ";  //If we only want to print the values of nodes then we can skip this line
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);
    cout<<root->data<<endl; // 1
    cout<<root->left->data<<endl; // 2
    cout<<root->right->data<<endl; // 3
    cout<<root->right->left->data<<endl; // 4
    cout<<root->right->right->data<<endl; // 5

    preOrder(root); // 1 2 -1 -1 3 4 -1 -1 5 -1 -1
    cout<<endl;
    
    inOrder(root); // 2 1 4 3 5
    cout<<endl;

    postOrder(root); // 2 4 5 3 1
    cout<<endl;

    return 0;
}