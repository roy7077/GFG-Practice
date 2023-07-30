// RECURSION  | MEMOIZATION  |  TABULATION  |  SPACE OPTIMIZED

// RECURSION
class Solution{
public:
    int help(vector<vector<int>> M,int n,int i,int j)
    {
        //base case
        if(i==n-1)
        return M[i][j];
        
        //recursive calls
        int a,b,c;
        a=b=c=M[i][j];
        
        if(i+1<n)
        a+=help(M,n,i+1,j);
        
        if(i+1<n and j+1<n)
        b+=help(M,n,i+1,j+1);
        
        if(i+1<n and j-1>=0)
        c+=help(M,n,i+1,j-1);
        
        return max({a,b,c});
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int ans=0;
        for(int i=0;i<N;i++)
        {
            int a=help(Matrix,N,0,i);
            ans=max(ans,a);
        }
        
        return ans;
    }
};
 

// MEMOIZATION
class Solution{
public:
    int help(vector<vector<int>>& M,int n,int i,int j,vector<vector<int>>& memo)
    {
        //base case
        if(i==n-1)
        return M[i][j];
        
        //memo check
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        //recursive calls
        int a,b,c;
        a=b=c=M[i][j];
        
        if(i+1<n)
        a+=help(M,n,i+1,j,memo);
        
        if(i+1<n and j+1<n)
        b+=help(M,n,i+1,j+1,memo);
        
        if(i+1<n and j-1>=0)
        c+=help(M,n,i+1,j-1,memo);
        
        return memo[i][j]=max({a,b,c});
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> memo(N,vector<int>(N,-1));
        int ans=0;
        for(int i=0;i<N;i++)
        {
            int a=help(Matrix,N,0,i,memo);
            ans=max(ans,a);
        }
        
        return ans;
    }
};
 

// TABULATION
class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(N,vector<int>(N,0));
        int ans=0;
        for(int i=N-1;i>=0;i--)
        {
            for(int j=0;j<N;j++)
            {
                int a,b,c;
                a=b=c=Matrix[i][j];
                
                if(i+1<N)
                a+=dp[i+1][j];
                
                if(i+1<N and j+1<N)
                b+=dp[i+1][j+1];
                
                if(i+1<N and j-1>=0)
                c+=dp[i+1][j-1];
                
                dp[i][j]=max({a,b,c});
            }
        }

        for(int i=0;i<N;i++)
        ans=max(ans,dp[0][i]);
        
        return ans;
    }
};
 

// SPACE OPTIMIZED
class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<int> next(N,0);
        int ans=0;
        for(int i=N-1;i>=0;i--)
        {
            vector<int> curr(N,0);
            for(int j=0;j<N;j++)
            {
                int a,b,c;
                a=b=c=Matrix[i][j];
                
                if(i+1<N)
                a+=next[j];
                
                if(i+1<N and j+1<N)
                b+=next[j+1];
                
                if(i+1<N and j-1>=0)
                c+=next[j-1];
                
                curr[j]=max({a,b,c});
            }
            next=curr;
        }

        for(int i=0;i<N;i++)
        ans=max(ans,next[i]);
        
        return ans;
    }
};