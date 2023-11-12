// User function Template for C++

class Solution {
  public:
    string removeKdigits(string num, int k) {
        if(k==num.size()){
            return "0" ;
        }
        if(k==0){
            return num ;
        }
        stack<int>st ;
        int n=num.size() ;

        //st.push(0) ;
        //int i=1 ;
        int i;
        int x=k ;
        for(i=0;i<n;i++){
            
            while(!st.empty() && num[i]<num[st.top()] && x>0){
                st.pop() ;
                x-- ;
            }
            

            if(st.empty() && num[i]=='0'){
                continue ;
            }
            st.push(i) ;
        }

        while(x>0 && !st.empty()){
            st.pop() ;
            x-- ;
        }

        if(st.empty()){
            return "0" ;
        }


        string ans;

        while(!st.empty()){
            ans.push_back(num[st.top()]) ;
            st.pop() ;
        }
        
        reverse(ans.begin(),ans.end()) ;

        return ans ;
    }
};
