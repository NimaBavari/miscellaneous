#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

char board [] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
bool isGame = true;

void drawBoard () {
	cout << " --- --- --- " << endl;
	cout << "|-" << board [0] << "-|-" << board [1] << "-|-" << board [2] << "-|" << endl;
	cout << " --- --- --- " << endl;
	cout << "|-" << board [3] << "-|-" << board [4] << "-|-" << board [5] << "-|" << endl;
	cout << " --- --- --- " << endl;
	cout << "|-" << board [6] << "-|-" << board [7] << "-|-" << board [8] << "-|" << endl;
	cout << " --- --- --- " << endl;
}

void playAgain () {
	for (int i = 0; i < 9; ++i) {
		board [i] = i + 1 + '0';
	}
	isGame = true;
}

void checkGameStatus () {
	int counter = 0;

	if ((board [0] == board [1] && board [0] == board [2] && board [0] == 'O')
		||	(board [3] == board [4] && board [3] == board [5] && board [3] == 'O')
		||	(board [6] == board [7] && board [6] == board [8] && board [6] == 'O')
		||	(board [0] == board [3] && board [0] == board [6] && board [0] == 'O')
		||	(board [1] == board [4] && board [1] == board [7] && board [1] == 'O')
		||	(board [2] == board [5] && board [2] == board [8] && board [2] == 'O')
		||	(board [0] == board [4] && board [0] == board [8] && board [0] == 'O')
		||	(board [2] == board [4] && board [2] == board [6] && board [2] == 'O')) {
		isGame = false;
		cout << "Computer won!" << endl;
	} else if ((board [0] == board [1] && board [0] == board [2] && board [0] == 'X')
		||	(board [3] == board [4] && board [3] == board [5] && board [3] == 'X')
		||	(board [6] == board [7] && board [6] == board [8] && board [6] == 'X')
		||	(board [0] == board [3] && board [0] == board [6] && board [0] == 'X')
		||	(board [1] == board [4] && board [1] == board [7] && board [1] == 'X')
		||	(board [2] == board [5] && board [2] == board [8] && board [2] == 'X')
		||	(board [0] == board [4] && board [0] == board [8] && board [0] == 'X')
		||	(board [2] == board [4] && board [2] == board [6] && board [2] == 'X')) {
		isGame = false;
		cout << "You won!" << endl;
	} else {
		for (int i = 0; i < 9; ++i) {
			if (board [i] == 'X' || board [i] == 'O') {
				++counter;
			}
		}

		if (counter == 9) {
			isGame = false;
			cout << "Draw!" << endl;
		}
	}
}

void userTurn () {
	int n;

	drawBoard ();
	cout << "Your turn. Enter a number: ";
	cin >> n;

	while (n < 1 || n > 9 || board [n - 1] == 'X' || board [n - 1] == 'O') {
		cout << "Please enter a legal move: ";
		cin >> n;
	}

	board [n - 1] = 'X';
}

