#include <iostream>
#include <vector>
#include <stack>
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

void initializePredecessor(Node* root, int x, stack<Node*>& pred) {
    while (root) {
        if (root->data <= x) {
            pred.push(root);
            root = root->right;
        } else {
            root = root->left;
        }
    }
}

void initializeSuccessor(Node* root, int x, stack<Node*>& succ) {
    while (root) {
        if (root->data > x) {
            succ.push(root);
            root = root->left;
        } else {
            root = root->right;
        }
    }
}

Node* getPredecessor(stack<Node*>& st) {
    Node* curr = st.top();
    st.pop();

    Node* temp = curr->left;

    while (temp) {
        st.push(temp);
        temp = temp->right;
    }

    return curr;
}

Node* getSuccessor(stack<Node*>& st) {
    Node* curr = st.top();
    st.pop();

    Node* temp = curr->right;

    while (temp) {
        st.push(temp);
        temp = temp->left;
    }

    return curr;
}

void kClosest(Node* root, int x, int k) {
    stack<Node*> pred, succ;

    initializePredecessor(root, x, pred);
    initializeSuccessor(root, x, succ);

    while (k-- > 0) {
        if (pred.empty()) {
            cout << getSuccessor(succ)->data << " ";
        }
        else if (succ.empty()) {
            cout << getPredecessor(pred)->data << " ";
        }
        else {
            int d1 = abs(pred.top()->data - x);
            int d2 = abs(succ.top()->data - x);

            if (d1 <= d2)
                cout << getPredecessor(pred)->data << " ";
            else
                cout << getSuccessor(succ)->data << " ";
        }
    }
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);

    root->left->left = new Node(2);
    root->left->right = new Node(7);

    root->right->left = new Node(12);
    root->right->right = new Node(20);

    root->left->right->left = new Node(6);
    root->left->right->right = new Node(8);

    int x = 9, k = 4;

    kClosest(root, x, k);

    return 0;
}
