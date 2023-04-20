int countSquares(vector<vector<int>>& matrix) {
    int col=matrix[0].size();
    int row=matrix.size() ;

    vector<int>heights(col,0) ;
    vector<vector<int>>dp(row,vector<int>(col,0)) ;

    int maxi=0 ;

    for(int i=0;i<row;i++){
        dp[i][0]=matrix[i][0] ;
        //maxi+=dp[i][0] ;
    }
    for(int j=0;j<col;j++){
        dp[0][j]=matrix[0][j] ;
        //maxi+=dp[0][j] ;
    }

    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(matrix[i][j]==1){
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1 ;
                //maxi+=dp[i][j] ;
            }
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            maxi+=dp[i][j] ;
        }
    }


    return maxi ;
}
