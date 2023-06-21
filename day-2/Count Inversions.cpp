class Solution{
public:
    
    long long merge(long long* nums, int low,int mid,int high)
    {
        long long inv_count=0, k=0;
        int l = low, r = mid+1, size = high-low+1;
        vector<long long>sorted;
        while(l <= mid and r <= high)
        {
            if(nums[l] <= nums[r]){
                sorted.push_back(nums[l++]);
            }
            else
            {
                sorted.push_back(nums[r++]);
                inv_count = inv_count + (mid-l+1); // only these changes
            }
        }
    
        while(l <= mid)
            sorted.push_back(nums[l++]);
    
        while(r <= high)
            sorted.push_back(nums[r++]);
    
        for(k = 0 ; k < sorted.size() ; k++)
            nums[k+low] = sorted[k];
        return inv_count;
    }
    
    long long mergeSort(long long* nums,int low,int high)
    {
        long long inv_count = 0;
        if(low >= high) return 0;
        
        long long mid = low + (high-low)/2;
        inv_count += mergeSort(nums,low,mid);
        inv_count += mergeSort(nums,mid+1,high);
        inv_count += merge(nums,low,mid,high);
        return inv_count;
    }
    
    long long int inversionCount(long long arr[], long long n)
    {
        return mergeSort(arr, 0, n-1);   
    }
};

// Time Complexity: O(NLogN).
// Auxiliary Space: O(N).