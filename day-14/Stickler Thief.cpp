
// GET  ALL  FOUR  APPROACHES
 

/*------------RECURSION-----------------*/

class Solution
{
    public:
    
    int helper(int* arr,int i)
    {
        //base case
        if(i<0)
        return 0;
        
        if(i==0)
        return arr[0];
        
        //recursive calls
        int a,b;
        a=b=0;
        
        //take and not-take
        a=helper(arr,i-1);
        b=arr[i]+helper(arr,i-2);
        
        return max(a,b);
    }
    int FindMaxSum(int arr[], int n)
    {
        return helper(arr,n-1);
    }
};

// Time   complexity - O(2^n)
// space complexity - O(n)

/*-----------------------MEMOIZATION---------------------*/

class Solution
{
    public:
    
    int helper(int* arr,int i,vector<int>& memo)
    {
        //base case
        if(i<0)
        return 0;
        
        if(i==0)
        return arr[0];
        
        //memo check
        if(memo[i]!=-1)
        return memo[i];
        
        //recursive calls
        int a,b;
        a=b=0;
        
        //take and not-take
        a=helper(arr,i-1,memo);
        b=arr[i]+helper(arr,i-2,memo);
        
        return memo[i]=max(a,b);
    }
    
    int FindMaxSum(int arr[], int n)
    {
        vector<int> memo(n+1,-1);
        return helper(arr,n-1,memo);
    }
};

// Time   complexity - O(n)
// space complexity - O(n+n)

/*------------------TABULATION---------------------*/

class Solution
{
    public:
    int FindMaxSum(int arr[], int n)
    {
        vector<int> memo(n+1,0);
        memo[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            int a,b;
            a=b=0;
            
            a=memo[i-1];
            b=arr[i];
            if(i-2>=0)
            b+=memo[i-2];
            
            memo[i]=max(a,b);
        }
        
        return memo[n-1];
    }
};

// Time   complexity - O(n)
// space complexity - O(n)

/*---------------------SPACE OPTIMIZED--------------------*/

class Solution
{
    public:
    int FindMaxSum(int arr[], int n)
    {
        int first=0;
        int second=arr[0];
        
        for(int i=1;i<n;i++)
        {
            int a,b;
            a=b=0;
            
            a=second;
            b=arr[i];
            if(i-2>=0)
            b+=first;
            
            first=second;
            second=max(a,b);
        }
        
        return second;
    }
};

// Time   complexity - O(n)
// space complexity - O(1)

