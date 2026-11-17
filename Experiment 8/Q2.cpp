#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

int minDepth(TreeNode *node)
{
    if (node == nullptr)
        return 0;

    if (node->left == nullptr)
        return minDepth(node->right) + 1;

    if (node->right == nullptr)
        return minDepth(node->left) + 1;

    return min(minDepth(node->left),
               minDepth(node->right)) + 1;
}

void deleteTree(TreeNode *node)
{
    if (node == nullptr)
        return;

    deleteTree(node->left);
    deleteTree(node->right);

    delete node;
}

int main()
{
    TreeNode *root = new TreeNode(5);

    root->left = new TreeNode(12);
    root->right = new TreeNode(18);

    root->left->left = new TreeNode(25);
    root->left->right = new TreeNode(30);

    root->right->right = new TreeNode(40);

    int depth = minDepth(root);

    cout << "Minimum Depth: " << depth << endl;

    deleteTree(root);

    return 0;
}
