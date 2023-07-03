class Solution{

    int mod=1e9+7;
	public:
	long long helper(int* arr,int n,int i,int target,vector<vector<long long>>& memo)
	{
	    //base case
	    if(i==n)
	    {
	        if(target==0)
	        return 1;
	        else
	        return 0;
	    }
	    
	   // if(target==0)
	   // return 1;
	    
	    if(target<0)
	    return 0;
	    
	    //memo check
	    if(memo[i][target]!=-1)
	    return memo[i][target];
	    
	    //recursive calls
	    //small calculation
	    
	    long long a,b;
	    a=b=0;
	    
	    //take and not-take
	    b=helper(arr,n,i+1,target-arr[i],memo);
	    a=helper(arr,n,i+1,target,memo);
	    
	    return memo[i][target]=(a+b)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<long long>> memo(n+1,vector<long long>(sum+1,-1));
        return helper(arr,n,0,sum,memo);
	}
	  
};