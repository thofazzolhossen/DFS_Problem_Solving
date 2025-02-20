#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// Function to print all paths from root to leaf nodes
void printPaths(TreeNode* root, vector<int>& path) {
    // Base case: if the node is null, return
    if (root == nullptr) {
        return;
    }

    // Add current node's value to the path
    path.push_back(root->val);

    // If it's a leaf node, print the current path
    if (root->left == nullptr && root->right == nullptr) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    } else {
        // Otherwise, continue the DFS traversal
        printPaths(root->left, path);
        printPaths(root->right, path);
    }

    // Remove the current node from the path before returning to the parent node
    path.pop_back();
}

int main() {
    // Manually creating nodes
    TreeNode* root = new TreeNode;
    root->val = 1;
    root->left = nullptr;
    root->right = nullptr;

    TreeNode* leftChild = new TreeNode;
    leftChild->val = 2;
    leftChild->left = nullptr;
    leftChild->right = nullptr;

    TreeNode* rightChild = new TreeNode;
    rightChild->val = 3;
    rightChild->left = nullptr;
    rightChild->right = nullptr;

    // Creating additional child nodes
    TreeNode* leftChildleft = new TreeNode;
    leftChildleft->val = 4;
    leftChildleft->left = nullptr;
    leftChildleft->right = nullptr;

    TreeNode* rightChildright = new TreeNode;
    rightChildright->val = 5;
    rightChildright->left = nullptr;
    rightChildright->right = nullptr;

    // Linking the nodes to form a simple binary tree
    root->left = leftChild;
    root->right = rightChild;

    root->left->left = leftChildleft;   // Link the left child of leftChild
    root->left->right = rightChildright; // Link the right child of leftChild

    // Vector to store the current path
    vector<int> path;

    // Printing all paths from the root to leaf nodes
    cout << "Paths from root to leaf nodes:" << endl;
    printPaths(root, path);

    return 0;
}
