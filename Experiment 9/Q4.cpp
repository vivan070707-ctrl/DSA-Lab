#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

struct Info {
    bool isBST;
    int minVal;
    int maxVal;
    int sum;
};

int maxSum = INT_MIN;

Info findMaxBST(Node* root) {
    if (root == NULL)
        return {true, INT_MAX, INT_MIN, 0};

    Info L = findMaxBST(root->left);
    Info R = findMaxBST(root->right);

    Info curr;

    if (L.isBST && R.isBST &&
        root->data > L.maxVal &&
        root->data < R.minVal) {

        curr.isBST = true;
        curr.sum = L.sum + R.sum + root->data;

        curr.minVal = min(root->data, L.minVal);
        curr.maxVal = max(root->data, R.maxVal);

        maxSum = max(maxSum, curr.sum);
    }
    else {
        curr.isBST = false;
        curr.sum = 0;
        curr.minVal = INT_MIN;
        curr.maxVal = INT_MAX;
    }

    return curr;
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);

    root->left->left = new Node(3);
    root->left->right = new Node(6);

    root->right->left = new Node(7);
    root->right->right = new Node(9);

    findMaxBST(root);

    cout << "Maximum BST subtree sum = " << maxSum;

    return 0;
}
