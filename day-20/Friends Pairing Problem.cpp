
/*__________________GET ALL APPROACHES________________*/

/*--------------RECURSION----------------*/

#define ll long long
class Solution
{
    public:
    
    int mod=1000000007;
    
    ll recursion(int i)
    {
        //base case
        if(i==1 or i==2)
        return i;
        
        //recursive calls
        ll a=recursion(i-1)%mod;
        ll b=((i-1)*(recursion(i-2)%mod))%mod;
        
        return (a+b)%mod;
    }
    int countFriendsPairings(int n) 
    { 
        return recursion(n);
    }
};    
/*-------------MEMOIZATION-------------------*/

#define ll long long
class Solution
{
    public:
    
    int mod=1000000007;
    
    ll memoization(int i,vector<ll>& memo)
    {
        //base case
        if(i==1 or i==2)
        return i;
        
        //memo check
        if(memo[i]!=-1)
        return memo[i];
        
        //recursive calls
        ll a=memoization(i-1,memo)%mod;
        ll b=((i-1)*(memoization(i-2,memo)%mod))%mod;
        
        return memo[i]=(a+b)%mod;
    }
    int countFriendsPairings(int n) 
    { 
        vector<ll> memo(n+1,-1); 
        return memoization(n,memo);
    }
};    
 
/*-----------------TABULATION--------------------*/

#define ll long long
class Solution
{
    public:
    
    int mod=1000000007;

    int countFriendsPairings(int n) 
    { 
        vector<ll> dp(n+1,0);
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<=n;i++)
        {
            ll a=dp[i-1]%mod;
            ll b=((i-1)*(dp[i-2]%mod))%mod;
            dp[i]=(a+b)%mod;
        }
        
        return dp[n];
    }
};    
/*-------------------SPACE OPTIMIZED--------------------*/

#define ll long long
class Solution
{
    public:
    
    int mod=1000000007;

    int countFriendsPairings(int n) 
    { 
        ll first=1;
        ll second=2;
        
        if(n==1)
        return 1;
        
        for(int i=3;i<=n;i++)
        {
            ll a=second%mod;
            ll b=((i-1)*(first%mod))%mod;
            
            first=second;
            second=(a+b)%mod;
        }
        
        return second;
    }
};    