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

/*
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

 

示例 1：



输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
输出：3
解释：和等于 8 的路径有 3 条，如图所示。
示例 2：

输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：3

*/

#include <iostream>
#include <unordered_map>

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
    
        unordered_map<long long, int> prefix;
    
        void dfs(TreeNode* root, int targetSum, long long tmpSum) {
            if (!root)  return;

            tmpSum += root->val;
            if (prefix.count(tmpSum - targetSum)) {
                res += prefix[tmpSum - targetSum];
            }
            
            prefix[tmpSum] ++;
            dfs(root->left, targetSum, tmpSum);
            dfs(root->right, targetSum, tmpSum);
            prefix[tmpSum] --;
    
            return;
        }
    
        int pathSum(TreeNode* root, int targetSum) {
            prefix[0] = 1;
            dfs(root, targetSum, 0);
            return res;
        }
    };

int main() {    
    Solution s;
    TreeNode* root = new TreeNode(1, new TreeNode(-2), new TreeNode(-3));
    cout << s.pathSum(root, -1) << endl;
    return 0;
}