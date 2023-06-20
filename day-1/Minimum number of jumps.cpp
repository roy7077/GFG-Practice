#define ll long long
class Solution{
  public:
  
  /*---------------------DP---------------------*/
    // ll help(int* a,int n,int i,vector<ll>& memo)
    // {
    //     //base case
    //     if(i==n-1)
    //     return 0;
        
    //     if(i>=n)
    //     return 1e9;
        
    //     //memo check
    //     if(memo[i]!=-1)
    //     return memo[i];
        
        
    //     //recursive calls
    //     //small calculation
        
    //     ll mini=1e9;
    //     for(int j=1;j<=a[i];j++)
    //     {
    //         ll ans=1+help(a,n,i+j,memo);
    //         mini=min(mini,ans);
    //     }
    //     return memo[i]=mini;
    // }
    // int minJumps(int arr[], int n)
    // {
        
    //     vector<ll> memo(1000000,-1);
    //     ll ans=help(arr,n,0,memo);
    //     if(ans==1e9)
    //     return -1;
    //     else
    //     return ans;
    // }
    
    int minJumps(int arr[], int n){
        
        // agar pahale hi point pr zero pada ho to bhaiya kaha jaoge. Ruk jao
        if(arr[0] == 0 && n>1) return -1;
        
        if(n == 1) return 0;
        
        // assume kro ki pahale point se apan jump lga diye hai
        int steps = arr[0];
        int maxReach = arr[0];
        int jumps = 1;
        
        for(int i = 1; i<n; i++){
            
            if(i == n-1) return jumps;
            
            // Ab apan agle point par aagye to maxReach nikalo aur store kralo
            if(steps) {
            	maxReach = max(maxReach, arr[i]+i);
            
            	// Ab apan agle point pr aagye hai to ek 			 step kam kardo
            	steps--;
            }
            
            // check kro ki steps khatm to nhi ho gye
            if(steps == 0){
                
                // agar end point tak pahuchne se pahale koi zero mil gya aur usse pahale koi maxReach nhi tha
                if(i>=maxReach) return -1;
                
                // steps khatm hue matlab new point par aagye
                // yha se bhi jump lga do
                // apan jump tabhi lagayenge jab steps khatm ho jayenge
                jumps++;
                
                // steps ko update krlo
                steps = maxReach - i;
            }
        }
        
        return -1;
    }

};