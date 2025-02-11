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

void preOrderTraversal(Node* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";
    
    preOrderTraversal(root->left);

    preOrderTraversal(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Pre-order Traversal of the Tree: ";
    preOrderTraversal(root);
    
    return 0;
}