//My approach
class Solution {
public:
    bool isPresent(TreeNode* root, TreeNode *n){
        if(root==NULL){
            return 0 ;
        }
        if(root==n){
            return 1;
        }

        return isPresent(root->left,n)||isPresent(root->right,n) ;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL|| root==p || root==q){
            return root ;
        }
        bool p_left = isPresent(root->left,p) ;
        bool q_left = isPresent(root->left,q) ;

        if(p_left && q_left){
            return lowestCommonAncestor(root->left,p,q) ;
        }
        else if(p_left || q_left){
            return root ;
        }
        else{
            return lowestCommonAncestor(root->right,p,q) ;
        }
    }
};




//from solutions
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q){
            return root ;
        }
        TreeNode *l=lowestCommonAncestor(root->left,p,q) ;
        TreeNode *r=lowestCommonAncestor(root->right,p,q) ;

        if(l==NULL){
            return r ;
        }
        else if(r==NULL){
            return l ;
        }
        else{
            return root ;
        }
    }
};
