#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

void inorder(Node* root, vector<int>& arr) {
    if (!root)
        return;

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    vector<int> arr;
    inorder(root, arr);

    int q;
    cin >> q;

    while (q--) {
        int k;
        cin >> k;

        if (k < 1 || k > arr.size())
            cout << -1 << endl;
        else
            cout << arr[k - 1] << endl;
    }

    return 0;
}
