/*
    给定一个二叉树 root ，返回其最大深度。

    二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
    
    输入：root = [3,9,20,null,null,15,7]
    输出：3
*/

#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
    TreeNode(int x, TreeNode* l, TreeNode* r):val(x),left(l),right(r){}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main() {
    // TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode* root = new TreeNode(1, NULL, new TreeNode(2));
    Solution s;
    cout << s.maxDepth(root) << endl;
    return 0;
}