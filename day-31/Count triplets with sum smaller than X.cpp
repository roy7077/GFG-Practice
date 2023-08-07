#define ll long long
class Solution{
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr,arr+n);
	    ll cnt=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        ll l=i+1;
	        ll r=n-1;
	        
	        while(l<r)
	        {
	            if(arr[i]+arr[l]+arr[r]<sum)
	            {
	                cnt+=(r-l);
                    l++;
	            }
	            else 
	            r--;
	        }
	    }
	    
	    return cnt;
	}
};
