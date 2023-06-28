class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
    Node* makelinkedlist(vector<int>& v1,vector<int>& v2)
    {
        Node* head=NULL;
        
        int carry=0;
        int i=v1.size()-1;
        int j=v2.size()-1;
        
        while(i>=0 and j>=0)
        {
            int num=v1[i]+v2[j]+carry;
            carry=num/10;
            
            Node* newnode=new Node(num%10);
            newnode->next=head;
            head=newnode;
            i--;
            j--;
        }
        
        while(i>=0)
        {
            int num=v1[i]+carry;
            carry=num/10;
            
            Node* newnode=new Node(num%10);
            newnode->next=head;
            head=newnode;
            i--;
        }
        
        while(j>=0)
        {
            int num=v2[j]+carry;
            carry=num/10;
            
            Node* newnode=new Node(num%10);
            newnode->next=head;
            head=newnode;
            j--;
        }
        
        if(carry!=0)
        {
            Node* newnode=new Node(carry);
            newnode->next=head;
            head=newnode;
        }
        
        return head;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        vector<int> v1;
        vector<int> v2;
        
        Node* h1=first;
        Node* h2=second;
        
        while(h1!=NULL)
        {
            v1.push_back(h1->data);
            h1=h1->next;
        }
        
        while(h2!=NULL)
        {
            v2.push_back(h2->data);
            h2=h2->next;
        }
        
        return makelinkedlist(v1,v2);
    }
};