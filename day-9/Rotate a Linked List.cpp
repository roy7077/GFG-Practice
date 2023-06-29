class Solution
{
    public:
    //Function to rotate a linked list.
    
    pair<Node*,int> length(Node* head)
    {
        int len=0;
        Node* pre=NULL;
        while(head!=NULL)
        {
            len++;
            pre=head;
            head=head->next;
        }
        
        return {pre,len};
    }
    
    Node* rotate(Node* head, int k)
    {
        pair<Node*,int> p=length(head);
        if(p.second==k)
        return head;
        
        Node* temp=head;
        Node* pre=NULL;
        while(k--)
        {
            pre=temp;
            temp=temp->next;
        }
        
        p.first->next=head;
        pre->next=NULL;
        return temp;
        
    }
};