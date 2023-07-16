class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        int ans=0;
        sort(arr,arr+n,greater<int> ());
        for(int i=0;i<n-2;i++)
        {
            int largerSide = arr[i];
            int l=i+1,r=n-1;
            while(l<r)
            {
                if(arr[l]+arr[r]>largerSide)
                {
                    ans+=r-l;
                    l++;
                }
                else
                    r--;
            }
        }
        return ans;
    }
};
