class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>mp ;
        int maxi=1 ;

        for(auto it:arr){
            if(mp.find(it-difference)!=mp.end()){
                mp[it]=mp[it-difference]+1 ;
            }
            else{
                mp[it]=1 ;
            }

            maxi=max(maxi,mp[it]) ;
        }

        return maxi ;
    }
};
