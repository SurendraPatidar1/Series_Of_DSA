#include <iostream>

// Define the structure for a binary tree node
struct Node {
    int key;
    Node* left, *right;
};

// Function to return the height of the binary tree
int height_of_tree(Node* root)
{
    if(root == NULL) return 0;

    return 1+ std:: max(height_of_tree(root->left),height_of_tree(root->right));
}

// Function to create a new binary tree node
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

int main() {
    // Create a sample binary tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // Calculate and print the sum of all elements in the binary tree
    std::cout << "the height of the binary tree: " << height_of_tree(root) << std::endl;

    return 0;
}