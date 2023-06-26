//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    Node* h1=head1;
    Node* h2=head2;
    int cnt1=0;
    int cnt2=0;
    
    //counting the length of nodes
    while(h1!=NULL)
    {
        cnt1++;
        h1=h1->next;
    }
    
    while(h2!=NULL)
    {
        cnt2++;
        h2=h2->next;
    }
    
    //making both nodes at the same level
    h1=head1;
    h2=head2;
    
    while(h1!=NULL and cnt1>cnt2)
    {
        h1=h1->next;
        cnt1--;
    }
    
    while(h2!=NULL and cnt2>cnt1)
    {
        h2=h2->next;
        cnt2--;
    }
    
    //comparing nodes untill they are not equal
    while(h1!=h2)
    {
        h1=h1->next;
        h2=h2->next;
    }
    
    if(h1==NULL)
    return -1;
    
    return h1->data;
}
