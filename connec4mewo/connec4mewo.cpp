// connec4mewo.cpp : Defines the entry point for the application.
//

#include "connec4mewo.h"
#include <vector>

using namespace std;

class Boardstate {
public:
	int xsize;
	int ysize;
	int winlength;
	vector<vector<int>> board;
	Boardstate(const int x,const int y, int wl) { //initialises the board with only zeroes in desired sizes
		vector<vector<int>> board_temp(x);
		xsize = x;
		ysize = y;
		winlength = wl;
		for (int i = 0; i < x; i++) {
			board_temp[i]=vector<int>(y);
			for (int j = 0; j < y; j++) { 
				board_temp[i][j] = 0;
			}

		}
		board = board_temp; // could not get it to work without the whole board temp thing
	}
	void visualise() { // prints the board to console
		for (int j = 0; j < ysize; j++) {
			cout << endl;
			for (int i = 0; i < xsize; i++) {
				cout << board[i][j];
			}
		}
		cout << endl;
	}

	bool isFull(int col) { //does not check for out of bounds etc, only for use after checking
		return board[col][0] != 0;
	}

	bool put(int col, int side) { // drop a piece into the board, returns true if success
		if (col < 0 || col >= xsize) {
			return false;
		}
		else if (isFull(col)) {
			return false;
		}
		else {
			for (int i = ysize - 1; i >= 0; i--) {
				if (board[col][i] == 0) {
					board[col][i] = side;
					break;
					return true;
				}
			}
		}
	}

	bool checkFalling(int side) { //Check falling diagonal win
		int chainlength;
		for (int i = xsize - 1; i > winlength-1; i--) {
			for (int j = ysize - 1; j > winlength - 1; j--) {
				chainlength = 0;
				for (int k = 0; k < winlength; k++) {
					if (board[i - k][j - k] == side) {
						chainlength++;
						if (chainlength == winlength) {
							cout << "win detected falling diagonal" << endl;
							return true;
						}
					}
					else {
						break;
					}
				}
			}
		}
		return false;
	}

	bool checkRising(int side) { //Check rising diagonal win
		int chainlength;
		for (int i = 0; i < xsize-winlength; i++) {
			for (int j = ysize - 1; j > winlength - 1; j--) {
				chainlength = 0;
				for (int k = 0; k < winlength; k++) {
					if (board[i + k][j-k] == side) {
						chainlength++;
						if (chainlength == winlength) {
							cout << "win detected rising diagonal" << endl;
							return true;
						}
					}
					else {
						break;
					}
				}
			}
		}
		return false;
	}

	bool checkHorizontal(int side) { // Check horizontal win
		int chainlength;
		for (int i = xsize - 1; i >= winlength - 1; i--) {
			for (int j = 0; j < ysize; j++) {
				chainlength = 0;
				for (int k = 0; k < winlength; k++) {
					if (board[i-k][j] == side) {
						chainlength++;
						if (chainlength == winlength) {
							cout << "win detected horizontal" << endl;
							return true;
						}
					}
					else {
						break;
					}
				}
			}
		}
		return false;
	}

	bool checkVertical(int side) { //Check vertical win
		int chainlength;
		for (int i = ysize - 1; i >= winlength - 1; i--) {
			for (int j = 0; j < xsize; j++) {
				chainlength = 0;
				for (int k = 0; k < winlength; k++) {
					if (board[j][i-k]==side) {
						chainlength++;
						if (chainlength == winlength) {
							cout << "win detected vertical" << endl;
							return true;
						}
					}
					else {
						break;
					}
				}
			}
		}
		return false;
	}

	bool checkWin(int side) { //check for win by checking all win conditions
		return checkVertical(side) || checkHorizontal(side) || checkRising(side) || checkFalling(side);
	}

	int gradeMove(int col, vector<vector<int>> board_t, int side, int depth) { //This is a recursive function that when given the initial move will check all possible consequent moves until a certain depth and grade them
		//if recursion number is 0:
			//check for victory and give score
		//if recursion number is not 0:
			//check all legal moves
			// for all legal modes
				//check each for victory
					//give those with victory score based on remaining depth
				// for all those without victory
					//run grademove with recursion number -1 and side
			//sum scores of each run
		//return score
			
	}

	int selectMove(vector<vector<int>> board_t, int side, int depth) { //this will find all legal moves then start a recursive gradeMove for each
		// check all legal moves
		//for all legal moves
			//run grademove with desired recursion number and side
	}


	

};

int main()
{
	cout << boolalpha;
	Boardstate b(7, 6, 4);
	cout << "mewo" << endl;
	b.visualise();
	
	
	
	return 0;
}
