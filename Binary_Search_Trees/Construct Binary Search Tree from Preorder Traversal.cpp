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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0){
            return NULL ;
        }

        TreeNode *temp = new TreeNode(preorder[0]) ;
        if(preorder.size()<=1){
            return temp ;
        }

        vector<int>l ;
        vector<int>r ;

        for(int i=0;i<preorder.size();i++){
            if(preorder[i]>preorder[0]){
                r.push_back(preorder[i]) ;
            }
            else if(preorder[i]<preorder[0]){
                l.push_back(preorder[i]) ;
            }
            
        }
        temp->left = bstFromPreorder(l) ;
        temp->right=bstFromPreorder(r) ;


        return temp;
    }
};
