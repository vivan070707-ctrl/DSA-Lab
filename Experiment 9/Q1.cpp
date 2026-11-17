#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void topView(Node* root) {
    if (root == NULL) return;

    map<int, int> mp;
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        Node* curr = p.first;
        int hd = p.second;

        if (mp.find(hd) == mp.end())
            mp[hd] = curr->data;

        if (curr->left)
            q.push({curr->left, hd - 1});

        if (curr->right)
            q.push({curr->right, hd + 1});
    }

    for (auto p : mp)
        cout << p.second << " ";
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    topView(root);

    return 0;
}
