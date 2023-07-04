class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        
        int num=0;
        bool flag=0;
        for(int i=0;i<str.length();i++)
        {
            char it=str[i];
            
            //if given num has to be negative
            if(i==0)
            {
                if(it=='-')
                {
                    flag=1;
                    continue;
                }
            }
            
            //current character should be in range of 48 to 57
            if(int(it)>=48 and int(it)<=57)
            {
                int temp=num;
                if(num<0)
                num*=-1;
                
                num*=10;
                if(flag)
                {
                    num+=it-'0';
                    num*=-1;
                    flag=0;
                }
                else
                num+=it-'0';
                
                if(temp<0)
                num*=-1;
            }
            else
            return -1;
        }
        
        return num;
    }
};