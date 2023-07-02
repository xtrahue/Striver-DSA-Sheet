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
    bool static cmp(pair<int,int>&a ,pair<int,int>&b){
        if(a.second!=b.second){
            return a.second<b.second ;
            
            
        }
        return a.first<b.first;
        
        
    }
    map<int,vector<pair<int,int>>>mp ;
    void solveit(TreeNode* root,int px,int py){
        if(root==NULL){
            return ;
        }
        mp[py].push_back({root->val,px}) ;
        solveit(root->left,px+1,py-1) ;
        solveit(root->right,px+1,py+1) ;
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solveit(root,0,0) ;
        vector<vector<int>>ans ;

        for(const auto &ptr:mp){
            vector<pair<int,int>>temp ;
            for(const auto k:ptr.second){
                temp.push_back({k.first,k.second}) ;
            }
            sort(temp.begin(),temp.end(),cmp) ;
            
            vector<int>temp2 ;
            for(int i=0;i<temp.size();i++){
                temp2.push_back(temp[i].first) ;
            }

            ans.push_back(temp2) ;
        }

        return ans;
    }
};
