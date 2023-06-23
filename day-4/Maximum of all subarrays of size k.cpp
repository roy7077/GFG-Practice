
class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int K)
    {
       vector<int> ans;
       priority_queue<pair<int,int>> pq;
       for(int i=0;i<K;i++)
       pq.push({arr[i],i});
       
       int i=0;
       int j=K-1;
       while(j<n)
       {
           while(!pq.empty() and pq.top().second<i)
           pq.pop();
           
           pq.push({arr[j],j});
           ans.push_back(pq.top().first);
           j++;
           i++;
       }
       
       return ans;
    }
};
