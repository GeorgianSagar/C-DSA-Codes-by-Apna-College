#include<iostream>
#include<vector>
#include<queue>

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
Node* buildTree(vector<int> preorder){ // pass by reference & TC: O(N)
    static int idx = -1;
    idx++;
    if(preorder[idx] == -1){
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder); // return Left Subtree
    root->right = buildTree(preorder); // return Right Subtree

    return root;
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main(){
    vector<int> Binary_Tree = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int result = height(buildTree(Binary_Tree));

    cout<< "Height of Binary Tree is: " << result <<endl;

    return 0;
}