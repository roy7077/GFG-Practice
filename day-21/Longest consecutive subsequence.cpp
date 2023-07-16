class Solution{
  public:
    int findLongestConseqSubseq(int arr[], int N)
    {
      sort(arr,arr+N);
      int ans=1;
      int cnt=1;
      
      int i=0;
      int j=1;
      
      while(j<N)
      {
        if(arr[i]==arr[j])
        {
            j++;
            continue;
        }
        
        if(arr[j]-1==arr[i])
        {
            cnt++;
            j++;
            i++;
        }
        else
        {
            i=j;
            j++;
            ans=max(ans,cnt);
            cnt=1;
        }
      }
      
      ans=max(ans,cnt);
      return ans;
    }
};