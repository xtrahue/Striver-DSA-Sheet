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
    unordered_map<int,int> mp ;
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root){
            return 0;
        }
        if(mp.find(k-(root->val)) != mp.end() ){
            return 1;
        }

        mp[root->val]++ ;
        return findTarget(root->left,k) || findTarget(root->right,k) ;

    }
};
