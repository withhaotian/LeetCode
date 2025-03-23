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


#include <iostream>

using namespace std;

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
        int res = 0;
        int max_depth = 0;
    
        int dfs(TreeNode* root, int dirt, int height) {
            if (!root)  return 0;
    
            int ret = 0;
            // int height = 0;
            int max_depth_l = 0;
            int max_depth_r = 0;
            if (root->left && dirt == 1) {
                height ++;
                max_depth_l = height + dfs(root->left, dirt * -1, height);
                height --;
            }
            if (root->right && dirt == -1) {
                height ++;
                max_depth_r = height + dfs(root->right, dirt * -1, height);
                height --;
            }
            ret = max(max_depth_l, max_depth_r);
            cout << ret << endl;
    
            return ret;
        }
    
        int longestZigZag(TreeNode* root) {
            int ret_l = dfs(root, 1, 0);    // 1: left
            int ret_r = dfs(root, -1, 0);   // -1: right
            return max(ret_l, ret_r);
        }
    };

/*
输入：root = [1,1,1,null,1,null,null,1,1,null,1]
输出：4
解释：蓝色节点为树中最长交错路径（左 -> 右 -> 左 -> 右）。
*/

int main() {    
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->left->right->left = new TreeNode(1);
    root->left->right->right = new TreeNode(1);
    root->left->right->left->right = new TreeNode(1);
    cout << s.longestZigZag(root) << endl;
    return 0;
}