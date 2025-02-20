#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void countPaths(TreeNode* root, int& totalPaths) {
    if (!root) return;

    totalPaths++;  // Count the current node as a single path

    countPaths(root->left, totalPaths);
    countPaths(root->right, totalPaths);
}

int totalPathCount(TreeNode* root) {
    if (!root) return 0;
    
    int totalPaths = 0;
    countPaths(root, totalPaths);
    return totalPaths;
}

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Total Paths in Binary Tree: " << totalPathCount(root) << endl;

    return 0;
}
