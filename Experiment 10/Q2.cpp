#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    bool lthread, rthread;

    Node(int val) {
        data = val;
        left = right = nullptr;
        lthread = rthread = false;
    }
};

Node* buildTree(vector<int>& a) {
    if (a.empty() || a[0] == -1)
        return nullptr;

    Node* root = new Node(a[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < a.size()) {
        Node* curr = q.front();
        q.pop();

        if (a[i] != -1) {
            curr->left = new Node(a[i]);
            q.push(curr->left);
        }
        i++;

        if (i < a.size() && a[i] != -1) {
            curr->right = new Node(a[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

void convert(Node* root, Node*& prev) {
    if (root == nullptr)
        return;

    if (root->left)
        convert(root->left, prev);
    else {
        root->left = prev;
        root->lthread = true;
    }

    if (prev != nullptr && prev->right == nullptr) {
        prev->right = root;
        prev->rthread = true;
    }

    prev = root;

    if (root->right)
        convert(root->right, prev);
}

void inorder(Node* root) {
    if (root == nullptr)
        return;

    Node* curr = root;

    while (!curr->lthread && curr->left != nullptr)
        curr = curr->left;

    while (curr != nullptr) {
        cout << curr->data << " ";

        if (curr->rthread)
            curr = curr->right;
        else {
            curr = curr->right;

            while (curr != nullptr && !curr->lthread)
                curr = curr->left;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    Node* root = buildTree(a);

    Node* prev = nullptr;
    convert(root, prev);

    if (prev != nullptr) {
        prev->right = nullptr;
        prev->rthread = true;
    }

    inorder(root);

    return 0;
}
