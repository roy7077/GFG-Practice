#define ll long long
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        
        int maxi=1e9;
        ll ans=0;
        int left_max=0;
        vector<ll> height(n,0);
        
        //storing maximum from left to right
        for(int i=0;i<n;i++)
        {
            height[i]=max(arr[i],left_max);
            left_max=max(arr[i],left_max);
        }
        
        //storing maximum from right to left in the same array
        int right_max=0;
        for(int i=n-1;i>=0;i--)
        {
            ll temp=max(arr[i],right_max);
            height[i]=(temp*maxi)+height[i];
            right_max=temp;
        }
        
        
        for(int i=0;i<n;i++)
        {
            if(i!=0 and i!=n-1)
            {
                ll temp=min(height[i-1]%maxi,height[i+1]/maxi)-arr[i];
                if(temp>0)
                ans+=temp;
            }
            
        }
        
        return ans;
    }
};