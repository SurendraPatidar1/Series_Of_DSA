
/*Structure of the node of the binary tree*/
#include <iostream>

// Define the structure for a binary tree node
struct Node {
    int key;
    Node* left, *right;
};

// Function to calculate the sum of all elements in the binary tree
void btSum(Node* root, int& sum) {
    if (!root) return;

    sum = sum + root->key;
    btSum(root->left, sum);
    btSum(root->right, sum);
}

// Function to return the sum of all elements in the binary tree
long int sumBT(Node* root) {
    int sum = 0; // Initialize sum to 0
    btSum(root, sum);
    return sum;
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
    std::cout << "Sum of all elements in the binary tree: " << sumBT(root) << std::endl;

    return 0;
}