class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
    	int maxi=1e9;
    	int i=0;
    	int j=n-1;
    	int k=0;
    	
    	bool flag=1;
    	while(k<n)
    	{
    	    if(flag)
    	    {
    	        arr[k]+=(arr[j]%maxi)*maxi;
    	        flag=(!flag);
    	        j--;
    	        k++;
    	    }
    	    else
    	    {
    	        arr[k]+=(arr[i]%maxi)*maxi;
    	        flag=(!flag);
    	        k++;
    	        i++;
    	    }
    	}
    	
    	for(int i=0;i<n;i++)
    	arr[i]/=maxi;
    }
};
