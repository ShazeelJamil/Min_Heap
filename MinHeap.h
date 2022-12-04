#ifndef MIIN_HEAP_H
#define MIIN_HEAP_H
#include"BTNode.h"
#include"LSLL.h"
template <typename T>
class MinHeap
{
	BTNode<T>* root;
	int nodeCount;
	void VLR(BTNode<T>* p);
	void updateMin(BTNode<T>*& s, BTNode<T>*& p);
	bool helperSearch(BTNode<T>* p, T val);
	bool isEmpty()
	{
		if (!root)
			return true;
		else
			return false;
	}
public:
	MinHeap();
	void insert(T val);
	void remove();
	T getMin()
	{
		return root->info;
	}
	bool search(T val);
	void preOrder();
	void heapSort();
};
template class MinHeap<int>;
#endif // !MIIN_HEAP_H
