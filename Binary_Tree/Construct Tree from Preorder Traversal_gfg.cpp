

/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return the root of the new binary tree formed
Node *solveit(int n, int pre[], char preLN[],int &ind){
    if(ind>=n){
        return NULL ;
    }
    Node *root = new Node(pre[ind]);
    ind++ ;
    if(preLN[ind-1]=='N'){
        root->left=solveit(n,pre,preLN,ind) ;
        root->right=solveit(n,pre,preLN,ind) ;
    }
    
    
    return root ;
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    if(n==0){
        return NULL ;
    }
    int ind=0 ;
    return solveit(n,pre,preLN,ind) ;
}
