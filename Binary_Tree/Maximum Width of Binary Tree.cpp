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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>qu ;
        qu.push({root,0}) ;

        long long ans=0 ;

        while(!qu.empty()){

            long long start=qu.front().second ;
            long long end=qu.back().second ;
            long long siz=qu.size() ;

            ans=max(ans,end-start+1) ;

            for(int i=0;i<siz;i++){
                pair<TreeNode*,long long>newnode=qu.front() ;


                long long it=newnode.second-start ;

                qu.pop() ;

                if(newnode.first->left!=NULL){
                    qu.push({newnode.first->left,2*it+1}) ;
                }
                if(newnode.first->right!=NULL){
                    qu.push({newnode.first->right,2*it+2}) ;
                }
            }

        }

        return (int)ans ;
    }
};
