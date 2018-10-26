
#include<bits/stdc++.h>
struct Node
{
	/* data */
	int data;
	Node *next;
	
};
Node * Inter_Reverse(Node * Listhead)
{
	//注意这里形参listhead 最后要赋值给全局变量给head,别忘了
	if (Listhead == nullptr && Listhead->next == nullptr)
		return Listhead;
	Node * current = Listhead->next;
	Listhead->next = nullptr;
	while (current) 
	{
		Node * temp = current->next;
		current->next = Listhead;
		Listhead = current;
		current = temp;
	}
	return Listhead;
}

Node* recursion_Reverse(Node *listhead)
{
	if (listhead->next == nullptr)
	{
		return listhead;
	}
 // 带返回值版本，递归中一定要把最后的尾指针返回，最后保存再newhead中
	Node *newhead = recursion_Reverse(listhead->next);
	Node* temp = listhead->next;
	temp->next = listhead;
	listhead->next = nullptr;
	return newhead;
}



























Node * recursion_Reverse(Node * phead)
{	
	
	if (phead ==nullptr || phead->next==nullptr) {
		/* code */
		return phead;
	}
	Node *newhead = recursion_Reverse(phead->next);
	Node *temp = phead->next;
	temp->next = phead;
	phead->next= nullptr;
	return newhead;

}

Node* Reversetest(Node * phead)
{

    
	if (phead == nullptr && phead->next == nullptr) {
		return phead;
		/* code */
	}
	Node *cur = phead->next;
	
	phead->next = nullptr;
	
	while(cur){
		Node *temp = cur->next;
		cur->next = phead;
		phead = cur;
		cur = temp;
	}
	

	return phead;
}
