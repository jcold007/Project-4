/*
 Ivan Coronel - Project 4
*/

 /*
board.cpp Class: Class used to serve to build and construct the game board. This
				is also where the the best move is determined and used.
	... 
 */

#include <iostream>
#include <vector>
#include <fstream> //print files
#include "board.h"
#include "heap.h"
using namespace std;

//vector<int> initial;
//vector<int> current; -> theBoard
vector<board> neighbors;
vector<board> previousBoards;
int currentScore;

/*
A constructor that is given a vector of integers. The zero location
is tracked, since this represents the empty space
*/
board::board(vector<int> startBoard){ //, int zeroLocation){
	theBoard = startBoard;
	//tracks zero location
	if(startBoard.size() > 1){
		for(int i = 0; i < theBoard.size(); i++){
			if (theBoard[i] == 0){
				zeroLocation = i;
			}
		}
	}
	cout << "Zero Location:" << zeroLocation << endl;
}

/*
Copy constructor that creates a copy of the inital board
*/
board::board(const board &copyBoard){
	theBoard = copyBoard.theBoard;
}

//board::buildPermutations(){

/*
Swap function that serves to switch the locations of two elemets
in the board
*/
void board::swapLocation(int &prevLocation, int &newLocation){
	int swapper = prevLocation;
	prevLocation = newLocation;
	newLocation = swapper;
}

void board::printBoard(){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cout << " " << theBoard[i*3 + j] << " ";
		}
		cout << endl;
	}
}

/*
Function serves to fetch the other board possibilities given an initial board.
*/
vector<board> board::getNeighbors(){
	cout << "test" << endl;
	vector<int> theNeighbors = theBoard;
	//vector<board> neighbors;
	int moveZero = zeroLocation;
	//--center--
	if (zeroLocation < 6){ //moves down
		moveZero = theNeighbors[zeroLocation + 3];
		theNeighbors[zeroLocation] = moveZero;
		theNeighbors[zeroLocation + 3] = 0;
		board neighbor(theNeighbors);
		neighbors.push_back(neighbor);
		theNeighbors = theBoard;
		cout << theNeighbors[0] << " " << theNeighbors[1] << " " << 
		theNeighbors[2] << " " << theNeighbors[3] << " " << theNeighbors[4] <<
		" " << theNeighbors[5] << " " << theNeighbors[6] << " " << 
		theNeighbors[7] << " " << theNeighbors[8] << endl;
	}
	if (zeroLocation > 2){ //moves up
		moveZero = theNeighbors[zeroLocation - 3];
		theNeighbors[zeroLocation] = moveZero;
		theNeighbors[zeroLocation - 3] = 0;
		board neighbor(theNeighbors);
		neighbors.push_back(neighbor);
		theNeighbors = theBoard;
		cout << theNeighbors[0] << " " << theNeighbors[1] << " " << 
		theNeighbors[2] << " " << theNeighbors[3] << " " << theNeighbors[4] <<
		" " << theNeighbors[5] << " " << theNeighbors[6] << " " << 
		theNeighbors[7] << " " << theNeighbors[8] << endl;
	}
	if ((zeroLocation + 1) % 3 != 0){ //moves right
		moveZero = theNeighbors[zeroLocation + 1];
		theNeighbors[zeroLocation] = moveZero;
		theNeighbors[zeroLocation + 1] = 0;
		board neighbor(theNeighbors);
		neighbors.push_back(neighbor);
		theNeighbors = theBoard;
		cout << theNeighbors[0] << " " << theNeighbors[1] << " " << 
		theNeighbors[2] << " " << theNeighbors[3] << " " << theNeighbors[4] <<
		" " << theNeighbors[5] << " " << theNeighbors[6] << " " << 
		theNeighbors[7] << " " << theNeighbors[8] << endl;
	}
	if ((zeroLocation + 1) % 3 == 0){ //moves right
		moveZero = theNeighbors[zeroLocation - 1];
		theNeighbors[zeroLocation] = moveZero;
		theNeighbors[zeroLocation - 1] = 0;
		board neighbor(theNeighbors);
		neighbors.push_back(neighbor);
		theNeighbors = theBoard;
		cout << theNeighbors[0] << " " << theNeighbors[1] << " " << 
		theNeighbors[2] << " " << theNeighbors[3] << " " << theNeighbors[4] <<
		" " << theNeighbors[5] << " " << theNeighbors[6] << " " << 
		theNeighbors[7] << " " << theNeighbors[8] << endl;
	}
	return neighbors;
}

/*
Function that prints the neighbors
*/
void board::printNeighbors(){
	// cout << neighbors[0] << " " << neighbors[1] << " " 
	// 	<< neighbors[2] << " " << neighbors[3] << " "
	// 	<< neighbors[4] << " " << neighbors[5] << " "
	// 	<< neighbors[6] << " " << neighbors[7] << " "
	// 	<< neighbors[8] << endl;

	// board neighbor(theBoard);
	// neighbor.getNeighbors();
	// for (int i = 0; i < 3; i++){
	// 	for (int j = 0; j < 3; j++){
	// 		cout << " " << theBoard[i*3 + j] << " ";
	// 	}
	// cout << endl;
	// }
}

/*
Function that gives a given board a score.
*/
int board::score(){
	int boardScore = 0;
	for(int i = 0; i < theBoard.size(); i++){
		if (theBoard[i]-1 != i){ //wrong spot
			boardScore++;
		}
	}
	cout << "Score:" << boardScore << endl;
	return boardScore;
}

/*
Less-than operator
*/
bool board::operator< (board &compareMe){
	if (compareMe.score() < score()){
		return true;
	} else {
	return false;
	}
}

/*
Greater-than operator
*/
bool board::operator== (board &compareMe){
	if (compareMe.theBoard == theBoard){
		return true;
	} else {
	return false;
	}
}

/*
Function that serves to check if the board has already been seen. In other words,
this helps scan to not move backwards. If the board has been seen in the vector,
it would get skip to the next board. 
*/
// bool board::notSeen(board one, board two){
// 	vector<board> board1 = one.theBoard;
// 	vector<board> board2 = two.theBoard;
// 	for (int i = 0; i < theBoard.size(); i++){
// 		if (board1[i] != board2[i]){
// 			return false; //not seen
// 		}
// 	}
// 	return true;
// }

/*
Best first search. This function is (supposed) to find the best move to take.
This function utilizes the heap class in order to organize the boards in the
tree and to easily choose the next best move
*/
// void board::BFS(board parentBoard)
// {
// 	//board aBoard(parentBoard);
// 	int moves = 0;
// 	parentBoard.getNeighbors();
// 	heap<board> heapSearch;
//     for (int i = 0; i < neighbors.size(); ++i){
//     	heapSearch.insert(neighbors[i]);
//     }
//     while(currentScore != 0){
//     	if(moves > 100){
//     		board best = heapSearch.deleteMin(); //(heapSearch.deleteMin().currentState);
//     		// best = heapSearch.deleteMin();
//     		best.getNeighbors();
//     		previousBoards.push_back(best);
//     		for (int i = 0; i < neighbors.size(); ++i){
//     			if(notSeen(neighbors[i]) == false){
//     				heapSearch.insert(neighbors[i]);
//     			}
//     		}
//     		moves = moves + 1;
//     	}
//     }
// }

