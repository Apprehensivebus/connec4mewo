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
	Boardstate(const int x,const int y) {
		vector<vector<int>> board(x,vector<int>(y));
		xsize = x;
		ysize = y;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				board[i][j] = 0;
			}
		}
	}
	void 


};

int main()
{
	Boardstate b(5, 5);
	cout << "Hello CMake." << endl;
	
	return 0;
}
