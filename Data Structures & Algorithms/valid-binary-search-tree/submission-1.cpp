/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    bool helper(TreeNode* root, int min, int max){
        if(!root)
            return true;
        int v=root->val;
        return (v>min && v<max) && helper(root->left,min,v) && helper(root->right, v, max);
    }

    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        return helper(root, INT_MIN,INT_MAX);
    }
};
