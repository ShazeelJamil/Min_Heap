#ifndef STACK_H
#define STACK_H
template<typename T>
class Stack
{
    T* data;
    int capacity;
    int top;
    void reSize(int newSize);
public:
    Stack();
    Stack(const Stack<T>& ref);
    Stack<T>& operator=(const Stack<T>& ref);
    ~Stack();
    void push(T element);
    T pop();
    T stackTop() const;
    bool isFull() const;
    bool isEmpty() const;
    int getCapacity() const;
    int getNumberOfElements() const;
};
#endif // !STACK_H
