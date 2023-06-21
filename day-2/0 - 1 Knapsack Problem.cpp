class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int helper(int* wt,int* val,int w,int i,vector<vector<int>>& memo)
    {
        //base case
        if(i<0)
        return 0;
        
        //memo check
        if(memo[i][w]!=-1)
        return memo[i][w];
        
        if(i==0)
        {
            if(wt[0]<=w)
            return val[0];
            else
            return 0;
        }
        
        //recursive calls
        //small calculation
        
        int a=0;
        int b=0;
        
        if(w>=wt[i])
        a=val[i]+helper(wt,val,w-wt[i],i-1,memo);
        b=helper(wt,val,w,i-1,memo);
        
        return memo[i][w]=max(a,b);
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        
       vector<vector<int>> memo(n+1,vector<int>(W+1,-1));
       return helper(wt,val,W,n-1,memo);
    }
};