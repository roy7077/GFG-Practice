//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    Node* head=NULL;
    Node* tail=NULL;
    
    //run till head1 and head2 are not null
    while(head1 and head2)
    {
        if(head1->data<head2->data)
        {
            if(head==NULL)
            {
                head=head1;
                tail=head1;
            }
            else
            {
                tail->next=head1;
                tail=head1;
            }
            head1=head1->next;
        }
        else
        {
            if(head==NULL)
            {
                head=head2;
                tail=head2;
            }
            else
            {
                tail->next=head2;
                tail=head2;
            }
            head2=head2->next;
        }
    }
    
    //if head1 is not null and head2 is null
    while(head1)
    {
        if(head==NULL)
        {
            head=head1;
            tail=head1;
        }
        else
        {
            tail->next=head1;
            tail=head1;
        }
        head1=head1->next;
    }
    
    //if head1 is null and head2 is not null
    while(head2)
    {
        if(head==NULL)
        {
            head=head2;
            tail=head2;
        }
        else
        {
            tail->next=head2;
            tail=head2;
        }
        head2=head2->next;
    }
    
    return head;
}  