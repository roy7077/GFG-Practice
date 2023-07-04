

/*-----------------Recursion------------------------*/

class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    
    int helper(int n)
    {
        //base case
        if(n==0)
        return 1;
        
        if(n<0)
        return 0;
        
        //recursive calls and small calculation
        int a,b;
        a=b=0;
        
        if(n-2>=0)
        a=helper(n-2);
        
        if(n-1>=0)
        b=helper(n-1);
        
        return a+b;
    }
    int countWays(int n)
    {
        return helper(n);
    }
};

// Time Complexity -  O(2^N)
// Space Complexity - O(N)

/*----------memoization-----------*/
#define ll long long
int mod=1e9+7;
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    
    ll helper(int n,vector<ll>& memo)
    {
        //base case
        if(n==0)
        return 1;
        
        if(n<0)
        return 0;
        
        //memo check
        if(memo[n]!=-1)
        return memo[n];
        
        //recursive calls 
        ll a,b;
        a=b=0;
        
        if(n-2>=0)
        a=helper(n-2,memo);
        
        if(n-1>=0)
        b=helper(n-1,memo);
        
        //small calculation
        return memo[n]=(a+b)%mod;
    }
    int countWays(int n)
    {
        vector<ll> memo(n+1,-1);
        return helper(n,memo);
    }
};

// Time Complexity -  O(N)
// Space Complexity - O(N)


/*----------Tabulation--------------------*/

#define ll long long
int mod=1e9+7;
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<=n;i++)
        {
            ll a=dp[i-2];
            ll b=dp[i-1];
            
            dp[i]=(a+b)%mod;
        }
        
        return dp[n];
    }
};

 

// Time Complexity -  O(N)
// Space Complexity - O(N)



/*------------------Space optimized-------------*/

#define ll long long
int mod=1e9+7;
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        if(n==0)
        return 0;
        else if(n==1)
        return 1;
        
        ll first=1;
        ll second=2;
        
        for(int i=3;i<=n;i++)
        {
            ll ans=(first+second)%mod;
            first=second;
            second=ans;
        }
        
        return second;
    }
};


// Time Complexity -  O(N)
// Space Complexity - O(1)

