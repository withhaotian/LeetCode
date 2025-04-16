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
        TreeNode* res = nullptr;
        int max_dept = -1;
    
        int dfs(TreeNode* root, int depth) {
            if (!root)  {
                max_dept = max(depth, max_dept);
                return depth;
            }
            
            auto max_l = dfs(root->left, depth+1);
            auto max_r = dfs(root->right, depth+1);
    
            if (max_l == max_dept && max_r == max_dept) {
                res = root;
            }
    
            return max(max_l, max_r);
        }
    
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            dfs(root, 0);
            return res;
        }
    };