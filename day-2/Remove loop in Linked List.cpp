
class Solution
{
    public:
    
    void removeLoop(Node* head)
    {
       Node *s= head;
       Node *f = head;
       while(f and f->next)
       {
           s = s->next;
           f = f->next->next;
           
                /*when slow == fast 
                  that's mean there is 
                  loop in a linked list,
                  
                  then to find that at which element 
                  there is loop .
                  make slow=head and traverse again
                */
           if(f == s)
           {
               s = head;
               while(s != f)
               {
                   s = s->next;
                   f = f->next;
               }
               while(f->next != s)
               {
                   f = f->next;
               }
               f->next = NULL;
           }
       }
       return;
    }
};