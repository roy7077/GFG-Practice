class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=l;i<=r;i++)
        pq.push(arr[i]);
        
        int ans=-1;
        while(k--)
        {
            ans=pq.top();
            pq.pop();
        }
        
        return ans;
    }
};

// time complexity -  O(n logn)
// space complexity - O(N)
