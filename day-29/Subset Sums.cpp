class Solution
{
    public:
    void subsequence(vector<int>& v,vector<int>& ans)
    {
        for(int i=0;i<(1<<v.size());i++)
        {
            int sum=0;
            for(int j=0;j<v.size();j++)
            {
                if(i&(1<<j))
                sum+=v[j];
            }
            ans.push_back(sum);
        }
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        subsequence(arr,ans);
        return ans;
    }
};
