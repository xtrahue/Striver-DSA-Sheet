//My Solution --> Gives TLE at 32 no. testcase in leetcode but enough for interview
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st ;
        
        int n=wordList.size() ;

        for(int i=0;i<n;i++){
            st.insert(wordList[i]) ;
        }

        queue<vector<string>>qu ;
        vector<string>pu ;
        pu.push_back(beginWord) ;
        qu.push(pu) ;

        int lev=0 ;
        int final_level=INT_MAX ;

        vector<vector<string>>ans ;

        while(!qu.empty()){           
            while(qu.front().size()==lev+1){
                //lev++ ;
                vector<string>sequence = qu.front() ;
                qu.pop() ;
                string curr = sequence[sequence.size()-1] ;
                cout<<curr<<" " ;

                if(curr==endWord){
                    if(sequence.size()<=final_level){
                        ans.push_back(sequence) ;
                        final_level=sequence.size() ;
                    }
                }
                st.erase(curr) ;
                for(int i=0;i<curr.size();i++){
                    for(char ch='a';ch<='z';ch++){
                        string differ=curr ;
                        differ[i]=ch ;

                        if(st.find(differ)!=st.end()){
                            sequence.push_back(differ) ;
                            qu.push(sequence) ;
                            sequence.pop_back() ;
                        }
                    }
                }
            }
            lev++ ;
        }
        cout<<endl;


        return ans ;
    }
};


//Striver's Brute force approach -->also gives TLE
