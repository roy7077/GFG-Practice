class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    
	   int s=0;
	   int e=0;
	   int max=0;
	   
	   int sum=0;
	   int k=0;
	   int i=0;
	   while(i<n)
	   {
	       k=i;
	       while(i<n)
	       {
	           if(a[i]<0)
	           {
	               if(sum>max)
	               {
	                   s=k;
	                   e=i-1;
	                   max=sum;
	                   sum=0;
	               }
	               else if(sum==max and (i-k)>(e-s+1))
	               {
	                   s=k;
	                   e=i-1;
	                   max=sum;
	                   sum=0;
	               }
	               sum=0;
	               break;
	           }
	           else
	           sum+=a[i];
	           
	           i++;
	       }
	       i++;
	   }
	   
	   if(sum>max or (sum==max and (n-k)>(e-s+1)))
	   {
	       s=k;
	       e=n-1;
	   }
	   
	   vector<int> ans;
	   for(int i=s;i<=e;i++)
	   ans.push_back(a[i]);
	   
	   return ans;
	}
};