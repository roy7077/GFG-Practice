class Solution
{
    public:
    pair<bool,int> helper(Node* root)
    {
        if(root->left==NULL and root->right==NULL)
        return {1,root->data};
        
        pair<bool,int> p1={1,0};
        pair<bool,int> p2={1,0};
        
        if(root->left!=NULL)
        {
            p1=helper(root->left);
            if(p1.first==0)
            return {0,0};
        }
        
        if(root->right!=NULL)
        {
            p2=helper(root->right);
            if(p2.first==0)
            return {0,0};
        }
        
        if((p1.second+p2.second)!=root->data)
        return {0,0};
        
        
        return {1,p1.second+p2.second+root->data};
    }
    
    bool isSumTree(Node* root)
    {
        
        if(root==NULL or (root->left==NULL and root->right==NULL))
        return true;
        
        pair<bool,int> ans=helper(root);
        
        return ans.first;
    }
};