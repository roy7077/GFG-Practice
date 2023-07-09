class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int i=l;
        int j=m+1;
        vector<int> temp(r-l+1);
        int k=0;
        
        while(i<=m and j<=r)
        {
            if(arr[i]<arr[j])
            {
                temp[k]=arr[i];
                k++;
                i++;
            }
            else
            {
                temp[k]=arr[j];
                k++;
                j++;
            }
        }
        
        while(i<=m)
        {
            temp[k]=arr[i];
            k++;
            i++;
        }
        
        while(j<=r)
        {
            temp[k]=arr[j];
            k++;
            j++;
        }
        
        k=l;
        for(auto it:temp)
        {
            arr[k]=it;
            k++;
        }
    }
    
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r)
        return ;
        
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};