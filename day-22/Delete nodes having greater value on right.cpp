class Solution
{
    public:
    
    //function for reversing a linked list
    Node* reverse(Node* head)
    {
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) 
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    
    //remove all the nodes which have a greater value on their right side.
    Node *compute(Node *head)
    {
        if(head==NULL)
        return NULL;
        
        Node* temp=reverse(head);
        stack<int> st;
        st.push(temp->data);
        
        Node* h1=temp->next;
        Node* pre=temp;
        
        while(h1)
        {
            int num=h1->data;
            while(!st.empty() and st.top()<=num)
            {
                st.pop();
            }
            
            if(st.empty())
            {
                h1=h1->next;
                pre=pre->next;
                st.push(num);
            }
            else
            {
                Node* Next=h1->next;
                pre->next=Next;
                delete h1;
                h1=Next;
            }
            
        }
        
        Node* temp2=reverse(temp);
        
        return temp2;
    }
    
};