class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
	void lower_bound_x(int* arr,int s,int e,int x,int& ind)
	{
	    
	    if(s>e)
	    return ;
	    
	    int mid=(s+e)/2;
	    if(arr[mid]==x)
	    {
	        ind=mid;
	        lower_bound_x(arr,s,mid-1,x,ind);
	    }
	    else if(x<arr[mid])
	    lower_bound_x(arr,s,mid-1,x,ind);
	    else
	    lower_bound_x(arr,mid+1,e,x,ind);
	    
	}
	
	void upper_bound_x(int* arr,int s,int e,int x,int& ind)
	{
	   
	    if(s>e)
	    return ;
	    
	    int mid=(s+e)/2;
	    if(arr[mid]==x)
	    {
	        ind=mid;
	        upper_bound_x(arr,mid+1,e,x,ind);
	    }
	    else if(x<arr[mid])
	    upper_bound_x(arr,s,mid-1,x,ind);
	    else
	    upper_bound_x(arr,mid+1,e,x,ind);
	    
	}
	int count(int arr[], int n, int x) {
	    
	    int lower=-1;
	    int upper=-1;
	    
	    lower_bound_x(arr,0,n-1,x,lower);
	    upper_bound_x(arr,0,n-1,x,upper);
	    
	    if(lower==-1 and upper==-1)
	    return 0;
	    
	    return upper-lower+1;
	}
};
