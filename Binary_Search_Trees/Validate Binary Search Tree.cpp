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
    bool solvedit(TreeNode *root , long long mini,long long maxi){
        if(!root){
            return true ;
        }
        if(root->val<=mini || root->val>=maxi){
            return false ;
        }
        else{
            return (solvedit(root->left,mini,root->val) && solvedit(root->right,root->val,maxi)) ;
        }
    }
    bool isValidBST(TreeNode* root) {
        long long mini=-30000000000,maxi=30000000000 ;
        return solvedit(root,mini,maxi) ;
    }
};
