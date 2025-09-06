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

// Node* buildTree(vector<int> &preorder, int &index){
//     if(index >= preorder.size() || preorder[index] == -1){
//         index++;
//         return NULL;
//     }

//     Node* root = new Node(preorder[index++]);
//     root->left = buildTree(preorder, index);
//     root->right = buildTree(preorder, index);

//     return root;
// }

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);
    cout<<root->data<<endl; // 1
    cout<<root->left->data<<endl; // 2
    cout<<root->right->data<<endl; // 3
    cout<<root->right->left->data<<endl; // 4
    cout<<root->right->right->data<<endl; // 5
    return 0;
}