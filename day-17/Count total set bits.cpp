class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
   {   
       if((n&(n-1)) == 0){
       		//if n is power of 2 directly return result
           return 1+ log2(n)*(n/2);
       }else{
           // y is 2th power  before n
           int y = pow(2,(int)log2(n));
           return (n-y) + countSetBits(y)+ countSetBits(n-y);
       }
   }
};
