#define ll long long
class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        
        ll cnt=0;
        map<ll,ll> mp;
        
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum==0)
            cnt++;
            
            if(mp.count(sum))
            cnt+=mp[sum];
            
            mp[sum]++;
        }
        
        return cnt;
    }
};
