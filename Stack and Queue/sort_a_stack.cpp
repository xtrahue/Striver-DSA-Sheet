#include <bits/stdc++.h> 
void insert(stack<int>& stack,int temp){
	if(stack.empty() || (!stack.empty() && stack.top()<temp)){
		stack.push(temp) ;
		return ;
	}

	int t2=stack.top() ;
	stack.pop() ;

	insert(stack,temp) ;
	stack.push(t2) ;

}
void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()){
		return ;
	}

	int temp=stack.top() ;
	stack.pop() ;

	sortStack(stack) ;

	insert(stack,temp) ;
}
