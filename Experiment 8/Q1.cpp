#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

bool isMirror(Node *leftNode, Node *rightNode)
{
    if (leftNode == nullptr && rightNode == nullptr)
        return true;

    if (leftNode == nullptr || rightNode == nullptr)
        return false;

    return (leftNode->data == rightNode->data) &&
           isMirror(leftNode->left, rightNode->right) &&
           isMirror(leftNode->right, rightNode->left);
}

void deleteTree(Node *root)
{
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

int main()
{
    Node *root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(20);

    root->left->left = new Node(30);
    root->left->right = new Node(40);

    root->right->left = new Node(40);
    root->right->right = new Node(30);

    if (isMirror(root->left, root->right))
        cout << "Symmetric" << endl;
    else
        cout << "Non-Symmetric" << endl;

    deleteTree(root);

    return 0;
}
