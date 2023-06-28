/**
 * case-1 - each set of number is between 0 - 255
 * case-2 - there should not be any leading zeros
 * case-3 - there should not be character which does not lies in the range of '0' to '9'
 **/
class Solution {
    public:
        int isValid(string s) {
            
            int cnt=0;
            int num=0;
            int zero=0;
            int number=0;
            
            for(auto it:s)
            {
                if(it!='.')
                {
                    //if current character is not in the range of '0' to '9'
                    if(it<'0' or it>'9')
                    return 0;
                    
                    if(num==0 and it=='0')
                    zero++;
                    
                    num*=10;
                    num+=(it-'0');
                    number++;
                    
                }
                else
                {
                    
                    if(number>0 and zero>0 and number!=zero)
                    return 0;
                    
                    if(num<0 or num>255 or zero>1 or number==0)
                    return 0;
                    
                    number=0;
                    zero=0;
                    num=0;
                    cnt++;
                }
            }
            if(number>0 and zero>0 and number!=zero)
            return 0;
                    
            if(num<0 or num>255 or zero>1 or number==0)
            return 0;
                    
            if(num<0 or num>255)
            return 0;
            
            if(cnt==3)
            return 1;
            else
            return 0;
        }
};
