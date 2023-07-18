
// 😎 GET  ALL  APPROACHES 😎


// RECURSION

class Solution{
    public:
    
    int maxi=0;
    int help(string& s1,string& s2,int i,int j)
    {
        //base case
        if(i<0 or j<0)
        return 0;
        
        //recursive calls
        //small calculation
        
        int take=0;
        if(s1[i]==s2[j])
        {
            take=1+help(s1,s2,i-1,j-1);
            maxi=max(take,maxi);
        }
        
        help(s1,s2,i-1,j);
        help(s1,s2,i,j-1);
        
        return take;
    }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int a=help(S1,S2,n-1,m-1);
        return maxi;
    }
};
 

// MEMOIZATION

class Solution{
    public:
    
    int maxi=0;
    int help(string& s1,string& s2,int i,int j,vector<vector<int>>& memo)
    {
        //base case
        if(i<0 or j<0)
        return 0;
        
        //memo check - is ans already calculated
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        //recursive calls
        //small calculation
        
        int take=0;
        if(s1[i]==s2[j])
        {
            take=1+help(s1,s2,i-1,j-1,memo);
            maxi=max(take,maxi);
        }
        
        help(s1,s2,i-1,j,memo);
        help(s1,s2,i,j-1,memo);
        
        memo[i][j]=take;
        return take;
    }
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>> memo(n+1,vector<int>(m+1,-1));
        int a=help(S1,S2,n-1,m-1,memo);
        return maxi;
    }
};
 

// TABULATION

class Solution{
    public:

    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int maxi=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int take=0;
                if(S1[i-1]==S2[j-1])
                {
                    take=1+dp[i-1][j-1];
                    maxi=max(take,maxi);
                    dp[i][j]=take;
                }
                else
                dp[i][j]=0;
            }
        }
        
        return maxi;
    }
};
 

// SPACE OPTIMIZED

class Solution{
    public:

    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<int> pre(m+1,0);
        int maxi=0;
        
        for(int i=1;i<=n;i++)
        {
            vector<int> curr(m+1,0);
            for(int j=1;j<=m;j++)
            {
                int take=0;
                if(S1[i-1]==S2[j-1])
                {
                    take=1+pre[j-1];
                    maxi=max(take,maxi);
                    curr[j]=take;
                }
                else
                curr[j]=0;
            }
            pre=curr;
        }
        
        return maxi;
    }
};