void compTurn () {
	vector<int> availMovs;
	int r, m;

	drawBoard ();

	cout << "Computer's turn..." << endl;
	if (board [0] == 'X' && board [1] == 'X' && board [2] != 'X' && board [2] != 'O') {
		board [2] = 'O';
	} else if (board [0] == 'X' && board [2] == 'X' && board [1] != 'X' && board [1] != 'O') {
		board [1] = 'O';
	} else if (board [1] == 'X' && board [2] == 'X' && board [0] != 'X' && board [0] != 'O') {
		board [0] = 'O';
	} else if (board [3] == 'X' && board [4] == 'X' && board [5] != 'X' && board [5] != 'O') {
		board [5] = 'O';
	} else if (board [3] == 'X' && board [5] == 'X' && board [4] != 'X' && board [4] != 'O') {
		board [4] = 'O';
	} else if (board [4] == 'X' && board [5] == 'X' && board [3] != 'X' && board [3] != 'O') {
		board [3] = 'O';
	} else if (board [6] == 'X' && board [7] == 'X' && board [8] != 'X' && board [8] != 'O') {
		board [8] = 'O';
	} else if (board [6] == 'X' && board [8] == 'X' && board [7] != 'X' && board [7] != 'O') {
		board [7] = 'O';
	} else if (board [7] == 'X' && board [8] == 'X' && board [1] != 'X' && board [1] != 'O') {
		board [6] = 'O';
	} else if (board [0] == 'X' && board [3] == 'X' && board [6] != 'X' && board [6] != 'O') {
		board [6] = 'O';
	} else if (board [0] == 'X' && board [6] == 'X' && board [3] != 'X' && board [3] != 'O') {
		board [3] = 'O';
	} else if (board [3] == 'X' && board [6] == 'X' && board [0] != 'X' && board [0] != 'O') {
		board [0] = 'O';
	} else if (board [1] == 'X' && board [4] == 'X' && board [7] != 'X' && board [7] != 'O') {
		board [7] = 'O';
	} else if (board [1] == 'X' && board [7] == 'X' && board [4] != 'X' && board [4] != 'O') {
		board [4] = 'O';
	} else if (board [4] == 'X' && board [7] == 'X' && board [1] != 'X' && board [1] != 'O') {
		board [1] = 'O';
	} else if (board [2] == 'X' && board [5] == 'X' && board [8] != 'X' && board [8] != 'O') {
		board [8] = 'O';
	} else if (board [2] == 'X' && board [8] == 'X' && board [5] != 'X' && board [5] != 'O') {
		board [5] = 'O';
	} else if (board [5] == 'X' && board [8] == 'X' && board [2] != 'X' && board [2] != 'O') {
		board [2] = 'O';
	} else if (board [0] == 'X' && board [4] == 'X' && board [8] != 'X' && board [8] != 'O') {
		board [8] = 'O';
	} else if (board [0] == 'X' && board [8] == 'X' && board [4] != 'X' && board [4] != 'O') {
		board [4] = 'O';
	} else if (board [4] == 'X' && board [8] == 'X' && board [0] != 'X' && board [0] != 'O') {
		board [0] = 'O';
	} else if (board [2] == 'X' && board [4] == 'X' && board [6] != 'X' && board [6] != 'O') {
		board [6] = 'O';
	} else if (board [2] == 'X' && board [6] == 'X' && board [4] != 'X' && board [4] != 'O') {
		board [4] = 'O';
	} else if (board [4] == 'X' && board [6] == 'X' && board [2] != 'X' && board [2] != 'O') {
		board [2] = 'O';
	} else if (board [4] == 'X') {
		if (board [0] != 'X' && board [0] != 'O') {
			board [0] = 'O';
		} else if (board [2] != 'X' && board [2] != 'O') {
			board [2] = 'O';
		} else if (board [6] != 'X' && board [6] != 'O') {
			board [6] = 'O';
		} else if (board [8] != 'X' && board [8] != 'O') {
			board [8] = 'O';
		} else {
			for (int i = 0; i < 9; ++i) {
				if (board [i] != 'X' && board [i] != 'O') {
					availMovs.push_back(i+1);
				}
			}
	
			r = rand () % availMovs.size ();
			m = availMovs [r];
	
			board [m - 1] = 'O';
		}
	} else {
		for (int i = 0; i < 9; ++i) {
			if (board [i] != 'X' && board [i] != 'O') {
				availMovs.push_back(i+1);
			}
		}

		r = rand () % availMovs.size ();
		m = availMovs [r];

		board [m - 1] = 'O';
	}
}

void togglePlayer () {
	system("cls");
	checkGameStatus ();
	if (isGame) {
		userTurn ();
		checkGameStatus ();
		if (isGame) {
			compTurn ();
		}
	}
}

void playGame () {
	togglePlayer ();
	drawBoard ();
}

int main () {
	char c;

	do {
		system("cls");
		cout << "\tTIC TAC TOE" << endl;
		while (isGame) {
			playGame ();
		}

		cout << "Press any key to play again, x to exit: ";
		cin >> c;
		playAgain ();
	} while (c != 'x' && c != 'X');

	return 0;
}
