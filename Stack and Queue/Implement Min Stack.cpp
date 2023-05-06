class MinStack {
public:
    stack<pair<int,int>>st ;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val}) ;
        }
        else{
            st.push({val,min(val,st.top().second)}) ;
        }
    }
    
    void pop() {
        st.pop() ;
    }
    
    int top() {
        return st.top().first ;
    }
    
    int getMin() {
        return st.top().second ;
    }
};



//optimized...space is reduced to O(n)
class MinStack {
public:
    stack<int>st ;
    int mini;
    
    MinStack() {
        mini=INT_MAX ;
    }
    
    void push(int val) {
        if(st.empty()){
            mini=val ;
            st.push(val) ;
        }
        else{
            if(val<mini){
                st.push(2*val -mini);
                mini=val ;
            }
            else{
                st.push(val) ;
            }
        }
    }
    
    void pop() {
        if(!st.empty()){
            if(st.top()<mini){
                mini=2*mini-st.top() ;
            }
            st.pop() ;
        }
    }
    
    int top() {
        return max(mini,st.top()) ;
    }
    
    int getMin() {
        return mini ;
    }
};
