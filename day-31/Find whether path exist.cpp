class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(n,0));
        
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    visited[i][j]=2;
                    q.push({i,j});
                }
                else if(grid[i][j]==0)
                visited[i][j]=-1;
            }
        }
        
        int x[]={1,-1,0,0};
        int y[]={0,0,1,-1};
        
        while(!q.empty())
        {
            auto it=q.front();
            int i=it.first;
            int j=it.second;
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int delr=i+x[k];
                int delc=j+y[k];
                
                if(delr>=0 and delr<n and delc>=0 and delc<m and visited[delr][delc]==0)
                {
                    visited[delr][delc]=1;
                    q.push({delr,delc});
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    if(visited[i][j]==0)
                    return 0;
                }
            }
        }
        
        return 1;
    }
};
