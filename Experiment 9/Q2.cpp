#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *first = NULL, *middle = NULL, *last = NULL;
Node *prevNode = NULL;

void correctBST(Node* root) {
    if (root == NULL) return;

    correctBST(root->left);

    if (prevNode != NULL && root->data < prevNode->data) {
        if (first == NULL) {
            first = prevNode;
            middle = root;
        } else {
            last = root;
        }
    }

    prevNode = root;

    correctBST(root->right);
}

void recoverBST(Node* root) {
    correctBST(root);

    if (first && last)
        swap(first->data, last->data);
    else if (first && middle)
        swap(first->data, middle->data);
}

void inorder(Node* root) {
    if (!root) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);

    root->left->left = new Node(1);
    root->left->right = new Node(7);

    root->right->left = new Node(4);
    root->right->right = new Node(9);

    recoverBST(root);

    inorder(root);

    return 0;
}
