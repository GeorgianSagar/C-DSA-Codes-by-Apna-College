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
        // cout<<-1<<" ";  //If we only want to print the values of nodes then we can skip this line
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

// Function to transform tree to sum tree (to be implemented)
int TransformSumTree(Node* root) {
    // To be implemented by user
    if(root == NULL){
        return 0;
    }

    int LeftSum = TransformSumTree(root->left);
    int RightSum = TransformSumTree(root->right);

    root-> data += LeftSum + RightSum;
    return root->data;

}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);
    
    cout << "before conversion: ";
    preOrder(root);
    cout << endl;

    TransformSumTree(root);
    cout << "after conversion: ";
    preOrder(root);
    cout << endl;

    return 0;
}