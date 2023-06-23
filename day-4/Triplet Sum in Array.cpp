class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);
        
        for(int i=0;i<n;i++)
        {
            int left=i+1;
            int right=n-1;
            
            while(left<right)
            {
                if(A[i]+A[left]+A[right]==X)
                return true;
                else if(A[i]+A[left]+A[right]<X)
                left++;
                else
                right--;
            }
        }
        
        return false;
    }

};