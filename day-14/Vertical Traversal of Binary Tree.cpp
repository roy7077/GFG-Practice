
class Solution
{
    public:
    vector<int> verticalOrder(Node *root)
    {
        map<int,vector<int>> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(!q.empty())
        {
            auto it=q.front();
            Node* node=it.first;
            int level=it.second;
            q.pop();
            
            mp[level].push_back(node->data);
            
            if(node->left)
            q.push({node->left,level-1});
            
            if(node->right)
            q.push({node->right,level+1});
            
        }
        
        vector<int> ans;
        
        for(auto it:mp)
        {
            for(auto x:it.second)
            ans.push_back(x);
        }
        
        return ans;
        
    }
};

