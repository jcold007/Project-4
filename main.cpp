/*
 Ivan Coronel - Project 4
*/

 /*
main.cpp Class: Used to handle the game. This is where an initial board is set, 
				then corrected and played
	... 
 */

#include <iostream>
#include <string>
#include <vector>
#include "heap.h"
#include "board.h"
using namespace std;

/*
Function used to run the program. Initial board is set then other functions are
called to order the game board. 
*/
int main(){
	cout << "test" << endl;
	vector<int> initBoard;
	initBoard.push_back(2);
	initBoard.push_back(6);
	initBoard.push_back(1);
	initBoard.push_back(0);
	initBoard.push_back(7);
	initBoard.push_back(8);
	initBoard.push_back(3);
	initBoard.push_back(5);
	initBoard.push_back(4);
	cout << "test" << endl;
	board gameBoard(initBoard);
	
	cout << "test1" << endl;
	gameBoard.getNeighbors();
	//cout << "test2" << endl;
	//gameBoard.printBoard();

	// for(vector<int>::iterator scanner = initBoard.begin()+1;
	// 			scanner != initBoard.end(); scanner++){
	// 	cout << initBoard[scanner] << endl;
	// }

	//gameBoard.printNeighbors();
	//gameBoard.score();
	//gameBoard.BFS(gameBoard);
}
