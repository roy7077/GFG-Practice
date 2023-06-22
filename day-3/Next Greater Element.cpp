#define ll long long
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> v, int n){
        
        
        vector<ll> ans(n);
        stack<ll> st;
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and v[i]>=st.top())
            st.pop();
            
            if(st.empty())
            ans[i]=-1;
            else
            ans[i]=st.top();
            
            st.push(v[i]);
        }
        
        return ans;
        // long long maxi=0;
        // vector<long long> ans(n);
        // for(int i=n-1;i>=0;i--)
        // {
        //     if(v[i]>=maxi)
        //     ans[i]=-1;
        //     else
        //     {
        //         for(int j=i+1;j<n;j++)
        //         {
        //             if(v[j]>v[i])
        //             {
        //                 ans[i]=v[j];
        //                 break;
        //             }
        //         }
        //     }
            
        //     maxi=max(maxi,v[i]);
        // }
        
        // return ans;
    }
};

// Time Complexity : O(N)
// Auxiliary Space : O(N)
