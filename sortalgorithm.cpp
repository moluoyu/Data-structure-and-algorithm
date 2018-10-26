#include <iostream>
#include<algorithm>
#include <stack>
using namespace std;
/**reference https://www.cnblogs.com/eniac12/p/5329396.html
 * \method
 *冒泡排序、插入排序、归并排序和基数排序是稳定的排序算法
 * \brief
 // 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
 * \param
 * \param
 * \author thnx1
 * \date 七月 2018 
 */
void bubbleSort(int array[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{ 
				swap(array[j], array[j + 1]);
			}
		}   
	}
}
/**
 * @brief 1 冒泡排序：递归版本 
注意问题：end--那里，注意每次递归的起始终止下标的移动，起始下标不变，终止下标每次减1，
循环结束条件 为start == end，以及i < length - 1;

 * @param data 
 * @param start 
 * @param end 
 */
void bubbleSort(int *data,int start,int end)
{
    if (start < end) {
        int temp = 0;
        int length = end - start + 1;
        for (int i = start; i < length - 1; i ++) {
            if (data[i] < data[i + 1]) {
                temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
            }
        }
        end --;
        bubbleSort(data,start,end);
    }
    
}






/**
 * \method
 *
 * \brief SelectionSort
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- O(n^2)
// 平均时间复杂度 ---- O(n^2)
 * \param
 * \param
 * \author thnx1
 * \date 七月 2018
 */

void selectionSort(int array[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int tempmin = i;
		for (int j = i + 1; j < size; j++)
		{
			if (array[tempmin] > array[j])
			{
				tempmin = j;
			}
		}
		if (tempmin != i)
		{
			std::swap(array[i], array[tempmin]);
		}
	}
}
/**
* @ Insertion sort pseudo  code
* 以A[0]和A[1]中间为分界线，左边为sorted array
* 右边unsorted,从A[1]开始,A[1]的值拿出来后，空出来的位置叫hole = 1(初值）
*
* ************************************************
Insertion sort(A ,n)
{
for(1 to n-1)
{
value =A[i];
hole = i;
while(hole > 0 && A[hole -1] > value)
{
A[hole] = A[hole -1];
hole = hole -1;
}
A[hole] = value;
}
}
**/
/**
 * \method InsertionSort
 * \brief 从小到大     best time complexity O(n)
 *					 worst time complexity O(n^2)
 * \param
 * \param
 * \author thnx1
 * \date 七月 2018
 */
void InsertionSort(int array[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int hole = i;
		int tempvalue = array[i];
		while (hole > 0 && array[hole - 1] > tempvalue)
		{
			array[hole] = array[hole - 1];
			hole = hole - 1;
		}
		array[hole] = tempvalue;//这句不能省，不然会有重复的值出现，A1行只是将左边的临近元素赋值给最右边的元素
	}
}

/**
 * \method
 *
 * \brief QuickSort Recursion version
//  Quick sort Implementation in c++ auxiliy
//  https://www.youtube.com/watch?v=COk73cpQbFQ&index=7&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U
// time complexity best :O(Nlog N)
//                worst : O(N^2)
//                average：O(Nlog N)
 * @brief  注意交换两个数形参的写法，不能直接int a ,int b
 * @param a
 * @param b
 *  https://www.khanacademy.org/computing/computer-science/algorithms/quick-sort/a/analysis-of-quicksort
 *  http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/7-Sort/Quick-analysis.html
 * The Quick Sort algorithm performs the worst when the pivot is the largest or smallest value in the array
 *  author thnx1
 * date 七月 2018
 */
void swapNumber(int &a, int &b)
{
	int tempvalue = a;
	a = b;
	b = tempvalue;
}
/**
 * \method
 *
 * \brief  从小到大排序
 * \param
 * \param
 * \author thnx1
 * \date 七月 2018
 */
int partition(int arr[], int left, int right)
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
/*This quickSort requires O(Log n) auxiliary space(辅助空间) inworst case.
 A simple implementation of QuickSort makes two calls to itself
 and in worst case requires O(n) space on function call stack.
*/
void  quickSort(int array[], int left, int right)
{
	//这里只能是if 要不然停不下来,注意与quickSortImp
	if (left < right)
	{
		//Choose a pivot element a[pivotIdx] with left <= pivotIdx <= right
		// Here, partition() returns the new index of the pivot element
		int newPivotIdx = partition(array, left, right);
		quickSort(array, left, newPivotIdx - 1);
		quickSort(array, newPivotIdx + 1, right);
	}
}
/**
 * \method Iteration version of quickSort
 *与递归版本相比，主要思想在于如何不断更新 各部分的 startindex endindex,排序的工作其实是在partition函数内完成
 * \brief  A[] --> Array to be sorted,
 *         lo --> Starting index,
 *	       hi --> Ending index
 * \param
 * \param
 * \author thnx1
 * \date 七月 2018
 * http://inst.eecs.berkeley.edu/~cs162
 */

void quickSortIterative(int arr[], int lo, int hi) {
	stack<int> start;
	stack<int> end;
	start.push(lo);
	end.push(hi);
	int l, r, p;
	while (!start.empty()) {
		l = start.top();
		r = end.top();
		if (l < r)
		{
			p = partition(arr, l, r);
			start.pop();
			end.pop();
			start.push(l);
			end.push(p - 1);
			start.push(p + 1);
			end.push(r);
		}
		else {
			start.pop();
			end.pop();
		}
	}
}

/* This QuickSort requires O(Log n) auxiliary space(辅助空间) in
worst case. */
void quickSortImp(int arr[], int low, int high)
{
	//只能用while,与recursion基本版本不同
	while (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// If left part is smaller, then recur for left
		// part and handle right part iteratively
		if (pi - low < high - pi)
		{
			quickSortImp(arr, low, pi - 1);
			low = pi + 1;
		}

		// Else recur for right part
		else
		{
			quickSortImp(arr, pi + 1, high);
			high = pi - 1;
		}
	}
}

// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(nlogn)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(n)
// 稳定性 ------------ 稳定

void merge(int arr[], int start, int mid, int end)
{
	int i = start;
	int j = mid+1;
	int index = 0;
	int length = end - start + 1;
	auto temp = new int[length];
	while (i <= mid && j <= end) {
		temp[index++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
		/* code */
	}
	while (i <= mid)
	{
		temp[index++] = arr[i++];
	}
	while (j <= end)
	{
		temp[index++] = arr[j++];
	}

	for (int i = 0; i < length; i++)
	{
		arr[start++] = temp[i];
	}
	delete temp;
}
void MergeSort(int arr[], int start, int end)
{
	if (start == end)//或者用if(start<end)包裹整个函数体
		return;
		int mid = (start + end) / 2;
		MergeSort(arr, start, mid);
		MergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	
}
int main()
{
	int A[] = { 17, 16, 5, 14, 31, 22, 12, 11 };
	MergeSort(A,0,7);
	//quickSort(A, 0, 7);
	//bubbleSort(A, 8);
	//selectionSort(A, 8);
	//quickSortIterative3(A, 0, 7);
	//quickSortImp(A, 0, 7);
	for (int i : A)
	{
		cout << i << endl;
	}
	/*cout << "___________";
	InsertionSort(A, 8);
	for (int i : A)
	{
		cout << i << endl;
	}*/
	return 0;
}

/************************************************************************
int A[] = { 7, 6, 5, 4, 3, 2, 1, 0 };
quickSort(A, 0, 7);
for (int i : A)
{
	cout << i << endl;
}

/************************************************************************/