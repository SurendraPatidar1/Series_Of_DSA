#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) return ans;
    
    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* temp = st.top();
        st.pop();
        ans.push_back(temp->val);

        // Push right child first so that left child is processed first
        if (temp->right) st.push(temp->right);
        if (temp->left) st.push(temp->left);
    }

    return ans;
}

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // Perform preorder traversal
    vector<int> result = preorderTraversal(root);

    // Print the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the allocated memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
