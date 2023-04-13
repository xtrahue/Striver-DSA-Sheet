class Solution {
public:
    static bool cmp(string &s1,string &s2){
        return s1.size()<s2.size() ;
    }
    bool check(string &s1,string &s2){
        if(s1.size()!=s2.size()+1){
            return 0;
        }
        int p1=0,p2=0 ;
        while(p1<s1.size() && p2<s2.size()){
            if(s1[p1]==s2[p2]){
                p1++ ;
                p2++ ;
            }
            else{
                p1++ ;
            }
        }
        if(p1<=s1.size() && p2==s2.size()){
            return 1;
        }
        return 0;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size() ;
        vector<int>dp(n,1) ;

        sort(words.begin(),words.end(),cmp) ;
        for(int i=0;i<words.size();i++){
            //cout<<words[i]<<endl ;
        }
        int maxi=1 ;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                //cout<<j<<" "<<i<<" check:"<<check(words[i],words[j])<<endl ;
                if(check(words[i],words[j]) && 1+dp[j]>dp[i]){
                    
                    dp[i]=1+dp[j] ;
                }
            }
            maxi=max(dp[i],maxi) ;
        }

        return maxi;
    }
};
