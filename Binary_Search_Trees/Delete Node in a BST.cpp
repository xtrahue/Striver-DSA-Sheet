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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *temp=root ;
        TreeNode* prev=NULL ;
        while(temp){
            if(key==temp->val){
                break ;
            }
            if(key>temp->val){
                prev=temp ;
                temp=temp->right ;
            }
            else{
                prev=temp ;
                temp=temp->left ;
            }
        }
        if(temp==NULL){
            return root ;
        }

        TreeNode *l ;
        temp->left?l=temp->left:l=NULL ;
        TreeNode *r;
        temp->right?r=temp->right:r=NULL ;

        bool lefty=0,righty=0 ;

        if(!l && !r){
            if(prev){
                if(prev->left && prev->left->val==key){
                    prev->left =NULL ;
                }
                else{
                    prev->right=NULL ;
                }
            }
            else{
                return NULL ;
            }
            return root ;
        }

        

        
        if(!l){
            if(!prev){
                return root->right ;
            }
            else if(prev->left && prev->left->val==key){
                prev->left = temp->right ;
            }
            else{
                prev->right = temp->right ;
            }
        }
        else if(!r){
            if(!prev){
                return root->left ;
            }
            else if(prev->left && prev->left->val==key){
                prev->left = temp->left ;
            }
            else{
                prev->right = temp->left ;
            }
        }
        else{
            TreeNode* store=r ;
            while(r->left){
                r=r->left ;
            }
            if(prev){
                if(prev->left && prev->left->val==key){
                    prev->left=temp->right ;
                }
                else{
                    prev->right=temp->right ;
                }
            }
            else{
                root=store ;
            }

            r->left=l ;
        }

        return root ;
    }
};
