
// GET  ALL  FOUR  WAYS


/*---------RECURSION------------*/

class Solution{
    public:
    
    int helper(int* coins,int i,int V)
    {
        //base case
        if(i==0)
        {
            if(V%coins[0]==0)
            return V/coins[0];
            else
            return 1e9;
        }
        
        if(V<0)
        return 1e9;
        else if(V==0)
        return 0;
        
        //recursive calls
        //small calculations
        
        int a,b;
        a=b=1e9;
        
        a=helper(coins,i-1,V);
        b=1+helper(coins,i,V-coins[i]);
        
        return min(a,b);
    }
    int minCoins(int coins[], int M, int V) 
    { 
        int ans=helper(coins,M-1,V);
        if(ans>=1e9)
        return -1;
        else
        return ans;
    } 
      
};

/*-----------MEMOIZATION----------------*/

class Solution{
    public:
    
    int helper(int* coins,int i,int V,vector<vector<int>>& memo)
    {
        //base case
        if(i==0)
        {
            if(V%coins[0]==0)
            return V/coins[0];
            else
            return 1e9;
        }
        
        if(V<0)
        return 1e9;
        else if(V==0)
        return 0;
        
        //memo check
        if(memo[i][V]!=-1)
        return memo[i][V];
        
        //recursive calls
        //small calculations
        
        int a,b;
        a=b=1e9;
        
        a=helper(coins,i-1,V,memo);
        b=1+helper(coins,i,V-coins[i],memo);
        
        return memo[i][V]=min(a,b);
    }
    int minCoins(int coins[], int M, int V) 
    { 
        vector<vector<int>> memo(M+1,vector<int>(V+1,-1));
        int ans=helper(coins,M-1,V,memo);
        if(ans>=1e9)
        return -1;
        else
        return ans;
    } 
      
};

/*--------------------TABULATION------------------*/

class Solution{
    public:
    
    int minCoins(int coins[], int M, int V) 
    { 
        vector<vector<int>> dp(M,vector<int>(V+1,1e9));
        for(int i=0;i<=V;i++)
        {
            if(i%coins[0]==0)
            dp[0][i]=i/coins[0];
        }
        
        for(int i=1;i<M;i++)
        {
            for(int j=0;j<=V;j++)
            {
                int a,b;
                a=b=1e9;
                
                a=dp[i-1][j];
                
                if(j-coins[i]>=0)
                b=1+dp[i][j-coins[i]];
                
                dp[i][j]=min(a,b);
            }
        }
        
        return dp[M-1][V]==1e9? -1 : dp[M-1][V];
        
    } 
      
};



/*-----------------SPACE OPTIMIZED-----------------*/


class Solution{
    public:
    
    int minCoins(int coins[], int M, int V) 
    { 
        vector<int> pre(V+1,1e9);
        for(int i=0;i<=V;i++)
        {
            if(i%coins[0]==0)
            pre[i]=i/coins[0];
        }
        
        for(int i=1;i<M;i++)
        {
            vector<int> curr(V+1,1e9);
            for(int j=0;j<=V;j++)
            {
                int a,b;
                a=b=1e9;
                
                a=pre[j];
                
                if(j-coins[i]>=0)
                b=1+curr[j-coins[i]];
                
                curr[j]=min(a,b);
            }
            pre=curr;
        }
        
        return pre[V]==1e9? -1 : pre[V];
        
    } 
      
};