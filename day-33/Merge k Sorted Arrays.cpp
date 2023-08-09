// BOTH WAYS OF SOLVING THIS PROBLEM

// SIMPLE METHOD | T - O(N*k*log(N*K))

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        for(auto it:arr)
        {
            for(auto x:it)
            ans.push_back(x);
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
 

// EFFICIENT SOLUTION | T - O(N*K*logK)

class Solution
{
    public:
    //Function to merge k sorted arrays.
    typedef pair<int,pair<int,int>> triplet;
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<triplet, vector<triplet>, greater<triplet> > pq;
        for(int i=0;i<K;i++)
        pq.push({arr[i][0],{i,0}});
        
        vector<int> ans;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            
            int elmnt=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            ans.push_back(elmnt);
            
            if(c+1<K)
            pq.push({arr[r][c+1],{r,c+1}});
        }
        
        return ans;
    }
};