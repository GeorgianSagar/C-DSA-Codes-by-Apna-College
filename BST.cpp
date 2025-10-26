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

Node* insertBST(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

Node* buildBST(vector<int> arr) {
    Node* root = NULL;
    for (int val : arr) {
        root = insertBST(root, val);
    }
    return root;
}

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
bool searchBST(Node* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    if (key < root->data) {
        return searchBST(root->left, key);
    } else {
        return searchBST(root->right, key);
    }
}

int main(){
    vector<int> arr = {3,2,1,5,6,4};
    Node* root = buildBST(arr);
    cout << "In-order Traversal of BST: ";
    inOrder(root);
    cout << endl;
    int key = 5;
    if (searchBST(root, key)) {
        cout << key << " found in BST." << endl;
    } else {
        cout << key << " not found in BST." << endl;
    }

    return 0;
}