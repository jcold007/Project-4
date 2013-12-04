/*
 Ivan Coronel - Project 4
*/

 /*
heap.h Class:
	... 
 */

#ifndef HEAP
#define HEAP
#include <iostream>
#include <vector>
using namespace std;

class heap{
private:
	vector<int> matrix;

public:
	int deleteMin();
	void insert(int element);
	void heapifyUp(int index);
	void heapifyDown(int index);
	bool empty();
	void print();

	int left(int parent);
	int right(int parent);
	int parent(int child);

};
#endif
