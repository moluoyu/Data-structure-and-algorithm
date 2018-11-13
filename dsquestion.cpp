#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stack>
//https://blog.csdn.net/fx677588/article/details/72357389  主要看图解
using namespace std;
typedef  struct Node
{
    int data;
    struct Node *Next;
} Node;

Node * head =NULL; //一般这种程序中都有一个 global  variable :head
/*
 *
 * @param data
 * 在尾部插入node
 *如果将插入函数定义成这种形式 ：Node *  Inserttail(Node * list,int data)
 *有返回值的情况下，一定要保存返回值，这种情况下，你传入head给list后，依然是值拷贝
 * 
 */
void  Inserttail(int data)
{

    Node *temp = new Node();
    temp->data = data;
    temp->Next = NULL;
    if(head==NULL)
    {
        head = temp;
    }
    else// 不能少了这个else,因为list为空，与链表不为空的情况是二选一
    {
        Node *tail = head;
        while (tail->Next != NULL)
        {
            tail = tail->Next;
        }
        tail->Next = temp;

    }

}
void Print()
{
    Node * temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->Next;
    }
    printf("\n");
}



/**
 * Reverse print linked list 
 * input: 2 3 4 5
 * output: 5 4 3 2
 * @param p 
 */
void PrintReverse(Node * p)
{
    if(p == NULL)
        return;
    PrintReverse(p->Next);//调换下面两行的顺序，输出顺序反转
    printf("%d ",p->data);
}




/*
 * Reverse linked list
 * @param p 传入linked list head
 * 一般来说，recurision不需要返回值
 */
void Reverse(Node *p )
{
    if(p->Next == NULL)//这里面不能写成(p === NULL ) 否则，下一步q 将会为null
    {
        head = p;
        return;
    }
    Reverse(p->Next);
    Node * q = p->Next;
    q->Next=p;
    p->Next =NULL;
}
/**
 * @brief 有返回值版本
 * @param listhead 
 * @return Node* 
 */
Node* recursion_Reverse(Node *listhead)
{
	if (listhead->Next == nullptr)
	{
		return listhead;
	}
 // 带返回值版本，递归中一定要把最后的尾指针返回，最后保存再newhead中
	Node *newhead = recursion_Reverse(listhead->Next);
	Node* temp = listhead->Next;
	temp->Next = listhead;
	listhead->Next = nullptr;
	return newhead;
}
/**
 * 利用STL stack reverse linked list
 */
void ReverseStack()
{
    if(NULL == head)
    {
        return;
    }
    stack<struct Node*> S;
    Node * temp = head;
    while(temp != NULL)
    {
        S.push(temp);
        temp = temp->Next;
    }
    temp = S.top();
    head = temp;
    S.pop();
    while (!S.empty())
    {
        temp->Next = S.top();
        S.pop();
        temp = temp->Next;
    }
    temp->Next = NULL; //这句不能少
}
Node * ReverseLinkedList(Node * Listhead)
{
	//注意这里形参listhead 最后要赋值给全局变量给head,别忘了
	if (Listhead == nullptr && Listhead->Next == nullptr)
		return Listhead;
	Node * current = Listhead->Next;
	Listhead->Next = nullptr;
	while (current) 
	{
		Node * temp = current->Next;
		current->Next = Listhead;
		Listhead = current;
		current = temp;
	}
	return Listhead;
}


Node* reverseList(Node* head) {
	Node *prev = NULL;
	while (head) {
		Node *Next = head->Next;
		head->Next = prev;
		prev = head;
		head = Next;
	}
	return prev;
}


void reverse_Iter(Node * phead)
{
	if (phead == nullptr || phead->Next == nullptr)
	{
		return;
	}
	
	Node* cur = phead->Next;
	phead->Next = nullptr;

	while (cur) {
		/* code */
 	    Node *temp1 = cur->Next;
		cur->Next = phead;
		phead = cur;
		cur = temp1;

	}
	head = phead;  //切记，当把指针当参数传入一个形参也为指针的函数时，次数，phead也知识临时变量，phead只是个形参
}

int main()
{
    // Node *head = NULL; //empty list
    Inserttail( 2); //list:2
    Inserttail( 3);
    Inserttail( 4);
    Inserttail( 5);
    Print();
    Reverse(head);
    // head  =  ReverseLinkedList(head);
    Print();
    return 0;
}
/**
 * @brief  判断单链表是否成环，以及判断环的入口
 * https://blog.csdn.net/wuzhekai1985/article/details/6725263
 * 
 */



template <class T>
/**
 * @brief n个数里找出前m个数 top K 问题（https://blog.csdn.net/see__you__again/article/details/51713809）
 * 思路：保存目前找到的最大k个数，每访问一个数，就与这k个数中的最小值比较，决定是否更新这k个数。
 * 储存k个数的数据结构可采用：败者树、二叉查找树、最小堆
 如果这个大数组本身已经按从大到小有序，那么数组的前1万个元素就是结果；
 然后，可以假设这个大数组已经从大到小有序，并将前1万个元素放到结果数组；
 再次，事实上这结果数组里放的未必是最大的一万个，
 因此需要将前1万个数字后续的元素跟结果数组的最小的元素比较，
 如果所有后续的元素都比结果数组的最小元素还小，那结果数组就是想要的结果
 如果某一后续的元素比结果数组的最小元素大，那就用它替换结果数组里最小的数字；
 最后，遍历完大数组，得到的结果数组就是想要的结果了。
 * @param BigArr   
 * @param ResArr 结果存放的数组
 */

void solution_3(T BigArr[], T ResArr[])
{
    //取最前面的一万个
    memcpy(ResArr, BigArr, sizeof(T) * RES_ARR_SIZE);
    //标记是否发生过交换
    bool bExchanged = true;
    //遍历后续的元素
    for (int i = RES_ARR_SIZE; i < BIG_ARR_SIZE; ++i)
    {
        int idx;
        //如果上一轮发生过交换
        if (bExchanged)
        {
            //找出ResArr中最小的元素
            int j;
            for (idx = 0, j = 1; j < RES_ARR_SIZE; ++j)
            {
                if (ResArr[idx] > ResArr[j])
                    idx = j;
            }
        }
        //这个后续元素比ResArr中最小的元素大，则替换。
        if (BigArr[i] > ResArr[idx])
        {
            bExchanged = true;
            ResArr[idx] = BigArr[i];
        }
        else
            bExchanged = false;
    }
}
