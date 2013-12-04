/*
 Ivan Coronel - Project 4
*/

 /*
heap.cpp Class: Class that is used for the search of the most efficient move for 
                the board to take
	... 
 */

#include <iostream>
#include <vector>
#include <fstream> //print files
#include "heap.h"
using namespace std;

/*
Function to delele the minimum value in the tree. When the function deletes the 
minimum value, the function calls heapifyDown in order to update the tree.
*/
int heap::deleteMin(){
	int min = matrix.front();
	matrix[0] = matrix.at(matrix.size() - 1);
	matrix.pop_back();
	heapifyDown(0);
	return min;
}

/*
Function that inserts an element. When the element in iserted, the tree is
updated by using the heapifyUp function.
*/
void heap::insert(int element){
	matrix.push_back(element);
	heapifyUp(matrix.size() - 1);
}

/*
Funtion used to move and manipulate the heap tree. This funtion serves to move
elements to a higher level
*/
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

/*
Funtion used to move and manipulate the heap tree. This funtion serves to move
elements to a lower level
*/
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

/*
Function to represent the left child of the tree. Used as tool to update and 
represent values in the heap tree
*/
int heap::left(int parent){
	int i = (parent << 1) + 1; // 2 * parent + 1
	return (i < matrix.size());
}

/*
Function to represent the right child of the tree. Used as tool to update and 
represent values in the heap tree
*/
int heap::right(int parent){
	int i = (parent << 1) + 2; // 2 * parent + 2
}

/*
Function to represent the parent values of the tree. The parent represents 
the values above both the left and right children used as tool to update and 
represent values in the heap tree
*/
int heap::parent(int child){
	if (child != 0){
		int i = (child - 1) >> 1;
		return i;
	}
	return -1;
}

/*
Boolean function that serves to determine if the heap is empty or not.
*/
bool heap::empty(){
	if (matrix.size() == 0){ //empty heap
		return true;
	}
	return false;
}

/*
Print function, prints the heap contents
*/
void heap::print(){
	vector<int>::iterator scan = matrix.begin();
    cout << "Heap contents = ";
    while (scan != matrix.end() ) {
        cout << *scan << " ";
        ++scan;
    }
    cout << endl;
}
