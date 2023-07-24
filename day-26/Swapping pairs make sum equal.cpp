class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        int sum1=0;
        int sum2=0;
        
        for(int i=0;i<n;i++)
        sum1+=A[i];
        
        for(int i=0;i<m;i++)
        sum2+=B[i];
        
        if(sum1==sum2)
        return 1;
        
        sort(A,A+n);
        sort(B,B+m);
        int i=0;
        int j=0;
        
        while(i<n and j<m)
        {
            int val1=sum1-A[i]+B[j];
            int val2=sum2-B[j]+A[i];
            
            if(val1==val2)
            return 1;
            
            if(val1>val2)
            i++;
            else
            j++;
        }
        
        return -1;
	}

};