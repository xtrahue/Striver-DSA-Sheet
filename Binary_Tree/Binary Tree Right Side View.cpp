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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans ;
        queue<TreeNode*>qu ;
        if(root==NULL){
            return ans;
        }
        qu.push(root) ;
        while(!qu.empty()){
            int k;
            int siz=qu.size() ;
            for(int i=0;i<siz;i++){
                TreeNode* newnode=qu.front() ;

                k=(newnode->val) ;

                if(newnode->left!=NULL){
                    qu.push(newnode->left) ;
                }
                if(newnode->right!=NULL){
                    qu.push(newnode->right) ;
                }
                qu.pop() ;
            }

            ans.push_back(k) ;
        }

        return ans ;

    }
};
