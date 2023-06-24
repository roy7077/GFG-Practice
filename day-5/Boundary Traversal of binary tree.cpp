class Solution {
public:


    void left_part(Node* root,vector<int>& ans)
    {
        if(root==NULL or (root->left==NULL and root->right==NULL))
        return ;
        
        ans.push_back(root->data);
        if(root->left)
        left_part(root->left,ans);
        else
        left_part(root->right,ans);
    }
    
    void leaf_part(Node* root,vector<int>& ans)
    {
        if(root==NULL)
        return ;
        
        if(root->left==NULL and root->right==NULL)
        {
            ans.push_back(root->data);
            return ;
        }
        
        leaf_part(root->left,ans);
        leaf_part(root->right,ans);
    }
    
    void right_part(Node* root,vector<int>& ans)
    {
        if(root==NULL or (root->left==NULL and root->right==NULL))
        return ;
        
        if(root->right)
        right_part(root->right,ans);
        else
        right_part(root->left,ans);
        
        ans.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root==NULL)
        return ans;
        
        ans.push_back(root->data);
        
        //left part
        left_part(root->left,ans);
        
        //leaf part
        leaf_part(root->left,ans);
        leaf_part(root->right,ans);
        
        //right part
        right_part(root->right,ans);
        
        return ans;
    }
};