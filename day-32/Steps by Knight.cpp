class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&S,vector<int>&E,int N)
	{
	    int n=N;
	    int m=N;
	    
	    vector<vector<int>> visited(n+1,vector<int>(n+1,0));
	    queue<pair<int,pair<int,int>>> q;
	    
	    q.push({0,{S[0],S[1]}});
	    int delrow[8]={1,1,-1,-1,2,2,-2,-2};
        int delcol[8]={2,-2,2,-2,1,-1,1,-1};
        
	    while(!q.empty())
	    {
	        auto it=q.front();
	        int x=it.second.first;
	        int y=it.second.second;
	        int s=it.first;
	        q.pop();
	        
	        if(x==E[0] and y==E[1])
	        return s;
	        
	        for(int i=0;i<8;i++)
	        {
	            int delr=x+delrow[i];
	            int delc=y+delcol[i];
	            
	            if(delr>=1 and delr<=n and delc>=1 and delc<=m and visited[delr][delc]==0)
	            {
	                q.push({s+1,{delr,delc}});
	                visited[delr][delc]=1;
	            }
	        }
	    }
	    
	    return -1;
	}
};
