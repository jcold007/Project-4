/*
 Ivan Coronel - Project 4
*/

 /*
heap.cpp Class:
	... 
 */

#include <iostream>
#include <vector>
#include <fstream> //print files
#include "heap.h"
using namespace std;

int heap::deleteMin(){
	int min = matrix.front();
	matrix[0] = matrix.at(matrix.size() - 1);
	matrix.pop_back();
	heapifyDown(0);
	return min;
}

void heap::insert(int element){
	matrix.push_back(element);
	heapifyUp(matrix.size() - 1);
}

void heap::heapifyUp(int index){
	//cout << "index=" << index << endl;
    //cout << "parent(index)=" << parent(index) << endl;
    //cout << "heap[parent(index)]=" << heap[parent(index)] << endl;
    //cout << "heap[index]=" << heap[index] << endl;
    while((index > 0) && (parent(index) >= 0)
    					&& (matrix[parent(index)] > (matrix[index]))){
    	int parentSwap = matrix[parent(index)];
    	matrix[parent(index)] = matrix[index];
    	matrix[index] = parentSwap;
    	index = parent(index);
    }
}

void heap::heapifyDown(int index){
	//cout << "index=" << index << endl;
    //cout << "left(index)=" << left(index) << endl;
    //cout << "right(index)=" << right(index) << endl;
    int child = left(index);
    if((child > 0) && (right(index) > 0) 
    						&& (matrix[child] > matrix[right(index)])){
    	child = right(index);
    }
    if(child > 0){
    	int childSwap = matrix[index];
    	matrix[index] = matrix[child];
    	matrix[child] = childSwap;
    	heapifyDown(child);
    }
}

//------??-------
int heap::left(int parent){
	int i = (parent << 1) + 1; // 2 * parent + 1
	return (i < matrix.size());
}
int heap::right(int parent){
	int i = (parent << 1) + 2; // 2 * parent + 2
}
int heap::parent(int child){
	if (child != 0){
		int i = (child - 1) >> 1;
		return i;
	}
	return -1;
}
//---------------

bool heap::empty(){
	if (matrix.size() == 0){ //empty heap
		return true;
	}
	return false;
}

void heap::print(){
	vector<int>::iterator scan = matrix.begin();
    cout << "Heap contents = ";
    while (scan != matrix.end() ) {
        cout << *scan << " ";
        ++scan;
    }
    cout << endl;
}
