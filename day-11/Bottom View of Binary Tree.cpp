class Solution {
  public:
  
    
    vector <int> bottomView(Node *root) {
        
        vector<int> ans;
        map<int,int> mp;
        queue<pair<int,Node*>> q;
        q.push({0,root});
        while(!q.empty())
        {
            int x = q.front().first;
            Node* it = q.front().second;
            q.pop();
            mp[x] = it->data;
            if(it->left){
                q.push({x-1,it->left});
            }
            if(it->right){
                q.push({x+1,it->right});
            }
        }
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
