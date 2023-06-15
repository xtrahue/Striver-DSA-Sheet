int findCelebrity(int n) {
 	// Write your code here.
	stack<int>st ;
	for(int i=0;i<n;i++){
		st.push(i) ;
	}

	while(st.size()>1){
		int a=st.top() ;
		st.pop() ;

		int b=st.top() ;
		st.pop() ;

		if(knows(a,b)){
			st.push(b) ;
		}
		else {
			st.push(a) ;
		}
		
	}
	int k=st.top() ;
	for(int i=0;i<n;i++){
		if((i!=k) && (knows(k,i) || (!knows(i,k)))){
			return -1;
		}
	}

	return k ;
}
