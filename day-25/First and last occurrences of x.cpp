void first_occurr(int* arr,int s,int e,int x,int& ind)
{
    //base case
    if(s>e)
    return ;
    
    int mid=(s+e)/2;
    if(arr[mid]==x)
    {
        ind=mid;
        first_occurr(arr,s,mid-1,x,ind);
    }
    else if(arr[mid]>x)
    first_occurr(arr,s,mid-1,x,ind);
    else
    first_occurr(arr,mid+1,e,x,ind);
    
}

void last_occurr(int* arr,int s,int e,int x,int& ind)
{
    //base case
    if(s>e)
    return ;
    
    int mid=(s+e)/2;
    if(arr[mid]==x)
    {
        ind=mid;
        last_occurr(arr,mid+1,e,x,ind);
    }
    else if(arr[mid]>x)
    last_occurr(arr,s,mid-1,x,ind);
    else
    last_occurr(arr,mid+1,e,x,ind);
    
}

vector<int> find(int arr[], int n , int x )
{
    int ind1=-1;
    int ind2=-1;
    
    first_occurr(arr,0,n-1,x,ind1);
    last_occurr(arr,0,n-1,x,ind2);
    
    if(ind1==-1 or ind2==-1)
    return {-1,-1};
    else
    return {ind1,ind2};
}
