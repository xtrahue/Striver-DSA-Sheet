//A derivation of the vertical order traversal -->My solution.Complexity ->0(nlogn)
//Striver's approach...just takes a queue ....and instead of map<int,pair> ....takes a map<int,int>
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    map<int,pair<int,int>>mp ;
    void solveit(Node *root,int px,int py){
        if(root==NULL){
            return ;
        }
        if(mp.find(py)==mp.end() ){
            mp[py]={root->data,px} ;
        }
        else if( mp[py].second>px){
            mp[py]={root->data,px} ;
        }

        solveit(root->left,px+1,py-1) ;
        solveit(root->right,px+1,py+1) ;
    }
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans ;
        solveit(root,0,0) ;
        
        for(auto it:mp){
            ans.push_back(it.second.first) ;
        }
        
        return ans ;
    }

};
