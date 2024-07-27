#include <iostream>

// Define the structure for a binary tree node
struct Node {
    int key;
    Node* left, *right;
};

// Function to calculate the sum of all elements in the binary tree
void leafNode(Node* root, int& count) {
    if (!root) return;

    if(root->left == NULL && root->right == NULL)
    {
        count++;
    }
    leafNode(root->left, count);
    leafNode(root->right, count);
}

// Function to return the sum of all elements in the binary tree
int countLeaves(Node* root)
{
    int count;
    leafNode(root,count);
    return count;
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
    std::cout << "Sum of all elements in the binary tree: " << countLeaves(root) << std::endl;

    return 0;
}