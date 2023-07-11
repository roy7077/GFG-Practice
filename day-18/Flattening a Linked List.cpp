void dfs(Node* root,vector<int>& ans)
{
    //base case
    if(root==NULL)
    return ;
    
    ans.push_back(root->data);
    
    //recursive calls
    dfs(root->bottom,ans);
    dfs(root->next,ans);
}

Node *flatten(Node *root)
{
   vector<int> ans;
   dfs(root,ans);
   
   sort(ans.begin(),ans.end());
   for(auto it:ans)
   cout<<it<<" ";
   
   return NULL;
}

