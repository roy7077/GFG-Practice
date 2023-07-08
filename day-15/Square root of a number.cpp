#define ll long long
class Solution{
  public:
  
    void helper(ll x,ll left,ll right,ll& ans)
    {
        //base case
        if(left>right)
        return ;
        
        //recursive calls
        //small calculation
        
        ll mid=(left+right)/2;
        if(mid*mid==x)
        {
            ans=mid;
            return ;
        }
        else if(mid*mid>x)
        helper(x,left,mid-1,ans);
        else
        {
            ans=mid;
            helper(x,mid+1,right,ans);
        }
    }
    long long int floorSqrt(long long int x) 
    {
        ll ans;
        helper(x,0,x,ans);
        
        return ans;
    }
};