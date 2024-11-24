#include<iostream>
 
 // Definition for a binary tree node.
  struct TreeNode {
    int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool cheaknode(TreeNode* root)
    {
        if(root->left==nullptr&&root->right==nullptr)
            return true;
        if(root->left==nullptr)
        {
            if(root->val<root->right->val)
            return true;
            else
            return false;
        }
        if(root->right==nullptr)
        {
            if(root->val>root->left->val)
            return true;
            else
            return false;
        }
        return (root->val>root->left->val&&root->val<root->right->val);
    }
    bool preOrder(TreeNode* root)
    {
        if(root->left==nullptr&&root->right==nullptr)
            return true;
        if(root->left==nullptr)
        {
            if(preOrder(root->right))
                return cheaknode(root);
            return false;
        }
        if(root->right==nullptr)
        {
            if(preOrder(root->left))
                return cheaknode(root);
            return false;
        }
        if(preOrder(root->left)&&preOrder(root->right))
            return cheaknode(root);
        return false;
    }
    bool isValidBST(TreeNode* root)
    {
        return preOrder(root);
    }
};

int main()
{
    TreeNode* e2=new TreeNode(1);
    TreeNode* e3=new TreeNode(3);
    TreeNode* e1=new TreeNode(2,e2,e3);
    Solution a1;
    std::cout<<a1.isValidBST(e1);
    return 0;
}