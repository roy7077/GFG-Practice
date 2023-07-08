class Solution{
public:
	bool checkTriplet(int arr[], int n) {
	    
	    sort(arr,arr+n);
	    
	    for(int i=n-1;i>=0;i--)
	    {
	        int left=0;
	        int right=i-1;
	        
	        while(left<right)
	        {
	            if(((arr[left]*arr[left])+(arr[right]*arr[right]))==(arr[i]*arr[i]))
	            return true;
	            else if(((arr[left]*arr[left])+(arr[right]*arr[right]))<(arr[i]*arr[i]))
	            left++;
	            else
	            right--;
	        }
	    }
	    
	    return false;
	}
};