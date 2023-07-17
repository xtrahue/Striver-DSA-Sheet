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
private:
    TreeNode *prev ;
    TreeNode *first ;
    TreeNode *mid ;
    TreeNode *second ;
public:
    void in(TreeNode *root){
        if(root==NULL){
            return ;
        }
        in(root->left) ;

        if(prev!=NULL && root->val<prev->val){
            if(first==NULL){
                first = prev ;
                mid=root ;
            }
            else{
                second=root ;
            }
        }

        prev=root ;
        in(root->right) ;
    }
    void recoverTree(TreeNode* root) {
        first=mid=second=NULL ;
        prev=new TreeNode(INT_MIN) ;
        in(root) ;
        if(first && second){
            swap(first->val,second->val) ;
        }
        else{
            swap(first->val,mid->val) ;
        }
    }
};
