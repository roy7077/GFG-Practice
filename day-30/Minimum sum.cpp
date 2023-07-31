class Solution
{   
    public:
    string solve(int arr[], int n) {
        
        sort(arr,arr+n);
        string s1="";
        string s2="";
        bool flag=1;
        
        for(int i=0;i<n;i++)
        {
            if(flag)
            s1+=char(arr[i]+48);
            else
            s2+=char(arr[i]+48);
            
            flag=(!flag);
        }
        
        string ans="";
        int c=0;
        int i=s1.size()-1;
        int j=s2.size()-1;
        
        
        while(i>=0 and j>=0)
        {
            int num1=s1[i]-'0';
            int num2=s2[j]-'0';
            
            int sum=num1+num2+c;
            ans+=char((sum%10)+48);
            c=sum/10;
            i--;
            j--;
        }
        
        while(i>=0)
        {
        
            int sum=(s1[i]-'0')+c;
            ans+=char((sum%10)+48);
            c=sum/10;
            i--;
        }
        
        while(j>=0)
        {
            int sum=(s2[j]-'0')+c;
            ans+=char((sum%10)+48);
            c=sum/10;
            j--;
        }
        
        if(c)
        ans+=char(c+48);
        
        reverse(ans.begin(),ans.end());
        
        for(int i=0;i<ans.length();i++)
        {
            if(ans[i]!='0')
            return ans.substr(i);
        }
        
        return "0";
    }
};
