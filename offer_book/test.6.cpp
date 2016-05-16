/*************************************************************************
    > File Name: test.6.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Mon May 16 15:37:53 2016
 ************************************************************************/
#include <iostream>
#include <stack>

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};

//尾部增加借点
void add_to_tail(ListNode** pHead, int value)
{
	ListNode *pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;

	if (pHead == nullptr)
		return;

	if (*pHead == nullptr)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode *pNode = *pHead;
		while (pNode->m_pNext != nullptr)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = pNew;
	}
}

//删除节点
void remove_node(ListNode** pHead, int value)
{
	if (pHead == nullptr || *pHead == nullptr)
		return;

	ListNode *pToBeDeleted = nullptr;
	if ((*pHead)->m_nValue == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode *pNode = *pHead;
		while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
		{
			pNode = pNode->m_pNext;
		}

		if (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
		{
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	if (pToBeDeleted != nullptr)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

//顺序打印链表
void print_list(ListNode* pHead)
{
	if (pHead == nullptr)
		return;

	while (pHead != nullptr)
	{
		std::cout << pHead->m_nValue << " ";
		pHead = pHead->m_pNext;
	}
	std::cout << std::endl;
}

//逆向打印链表 - 使用栈实现
void print_list_reversingly_iteratively(ListNode* pHead)
{
	std::stack<ListNode*> nodes;

	ListNode *pNode = pHead;
	while (pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty())
	{
		pNode = nodes.top();
		std::cout << pNode->m_nValue << " ";
		nodes.pop();
	}
	std::cout << std::endl;
}

//逆向打印链表 - 使用递归实现
void print_list_reversingly_recursively(ListNode* pHead)
{
	if (pHead != nullptr)
	{
		if (pHead->m_pNext != nullptr)
		{
			print_list_reversingly_recursively(pHead->m_pNext);
		}
		std::cout << pHead->m_nValue << ' ';
	}
}

int main(int argc, char** argv)
{
	ListNode *head;
	add_to_tail(&head, 1);
	add_to_tail(&head, 2);
	add_to_tail(&head, 3);

	print_list(head);
	print_list_reversingly_iteratively(head);
	print_list_reversingly_recursively(head);
	std::cout << std::endl;

	remove_node(&head, 5);
	print_list(head);
	print_list_reversingly_iteratively(head);
	print_list_reversingly_recursively(head);
	std::cout << std::endl;

	remove_node(&head, 1);
	print_list(head);

	remove_node(&head, 3);
	print_list(head);

}
