// 
//


#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void ranDom(char[], int[], int, int);
void you(char[], int[], int, int, char);
bool ThereIs(int[], int);
bool winner(const char[], int, int, char);
void screen(const char[], int);

int main()
{
	char a[9] = {};
	for (int i = 0; i < 9; i++) {
		a[i] = i + 49;
	}
	cout << "1 PLAYER PRESS (1) "<<endl<<"2 PLAYER PRESS (2) " << endl;
	int swiTch;
	cin >> swiTch;
	if (swiTch == 1) { //play with PC
		int ranD[9] = {};
		for (int turn = 0; turn < 9; turn++) {
			if (turn % 2 == 0 || turn == 0)
				ranDom(a, ranD, 9, turn);
			else
				you(a, ranD, 9, turn, 'X');
			screen(a, turn);
			if (winner(a, 9, turn, 'X') == true) {
				system("pause");
				return 0;
			}
			if (turn == 8) {
				if (winner(a, 9, turn, 'X') != true) {
					cout << "	THERE IS NO WINNER " << endl;
					system("pause");
					return 0;
				}
			}
			if (winner(a, 9, turn, 'O') == true) {
				system("pause");
				return 0;
			}
		}
	}

	else if (swiTch == 2) {
		screen(a, 0);
		cout << "	FIRST PLAYER IS O " << endl;
		int ranD[9] = {};
		for (int turn = 0; turn < 9; turn++) {
			if (turn % 2 == 0 || turn == 0)
				you(a, ranD, 9, turn, 'O');
			else
				you(a, ranD, 9, turn, 'X');
			screen(a, turn);
			if (winner(a, 9, turn, 'X') == true || winner(a, 9, turn, 'O') == true) {
				system("pause");
				return 0;
			}
			if (turn == 8) {
				if (winner(a, 9, turn, 'X') != true) {
					cout << "	THERE IS NO WINNER " << endl;
					system("pause");
					return 0;
				}
			}
		}
	}
	else
		exit(0);
}

void you(char a[], int ranD[], int l, int turn, char u) {
	cout << "	YOUR TURN : ";
	int y;
	cin >> y;
	if (a[y-1] <'1' || a[y-1]>'9') {
		cout << "PLEASE CHOOSE ANOTHER NUMBER : ";
		cin >> y;
	}	
	a[y - 1] = u;
	ranD[turn] = y - 1;
}

bool ThereIs(int ranD[], int randnum) {
	for (int i = 0; i < 9; i++) {
		if (randnum == ranD[i])
			return true;
	}
	return false;
}

void ranDom(char a[], int ranD[], int l, int turn) {
	srand(time(0));
	int randnum = rand() % 9;
	if (turn == 8) {
		for (int i = 0; i < 9; i++) 
			if (a[i] >= '1' && a[i] <= '9') 
				a[i] = 'O';
	}
	else {
		if (ThereIs(ranD, randnum) == false) {
			a[randnum] = 'O';
			ranD[turn] = randnum;
		}
		else {
			while (ThereIs(ranD, randnum) == true) {
				randnum = rand() % 9;
			}
			a[randnum] = 'O';
			ranD[turn] = randnum;
		}
	}
}

bool winner(const char a[], int l,int turn,char u) {
	if (a[0] == a[1] && a[1] == a[2]) {
		if (a[0] == u) {
			cout << '\t' << u << " WON !! " << endl;
			return true;
		}
	}
		
	else if (a[3] == a[4] && a[4] == a[5]) {
		if (a[3] == u) {
			cout << '\t' << u << " WON !! " << endl;
			return true;
		}
	}
	else if (a[6] == a[7] && a[7] == a[8]) {
		if (a[6] == u) {
			cout << '\t' << u << " WON !! " << endl;
			return true;
		}
	}
	else if (a[0] == a[3] && a[3] == a[6]) {
		if (a[0] == u) {
			cout << '\t' << u << " WON !! " << endl;
			return true;
		}
	}
	else if (a[1] == a[4] && a[4] == a[7]) {
		if (a[1] == u) {
			cout << '\t' << u << " WON !! " << endl;
			return true;
		}
	}
	else if (a[2] == a[5] && a[5] == a[8]) {
		if (a[2] == u) {
			cout << '\t' << u << " WON !! " << endl;
			return true;
		}
	}
	else if (a[0] == a[4] && a[4] == a[8]) {
		if (a[0] == u) {
			cout << '\t' << u << " WON !! " << endl;
			return true;
		}
	}
	else if (a[2] == a[4] && a[4] == a[6]) {
		if (a[2] == u) {
			cout << '\t' << u << " WON !! " << endl;
			return true;
		}
	}
	else
		return false;
}

void screen(const char a[],int turn) {
	system("cls");
	cout << "	TURN : " << turn+1 << endl;
	cout << "\t" << char(201) << char(205) << char(205) << char(205) << char(205) << char(203);//first line
	cout << char(205) << char(205) << char(205) << char(205) << char(203);
	cout << char(205) << char(205) << char(205) << char(205) << char(187) << endl;//end of first line
	
	cout << "\t" << char(186) << " " << a[0] << "  " << char(186) << " " << a[1] << "  " << char(186) << " " << a[2] << "  " << char(186) << endl;
	
	cout << "\t" << char(204) << char(205) << char(205) << char(205) << char(205) << char(206);//second line
	cout << char(205) << char(205) << char(205) << char(205) << char(206);
	cout << char(205) << char(205) << char(205) << char(205) << char(185) << endl;//end of second line
	
	cout << "\t" << char(186) << " " << a[3] << "  " << char(186) << " " << a[4] << "  " << char(186) << " " << a[5] << "  " << char(186) << endl;
	
	cout << "\t" << char(204) << char(205) << char(205) << char(205) << char(205) << char(206);//third line
	cout << char(205) << char(205) << char(205) << char(205) << char(206);
	cout << char(205) << char(205) << char(205) << char(205) << char(185) << endl;//end of third line

	cout << "\t" << char(186) << " " << a[6] << "  " << char(186) << " " << a[7] << "  " << char(186) << " " << a[8] << "  " << char(186) << endl;

	cout << "\t" << char(200) << char(205) << char(205) << char(205) << char(205) << char(202);//4th line
	cout << char(205) << char(205) << char(205) << char(205) << char(202);
	cout << char(205) << char(205) << char(205) << char(205) << char(188) << endl;//end of 4th line
}