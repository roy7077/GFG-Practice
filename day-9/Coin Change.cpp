#define ll long long
class Solution {
  public:
  
    ll help(int* coins,int i,int sum,vector<vector<ll>>& memo)
    {
        //base case
        
        if(i==0)
        {
            if(sum%coins[0]==0)
            return 1;
            else
            return 0;
        }
        if(sum<0)
        return 0;
        
        if(sum==0)
        return 1;
        
        //memo check
        if(memo[i][sum]!=-1)
        return memo[i][sum];
        
        //recursive calls
        //small calculation
        
        ll a,b;
        a=b=0;
        if(coins[i]<=sum)
        a=help(coins,i,sum-coins[i],memo);
    
        b=help(coins,i-1,sum,memo);
        
        return memo[i][sum]=a+b;
    }
    long long int count(int coins[], int N, int sum) {
        
        vector<vector<ll>> memo(N,vector<ll>(sum+1,-1));
        return help(coins,N-1,sum,memo);
    }
};