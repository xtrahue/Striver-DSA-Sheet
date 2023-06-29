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
    int diameterOfBinaryTree(TreeNode* root) {
        int height=0 ;
        ans(root,height) ;

        return height ;
    }
private:
    int ans(TreeNode* root,int &height){
        if(root==NULL){
            return 0;
        }

        int lh=ans(root->left,height) ;
        int rh=ans(root->right,height) ;

        height=max(height,rh+lh) ;

        return 1+max(lh,rh) ;
    }
};
