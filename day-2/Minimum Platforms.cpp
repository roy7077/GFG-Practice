class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	int visited[50002]={0};
    	
    	for(int i=0;i<n;i++)
    	{
    	    visited[arr[i]]++;
    	    visited[dep[i]+1]--;
    	}
    	
    	int maxi=0;
    	for(int i=1;i<50002;i++)
    	{
    	    visited[i]+=visited[i-1];
    	    maxi=max(visited[i],maxi);
    	}
    	
    	return maxi;
    }
};

// Time Complexity: O(n)
// Auxiliary Space: O(n)

