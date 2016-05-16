/*************************************************************************
    > File Name: test.6.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Mon May 16 15:37:53 2016
 ************************************************************************/
#include <iostream>

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};

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

int main(int argc, char** argv)
{
	ListNode *head;
	add_to_tail(&head, 1);
	add_to_tail(&head, 2);
	add_to_tail(&head, 3);

	print_list(head);

	remove_node(&head, 5);
	print_list(head);

	remove_node(&head, 1);
	print_list(head);

	remove_node(&head, 3);
	print_list(head);

}
