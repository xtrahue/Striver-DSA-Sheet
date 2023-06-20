#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    stack<TreeNode*>st ;
    vector<int>ans ;
    if(root==NULL){
        return ans ;
    }
    
    TreeNode *newnode=root ;
    while(true){
        if(newnode!=NULL){
            st.push(newnode) ;
            newnode=newnode->left ;
        }
        else{
            if(st.empty()){
                break ;
            }
            newnode=st.top() ;
            st.pop() ;
            ans.push_back(newnode->data) ;
            newnode=newnode->right ;
        }
    }
    return ans ;
}
