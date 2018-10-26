/**
 * @brief 
 *
 * https://blogs.msdn.microsoft.com/devdev/2006/01/18/efficient-selection-and-partial-sorting-based-on-quicksort/
 * @question     Get the value of the kth smallest element in the list
 * ****************************pseudo code*******************************************************
 * 
    object quickselect(a, k)
    {

        int left = 0, right = a.Length - 1;

        while (right > left)
        {
        // Choose a pivot element a[pivotIdx] with left <= pivotIdx <= right
            newPivotIdx = partition(a, left, right);

            if (k < newPivotIdx)
            {
                right = newPivotIdx - 1;
            }
            else
            {
                left = newPivotIdx + 1;
            }
        }
        return a[k];
    }
 * @file findkth.cpp
 * @author Luo Yu
 * @date 2018-07-31
 */
#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> &arr, int left, int right)
{
	int pivot = arr[right];
	int partitionIndex = left;//set partition index as start initially

	for (int i = left; i < right; i++)
	{
		if (arr[i] < pivot)
		{
			std::swap(arr[i], arr[partitionIndex]);
			partitionIndex++;
		}
	}
	std::swap(arr[partitionIndex], arr[right]);  //swap pivot element at partition index
	return partitionIndex;
}
// A useful variation on quicksort is the partially tail-recursive variant,
// where we only make a recursive call for the smaller of the two sublists,
// and use a loop to deal with the other one
// This QuickSort requires O(Log n) auxiliary space(辅助空间) in worst case.
void quickSortImp(int arr[], int left, int right)
{
	//只能用while,与recursion基本版本不同
	while (left < right)
	{
		/* newPivotIdx is partitioning index, arr[p] is now
		at right place */
		int newPivotIdx = partition(arr, left, right);

		// If left part is smaller, then recur for left
		// part and handle right part iteratively
		if (newPivotIdx - left < right - newPivotIdx)
		{
			quickSortImp(arr, left, newPivotIdx - 1);
			left = newPivotIdx + 1;
		}

		// Else recur for right part
		else
		{
			quickSortImp(arr, newPivotIdx + 1, right);
			right = newPivotIdx - 1;
		}
	}
}
/*
* \method
* \brief     Get the value of the kth smallest element in the list
*            此处指的kth smallest 是指从小到达排序中下标为k的值。
*            example:   1 2 3 4 5 6 7 8
*            现求 3th smallest ,结果为4 因为 从小到达排序后，array[3]=4
 * \param
 * \param
 * \author thnx1
 * \date 七月 2018
 */
int quickselect(vector<int> &arr, int k)
{
    //left ,最小小标，
    //right 最大下标
    int left = 0, right = arr.size() - 1;

    while (left < right)
    {
        //Choose a pivot element a[pivotIdx] with left <= pivotIdx <= right
        int newPivotIdx = partition(arr, left, right);

        if (k == newPivotIdx)
        {
            break;
        }
        //kth smallest 在左部分（不一定是恰好一半），
        //arr[newPivotIdx] 就是 newPivotIdxth smallest
        //只需对左部分排序
        if (k < newPivotIdx)
        {
            right = newPivotIdx - 1;
        }
        //只需对右部分排序
        else
        {
            left = newPivotIdx + 1;
        }
    }
    return arr[k];
}
/**
 * \method 数组版本
* \brief     Get the value of the kth smallest element in the list
*            此处指的kth smallest 是指从小到达排序中下标为k的值。
*            example:   1 2 3 4 5 6 7 8
*            现求 3th smallest ,结果为4 因为 从小到达排序后，array[3]=4
 * \author thnx1
 * \date 七月 2018
 */
int quickselect(int arr[], int k,int size)
{
	//left ,最小小标，
	//right 最大下标
	int left = 0, right = size -1;

	while (left < right)
	{
		//Choose a pivot element a[pivotIdx] with left <= pivotIdx <= right
		int newPivotIdx = partition(arr, left, right);
        if (k== newPivotIdx)
		{
			break;
		}
		if (k < newPivotIdx)
		{
			right = newPivotIdx - 1;
		}

		else
		{
			left = newPivotIdx + 1;
		}
	}
	return arr[k];
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

int quickselect2(int arr[], int k)
{
    int left = 0, right = size - 1;

    while (left < right)
    {
        int newPivotIdx = partition(arr, left, right);
        if (k == newPivotIdx)
        {
            break;
        }

        if (k < newPivotIdx)
        {
            right = newPivotIdx - 1;
        }
        else
        {
            left = newPivotIdx + 1;
        }
    }
    return arr[k];
}
/**
 * @brief  finding the k smallest or largest values in a list
 * 
 * @param arr 
 * @param left 
 * @param right 
 * @param k 
 */
void quicksortSmallestK(int arr[], int left, int right, int k)
{
    //Choose a pivot element a[pivotIdx] with left <= pivotIdx <= right
    while (left < right)
    {
        int newPivotIdx = partition(arr, left, right);
        if (k <= newPivotIdx)
        {
            right = newPivotIdx - 1;
        }
        else if (newPivotIdx - left > right - newPivotIdx)
        {
            quickSortImp(arr, newPivotIdx + 1, right);
            right = newPivotIdx - 1;
        }
        else
        {
            quickSortImp(arr, left, newPivotIdx - 1);
            left = newPivotIdx + 1;
        }
    }
}
