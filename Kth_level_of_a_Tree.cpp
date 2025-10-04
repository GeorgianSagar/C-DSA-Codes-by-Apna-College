#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

void KthLevel(Node* root, int k){
    if(root ==NULL){
        return ;
    }

    if(k==1){
        cout<<root->data<<" ";
        return ;
    }
    KthLevel(root->left, k-1);
    KthLevel(root->right, k-1);

}

int main(){
    vector<int> preorder = {1,2,7,-1,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);

    KthLevel(root, 3);
    return 0;
}