class Solution{
    public:
    vector<vector<int> > fourSum(vector<int> &arr, int K) {
        
        int n=arr.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(arrbegin(),arr.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int l=j+1;
                int r=n-1;
                
                while(l<r)
                {
                    if((arr[i]+arr[j]+arr[l]+arr[r])==K)
                    {
                        st.insert({arr[i],arr[j],arr[l],arr[r]});
                        l++;
                        r--;
                    }
                    else if((arr[i]+arr[j]+arr[l]+arr[r])<K)
                    l++;
                    else
                    r--;
                }
            }
        }
        
        for(auto it:st)
        ans.push_back(it);
        
        return ans;
    }
};