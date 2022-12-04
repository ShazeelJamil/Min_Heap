#include<iostream>
using namespace std;
#include"MinHeap.h"
int main()
{
	MinHeap<int> q;
	q.insert(20);
	q.insert(50);
	q.insert(40);
	q.insert(60);
	q.insert(70);
	q.insert(80);
	q.insert(90);
	q.insert(25);

	q.remove();
	q.remove();
	//q.remove();
	q.preOrder();
	//q.heapSort();


	/*q.remove();
	q.preOrder();*/

	//cout << q.search(80)<<"\n";
	//cout << q.search(100);

	return 0;
}