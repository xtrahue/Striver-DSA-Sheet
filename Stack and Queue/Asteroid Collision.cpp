class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n=a.size();
        stack<int>pos ;
        stack<int>neg ;

        for(int i=n-1;i>=0;i--){
            if(a[i]>0){
                if(!neg.empty()){
                    while(!neg.empty() && a[i]>abs(neg.top()) ){
                        neg.pop() ;
                    }
                    if(!neg.empty()){
                        if(abs(neg.top())==a[i]){
                            neg.pop() ;
                        }
                    }
                    else{
                        pos.push(a[i]) ;
                    }
                }
                else{
                    pos.push(a[i]) ;
                }

            }
            else{
                neg.push(a[i]) ;
            }
        }

        

        vector<int>ans ;
        while(!neg.empty()){
            ans.push_back(neg.top()) ;
            neg.pop() ;
        }

        while(!pos.empty()){
            ans.push_back(pos.top()) ;
            pos.pop() ;
        }


        return ans ;
    }
};
