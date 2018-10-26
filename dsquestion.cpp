#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stack>gi
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
