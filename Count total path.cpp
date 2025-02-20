#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// Function to count the total number of paths from root to leaf nodes
int countPaths(TreeNode* root) {
    // Base case: if the node is null, no path exists
    if (root == nullptr) {
        return 0;
    }

    // If the node is a leaf (both left and right are null), return 1 as a valid path is found
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    // Recursively count paths in the left and right subtrees
    return countPaths(root->left) + countPaths(root->right);
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

    // Correctly creating additional child nodes
    TreeNode* leftChildleft = new TreeNode;
    leftChildleft->val = 4;  // Set correct value
    leftChildleft->left = nullptr;
    leftChildleft->right = nullptr;

    TreeNode* rightChildright = new TreeNode;
    rightChildright->val = 5;  // Set correct value
    rightChildright->left = nullptr;
    rightChildright->right = nullptr;

    // Linking the nodes to form a simple binary tree
    root->left = leftChild;
    root->right = rightChild;

    root->left->left = leftChildleft;   // Link the left child of leftChild
    root->left->right = rightChildright; // Link the right child of leftChild

    // Counting the total paths in the tree
    int totalPaths = countPaths(root);

    // Output the result
    cout << "Total number of paths: " << totalPaths << endl;

    return 0;
}
