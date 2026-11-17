#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* insertNode(Node *root, int value)
{
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);

    return root;
}

void inorderTraversal(Node *root, vector<int> &result)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left, result);
    result.push_back(root->data);
    inorderTraversal(root->right, result);
}

void deleteTree(Node *root)
{
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    int n;

    cout << "Enter number of integers: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Please enter a positive number." << endl;
        return 0;
    }

    vector<int> numbers(n);

    cout << "Enter " << n << " integers: ";

    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    Node *root = NULL;

    for (int i = 0; i < n; i++)
        root = insertNode(root, numbers[i]);

    vector<int> sortedNumbers;

    inorderTraversal(root, sortedNumbers);

    cout << "Sorted: ";

    for (int i = 0; i < (int)sortedNumbers.size(); i++)
        cout << sortedNumbers[i] << " ";

    cout << endl;

    deleteTree(root);

    return 0;
}
