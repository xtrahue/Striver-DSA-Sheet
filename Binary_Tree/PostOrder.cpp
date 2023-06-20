//best one...just do pre than reverse the array and return 
class Solution{
    public:
    vector<int> postOrder(Node* node) {
        // code here
        stack<Node*>st ;
        vector<int>ans ;
        
        st.push(node) ;
        
        if(node==NULL){
            return ans;
        }
        
        Node *newnode=node ;
        while(!st.empty()){
            Node* temp=st.top() ;
            st.pop() ;
            
            ans.push_back(temp->data) ;
            
            if(temp->left!=NULL){
                st.push(temp->left) ;
            }
            if(temp->right!=NULL){
                st.push(temp->right) ;
            }
        }
        reverse(ans.begin(),ans.end()) ;
        return ans ;
    }
};


//using one stack
class Solution{
    public:
    vector<int> postOrder(Node* node) {
        // code here
        stack<Node*>st ;
        vector<int>ans ;
        if(node==NULL){
            return ans;
        }
        
        Node *newnode=node ;
        while(!st.empty() || newnode!=NULL){
            if(newnode!=NULL){
                st.push(newnode) ;
                newnode=newnode->left ;
            }
            else{
                Node* temp=st.top()->right;
                if(temp!=NULL){
                    newnode=temp;
                }
                else{
                    temp=st.top() ;
                    ans.push_back(temp->data);
                    st.pop();
                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top() ;
                        st.pop();
                        ans.push_back(temp->data);
                    }
                }
            }
        }
        
        return ans ;
    }
};
