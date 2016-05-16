/*************************************************************************
    > File Name: test.7.cpp
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Mon May 16 21:55:48 2016
 ************************************************************************/
//题目描述:给定二叉树的前序遍历和中序遍历，重建二叉树
#include <iostream>
#include <exception>

struct InvalidInput : public std::exception
{
	const char* what() const throw()
	{
		char *str = new char[30];
		sprintf(str, "%s(%d)-%s: %s", __FILE__, __LINE__, __FUNCTION__, "Invalid input.");
		return str;
	}
};

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

BinaryTreeNode* construct_core(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);

BinaryTreeNode* construct(int* preorder, int* inorder, int length)
{
	//没有节点
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;

	return construct_core(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* construct_core(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	//前序遍历序列的第一个数字是根节点的值
	int nRootValue = startPreorder[0];
	BinaryTreeNode *pRoot = new BinaryTreeNode();
	pRoot->m_nValue = nRootValue;
	pRoot->m_pLeft = pRoot->m_pRight = nullptr;

	if (startPreorder == endPreorder)
	{
		//只有一个节点
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return pRoot;
		else
			throw InvalidInput();
	}

	//在中序遍历中找到根节点值
	int *pRootInorder = startInorder;
	while (pRootInorder <= endInorder && *pRootInorder != nRootValue)
	{
		++pRootInorder;
	}

	//中序遍历错误
	if (pRootInorder == endInorder && *pRootInorder != nRootValue)
	{
		throw InvalidInput();
	}

	int leftLength = pRootInorder - startInorder;
	int *leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{
		//构建左子树
		pRoot->m_pLeft = construct_core(startPreorder + 1, leftPreorderEnd, startInorder, pRootInorder - 1);
	}

	if (leftLength < endPreorder - startPreorder)
	{
		//构建右子树
		pRoot->m_pRight = construct_core(leftPreorderEnd + 1, endPreorder, pRootInorder + 1, endInorder);
	}

	return pRoot;
}

void print_binary_tree_preorder(BinaryTreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		std::cout << pRoot->m_nValue << ' ';
		print_binary_tree_preorder(pRoot->m_pLeft);
		print_binary_tree_preorder(pRoot->m_pRight);
	}
}

void print_binary_tree_inorder(BinaryTreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		print_binary_tree_inorder(pRoot->m_pLeft);
		std::cout << pRoot->m_nValue << ' ';
		print_binary_tree_inorder(pRoot->m_pRight);
	}
}

void print_binary_tree_postorder(BinaryTreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		print_binary_tree_postorder(pRoot->m_pLeft);
		print_binary_tree_postorder(pRoot->m_pRight);
		std::cout << pRoot->m_nValue << ' ';
	}
}

int main(int argc, char** argv)
{
	int preorder[] = {1, 2, 4, 7, 3, 5, 6, 8};
	int inorder[] = {4, 7, 2, 1, 5, 3, 8, 6};
	try
	{
		BinaryTreeNode *pRoot = construct(preorder, inorder, 8);
		print_binary_tree_preorder(pRoot);
		std::cout << std::endl;
		print_binary_tree_inorder(pRoot);
		std::cout << std::endl;
		print_binary_tree_postorder(pRoot);
		std::cout << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
