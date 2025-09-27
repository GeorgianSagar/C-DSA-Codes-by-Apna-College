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

void BottomView(Node* root){
    queue <pair<Node*, int>> q; // node, horizontal distance
    map<int, int> m; // horizontal distance, node->data
    int minH = 0, maxH = 0; // to keep track of min and max horizontal distance
    q.push({root,0}); // horizontal distance of root is 0

    while(q.size()>0){
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();

        // if(m.find(currHD) == m.end()){ // if horizontal distance is not present in map
        //     m[currHD] = curr->data; // insert the node's data
        // }
        // else{
        //     m[currHD] = curr->data; // update the node's data (for bottom view)
        // }
        
        m[currHD] = curr->data; // insert the node's data (for bottom view, we always update)

        if(curr->left != NULL){
            q.push({curr->left, currHD-1}); // horizontal distance of left child is currHD-1
        }
        if(curr->right != NULL){
            q.push({curr->right, currHD+1}); // horizontal distance of right child is currHD+1
        }
    }
    for(auto it:m){
        cout<<it.second<<" "; // print the node's data
    }
    cout<<endl;
}
int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);

    BottomView(root);
    return 0;
}