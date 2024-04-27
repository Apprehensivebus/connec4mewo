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
		board = board_temp;
	}
	void visualise() { // prints the board to console
		for (int j = 0; j < ysize; j++) {
			cout << endl;
			for (int i = 0; i < xsize; i++) {
				cout << board[i][j];
			}
		}
	}


};

int main()
{
	Boardstate b(5, 5);
	cout << "Hello CMake." << endl;
	b.visualise();
	
	return 0;
}
