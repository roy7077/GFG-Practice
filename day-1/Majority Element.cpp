class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    
    /*---------Moore's Voting  Algorithm-----------*/
    int majorityElement(int a[], int size)
    {
        
        int cnt=1;
        int index=0;
        for(int i=1;i<size;i++)
        {
            if(a[index]==a[i])
            cnt++;
            else
            cnt--;
            
            if(cnt==0)
            {
                index=i;
                cnt=1;
            }
        }
        
        cnt=0;
        for(int i=0;i<size;i++)
        {
            if(a[i]==a[index])
            cnt++;
        }
        
        if(cnt>size/2)
        return a[index];
        else
        return -1;
    }
};

// Time Complexity: O(N).
// Auxiliary Space: O(1).