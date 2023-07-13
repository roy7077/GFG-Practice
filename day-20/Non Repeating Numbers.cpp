class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        map<int,int> mp;
        for(auto it:nums)
        mp[it]++;
        
        int a,b;
        a=b=-1;
        
        for(auto it:mp)
        {
            if(it.second==1)
            {
                if(a==-1)
                a=it.first;
                else
                {
                    b=it.first;
                    return {a,b};
                }
            }
        }
    }
};