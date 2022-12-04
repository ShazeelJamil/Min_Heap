#include"MinHeap.h"
#include"Stack.h"
#include<iostream>
using namespace std;
template<typename T>
MinHeap<T>::MinHeap()
{
	root = nullptr;
	nodeCount = 0;
}


template<typename T>
void MinHeap<T>::insert(T val)
{
	if (!root)
	{
		root = new BTNode<T>(val);
		nodeCount++;
		return;
	}
	if (!root->left )
	{
		root->left = new BTNode<T>(val);
		nodeCount++;
		if (root->info > val)
			swap(root->info, root->left->info);
		return;
	}
	if (!root->right)
	{
		root->right = new BTNode<T>(val);
		nodeCount++;
		if (root->info > val)
			swap(root->info, root->right->info);
		return;
	}

	int num = (nodeCount + 1) / 2;
	Stack<T> bin;
	Stack<BTNode<T>*> path;
	while (num != 0)
	{
		bin.push(num % 2);
		num = num / 2;
	}
	bin.pop();
	BTNode<T>* p = root;
	path.push(root);
	while (!bin.isEmpty())
	{
		if (bin.pop() == 0)
		{
			path.push(p->left);
			p = p->left;
		}
		else
		{
			path.push(p->right);
			p = p->right;
		}
	}
	if (!p->left)
	{
		p->left = new BTNode<T>(val);
		nodeCount++;
		p = p->left;
	}
	else if(!p->right)
	{
		p->right = new BTNode<T>(val);
		nodeCount++;
		p = p->right;
	}

	BTNode<T>* directParent = path.pop();
	while (!path.isEmpty() && directParent->info > p->info)
	{
		swap(directParent->info, p->info);
		p = directParent;
		directParent = path.pop();
	}
	/*if (directParent->left)
	{
		while (!path.isEmpty() && directParent->info > directParent->left->info)
		{
			swap(directParent->info, directParent->left->info);
			directParent = path.pop();
		}
	}
	if(directParent->right)
	{
		while (!path.isEmpty() && directParent->info > directParent->right->info)
		{
			swap(directParent->info, directParent->right->info);
			directParent = path.pop();
		}
	}*/
}

template <typename T>
void MinHeap<T>::remove()
{
	if (!root->left && !root->right)
	{
		delete root;
		root = nullptr;
		return;
	}
	int num = nodeCount; 
	Stack<int> bin;
	while (num != 0)
	{
		bin.push(num % 2);
		num = num / 2;
	}
	bin.pop();
	BTNode<T>* p = root;
//	Stack<BTNode<T>* > path;
	BTNode<T>* prev = root;
	while (!bin.isEmpty())
	{
		if (bin.pop() == 0)
		{
			//path.push(p->left);
			prev = p;
			p = p->left;
		}
		else
		{
			//path.push(p->right);
			prev = p;
			p = p->right;
		}
	}
	root->info = p->info;
	//p = path.pop();
	p = prev;
	if (p->right)
	{
		delete p->right;
		p->right = nullptr;
	}
	else
	{
		delete p->left;
		p->left = nullptr;
	}
	BTNode<T>* startNode = root;
	if (startNode->left)
	{
		updateMin(root, startNode->left);
	}
	if (startNode->right)
	{
		updateMin(root,startNode->right);
	}
}


template <typename T>
void MinHeap<T>::updateMin(BTNode<T>*& s, BTNode<T>*& p)
{
	if (s->info > p->info)
		swap(s->info, p->info);
	if (!p->left && !p->right)
		return;
	if (p->left)
		updateMin(s->left, p->left);
	if (p->right)
		updateMin(s->right, p->right);
}
template <typename T>
bool MinHeap<T>::search(T val)
{
	if (!root)
		return false;
	return helperSearch(root, val);
}
template <typename T>
bool MinHeap<T>::helperSearch(BTNode<T>* p, T val)
{
	if (p->info == val)
		return true;
	bool status = false;
	if (p->left)
		status = helperSearch(p->left, val);
	if (!status && p->right)
		status = helperSearch(p->right, val);
	return status;
}
template<typename T>
void MinHeap<T>::VLR(BTNode<T>* p)
{
	cout << p->info << "\n";
	if (p->left)
		VLR(p->left);
	if (p->right)
		VLR(p->right);
}
template<typename T>
void MinHeap<T>::preOrder()
{
	VLR(root);
}
template<typename T>
void MinHeap<T>::heapSort()
{
	LSLL<T> sorted;

	//while (!isEmpty())
	//{
	//	sorted.insertAtHead(getMin());
	//	remove();
	//}
	sorted.display();
}