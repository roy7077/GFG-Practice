#define ll long long
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        ll sum=0;
        ll maxi=-1e9;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            maxi=max(maxi,sum);
            if(sum<0)
            sum=0;
        }
        
        return maxi;
        
    }
};

// Time Complexity: O(N)
// Auxiliary Space: O(1)