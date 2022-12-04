#ifndef NODE_H
#define NODE_H
template<typename T>
struct Node
{
	T info;
	Node<T>* nextPtr;
	Node()
	{
		nextPtr = nullptr;
	}
	Node(T val)
	{
		info = val;
		nextPtr = nullptr;
	}
};

#endif // !
