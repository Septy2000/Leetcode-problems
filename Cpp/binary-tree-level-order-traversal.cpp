// https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/628/

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
    vector<vector<int>> levels;
    
    void helper(TreeNode* node, int level) {
        if (levels.size() == level) {
            levels.push_back(vector<int>());
        }
        
        levels[level].push_back(node->val);
        
        if (node->left) {
            helper(node->left, level + 1);
        }
        if (node->right) {
            helper(node -> right, level + 1);
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return levels;
        helper(root, 0);
        return levels;
    }
};