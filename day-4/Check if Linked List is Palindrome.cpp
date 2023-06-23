
class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        int left_num=0;
        int right_num=0;
        int i=1;
        
        Node* temp=head;
        while(temp!=NULL)
        {
            left_num*=10;
            left_num+=temp->data;
            
            right_num+=(temp->data)*i;
            i*=10;
            
            temp=temp->next;
        }
        
        if(left_num==right_num)
        return true;
        else
        return false;
        
        
        // int size=0;
        // Node* temp=head;
        // stack<Node*> st;
        // while(temp!=NULL)
        // {
        //     st.push(temp);
        //     temp=temp->next;
        // }
        
        // temp=head;
        // while(!st.empty())
        // {
        //     if(st.top()->data!=temp->data)
        //     return 0;
            
        //     st.pop();
        //     temp=temp->next;
        // }
        
        // return true;
    }
};
