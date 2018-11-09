void Merge(int A[],int star,int mid,int end)
{
    int i=star;
    int j=mid+1;
    int length= end-star+1;
    auto newarray= new int[length];
    int index = 0;
    while(i<=mid && j<=end){
        /* code */
        newarray[index++]= (A[i++]<A[j++])?A[i++]: A[j++];
    }
    
    while(i<=mid){
        newarray[index++]=A[i++];
    }
    
    while(j<=end){
        newarray[index++]=A[j++];
    }
    
    for(int k = 0; k <length; k++)
    {
        A[star++]=newarray[k];
    
    }
        delete newarray;
}
void MergeSort(int A[],int star,int end)
{
    
    if (star==end)
    return;
    int mid = (star+end)/2;
    MergeSort(A,star,mid);
    MergeSort(A,mid+1,end);
    Merge(A,star,mid,end);

    
}