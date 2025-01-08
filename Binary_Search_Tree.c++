#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (!root) return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

bool search(Node* root, int value) {
    if (!root) return false;

    if (root->data == value) return true;
    if (value < root->data) return search(root->left, value);
    return search(root->right, value);
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    int value;
    cout << "Enter a value to search: ";
    cin >> value;

    if (search(root, value))
        cout << value << " found in the tree.\n";
    else
        cout << value << " not found in the tree.\n";

    return 0;
}
