class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st ;
        int n=heights.size() ;

        int maxi=0;

        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i])){
                int h=heights[st.top()] ;
                st.pop() ;
                int w=i ;
                if(!st.empty()){
                    w=i-st.top()-1 ;
                }

                maxi=max(maxi,h*w) ;
            }
            st.push(i) ;
        }

        return maxi ;
    }
};
