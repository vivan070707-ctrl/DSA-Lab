#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
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

void markParents(Node* root, unordered_map<Node*, Node*>& parent,
                 Node*& target, int S) {
    if (!root)
        return;

    if (root->data == S)
        target = root;

    if (root->left) {
        parent[root->left] = root;
        markParents(root->left, parent, target, S);
    }

    if (root->right) {
        parent[root->right] = root;
        markParents(root->right, parent, target, S);
    }
}

vector<int> distanceK(Node* root, int S, int K) {
    unordered_map<Node*, Node*> parent;
    Node* target = nullptr;

    markParents(root, parent, target, S);

    vector<int> ans;

    if (!target)
        return ans;

    queue<Node*> q;
    unordered_set<Node*> visited;

    q.push(target);
    visited.insert(target);

    int dist = 0;

    while (!q.empty()) {
        int sz = q.size();

        if (dist == K) {
            while (!q.empty()) {
                ans.push_back(q.front()->data);
                q.pop();
            }
            break;
        }

        while (sz--) {
            Node* curr = q.front();
            q.pop();

            if (curr->left && !visited.count(curr->left)) {
                q.push(curr->left);
                visited.insert(curr->left);
            }

            if (curr->right && !visited.count(curr->right)) {
                q.push(curr->right);
                visited.insert(curr->right);
            }

            if (parent.count(curr) && !visited.count(parent[curr])) {
                q.push(parent[curr]);
                visited.insert(parent[curr]);
            }
        }

        dist++;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int S, K;
    cin >> S >> K;

    Node* root = buildTree(a);

    vector<int> ans = distanceK(root, S, K);

    cout << "[";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];

        if (i != ans.size() - 1)
            cout << ", ";
    }

    cout << "]";

    return 0;
}
