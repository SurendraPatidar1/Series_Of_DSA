#include <iostream>

// Define the structure for a binary tree node
struct Node {
    int key;
    Node* left, *right;
};

// Function to calculate the sum of all elements in the binary tree
void non_leafNode(Node* root, int& count) {
    if (!root) return;

    if(root->left == NULL && root->right == NULL)
    return;

    count++;
    non_leafNode(root->left, count);
    non_leafNode(root->right, count);
}

// Function to return the sum of all elements in the binary tree
int countNon_Leaves(Node* root)
{
    int count;
    non_leafNode(root,count);
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
    std::cout << "count of all Non-leaf Nodes in the binary tree: " << countNon_Leaves(root) << std::endl;

    return 0;
}