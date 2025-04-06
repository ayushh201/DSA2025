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
    int maxSum;
    int solve(TreeNode* root){
        if(root==nullptr) return 0;
        int l=solve(root->left);
        int r=solve(root->right);

        int path1 = l+r+root->val;
        int path2 = max(l,r)+root->val;
        int path3 = root->val;

        maxSum = max({maxSum,path1,path2,path3});
        return max(path2,path3);
    }
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        solve(root);
        return maxSum;
    }
};
