/*
 Ivan Coronel - Project 4
*/

 /*
board.h Class:
	... 
 */

#ifndef BOARD
#define BOARD
#include <iostream>
#include <vector>
using namespace std;

class board{
private:
	int zeroLocation;
	vector<int> theBoard;
public:
	void BFS(board gameBoard);
	void printBoard();
	void swapLocation(int &first, int &second);
	board(vector<int> theBoard);
	board(const board &theOtherBoard);
	//int buildPermutations();
	vector<board> getNeighbors();
	void printNeighbors();
	int score();
	bool operator< (board &compareMe);
	bool operator== (board &compareMe);
	bool notSeen(board a, board b);
};
#endif
