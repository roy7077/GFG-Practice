class Solution{
public:
    vector<int> findTwoElement(vector<int> a, int n) {
        
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int value = abs(a[i]);
            int element = a[value-1];
            if(element > 0) 
            a[value-1] = -element;
            else 
            ans.push_back(value);
        }
        
        for(int i=0;i<n;i++)
        {
            if(a[i]>=0)
            {
                ans.push_back(i+1);
                return ans;
            }
        }
        
        
        // map<int,int> mp;
        // vector<int> ans;
        // for(auto it:arr)
        // {
        //     mp[it]++;
        //     if(mp[it]>=2)
        //     ans.push_back(it);
        // }
        
        // for(int i=1;i<=n;i++)
        // {
        //     if(mp.count(i)==0)
        //     {
        //         ans.push_back(i);
        //         return ans;
        //     }
        // }
    }
};

// Time Complexity: O(N)
// Auxiliary Space: O(1)
