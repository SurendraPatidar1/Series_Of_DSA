#include<iostream>
#include<vector>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution {
  public:
  void total(Node* root , int &count){
    if(root == NULL) return;

    count++;
    total(root->left,count);
    total(root->right,count);
  }
  int getSize(Node* root)
  {
    int count;
     total(root,count);
     return count;
  }
};