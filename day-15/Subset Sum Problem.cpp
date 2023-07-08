class Solution{   
public:
    
    bool helper(vector<int>& arr,int i,int x,int sum,vector<vector<int>>& memo)
    {
        //base case
        if(i>=arr.size())
        {
            if(x==sum)
            return true;
            else
            return false;
        }
        
        if(x>sum)
        return false;
        
        //memo check
        if(memo[i][x]!=-1)
        return memo[i][x];
        
        //recursive calls
        //small calculation
        
        bool a=helper(arr,i+1,x,sum,memo);
        bool b=helper(arr,i+1,x+arr[i],sum,memo);
        
        return memo[i][x]=(a or b);
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        
        vector<vector<int>> memo(arr.size()+1,vector<int>(sum+1,-1));
        return helper(arr,0,0,sum,memo);
    }
};
