#include <iostream>
#include <vector>
#include <string>
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

Node* insert(Node* root, int val) {
    if (!root)
        return new Node(val);

    if (val < root->data) {
        if (!root->left)
            root->left = new Node(val);
        else
            insert(root->left, val);
    }
    else if (val > root->data) {
        if (!root->right)
            root->right = new Node(val);
        else
            insert(root->right, val);
    }

    return root;
}

void convert(Node* root, Node*& prev) {
    if (!root)
        return;

    if (!root->lthread && root->left)
        convert(root->left, prev);
    else {
        root->left = prev;
        root->lthread = true;
    }

    if (prev && !prev->rthread && prev->right == nullptr) {
        prev->right = root;
        prev->rthread = true;
    }

    prev = root;

    if (!root->rthread && root->right)
        convert(root->right, prev);
}

Node* search(Node* root, int x) {
    Node* curr = root;

    while (curr) {
        if (x == curr->data)
            return curr;

        if (x < curr->data) {
            if (curr->lthread)
                return nullptr;
            curr = curr->left;
        }
        else {
            if (curr->rthread)
                return nullptr;
            curr = curr->right;
        }
    }

    return nullptr;
}

Node* successor(Node* curr) {
    if (!curr)
        return nullptr;

    if (curr->rthread)
        return curr->right;

    curr = curr->right;

    while (curr && !curr->lthread)
        curr = curr->left;

    return curr;
}

Node* predecessor(Node* curr) {
    if (!curr)
        return nullptr;

    if (curr->lthread)
        return curr->left;

    curr = curr->left;

    while (curr && !curr->rthread)
        curr = curr->right;

    return curr;
}

Node* lowerBound(Node* root, int x) {
    Node* curr = root;
    Node* ans = nullptr;

    while (curr) {
        if (curr->data >= x) {
            ans = curr;

            if (curr->lthread)
                break;

            curr = curr->left;
        }
        else {
            if (curr->rthread)
                break;

            curr = curr->right;
        }
    }

    return ans;
}

Node* minimum(Node* root) {
    if (!root)
        return nullptr;

    while (!root->lthread)
        root = root->left;

    return root;
}

int main() {
    Node* root = nullptr;
    bool converted = false;

    int q;
    cin >> q;

    while (q--) {
        string operation;
        cin >> operation;

        if (operation == "BUILD") {
            int n;
            cin >> n;

            for (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                root = insert(root, x);
            }

            converted = false;
        }

        else if (operation == "CONVERT") {
            Node* prev = nullptr;
            convert(root, prev);

            if (prev) {
                prev->right = nullptr;
                prev->rthread = true;
            }

            converted = true;
        }

        else if (operation == "NEXT") {
            int x;
            cin >> x;

            Node* curr = search(root, x);
            Node* ans = successor(curr);

            if (ans)
                cout << ans->data << endl;
            else
                cout << "NULL" << endl;
        }

        else if (operation == "PREV") {
            int x;
            cin >> x;

            Node* curr = search(root, x);
            Node* ans = predecessor(curr);

            if (ans)
                cout << ans->data << endl;
            else
                cout << "NULL" << endl;
        }

        else if (operation == "RANGE") {
            int L, R;
            cin >> L >> R;

            Node* curr = lowerBound(root, L);

            cout << "[";

            bool first = true;

            while (curr && curr->data <= R) {
                if (!first)
                    cout << ", ";

                cout << curr->data;
                first = false;

                curr = successor(curr);
            }

            cout << "]" << endl;
        }

        else if (operation == "KTH") {
            int k;
            cin >> k;

            Node* curr = minimum(root);

            for (int i = 1; i < k && curr; i++)
                curr = successor(curr);

            if (k < 1 || !curr)
                cout << "NULL" << endl;
            else
                cout << curr->data << endl;
        }
    }

    return 0;
}
