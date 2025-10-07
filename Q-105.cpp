#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int search(vector<int> & inorder, int left, int right, int val){
        for(int i=left; i<=right; i++ ){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }

    TreeNode* BT(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right){
        if(left > right){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preIdx]);
        int inIdx = search(inorder, left, right, preorder[preIdx]);
        preIdx++;
        root->left = BT(preorder, inorder, preIdx, left, inIdx-1);
        root->right = BT(preorder, inorder, preIdx, inIdx+1, right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return BT(preorder, inorder, preIdx, 0, inorder.size()-1);
    }
};

// Helper function to print inorder traversal
void printInorder(TreeNode* root) {
    if(!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;
    return 0;
}