//My approach-->TLE
class Solution {
private:
    vector<string>ans ;   
    vector<bool>vis ;

    void solveit(string w,vector<int>&groups,vector<string>temp,unordered_map<string,int>mp ){
        if(temp.size()>ans.size()){
            ans =temp ;                           
        }
        
        int curr_ind=mp[w] ;
        
        vis[curr_ind]=1 ;
        int curr_grp = groups[curr_ind] ;
        //cout<<w<<" " ;
        //cout<<curr_grp ;
        
        for(int i=0;i<w.size();i++){
            char reset = w[i] ;
            //cout<<reset<<endl ;

            for(char ch='a';ch<='z';ch++){   
                if(ch!=reset){
                    w[i]=ch ;
                    //cout<<w<<"->" ;
                    if(mp.find(w)!=mp.end()){
                        //cout<<mp[w]<<endl ;
                        //cout<<w<<"->"<<mp[w]<<"->" ;
                        int nxt_grp=groups[mp[w]] ;
                        
                        //cout<<nxt_grp<<" " ;
                        if((nxt_grp!=curr_grp) && mp[w]>curr_ind){
                            //cout<<curr_grp<<" "<<nxt_grp ;
                            //cout<<w<<" "<<endl ;
                            temp.push_back(w) ;
                            
                            solveit(w,groups,temp,mp) ;
                            temp.pop_back() ;
                        }
                    }
                    
                    w[i]=reset ;
                   
                }
            }
            
        }
        //cout<<endl ;

        return ;
    }
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        //int n=words.size();
        vis.resize(n,0) ;
        unordered_map<string,int>mp ;
        for(int i=0;i<n;i++){
            mp[words[i]] = i ;
        }

        // for(auto it:words){
        //     cout<<it<<"->"<<mp[it]<<" " ;
        // }
        // cout<<endl ;

        // if(mp.find("dab")!=mp.end()){
        //     cout<<"-1"<<endl ;
        // }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                //cout<<words[i]<<" " ;
                vector<string>temp ;
                temp.push_back(words[i]) ;
                solveit(words[i],groups,temp,mp) ;
            }
        }


        return ans ;
    }
};



//Antoher Approach using LIS
class Solution {
private:
    bool isHam_1(string a,string b){
        if(a.size()!=b.size()){
            return 0;
        }

        int cnt=0;

        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                cnt++ ;
            }
        }

        return (cnt==1) ;
    }
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<int>cnt(n,1) ;
        vector<int>prev(n,-1) ;

        int maxCnt=1,maxInd=0 ;

        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(groups[i]!=groups[j] && isHam_1(words[i],words[j])){
                    if(cnt[j]+1>cnt[i]){
                        cnt[i]=cnt[j]+1 ;
                        prev[i]=j ;
                    }

                    if(cnt[i]>maxCnt){
                        maxInd=i ;
                        maxCnt=cnt[i] ;
                    }
                }
            }
        }

        vector<string>ans ;

        while(maxCnt>0){
            ans.push_back(words[maxInd]);
            maxInd=prev[maxInd] ;
            maxCnt-- ;
        }

        reverse(ans.begin(),ans.end()) ;

        return ans ;
    }
};
