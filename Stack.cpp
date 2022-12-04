#include"Stack.h"
#include<iostream>
using namespace std;
template<typename T>
Stack<T>::Stack() :capacity(0), top(0)
{
	data = nullptr;
}
template<typename T>
Stack<T>::Stack(const Stack<T>& ref)
{
	*this = ref;
}
template<typename T>
void Stack<T>::reSize(int newSize)
{
	T* temp = new T[newSize];
	for (int i = 0; i < top; i++)
		temp[i] = data[i];
	capacity = newSize;
	delete[] data;
	data = temp;
	temp = nullptr;
}
template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& ref)
{
	if (data == ref.data)
		return *this;
	this->~Stack();
	if (ref.data)
	{
		top = ref.top;
		capacity = ref.capacity;
		data = new T[capacity];
		for (int i = 0; i < top; i++)
			data[i] = ref.data[i];
	}
	return *this;
}
template<typename T>
Stack<T>::~Stack()
{
	delete[] data;
	data = nullptr;
	capacity = 0;
	top = 0;
}
template<typename T>
void Stack<T>::push(T element)
{
	if (isEmpty())
		reSize(capacity + 5);
	else if (isFull())
		reSize(capacity * 2);
	data[top] = element;
	top++;
}
template<typename T>
T Stack<T>::pop()
{
	if (capacity == top / 4)
		reSize(capacity / 2);
	return data[--top];
}
template<typename T>
T Stack<T>::stackTop() const
{
	return data[top - 1];
}
template<typename T>
bool Stack<T>::isFull() const
{
	return (top == capacity ? true : false);
}
template<typename T>
bool Stack<T>::isEmpty() const
{
	return (top == 0 ? true : false);
}
template<typename T>
int Stack<T>::getCapacity() const
{ 
	return capacity;
}
template<typename T>
int Stack<T>::getNumberOfElements() const
{ 
	return top;
}