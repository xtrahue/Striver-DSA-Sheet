// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start==end){
            return 0;
        }
        
        queue<pair<int,int>>qu ;
        qu.push({0,start}) ;
        
        vector<int>dis(100001,INT_MAX) ;
        dis[start] =0 ;
        
        while(!qu.empty()){
            int node=qu.front().second ;
            int steps = qu.front().first ;
            qu.pop() ;
            
            for(auto it:arr){
                int newNode = (node *it)%100000 ;
                
                if(dis[newNode]>steps+1){
                    dis[newNode]=steps+1 ;
                    if(newNode==end){
                        return steps+1 ;
                    }
                    qu.push({steps+1,newNode}) ;
                }
            }
        }
        
        return -1;
    }
};
