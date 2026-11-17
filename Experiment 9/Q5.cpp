#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void serialize(Node* root, stringstream& ss) {
    if (root == NULL) {
        ss << "# ";
        return;
    }

    ss << root->data << " ";

    serialize(root->left, ss);
    serialize(root->right, ss);
}

string serializeTree(Node* root) {
    stringstream ss;
    serialize(root, ss);
    return ss.str();
}

Node* deserialize(stringstream& ss) {
    string val;

    if (!(ss >> val))
        return NULL;

    if (val == "#")
        return NULL;

    Node* root = new Node(stoi(val));

    root->left = deserialize(ss);
    root->right = deserialize(ss);

    return root;
}

Node* deserializeTree(string data) {
    stringstream ss(data);
    return deserialize(ss);
}

void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    string data = serializeTree(root);

    cout << "Serialized Tree: " << data << endl;

    Node* newRoot = deserializeTree(data);

    cout << "Inorder after Deserialization: ";
    inorder(newRoot);

    return 0;
}
