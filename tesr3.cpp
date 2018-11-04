void SelectionSort(int arr[],int n)
{
    
    for(int i = 0; i < n-1; i++)
    {
        /* code */

        int min = i;
        
        for(int j = i+1; j < n; j++)
        {
            /* code */
            
            if (arr[j]<arr[min]) {
                /* code */
                min = j;
            }
            
        }
        if(min !=i)
        {
            std::swap(arr[i],arr[min]);
        }
        


    }
    
    
}


void insertionSort(int arr[],int n)
{
    int hole;
    for(int i = 1; i < n; i++)
    {
        int temp = arr[i];
        hole = i;
        while(hole>0 && arr[hole-1]>temp){
            arr[hole] = arr[hole-1];
            hole = hole-1;

        }
        arr[hole] = temp;
        
        
    }
    
}

int partition(int arr[],int left,int right)
{
    int pivot = arr[right];
    int partitionIndex = left;

for(int i = left; i < right; i++)
{
    
    if (arr[i]<pivot) {
        /* code */
        std::swap(arr[i],arr[partitionIndex]);
        partitionIndex++;
    }

    
}
std::swap(arr[partitionIndex],arr[right]);
    return partitionIndex ;
}
void quickSort(int arr[],int left,int right)
{

    
    if (left < right) {
        /* code */
        int tmepIndex = partition(arr,left,right);
        quickSort(arr,left,tmepIndex-1);        
        quickSort(arr,tmepIndex+1,right);

    }
    


}
#include<stack>
using namespace std;
void quickSortIter(int arr[], int left, int right)
{
    stack<int> start;
    stack<int> end;
    start.push(left);
    end.push(right);
    int lo, ri;
    while (!start.empty())
    {
        /* code */
        lo = start.top();
        ri = end.top();
        if (lo < ri)
        {
            int newIndex = partition(arr, lo, ri);
             start.pop();
            end.pop();
            start.push(lo);
            end.push(newIndex - 1);
            start.push(newIndex + 1);
            end.push(ri);
        
        }
        else
        {
            start.pop();
            end.pop();
        }
    }
}

int arr[][3] = {
    {1,2,3},
    {1,3,4},
    {2,3,3},
    {2,4,4}
}