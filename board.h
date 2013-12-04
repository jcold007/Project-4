/*
 Ivan Coronel - Project 4
*/

 /*
board.h Class: intializations for the board class.
	... 
 */

#ifndef BOARD
#define BOARD
#include <iostream>
#include <vector>
using namespace std;

class board{
private:
	int zeroLocation;							//variable for the zero location
	vector<int> theBoard;						//vector storage to represent board
public:
	void BFS(board gameBoard);					//Best-first-search chooses the best move
	void printBoard();							//print function
	void swapLocation(int &first, int &second);	//swap function
	board(vector<int> theBoard);				//constructor 
	board(const board &theOtherBoard);			//constructor 
	//int buildPermutations();
	vector<board> getNeighbors();				//vector of boards to get neighbors
	void printNeighbors();						//prints the neighbors
	int score();								//function for the score
	bool operator< (board &compareMe);			//less-than operator
	bool operator== (board &compareMe);			//equals operator
	bool notSeen(board a, board b);				//check function
};
#endif
