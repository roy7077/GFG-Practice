class Solution
{
   public:
   bool solve(unordered_set<string>&set,string s)
   {
       int n=s.size();
       if(n==0)
       return 1;
           
       for(int i=1;i<=n;i++)
       {
           string temp=s.substr(0,i);
           if(set.find(temp)!=set.end())
           {
               if(solve(set,s.substr(i)))
               return 1;
           }
       }
       return 0;
   }

   int wordBreak(string A, vector<string> &B) 
   {
      unordered_set<string>s;
      for(int i=0;i<B.size();i++)
      {
          s.insert(B[i]);
      }
      
      return solve(s,A)==1;
      
   }
};