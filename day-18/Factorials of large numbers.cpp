class Solution {
public:
    vector<int> factorial(int N)
    {
        
        vector<int> ans;
        ans.push_back(1);
        
        for(int i=2;i<=N;i++)
        {
            int car=0;
            for(int j=ans.size()-1;j>=0;j--)
            {
                int value=ans[j]*i+car;
                ans[j]=value%10;
                car=value/10;
            }
            
            while(car)
            {
                ans.insert(ans.begin(),car%10);
                car/=10;
            }
        }
        
        return ans;
    }
};