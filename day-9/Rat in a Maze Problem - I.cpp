class Solution{
    public:
    
    void solve(vector<vector<int>>& mat,int n,int i,int j,vector<string>& ans,string s)
    {
        //base case
        
        if(i==n-1 and j==n-1)
        {
            ans.push_back(s);
            return ;
        }
        
        //recursive calls
        //small calculation
        
        if(i<0 or i>=n or j<0 or j>=n or mat[i][j]==0)
        return ;
        
        //up
        mat[i][j]=0;
        solve(mat,n,i-1,j,ans,s+'U');
        //right
        solve(mat,n,i,j+1,ans,s+'R');
        //down
        solve(mat,n,i+1,j,ans,s+'D');
        //left
        solve(mat,n,i,j-1,ans,s+'L');
        mat[i][j]=1;
        return ;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        if(m[n-1][n-1]==0)
        return {};
        
        vector<string> ans;
        string s="";
        solve(m,n,0,0,ans,s);

        
        return ans;
    }
};