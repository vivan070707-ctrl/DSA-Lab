#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void inorderTraversal(TreeNode *root, vector<int> &values)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left, values);
    values.push_back(root->data);
    inorderTraversal(root->right, values);
}

pair<int, int> findKthSmallestLargest(TreeNode *root, int k)
{
    vector<int> values;

    inorderTraversal(root, values);

    if (k < 1 || k > (int)values.size())
        return make_pair(-1, -1);

    int smallest = values[k - 1];
    int largest = values[values.size() - k];

    return make_pair(smallest, largest);
}

void deleteTree(TreeNode *root)
{
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    TreeNode *root = new TreeNode(10);

    root->left = new TreeNode(6);
    root->right = new TreeNode(14);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(8);

    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(16);

    int k = 3;

    pair<int, int> result = findKthSmallestLargest(root, k);

    if (result.first == -1)
    {
        cout << "Invalid value of k" << endl;
    }
    else
    {
        cout << "Kth smallest: " << result.first << endl;
        cout << "Kth largest: " << result.second << endl;
    }

    deleteTree(root);

    return 0;
}
