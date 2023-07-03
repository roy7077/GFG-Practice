class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        map<int,int> mp;
        mp[0]=-1;
        int sum=0;
        int ans=0;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            if(mp.count(sum-k))
            ans=max(i-mp[sum-k],ans);
            
            if(mp.count(sum)==0)
            mp[sum]=i;
        }
        
        return ans;
    } 

};
