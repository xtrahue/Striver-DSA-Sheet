class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        set<string>st ;

        int n=wordList.size() ;

        for(int i=0;i<n;i++){
            st.insert(wordList[i]) ;
        }

        queue<pair<string,int>>qu ;
        qu.push({beginWord,1}) ;

        int step=1 ;
        st.erase(beginWord) ;

        while(!qu.empty()){
            string curr=qu.front().first ;
            step = qu.front().second ;

            qu.pop() ;

            int siz = curr.size() ;
            for(int i=0;i<siz;i++){
                for(char ch='a' ;ch<='z'; ch++){
                    string temp = curr ;
                    temp[i]=ch ;

                   // cout<<temp<<endl ;
                    if(st.find(temp)!=st.end()){
                        if(temp==endWord){
                            return step+1 ;
                        }
                        qu.push({temp,step+1}) ;
                        st.erase(temp) ;
                    }
                }
            }
        }

        return 0;
    }
};
