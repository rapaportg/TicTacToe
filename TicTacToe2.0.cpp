#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <cmath>

using namespace std;

struct Board{
	char a;
	char b;
	char c;
	char d;
	char e;
	char f;
	char g;
	char h;
	char i;
	
};


class Game{
	private:
		string test;
		
	public:
		Board Pos;
	
		void setMove(int x , char player){
			if (x == 1){
				Pos.a = player;
			}
			if (x == 2){
				Pos.b = player;
			}
			if (x == 3){
				Pos.c = player;
			}
			if (x == 4){
				Pos.d = player;
			}
			if (x == 5){
				Pos.e = player;
			}
			if (x == 6){
				Pos.f = player;
			}
			if (x == 7){
				Pos.g = player;
			}
			if (x == 8){
				Pos.h = player;
			}
			if (x == 9){
				Pos.i = player;
			}
		}
		
		bool validMove(int x){
			if (x == 1){
				if (isdigit(Pos.a) && (Pos.a != 'X' && Pos.a !='O')){
					return false;
				}
			}
			if (x == 2){
				if (isdigit(Pos.b) && (Pos.b != 'X' && Pos.b !='O')){
					return false;
				}
			}
			if (x == 3){
				if (isdigit(Pos.c) && (Pos.c != 'X' && Pos.c !='O')){
					return false;
				}
			}
			if (x == 4){
				if (isdigit(Pos.d) && (Pos.d != 'X' && Pos.d !='O')){
					return false;
				}
			}
			if (x == 5){
				if (isdigit(Pos.e) && (Pos.e != 'X' && Pos.e !='O')){
					return false;
				}
			}
			if (x == 6){
				if (isdigit(Pos.f) && (Pos.f != 'X' && Pos.f !='O')){
					return false;
				}
			}
			if (x == 7){
				if (isdigit(Pos.g) && (Pos.g != 'X' && Pos.g !='O')){
					return false;
				}
			}
			if (x == 8){
				if (isdigit(Pos.h) && (Pos.h != 'X' && Pos.h !='O')){
					return false;
				}
			}
			if (x == 9){
				if (isdigit(Pos.i) && (Pos.i != 'X' && Pos.i !='O')){
					return false;
				}
			}else{
				return true;
			}
		}
		bool isWinner(){
			if (Pos.a = 'X' && Pos.b == 'X' && Pos.c == 'X'){
				cout << endl << "Player 1 is the Winner!"<< endl;
				return false;
			}
			if (Pos.d == 'X' && Pos.e == 'X' && Pos.f == 'X'){
				cout << endl << "Player 1 is the Winner!" << endl;
				return false;
			}
			if (Pos.g == 'X' && Pos.h == 'X' && Pos.i == 'X'){
				cout << endl << "Player 1 is there Winner!" << endl;
				return false;
			}
			if (Pos.a == 'X' && Pos.d == 'X' && Pos.g == 'X'){
				cout <<endl << "Player 1 is there Winner!" << endl;
				return false; 
			}
			if (Pos.b == 'X' && Pos.e == 'X' && Pos.h == 'X'){
				cout <<endl << "Player 1 is there Winner!" << endl;
				return false; 
			}
			if (Pos.c == 'X' && Pos.f == 'X' && Pos.i == 'X'){
				cout <<endl << "Player 1 is there Winner!" << endl;
				return false; 
			}
			if (Pos.a == 'X' && Pos.e == 'X' && Pos.i == 'X'){
				cout <<endl << "Player 1 is there Winner!" << endl;
				return false; 
			}
			if (Pos.c == 'X' && Pos.e == 'X' && Pos.g == 'X'){
				cout <<endl << "Player 1 is there Winner!" << endl;
				return false; 
			}
			////////////////////////////////////////////////////////////////
			if (Pos.a = 'O' && Pos.b == 'O' && Pos.c == 'O'){
				cout << endl << "Player 2 is the Winner!"<< endl;
				return false;
			}
			if (Pos.d == 'O' && Pos.e == 'O' && Pos.f == 'O'){
				cout << endl << "Player 2 is the Winner!" << endl;
				return false;
			}
			if (Pos.g == 'O' && Pos.h == 'O' && Pos.i == 'O'){
				cout << endl << "Player 2 is there Winner!" << endl;
				return false;
			}
			if (Pos.a == 'O' && Pos.d == 'O' && Pos.g == 'O'){
				cout <<endl << "Player 2 is there Winner!" << endl;
				return false; 
			}
			if (Pos.b == 'O' && Pos.e == 'O' && Pos.h == 'O'){
				cout <<endl << "Player 2 is there Winner!" << endl;
				return false; 
			}
			if (Pos.c == 'O' && Pos.f == 'O' && Pos.i == 'O'){
				cout <<endl << "Player 2 is there Winner!" << endl;
				return false; 
			}
			if (Pos.a == 'O' && Pos.e == 'O' && Pos.i == 'O'){
				cout <<endl << "Player 2 is there Winner!" << endl;
				return false; 
			}
			if (Pos.c == 'O' && Pos.e == 'O' && Pos.g == 'O'){
				cout <<endl << "Player 2 is there Winner!" << endl;
				return false; 
			}else{ 
				return true;
			}
		}
			
			
		void displayGrid(){
			cout << endl
				   <<"       " << Pos.a << "   |   " << Pos.b << "   |   " << Pos.c<< endl
				   <<"     ..... + ..... + ..... " << endl
				   <<"       " << Pos.d << "   |   " << Pos.e << "   |   " << Pos.f << endl
				   <<"     ..... + ..... + ..... "<< endl
				   <<"       " << Pos.g << "   |   " << Pos.h << "   |   " << Pos.i << endl << endl;
		}
};
int main(){
	bool check1 = true;
	int count = 0;
	int move;
	char player;
	cout <<endl<< "Welcome to the Tic-Tac-Toe Game" << endl << endl;
	//cout << "Please choose a game mode, 1 or 2 players (enter 1 or 2): ";
	Game GameBoy;
	GameBoy.Pos.a = '1'; GameBoy.Pos.b = '2'; GameBoy.Pos.c = '3';
	GameBoy.Pos.d = '4'; GameBoy.Pos.e = '5'; GameBoy.Pos.f = '6';
	GameBoy.Pos.g = '7'; GameBoy.Pos.h = '8'; GameBoy.Pos.i = '9';
	GameBoy.displayGrid();

	while (check1){
		if (count%2 == 0){
			bool check2 = true;
			int count2 = 0;
			player = 'X';
			while(check2){
				if (count2 == 0){
					cout << "Player 1 Make Your Move!" << endl;
				}else{
					cout << "Invalid Input! re-enter move" << endl;
				}
				cin >> move;
				cout << endl;
				check2 = GameBoy.validMove(move);
				count2++;
			}
			GameBoy.setMove(move, player);
			GameBoy.displayGrid();	
			check1 = GameBoy.isWinner();
		}
		if (count%2 == 0){
			bool check3 = true;
			int count3 = 0;
			player = 'O';
			while(check3){
				if (count3 == 0){
					cout << "Player 2 Make Your Move!" << endl;
				}else{
					cout << "Invalid Input! re-enter move" << endl;
				}
				cin >> move;
				cout << endl;
				check3 = GameBoy.validMove(move);
				count3++;
			}
			GameBoy.setMove(move, player);
			GameBoy.displayGrid();	
			check1 =GameBoy.isWinner();
		}
	count++;
	}			
}
