class Solution{
public:
    
    string rremove(string s)
    {
        string ans;
        int n=s.size(); 
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==s[i+1] || s[i]==s[i-1])
             continue;
            else 
              ans.push_back(s[i]);
        }
        
        if(ans.size()== n)
           return ans;  
           
        return rremove(ans);
    }
};