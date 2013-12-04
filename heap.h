/*
 Ivan Coronel - Project 4
*/

 /*
heap.h Class: Handles the initializations for the heap class
	... 
 */

#ifndef HEAP
#define HEAP
#include <iostream>
#include <vector>
using namespace std;

class heap{
private:
	vector<int> matrix;				//vector that stores the heap values

public:
	int deleteMin();				//deletes the minimum values		
	void insert(int element);		//inserts a value to the tree
	void heapifyUp(int index);		//updates values upwards
	void heapifyDown(int index);	//updates values downwards
	bool empty();					//checks if the heap is empty
	void print();					//print function 

	int left(int parent);			//represents the left value
	int right(int parent);			//represents the right value
	int parent(int child);			//represents the above value from the
										//left and right children

};
#endif
