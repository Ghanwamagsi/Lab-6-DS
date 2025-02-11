#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}

bool searchNonRecursive(Node* root, int key) {
    while (root != nullptr) {
        if (key == root->data)
            return true;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

bool searchRecursive(Node* root, int key) {
    if (root == nullptr)
        return false;

    if (key == root->data)
        return true;
    else if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

void inOrderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    Node* root = nullptr;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : values) {
        root = insert(root, val);
    }

    cout << "In-Order Traversal of BST: ";
    inOrderTraversal(root);
    cout << endl;

    int key = 40;
    if (searchNonRecursive(root, key))
        cout << "Key " << key << " found (Non-Recursive Search)" << endl;
    else
        cout << "Key " << key << " not found (Non-Recursive Search)" << endl;

    key = 100;
    if (searchRecursive(root, key))
        cout << "Key " << key << " found (Recursive Search)" << endl;
    else
        cout << "Key " << key << " not found (Recursive Search)" << endl;

    return 0;
}