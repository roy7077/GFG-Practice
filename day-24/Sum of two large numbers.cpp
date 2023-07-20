class Solution {
  public:
    string findSum(string X, string Y) {
        
        string ans="";
        int i=X.length()-1;
        int j=Y.length()-1;
        int carry=0;
        
        while(i>=0 and j>=0)
        {
            int num=carry+((X[i]-'0'))+((Y[j]-'0'));
            char last=char((num%10)+48);
            int first=num/10;
            
            ans+=last;
            carry=first;
            i--;
            j--;
        }
        
        while(i>=0)
        {
            int num=carry+((X[i]-'0'));
            char last=char((num%10)+48);
            int first=num/10;
            
            ans+=last;
            carry=first;
            i--;
        }
        
        while(j>=0)
        {
            int num=carry+((Y[j]-'0'));
            char last=char((num%10)+48);
            int first=num/10;
            
            ans+=last;
            carry=first;
            j--;
        }
        
        if(carry)
        ans+=char(carry+48);
        
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.length();i++)
        {
            if(ans[i]!='0')
            return ans.substr(i);
        }
        
        return "0";
    }
};