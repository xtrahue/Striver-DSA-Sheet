class Solution {
public:
    void solveit(int i,string digits,string temp,vector<string> &ans,vector<string> &char_map){
        if(i==digits.size()){
            ans.push_back(temp) ;
            return ;
        }
        int ind=(int)(digits[i]-'0') ;
        for(int j=0;j<char_map[ind].size();j++){
            solveit(i+1,digits,temp+char_map[ind][j],ans,char_map) ;
        }
    }
    vector<string> letterCombinations(string digits) {
        int n=digits.size() ;
        vector<string>ans ;
        if(n==0){
            return ans ;
        }
        vector<string>char_map={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"} ;
        

        solveit(0,digits,"",ans,char_map) ;

        return ans;
    }
};
