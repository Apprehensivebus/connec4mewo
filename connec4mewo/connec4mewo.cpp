// connec4mewo.cpp : Defines the entry point for the application.
//

#include "connec4mewo.h"
#include <vector>

using namespace std;

class Boardstate {
public:
	int xsize;
	int ysize;
	vector<vector<int>> board;
	Boardstate(const int x,const int y) { //initialises the board with only zeroes in desired sizes
		vector<vector<int>> board_temp(x);
		xsize = x;
		ysize = y;
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

	bool put(int col, int side) {
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


};

int main()
{
	cout << boolalpha;
	Boardstate b(4, 3);
	cout << "Hello CMake." << endl;
	b.visualise();
	b.put(2, 1); 

	b.visualise();
	
	
	return 0;
}
