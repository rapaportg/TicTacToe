#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <cmath>
#include <cstring>

using namespace std;



struct Board{ // saves all 81 locations of board
	string a1,a2,a3,a4,a5,a6,a7,a8,a9;
	string b1,b2,b3,b4,b5,b6,b7,b8,b9;
	string c1,c2,c3,c4,c5,c6,c7,c8,c9;
	string d1,d2,d3,d4,d5,d6,d7,d8,d9;
	string e1,e2,e3,e4,e5,e6,e7,e8,e9;
	string f1,f2,f3,f4,f5,f6,f7,f8,f9;
	string g1,g2,g3,g4,g5,g6,g7,g8,g9;
	string h1,h2,h3,h4,h5,h6,h7,h8,h9;
	string i1,i2,i3,i4,i5,i6,i7,i8,i9;	

};
bool find(int numberToCheck, vector <int> PlayerWin){ // used by winGame function to look through PlayerWin vectors
	//cout << "Running Find Function\n";
	for (unsigned i = 0; i < PlayerWin.size(); i ++){
		if (PlayerWin[i] == numberToCheck){
			//cout << "True Case found\n";
			return true;
		}
	}
	return false;
}
void colorAdd(string k){ // adds color to the board to make the game easier to follow
	if (k.compare("X.")==0){
		cout << BOLDRED << "X." << RESET;
	}
	if (k.compare("O.")==0){
		cout << BOLDBLUE << "O." << RESET;
	}
	if ((k.compare("012345678901234567890")==1) || (k.compare("1.") == 1) || (k.compare("2.") == 1) || (k.compare("3.") == 1) || (k.compare("4.") == 1) || (k.compare("5.") == 1) || (k.compare("6.") == 1) || (k.compare("7.") == 1) || (k.compare("8.") == 1) || (k.compare("9.") == 1)){
		cout << BOLDWHITE << k << RESET;
	}
}
class Game{
	private:
		string test;
		vector <int> Player1Win;
		vector <int> Player2Win;
		
	public:
		Board Pos;
		/*
		void debug(){
			for (unsigned u = 0; u<Player1Win.size(); u++){
				cout  << BOLDMAGENTA<< "\nPlayer1Win: " << Player1Win[u] <<RESET<< endl;
			}
			for (unsigned v = 0; v<Player2Win.size(); v++){
				cout << BOLDMAGENTA << "\nPlayer2Win: " << Player2Win[v] << RESET<< endl;
			}
		}
		*/
		bool deathGrid(int t){ // t is nextGrid input
			
				if (t ==1){
					if ((Pos.a1 == "X." || Pos.a1 == "O.") && (Pos.b1 == "X." || Pos.b1 == "O.") && (Pos.c1 == "X." || Pos.c1 == "O.") && (Pos.a2 == "X." || Pos.a2 == "O.") && (Pos.b2 == "X." || Pos.b2 == "O.") && (Pos.c2 == "X." || Pos.c2 == "O.") && (Pos.a3 == "X." || Pos.a3 == "O.") && (Pos.b3 == "X." || Pos.b3 == "O.") && (Pos.c3 == "X." || Pos.c3 == "O.")){
						return true;
					}else{
						return false;
					}
				}
				if (t ==4){
					if ((Pos.a4 == "X." || Pos.a4 == "O.") && (Pos.b4 == "X." || Pos.b4 == "O.") && (Pos.c4 == "X." || Pos.c4 == "O.") && (Pos.a5 == "X." || Pos.a5 == "O.") && (Pos.b5 == "X." || Pos.b5 == "O.") && (Pos.c5 == "X." || Pos.c5 == "O.") && (Pos.a6 == "X." || Pos.a6 == "O.") && (Pos.b6 == "X." || Pos.b6 == "O.") && (Pos.c6 == "X." || Pos.c6 == "O.")){
						return true;
					}else{
						return false;
					}
				}
				if (t ==7){
					if ((Pos.a7 == "X." || Pos.a7 == "O.") && (Pos.b7 == "X." || Pos.b7 == "O.") && (Pos.c7 == "X." || Pos.c7 == "O.") && (Pos.a8 == "X." || Pos.a8 == "O.") && (Pos.b8 == "X." || Pos.b8 == "O.") && (Pos.c8 == "X." || Pos.c8 == "O.") && (Pos.a9 == "X." || Pos.a9 == "O.") && (Pos.b9 == "X." || Pos.b9 == "O.") && (Pos.c9 == "X." || Pos.c9 == "O.")){
						return true;
					}else{
						return false;
					}
				}
				if (t ==2){
					if ((Pos.d1 == "X." || Pos.d1 == "O.") && (Pos.e1 == "X." || Pos.e1 == "O.") && (Pos.f1 == "X." || Pos.f1 == "O.") && (Pos.d2 == "X." || Pos.d2 == "O.") && (Pos.e2 == "X." || Pos.e2 == "O.") && (Pos.f2 == "X." || Pos.f2 == "O.") && (Pos.d3 == "X." || Pos.d3 == "O.") && (Pos.e3 == "X." || Pos.e3 == "O.") && (Pos.f3 == "X." || Pos.f3 == "O.")){
						return true;
					}else{
						return false;
					}
				}
				if (t ==5){
					if ((Pos.d4 == "X." || Pos.d4 == "O.") && (Pos.e4 == "X." || Pos.e4 == "O.") && (Pos.f4 == "X." || Pos.f4 == "O.") && (Pos.d5 == "X." || Pos.d5 == "O.") && (Pos.e5 == "X." || Pos.e5 == "O.") && (Pos.f5 == "X." || Pos.f5 == "O.") && (Pos.d6 == "X." || Pos.d6 == "O.") && (Pos.e6 == "X." || Pos.e6 == "O.") && (Pos.f6 == "X." || Pos.f6 == "O.")){
						return true;
					}else{
						return false;
					}
				}
				if (t ==8){
					if ((Pos.d7 == "X." || Pos.d7 == "O.") && (Pos.e7 == "X." || Pos.e7 == "O.") && (Pos.f7 == "X." || Pos.f7 == "O.") && (Pos.d8 == "X." || Pos.d8 == "O.") && (Pos.e8 == "X." || Pos.e8 == "O.") && (Pos.f8 == "X." || Pos.f8 == "O.") && (Pos.d9 == "X." || Pos.d9 == "O.") && (Pos.e9 == "X." || Pos.e9 == "O.") && (Pos.f9 == "X." || Pos.f9 == "O.")){
						return true;
					}else{
						return false;
					}
				}
				if (t ==3){
					if ((Pos.g1 == "X." || Pos.g1 == "O.") && (Pos.h1 == "X." || Pos.h1 == "O.") && (Pos.i1 == "X." || Pos.i1 == "O.") && (Pos.g2 == "X." || Pos.g2 == "O.") && (Pos.h2 == "X." || Pos.h2 == "O.") && (Pos.i2 == "X." || Pos.i2 == "O.") && (Pos.g3 == "X." || Pos.g3 == "O.") && (Pos.h3 == "X." || Pos.h3 == "O.") && (Pos.i3 == "X." || Pos.i3 == "O.")){
						return true;
					}else{
						return false;
					}
				}
				if (t ==6){
					if ((Pos.g4 == "X." || Pos.g4 == "O.") && (Pos.h4 == "X." || Pos.h4 == "O.") && (Pos.i4 == "X." || Pos.i4 == "O.") && (Pos.g5 == "X." || Pos.g5 == "O.") && (Pos.h5 == "X." || Pos.h5 == "O.") && (Pos.i5 == "X." || Pos.i5 == "O.") && (Pos.g6 == "X." || Pos.g6 == "O.") && (Pos.h6 == "X." || Pos.h6 == "O.") && (Pos.i6 == "X." || Pos.i6 == "O.")){
						return true;
					}else{
						return false;
					}
				}
				if (t ==9){
					if ((Pos.g7 == "X." || Pos.g7 == "O.") && (Pos.h7 == "X." || Pos.h7 == "O.") && (Pos.i7 == "X." || Pos.i7 == "O.") && (Pos.g8 == "X." || Pos.g8 == "O.") && (Pos.h8 == "X." || Pos.h8 == "O.") && (Pos.i8 == "X." || Pos.i8 == "O.") && (Pos.g9 == "X." || Pos.g9 == "O.") && (Pos.h9 == "X." || Pos.h9 == "O.") && (Pos.i9 == "X." || Pos.i9 == "O.")){
						return true;
					}else{
						return false;
					}
				}else{
					return false;
				}
		}
				
			
				
		bool winGame(){
			//cout << "\n Win Game\n";
			if (find(1, Player1Win) && find(2, Player1Win) && find(3, Player1Win)){
				cout << BOLDRED << "\nPlayer 1 " << BOLDWHITE << "is the Winner!\n\n" << RESET;
				return false;
			}
			if (find(4, Player1Win) && find(5, Player1Win) && find(6, Player1Win)){
				cout << BOLDRED << "\nPlayer 1 " << BOLDWHITE << "is the Winner!\n\n" << RESET;
				return false;
			}
			if (find(7, Player1Win)==1 && find(8, Player1Win) && find(9, Player1Win)){
				cout << BOLDRED << "\nPlayer 1 " << BOLDWHITE << "is the Winner!\n\n" << RESET;
				return false;
			}
			if (find(1, Player1Win) && find(4, Player1Win) && find(7, Player1Win)){
				cout << BOLDRED<< "\nPlayer 1 " << BOLDWHITE << "is the Winner!\n\n" << RESET;
				return false;
			}
			if (find(2, Player1Win) && find(5, Player1Win) && find(8, Player1Win)){
				cout << BOLDRED << "\nPlayer 1 " << BOLDWHITE << "is the Winner!\n\n" << RESET;
				return false;
			}
			if (find(3, Player1Win) && find(6, Player1Win) && find(9, Player1Win)){
				cout << BOLDRED << "\nPlayer 1 " << BOLDWHITE << "is the Winner!\n\n" << RESET;
				return false;
			}
			if (find(1, Player1Win) && find(5, Player1Win) && find(9, Player1Win)){
				cout << BOLDRED << "\nPlayer 1 " << BOLDWHITE << "is the Winner!\n\n" << RESET;
				return false;
			}
			if (find(7, Player1Win) && find(5, Player1Win) && find(3, Player1Win)){
				cout << BOLDRED << "\nPlayer 1 " << BOLDWHITE << "is the Winner!\n\n" << RESET;
				return false;
			}	
			/////////////////////////////////////////////////////////////////////////////////////////////////
			if (find(1, Player2Win) && find(2, Player2Win) && find(3, Player2Win)){
				cout << BOLDBLUE << "\nPlayer 2 " << BOLDWHITE << "is the Winner!\n\n" << RESET;
				return false;
			}
			if (find(4, Player2Win) && find(5, Player2Win) && find(6, Player2Win)){
				cout << BOLDBLUE << "\nPlayer 2 " << BOLDWHITE << "is the Winner!\n\n" << RESET;
				return false;
			}
			if (find(7, Player2Win) && find(8, Player2Win) && find(9, Player2Win)){
				cout << BOLDBLUE << "\nPlayer 2 " << BOLDWHITE << "is the Winner!\n\n" << RESET;
				return false;
			}
			if (find(1, Player2Win) && find(4, Player2Win) && find(7, Player2Win)){
				cout << BOLDBLUE << "\nPlayer 2 " << BOLDWHITE << "is the Winner!\n\n" << RESET;
				return false;
			}
			if (find(2, Player2Win) && find(5, Player2Win) && find(8, Player2Win)){
				cout << BOLDBLUE << "\nPlayer 2 " << BOLDWHITE << "is the Winner!\n\n" << RESET;
				return false;
			}
			if (find(3, Player2Win) && find(6, Player2Win) && find(9, Player2Win)){
				cout << BOLDBLUE << "\nPlayer 2 " << BOLDWHITE << "is the Winner!\n\n" << RESET;
				return false;
			}
			if (find(1, Player2Win) && find(5, Player2Win) && find(9, Player2Win)){
				cout << BOLDBLUE << "\nPlayer 2 " << BOLDWHITE << "is the Winner!\n\n" << RESET;
				return false;
			}
			if (find(7, Player2Win) && find(5, Player2Win) && find(3, Player2Win)){
				cout << BOLDBLUE << "\nPlayer 2 " << BOLDWHITE << "is the Winner!\n\n" << RESET;
				return false;
			}
		}
		
				
		int setMove(int x , string player){ //in hindsight this way is terribly inefficient
			if (x == 1){
				Pos.a1 = player;

			}
			if (x == 2){
				Pos.b1 = player;
			}
			if (x == 3){
				Pos.c1 = player;
			}
			if (x == 4){
				Pos.d1 = player;
			
			}
			if (x == 5){
				Pos.e1 = player;
				
			}
			if (x == 6){
				Pos.f1 = player;
				
			}
			if (x == 7){
				Pos.g1 = player;
				
			}
			if (x == 8){
				Pos.h1 = player;
				
			}
			if (x == 9){
				Pos.i1 = player;
			
			}
			if (x == 10){
				Pos.a2 = player;
				
			}
			if (x == 11){
				Pos.b2 = player;
				
			}
			if (x == 12){
				Pos.c2 = player;
				
			}
			if (x == 13){
				Pos.d2 = player;
				
			}
			if (x == 14){
				Pos.e2 = player;
				
			}
			if (x == 15){
				Pos.f2 = player;
				
			}
			if (x == 16){
				Pos.g2 = player;
				
			}
			if (x == 17){
				Pos.h2 = player;
				
			}
			if (x == 18){
				Pos.i2 = player;
				
			}
			if (x == 19){
				Pos.a3 = player;
				
			}
			if (x == 20){
				Pos.b3 = player;
				
			}
			if (x == 21){
				Pos.c3 = player;
		
			}
			if (x == 22){
				Pos.d3 = player;
			
			}
			if (x == 23){
				Pos.e3 = player;
				
			}
			if (x == 24){
				Pos.f3 = player;
			
			}
			if (x == 25){
				Pos.g3 = player;
		
			}
			if (x == 26){
				Pos.h3 = player;
			
			}
			if (x == 27){
				Pos.i3 = player;
		
			}
			if (x == 28){
				Pos.a4 = player;
		
			}
			if (x == 29){
				Pos.b4 = player;
			
			}
			if (x == 30){
				Pos.c4 = player;
	
			}
			if (x == 31){
				Pos.d4 = player;
	
			}
			if (x == 32){
				Pos.e4 = player;
		
			}
			if (x == 33){
				Pos.f4 = player;
	
			}
			if (x == 34){
				Pos.g4 = player;
				
			}
			if (x == 35){
				Pos.h4 = player;
			
			}
			if (x == 36){
				Pos.i4 = player;
				
			}
			if (x == 37){
				Pos.a5 = player;
				
			}
			if (x == 38){
				Pos.b5 = player;
			
			}
			if (x == 39){
				Pos.c5 = player;
			
			}
			if (x == 40){
				Pos.d5 = player;
				
			}
			if (x == 41){
				Pos.e5 = player;
				
			}
			if (x == 42){
				Pos.f5 = player;
				
			}
			if (x == 43){
				Pos.g5 = player;
				
			}
			if (x == 44){
				Pos.h5 = player;
		
			}
			if (x == 45){
				Pos.i5 = player;
	
			}
			if (x == 46){
				Pos.a6 = player;
			
			}
			if (x == 47){
				Pos.b6 = player;
		
			}
			if (x == 48){
				Pos.c6 = player;
			
			}
			if (x == 49){
				Pos.d6 = player;
			
			}
			if (x == 50){
				Pos.e6 = player;
				
			}
			if (x == 51){
				Pos.f6 = player;
			
			}
			if (x == 52){
				Pos.g6 = player;
				
			}
			if (x == 53){
				Pos.h6 = player;
		
			}
			if (x == 54){
				Pos.i6 = player;
			
			}
			if (x == 55){
				Pos.a7 = player;
			
			}
			if (x == 56){
				Pos.b7 = player;
				
			}
			if (x == 57){
				Pos.c7 = player;
				
			}
			if (x == 58){
				Pos.d7 = player;
	
			}
			if (x == 59){
				Pos.e7 = player;
			
			}
			if (x == 60){
				Pos.f7 = player;
			
			}
			if (x == 61){
				Pos.g7 = player;
			
				
			}
			if (x == 62){
				Pos.h7 = player;
		
			}
			if (x == 63){
				Pos.i7 = player;
			
			}
			if (x == 64){
				Pos.a8 = player;
	
			}
			if (x == 65){
				Pos.b8 = player;
			
			}
			if (x == 66){
				Pos.c8 = player;
		
			}
			if (x == 67){
				Pos.d8 = player;
	
			}
			if (x == 68){
				Pos.e8 = player;
		
			}
			if (x == 69){
				Pos.f8 = player;

			}
			if (x == 70){
				Pos.g8 = player;
				
			}
			if (x == 71){
				Pos.h8 = player;
		
			}
			if (x == 72){
				Pos.i8 = player;
	
			}if (x == 73){
				Pos.a9 = player;
		
			}
			if (x == 74){
				Pos.b9 = player;
	
			}
			if (x == 75){
				Pos.c9 = player;
		
			}
			if (x == 76){
				Pos.d9 = player;
		
			}
			if (x == 77){
				Pos.e9 = player;
	
			}
			if (x == 78){
				Pos.f9 = player;

			}
			if (x == 79){
				Pos.g9 = player;

			}
			if (x == 80){
				Pos.h9 = player;
		
			}
			if (x == 81){
				Pos.i9 = player;

			}
		}
		bool validMove(int x, int prev){
			if (x >81){
				return true;
			}
	
			if (nextGrid(prev) == 1){
				/*
				if (x == 0){
					x = 99;
					cout <<"\nInput Numbers Only!\n";
					return true;
				}
				*/
				cout << "\nNext Grid is 1\n";
				if (x == 1){
					if (Pos.a1.find_first_not_of("0123456789") && (Pos.a1 != "X" && Pos.a1 != "O")){
						return false;
					}
				}
				if (x == 2){
					if (Pos.b1.find_first_not_of("0123456789") && (Pos.b1 != "X" && Pos.b1 !="O")){
						return false;
					}
				}
				if (x == 3){
					if (Pos.c1.find_first_not_of("0123456789") && (Pos.c1 != "X" && Pos.c1 !="O")){
						return false;
					}
				}
				if (x == 10){
					if (Pos.a2.find_first_not_of("1234567890") && (Pos.a2 != "X" && Pos.a2 !="O")){
						return false;
					}
				}
				if (x == 11){
					if (Pos.b2.find_first_not_of("1234567890") && (Pos.b2 != "X" && Pos.b2 !="O")){
						return false;
					}
				}
				if (x == 12){
					if (Pos.c2.find_first_not_of("1234567890") && (Pos.c2 != "X" && Pos.c2 !="O")){
						return false;
					}
				}
				if (x == 19){
					if (Pos.a3.find_first_not_of("1234567890") && (Pos.a3 != "X" && Pos.a3 !="O")){
						return false;
					}
				}
				if (x == 20){
					if (Pos.b3.find_first_not_of("1234567890") && (Pos.b3 != "X" && Pos.b3 !="O")){
						return false;
					}
				}
				if (x == 21){
					if (Pos.c3.find_first_not_of("1234567890") && (Pos.c3 != "X" && Pos.c3 !="O")){
						return false;
					}
				}else{
					return true;
				}
			}
			if (nextGrid(prev) == 2){
				if (x == 0){
					cout <<"\nInput Numbers Only!\n";
				return true;
				}
				cout << "\nNext Grid is 2\n";
				if (x == 4){
					if (Pos.d1.find_first_not_of("0123456789") && (Pos.d1 != "X" && Pos.d1 !="O")){
						return false;
					}
				}
				if (x == 5){
					if (Pos.e1.find_first_not_of("0123456789") && (Pos.e1 != "X" && Pos.e1 !="O")){
						return false;
					}
				}
				if (x == 6){
					if (Pos.f1.find_first_not_of("0123456789") && (Pos.f1 != "X" && Pos.f1 !="O")){
						return false;
					}
				}
				if (x == 13){
					if (Pos.d2.find_first_not_of("1234567890") && (Pos.d2 != "X" && Pos.d2 !="O")){
						return false;
					}
				}
				if (x == 14){
					if (Pos.e2.find_first_not_of("1234567890") && (Pos.e2 != "X" && Pos.e2 !="O")){
						return false;
					}
				}
				if (x == 15){
					if (Pos.f2.find_first_not_of("1234567890") && (Pos.f2 != "X" && Pos.f2 !="O")){
					return false;
					}
				}
				if (x == 22){
					if (Pos.a4.find_first_not_of("1234567890") && (Pos.a4 != "X" && Pos.a4 !="O")){
						return false;
					}
				}
				if (x == 23){
					if (Pos.b4.find_first_not_of("1234567890") && (Pos.b4 != "X" && Pos.b4 !="O")){
					return false;
					}
				}
				if (x == 24){
					if (Pos.c4.find_first_not_of("1234567890") && (Pos.c4 != "X" && Pos.c4 !="O")){
						return false;
					}
				}else{
					return true;
				}
			}
			if (nextGrid(prev) == 3){
				if (x == 0){
					cout <<"\nInput Numbers Only!\n";
				return true;
				}
				cout << "\nNext Grid is 3\n";
				if (x == 7){
					if (Pos.g1.find_first_not_of("0123456789") && (Pos.g1 != "X" && Pos.g1 !="O")){
						return false;
					}
				}
				if (x == 8){
					if (Pos.h1.find_first_not_of("0123456789") && (Pos.h1 != "X" && Pos.h1 !="O")){
						return false;
					}
				}
				if (x == 9){
					if (Pos.i1.find_first_not_of("0123456789") && (Pos.i1 != "X" && Pos.i1 !="O")){
						return false;
					}
				}
				if (x == 16){
					if (Pos.g2.find_first_not_of("1234567890") && (Pos.g2 != "X" && Pos.g2 !="O")){
						return false;
					}	
				}
				if (x == 17){
					if (Pos.h2.find_first_not_of("1234567890") && (Pos.h2 != "X" && Pos.h2 !="O")){
						return false;
					}
				}
				if (x == 18){
					if (Pos.i2.find_first_not_of("1234567890") && (Pos.i2 != "X" && Pos.i2 !="O")){
						return false;
					}
				}
				if (x == 25){
					if (Pos.d4.find_first_not_of("1234567890") && (Pos.d4 != "X" && Pos.d4 !="O")){
						return false;
					}
				}
				if (x == 26){
					if (Pos.e4.find_first_not_of("1234567890") && (Pos.e4 != "X" && Pos.e4 !="O")){
						return false;
					}
				}
				if (x == 27){
					if (Pos.f4.find_first_not_of("1234567890") && (Pos.f4 != "X" && Pos.f4 !="O")){
						return false;
					}
				}else{
					return true;
				}
			}
			if (nextGrid(prev) == 4){
				cout << "\nNext Grid is 4\n";
				if (x == 28){
					if (Pos.g4.find_first_not_of("1234567890") && (Pos.g4 != "X" && Pos.g4 !="O")){
						return false;
					}
				}
				if (x == 29){
					if (Pos.h4.find_first_not_of("1234567890") && (Pos.h4 != "X" && Pos.h4 !="O")){
						return false;
					}
				}
				if (x == 30){
					if (Pos.i4.find_first_not_of("1234567890") && (Pos.i4 != "X" && Pos.i4 !="O")){
						return false;
					}
				}
				if (x == 37){
					if (Pos.a5.find("1234567890") && (Pos.a5 != "X" && Pos.a5 !="O")){
						return false;
					}
				}
				if (x == 38){
					if (Pos.b5.find_first_not_of("1234567890") && (Pos.b5 != "X" && Pos.b5 !="O")){
						return false;
					}
				}
				if (x == 39){
					if (Pos.c5.find_first_not_of("1234567890") && (Pos.c5 != "X" && Pos.c5 !="O")){
						return false;
					}
				}if (x == 46){
					if (Pos.a6.find_first_not_of("1234567890") && (Pos.a6 != "X" && Pos.a6 !="O")){
						return false;
					}
				}
				if (x == 47){
					if (Pos.b6.find_first_not_of("1234567890") && (Pos.b6 != "X" && Pos.b6 !="O")){
						return false;
					}
				}
				if (x == 48){
					if (Pos.c6.find_first_not_of("1234567890") && (Pos.c6 != "X" && Pos.c6 !="O")){
						return false;
					}
				}else{	
					return true;
				}
			}
			if (nextGrid(prev) == 5){	
				cout << "\nNext Grid is 5\n";
				if (x == 31){
					if (Pos.d4.find_first_not_of("1234567890") && (Pos.d4 != "X" && Pos.d4 !="O")){
						return false;
					}
				}
				if (x == 32){
					if (Pos.e4.find_first_not_of("1234567890") && (Pos.e4 != "X" && Pos.e4 !="O")){
						return false;
					}
				}
				if (x == 33){
					if (Pos.f4.find_first_not_of("1234567890") && (Pos.f4 != "X" && Pos.f4 !="O")){
						return false;
					}
				}
				if (x == 40){
					if (Pos.d5.find("1234567890") && (Pos.d5 != "X" && Pos.d5 !="O")){
						return false;
					}
				}
				if (x == 41){
					if (Pos.e5.find_first_not_of("1234567890") && (Pos.e5 != "X" && Pos.e5 !="O")){
						return false;
					}
				}
				if (x == 42){
					if (Pos.f5.find_first_not_of("1234567890") && (Pos.f5 != "X" && Pos.f5 !="O")){
						return false;
					}
				}if (x == 49){
					if (Pos.d6.find_first_not_of("1234567890") && (Pos.d6 != "X" && Pos.d6 !="O")){
						return false;
					}
				}
				if (x == 50){
					if (Pos.e6.find_first_not_of("1234567890") && (Pos.e6 != "X" && Pos.e6 !="O")){
						return false;
					}
				}
				if (x == 51){
					if (Pos.f6.find_first_not_of("1234567890") && (Pos.f6 != "X" && Pos.f6 !="O")){
						return false;
					}
				}else{
					return true;
				}
			}
			if (nextGrid(prev) == 6){
				cout << "\nNext Grid is 6\n";
				if (x == 34){
					if (Pos.g4.find_first_not_of("1234567890") && (Pos.g4 != "X" && Pos.g4 !="O")){
						return false;
					}
				}
				if (x == 35){
					if (Pos.h4.find_first_not_of("1234567890") && (Pos.h4 != "X" && Pos.h4 !="O")){
						return false;
					}
				}
				if (x == 36){
					if (Pos.i4.find_first_not_of("1234567890") && (Pos.i4 != "X" && Pos.i4 !="O")){
						return false;
					}
				}	
				if (x == 43){
					if (Pos.g5.find_first_not_of("1234567890") && (Pos.g5 != "X" && Pos.g5 !="O")){
						return false;
					}
				}
				if (x == 44){
					if (Pos.h5.find_first_not_of("1234567890") && (Pos.h5 != "X" && Pos.h5 !="O")){
						return false;
					}
				}
				if (x == 45){
					if (Pos.i5.find_first_not_of("1234567890") && (Pos.i5 != "X" && Pos.i5 !="O")){
						return false;
					}
				}
				if (x == 52){
					if (Pos.g6.find_first_not_of("1234567890") && (Pos.g6 != "X" && Pos.g6 !="O")){
						return false;
					}
				}
				if (x == 53){
					if (Pos.h6.find_first_not_of("1234567890") && (Pos.h6 != "X" && Pos.h6 !="O")){
						return false;
					}
				}
				if (x == 54){
					if (Pos.i6.find_first_not_of("1234567890") && (Pos.i6 != "X" && Pos.i6 !="O")){
						return false;
					}
				}else{
					return true;
				} 
			}
			if (nextGrid(prev) == 7){
				cout << "\nNext Grid is 7\n";
				if (x == 55){
					if (Pos.a7.find_first_not_of("1234567890") && (Pos.a7 != "X" && Pos.a7 !="O")){
						return false;
					}
				}
				if (x == 56){
					if (Pos.b7.find_first_not_of("1234567890") && (Pos.b7 != "X" && Pos.b7 !="O")){
						return false;
					}
				}
				if (x == 57){
					if (Pos.c7.find_first_not_of("1234567890") && (Pos.c7 != "X" && Pos.c7 !="O")){
						return false;
					}
				}
				if (x == 64){
					if (Pos.a8.find_first_not_of("1234567890") && (Pos.a8 != "X" && Pos.a8 !="O")){
						return false;
					}
				}
				if (x == 65){
					if (Pos.b8.find_first_not_of("1234567890") && (Pos.b8 != "X" && Pos.b8 !="O")){
						return false;
					}
				}
				if (x == 66){
					if (Pos.c8.find_first_not_of("1234567890") && (Pos.c8 != "X" && Pos.c8 !="O")){
						return false;
					}
				}
				if (x == 73){
					if (Pos.a9.find_first_not_of("1234567890") && (Pos.a9 != "X" && Pos.a9 !="O")){
						return false;
					}
				}
				if (x == 74){
					if (Pos.b9.find_first_not_of("1234567890") && (Pos.b9 != "X" && Pos.b9 !="O")){
						return false;
					}
				}
				if (x == 75){
					if (Pos.c9.find_first_not_of("1234567890") && (Pos.c9 != "X" && Pos.c9 !="O")){
						return false;
					}
				}else{
					return true;
				}
			}
			if (nextGrid(prev) == 8){
				cout << "\nNext Grid is 8\n";
				if (x == 58){
					if (Pos.d7.find_first_not_of("1234567890") && (Pos.d7 != "X" && Pos.d7 !="O")){
						return false;
					}
				}
				if (x == 59){
					if (Pos.e7.find_first_not_of("1234567890") && (Pos.e7 != "X" && Pos.e7 !="O")){
						return false;
					}
				}
				if (x == 60){
					if (Pos.f7.find_first_not_of("1234567890") && (Pos.f7 != "X" && Pos.f7 !="O")){
						return false;
					}
				}if (x == 67){
					if (Pos.d8.find_first_not_of("1234567890") && (Pos.d8 != "X" && Pos.d8 !="O")){
						return false;
					}
				}
				if (x == 68){
					if (Pos.e8.find_first_not_of("1234567890") && (Pos.e8 != "X" && Pos.e8 !="O")){
						return false;
					}
				}
				if (x == 69){
					if (Pos.f8.find_first_not_of("1234567890") && (Pos.f8 != "X" && Pos.f8 !="O")){
						return false;
					}
				}
				if (x == 76){
					if (Pos.d9.find_first_not_of("1234567890") && (Pos.d9 != "X" && Pos.d9 !="O")){
						return false;
					}
				}
				if (x == 77){
					if (Pos.e9.find_first_not_of("1234567890") && (Pos.e9 != "X" && Pos.e9 !="O")){
						return false;
					}
				}
				if (x == 78){
					if (Pos.f9.find_first_not_of("1234567890") && (Pos.f9 != "X" && Pos.f9 !="O")){
						return false;
					}
				}else{
					return true;
				}
			}
			if (nextGrid(prev) == 9){
				cout << "\nNext Grid is 9\n";
				if (x == 61){
					if (Pos.g7.find_first_not_of("1234567890") && (Pos.g7 != "X" && Pos.g7 !="O")){
						return false;
					}
				}
				if (x == 62){
					if (Pos.h7.find_first_not_of("1234567890") && (Pos.h7 != "X" && Pos.h7 !="O")){
						return false;
					}
				}
				if (x == 63){
					if (Pos.i7.find_first_not_of("1234567890") && (Pos.i7 != "X" && Pos.i7 !="O")){
						return false;
					}
				}
				if (x == 70){
					if (Pos.g8.find_first_not_of("1234567890") && (Pos.g8 != "X" && Pos.g8 !="O")){
						return false;
					}
				}
				if (x == 71){
					if (Pos.h8.find_first_not_of("1234567890") && (Pos.h8 != "X" && Pos.h8 !="O")){
						return false;
					}
				}
				if (x == 72){
					if (Pos.i8.find_first_not_of("1234567890") && (Pos.i8 != "X" && Pos.i8 !="O")){
						return false;
					}
				}							
				if (x == 79){
					if (Pos.g9.find_first_not_of("1234567890") && (Pos.g9 != "X" && Pos.g9 !="O")){
						return false;
					}
				}
				if (x == 80){
					if (Pos.h9.find_first_not_of("1234567890") && (Pos.h9 != "X" && Pos.h9 !="O")){
						return false;
					}
				}
				if (x == 81){
					if (Pos.i9.find_first_not_of("1234567890") && (Pos.i9 != "X" && Pos.i9 !="O")){
						return false;
					}
				}else{
					return true;
				}
			}
		}
		int nextGrid(int move2){
			if (move2 == 1 || move2 == 4 || move2 == 7 || move2 == 28 || move2 == 31 || move2 == 34 || move2 == 55 || move2 == 58 || move2 == 61){
				
				return 1;
			}
			if (move2 == 2 || move2 == 5 || move2 == 8 || move2 == 29 || move2 == 32 || move2 == 35 || move2 == 56 || move2 == 59 || move2 == 62){
				
				return 2;
			}
			if (move2 == 3 || move2 == 6 || move2 == 9 || move2 == 30 || move2 == 33 || move2 == 36 || move2 == 57 || move2 == 60 || move2 == 63){
				
				return 3;
			}
			if (move2 == 10 || move2 ==  13 || move2 == 16 || move2 == 37 || move2 == 40 || move2 == 43 || move2 == 63 || move2 == 67 || move2 == 70){
				
				return 4;
			}
			if (move2 == 11|| move2 == 14 || move2 == 17 || move2 ==  38 || move2 == 41 || move2 == 44 || move2 == 65 || move2 == 68 || move2 == 71){
				
				return 5;
			}
			if (move2 == 12 || move2 == 15 || move2 == 18 || move2 == 39 || move2 == 42 || move2 == 45 || move2 == 66 || move2 == 69 || move2 == 72){
				 
				return 6;
			}
			if (move2 == 19 || move2 == 22 || move2 == 25 || move2 == 46 || move2 == 49 || move2 == 52 || move2 == 73 || move2 == 76 || move2 == 79){
				
				return 7;
			}
			if (move2 == 20 || move2 == 23|| move2 == 26 || move2 == 47 || move2 == 50 || move2 == 53 || move2 == 74 || move2 == 77 || move2 == 80){
				
				return 8;
			}
			if (move2 == 21 || move2 == 24 || move2 == 27 || move2 == 48 || move2 == 51 || move2 == 54 || move2 == 75 || move2 == 78 || move2 == 81){
				
				return 9;	
			}
		}
		int nextGrid2(int move3){
			if (deathGrid(nextGrid(move3))){
				cout << "\nPlay On:" << BOLDMAGENTA <<" Anywhere Available\n\n" << RESET;
			}else{
				if (move3 == 1 || move3 == 4 || move3 == 7 || move3 == 28 || move3 == 31 || move3 == 34 || move3 == 55 || move3 == 58 || move3 == 61){
					cout << "\nPlay On:" << BOLDMAGENTA<<" Top Left\n\n" <<RESET; 
					return 1;
				}
				if (move3 == 2 || move3 == 5 || move3 == 8 || move3 == 29 || move3 == 32 || move3 == 35 || move3 == 56 || move3 == 59 || move3 == 62){
					cout << "\nPlay On:" <<BOLDMAGENTA<<" Top Middle\n\n" <<RESET; 
					return 2;
				}
				if (move3 == 3 || move3 == 6 || move3 == 9 || move3 == 30 || move3 == 33 || move3 == 36 || move3 == 57 || move3 == 60 || move3 == 63){
					cout << "\nPlay On:" <<BOLDMAGENTA<<" Top Right\n\n" << RESET; 
					return 3;
				}
				if (move3 == 10 || move3 ==  13 || move3 == 16 || move3 == 37 || move3 == 40 || move3 == 43 || move3 == 63 || move3 == 67 || move3 == 70){
					cout << "\nPlay On:"<<BOLDMAGENTA << " Middle Left\n\n" <<RESET; 
					return 4;
				}
				if (move3 == 11|| move3 == 14 || move3 == 17 || move3 ==  38 || move3 == 41 || move3 == 44 || move3 == 65 || move3 == 68 || move3 == 71){
					cout << "\nPlay On:" << BOLDMAGENTA<<" Middle Middle\n\n" << RESET; 
					return 5;
				}
				if (move3 == 12 || move3 == 15 || move3 == 18 || move3 == 39 || move3 == 42 || move3 == 45 || move3 == 66 || move3 == 69 || move3 == 72){
					cout << "\nPlay On:" << BOLDMAGENTA <<" Middle Right\n\n" <<RESET; 
					return 6;
				}
				if (move3 == 19 || move3 == 22 || move3 == 25 || move3 == 46 || move3 == 49 || move3 == 52 || move3 == 73 || move3 == 76 || move3 == 79){
					cout << "\nPlay On:" << BOLDMAGENTA << " Bottom Left\n\n" << RESET; 
					return 7;
				}
				if (move3 == 20 || move3 == 23|| move3 == 26 || move3 == 47 || move3 == 50 || move3 == 53 || move3 == 74 || move3 == 77 || move3 == 80){
					cout << "\nPlay On:" << BOLDMAGENTA << " Bottom Middle\n\n" << RESET; 
					return 8;
				}
				if (move3 == 21 || move3 == 24 || move3 == 27 || move3 == 48 || move3 == 51 || move3 == 54 || move3 == 75 || move3 == 78 || move3 == 81){
					cout << "\nPlay On:" << BOLDMAGENTA << " Bottom Right\n\n" << RESET; 
					return 9;	
				}
			}
		}

	
		int whichGrid(int move){
			if (move == 1 || move == 2 || move == 3 || move == 10 || move == 11 || move == 12 ||move == 19 || move == 20 || move == 21){
				return 1;
			}
			if (move == 4 || move == 5 || move == 6 || move == 13 || move == 14 || move == 15 ||move == 22 || move == 23 || move == 24){
				return 2;
			}
			if (move == 7 || move == 8 || move == 9 || move == 16 || move == 17 || move == 18 ||move == 25 || move == 26 || move == 27){
				return 3;
			}
			if (move == 28 || move == 29 || move == 30 || move == 37 || move == 38 || move == 39 ||move == 46 || move == 47 || move == 48){
				return 4;
			}
			if (move == 31 || move == 32 || move == 33 || move == 40 || move == 41 || move == 42 ||move == 49 || move == 50 || move == 51){
				return 5;
			}
			if (move == 34 || move == 35 || move == 36 || move == 43 || move == 44 || move == 45 ||move == 52 || move == 53 || move == 54){
				return 6;
			}
			if (move == 55 || move == 56 || move == 57 || move == 64 || move == 65 || move == 66 ||move == 73 || move == 74 || move == 75){
				return 7;
			}
			if (move == 58 || move == 59 || move == 60 || move == 67 || move == 68 || move == 69 ||move == 76 || move == 77 || move == 78){
				return 8;
			}
			if (move == 61 || move == 62 || move == 63 || move == 70 || move == 71 || move == 72 ||move == 79 || move == 80 || move == 81){
				return 9;
			}
		}	
	
		bool isWinner(int m){
			//cout << whichGrid(m) << endl;
			if (whichGrid(m) == 1){
				//cout << "Im in Grid 1\n";
				string p = "On Grid 1: \n";
				if ((Pos.a1.compare("X")==1) && (Pos.b1.compare("X")==1) && (Pos.c1.compare("X")==1)){
					//cout << endl << p <<  "Player 1 is the Winner!\n"<< endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.a2.compare("X") ==1) && (Pos.b2.compare("X") == 1) && (Pos.c2.compare("X")==1)){
					//cout << endl << p << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.a3.compare("X") == 1) && (Pos.b3.compare("X") == 1) && (Pos.c3.compare("X")==1)){
					//cout << endl << p << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.a1.compare("X")==1) && (Pos.a2.compare("X")==1) && (Pos.a3.compare("X")==1)){
					//cout <<endl << p << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.b1.compare("X") == 1) && (Pos.b2.compare("X") == 1) && (Pos.b3.compare("X")==1)){
					//cout <<endl << p << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.c1.compare("X") ==1) && (Pos.c2.compare("X") == 1) && (Pos.c3.compare("X")== 1)){
					//cout <<endl << p << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				//cout << " Before a3  b2  c1\n";
				//??????????????????????????????????????????????????????????
				if ((Pos.a3.compare("X") == 1) && (Pos.b2.compare("X") == 1) && (Pos.c1.compare("X") == 1)){
					//cout <<endl << p << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				//cout << " After\n";
				//??????????????????????????????????????????????????????????????
				if ((Pos.a1.compare("X")==1) && (Pos.b2.compare("X")==1) && (Pos.c3.compare("X")==1)){
					//cout <<endl << p << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
			/////////////////////////////////////////////////////////////////////////
				if ((Pos.a1.compare("O")==1) && (Pos.b1.compare("O")==1) && (Pos.c1.compare("O")==1)){
					//cout << endl << p << "Player 2 is the Winner!\n"<< endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.a2.compare("O")==1) && (Pos.b2.compare("O")==1) && (Pos.c2.compare("O")==1)){
					//cout << endl << p << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.a3.compare("O")==1) && (Pos.b3.compare("O")==1) && (Pos.c3.compare("O")==1)){
					//cout << endl << p << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.a1.compare("O")==1) && (Pos.a2.compare("O")==1) && (Pos.a3.compare("O")==1)){
					//cout <<endl << p << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.b1.compare("O")==1) && (Pos.b2.compare("O")==1) && (Pos.b3.compare("O"))){
					//cout <<endl << p << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.c1.compare("O")==1) && (Pos.c2.compare("O")==1) && (Pos.c3.compare("O")==1)){
					//cout <<endl << p << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.a3.compare("O")==1) && (Pos.b2.compare("O")==1) && (Pos.c1.compare("O")==1)){
					//cout <<endl << p << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
			if ((Pos.a1.compare("O")==1) && (Pos.b2.compare("O")==1) && (Pos.c3.compare("O")==1)){
					//cout <<endl << p << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}else{
					return true;
				}
			
			}
	//000000000000000000000000000000000000000000000000000000000		
			if (whichGrid(m) == 2){
				//cout << "Im in Grid 2\n";
				string o = "On Grid 2:  \n";
				if ((Pos.d1.compare("X")==1) && (Pos.e1.compare("X")==1) && (Pos.f1.compare("X")==1)){
					//cout << endl << o <<  "Player 1 is the Winner!\n"<< endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.d2.compare("X") == 1) && (Pos.e2.compare("X")==1) && (Pos.f2.compare("X")==1)){
					//cout << endl << o << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.d3.compare("X")==1) && (Pos.e3.compare("X")==1) && (Pos.f3.compare("X")==1)){
					//cout << endl << o << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.d1.compare("X")==1) && (Pos.d2.compare("X")==1) && (Pos.d3.compare("X")==1)){
					//cout <<endl << o << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.e1.compare("X")==1) && (Pos.e2.compare("X")==1) && (Pos.e3.compare("X")==1)){
					//cout <<endl << o << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.f1.compare("X")==1) && (Pos.f2.compare("X")==1) && (Pos.f3.compare("X")==1)){
					//cout <<endl << o << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.d3.compare("X")==1) && (Pos.e2.compare("X")==1) && (Pos.f1.compare("X")==1)){
					//cout <<endl << o << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.d1.compare("X")==1) && (Pos.e2.compare("X")==1) && (Pos.f3.compare("X")==1)){
					//cout <<endl << o << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
			/////////////////////////////////////////////////////////////////////////////	
				if ((Pos.d1.compare("O")==1) && (Pos.e1.compare("O")==1) && (Pos.f1.compare("O")==1)){
					//cout << endl << o << "Player 2 is the Winner!\n"<< endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.d2.compare("O")==1) && (Pos.e2.compare("O")==1) && (Pos.f2.compare("O")==1)){
					//cout << endl << o << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.d3.compare("O")==1) && (Pos.e3.compare("O")==1) && (Pos.f3.compare("O")==1)){
					//cout << endl << o << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.d1.compare("O")==1) && (Pos.d2.compare("O")==1) && (Pos.d3.compare("O")==1)){
					//cout <<endl << o << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.e1.compare("O")==1) && (Pos.e2.compare("O")==1) && (Pos.e3.compare("O")==1)){
					//cout <<endl << o << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.f1.compare("O")==1) && (Pos.f2.compare("O")==1) && (Pos.f3.compare("O")==1)){
					//cout <<endl << o << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.d3.compare("O")==1) && (Pos.e2.compare("O")==1) && (Pos.f1.compare("O")==1)){
					//cout <<endl << o << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.d1.compare("O")==1) && (Pos.e2.compare("O")==1) && (Pos.f3.compare("O")==1)){
				//	cout <<endl << o << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}else{
					return true;
				}
			}
	//0000000000000000000000000000000000000000000000000000000000000			
			if (whichGrid(m) == 3){
				//cout << "Im in Grid 3\n";
				string r = "On Grid 3:  \n";
				if ((Pos.g1.compare("X")==1) && (Pos.h1.compare("X")==1) && (Pos.i1.compare("X")==1)){
					//cout << endl << r <<  "Player 1 is the Winner!\n"<< endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.g2.compare("X")==1) && (Pos.h2.compare("X")==1) && (Pos.i2.compare("X")==1)){
					//cout << endl << r <<  "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.g3.compare("X")==1) && (Pos.h3.compare("X")==1) && (Pos.i3.compare("X")==1)){
					//cout << endl << r <<  "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.g1.compare("X")==1) && (Pos.g2.compare("X")==1) && (Pos.g3.compare("X")==1)){
					//cout <<endl << r <<"Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.h1.compare("X")==1) && (Pos.h2.compare("X")==1) && (Pos.h3.compare("X")==1)){
					//cout <<endl << r << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.i1.compare("X")==1) && (Pos.i2.compare("X")==1) && (Pos.i3.compare("X")==1)){
					//cout <<endl << r <<"Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.g3.compare("X")==1) && (Pos.h2.compare("X")==1) && (Pos.i1.compare("X")==1)){
					//cout <<endl << r << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.g1.compare("X")==1) && (Pos.h2.compare("X")==1) && (Pos.i3.compare("X")==1)){
					//cout <<endl << r << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
		//////////////////////////////////////////////////////////////////////////////////////	
				if ((Pos.g1.compare("O")==1) && (Pos.h1.compare("O")==1) && (Pos.i1.compare("O")==1)){
					//cout << endl << r << "Player 2 is the Winner!\n"<< endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.g2.compare("O")==1) && (Pos.h2.compare("O")==1) && (Pos.i2.compare("O")==1)){
					//cout << endl << r << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.g3.compare("O")==1) && (Pos.h3.compare("O")==1) && (Pos.i3.compare("O")==1)){
					//cout << endl << r << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.g1.compare("O")==1) && (Pos.g2.compare("O")==1) && (Pos.g3.compare("O")==1)){
					//cout <<endl << r << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.h1.compare("O")==1) && (Pos.h2.compare("O")==1) && (Pos.h3.compare("O")==1)){
					//cout <<endl << r << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.i1.compare("O")==1) && (Pos.i2.compare("O")==1) && (Pos.i3.compare("O")==1)){
					//cout <<endl << r << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.g3.compare("O")==1) && (Pos.h2.compare("O")==1) && (Pos.i1.compare("O")==1)){
					//cout <<endl << r << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.g1.compare("O")==1) && (Pos.h2.compare("O")==1) && (Pos.i3.compare("O")==1)){
					//cout <<endl << r << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}else{
					return true;
				}
			}
	//00000000000000000000000000000000000000000000000000000000000000		
			if (whichGrid(m) == 4){
				//cout << "Im in Grid 4\n";
				string n = "On Grid 4:  \n";
				if ((Pos.a4.compare("X")==1) && (Pos.b4.compare("X")==1) && (Pos.c4.compare("X")==1)){
					//cout << endl << n << "Player 1 is the Winner!\n"<< endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.a5.compare("X")==1) && (Pos.b5.compare("X")==1) && (Pos.c5.compare("X")==1)){
				//	cout << endl << n << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.a6.compare("X")==1) && (Pos.b6.compare("X")==1) && (Pos.c6.compare("X")==1)){
				//	cout << endl << n << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.a4.compare("X")==1) && (Pos.a5.compare("X")==1) && (Pos.a6.compare("X")==1)){
				//	cout <<endl << n << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.b4.compare("X")==1) && (Pos.b5.compare("X")==1) && (Pos.b6.compare("X")==1)){
				//	cout <<endl << n << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.c4.compare("X")==1) && (Pos.c5.compare("X")==1) && (Pos.c6.compare("X")==1)){
				//	cout <<endl << n << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.a4.compare("X")==1) && (Pos.b5.compare("X")==1) && (Pos.c6.compare("X")==1)){
				//	cout <<endl << n << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.a6.compare("X")==1) && (Pos.b5.compare("X")==1) && (Pos.c4.compare("X")==1)){
				//	cout <<endl << n << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
		/////////////////////////////////////////////////////////////////////////////////	
				if ((Pos.a4.compare("O")==1) && (Pos.b4.compare("O")==1) && (Pos.c4.compare("O")==1)){
				//	cout << endl << n << "Player 2 is the Winner!\n"<< endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();();
					return false;
				}
				if ((Pos.a5.compare("O")==1) && (Pos.b5.compare("O")==1) && (Pos.c5.compare("O")==1)){
				//	cout << endl << n << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();();
					return false;
				}
				if ((Pos.a6.compare("O")==1) && (Pos.b6.compare("O")==1) && (Pos.c6.compare("O")==1)){
				//	cout << endl << n << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();();
					return false;
				}
				if ((Pos.a4.compare("O")==1) && (Pos.a5.compare("O")==1) && (Pos.a6.compare("O")==1)){
				//	cout <<endl << n << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();();
					return false; 
				}
				if ((Pos.b4.compare("O")==1) && (Pos.b5.compare("O")==1) && (Pos.b6.compare("O")==1)){
				//	cout <<endl << n << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();();
					return false; 
				}
				if ((Pos.c4.compare("O")==1) && (Pos.c5.compare("O")==1) && (Pos.c6.compare("O")==1)){
				//	cout <<endl << n << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();();
					return false; 
				}
				if ((Pos.a4.compare("O")==1) && (Pos.b5.compare("O")==1) && (Pos.c6.compare("O")==1)){
				//	cout <<endl << n << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();();
					return false; 
				}
				if ((Pos.a6.compare("O")==1) && (Pos.b5.compare("O")==1) && (Pos.c4.compare("O")==1)){
				//	cout <<endl << n << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}else{
					return true;
				}
			}
	//000000000000000000000000000000000000000000000000000000000000
			if (whichGrid(m) == 5){
				string c = "On Grid 5:  \n";
				//cout << "Im in Grid 5\n";
				if ((Pos.d4.compare("X")==1) && (Pos.e4.compare("X")==1) & (Pos.f4.compare("X")==1)){
					//cout << endl << c << "Player 1 is the Winner!\n"<< endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.d5.compare("X")==1) && (Pos.e5.compare("X")==1) && (Pos.f5.compare("X")==1)){
					//cout << endl << c <<"Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.d6.compare("X")==1) && (Pos.e6.compare("X")==1) && (Pos.f6.compare("X")==1)){
					//cout << endl << c <<  "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.d4.compare("X")==1) && (Pos.d5.compare("X")==1) && (Pos.d6.compare("X")==1)){
					//cout <<endl << c << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.e4.compare("X")==1) && (Pos.e5.compare("X")==1) && (Pos.e6.compare("X")==1)){
					//cout <<endl << c <<  "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.f4.compare("X")==1) && (Pos.f5.compare("X")==1) && (Pos.f6.compare("X")==1)){
					//cout <<endl << c <<  "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.d4.compare("X")==1) && (Pos.e5.compare("X")==1) && (Pos.f6.compare("X")==1)){
					//cout <<endl << c <<  "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.d6.compare("X")==1) && (Pos.e5.compare("X")==1) && (Pos.f4.compare("X")==1)){
					//cout <<endl << c <<  "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
			////////////////////////////////////////////////////////////////////////////	
				if ((Pos.d4.compare("O")==1) && (Pos.e4.compare("O")==1) && (Pos.f4.compare("O")==1)){
					//cout << endl << c << "Player 2 is the Winner!\n"<< endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.d5.compare("O")==1) && (Pos.e5.compare("O")==1) && (Pos.f5.compare("O")==1)){
					//cout << endl << c << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.d6.compare("O")==1) && (Pos.e6.compare("O")==1) && (Pos.f6.compare("O")==1)){
					//cout << endl << c << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.d4.compare("O")==1) && (Pos.d5.compare("O")==1) && (Pos.d6.compare("O")==1)){
					//cout <<endl <<c <<  "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.e4.compare("O")==1) && (Pos.e5.compare("O")==1) && (Pos.e6.compare("O")==1)){
					//cout <<endl << c << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.f4.compare("O")==1) && (Pos.f5.compare("O")==1) && (Pos.f6.compare("O")==1)){
					//cout <<endl << c << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.d4.compare("O")==1) && (Pos.e5.compare("O")==1) && (Pos.f6.compare("O")==1)){
					//cout <<endl << c << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.d6.compare("O")==1) && (Pos.e5.compare("O")==1) && (Pos.f4.compare("O")==1)){
				//	cout <<endl << c << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}else{
					return true;
				}
			}
	//0000000000000000000000000000000000000000000000000000000000000000000
			if (whichGrid(m) == 6){
				string g = "On Grid 6:  \n";
				//cout << "Im in Grid 6\n";
				if ((Pos.g1.compare("X")==1) && (Pos.h1.compare("X")==1) && (Pos.i1.compare("X")==1)){
					//cout << endl << g << "Player 1 is the Winner!\n"<< endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.g2.compare("X")==1) && (Pos.h2.compare("X")==1) && (Pos.i2.compare("X")==1)){
					//cout << endl << g << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if((Pos.g3.compare("X") ==1) && (Pos.h3.compare("X")==1) && (Pos.i3.compare("X")==1)){
					//cout << endl << g << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.g1.compare("X")==1) && (Pos.g2.compare("X")==1) && (Pos.g3.compare("X")==1)){
					//cout <<endl << g << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.h1.compare("X")==1) && (Pos.h2.compare("X")==1) && (Pos.h3.compare("X")==1)){
					//cout <<endl << g << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.i1.compare("X")==1) && (Pos.i2.compare("X")==1) && (Pos.i3.compare("X")==1)){
					//cout <<endl << g << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.g3.compare("X")==1) && (Pos.h2.compare("X")==1) && (Pos.i1.compare("X")==1)){
					//cout <<endl << g << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.g1.compare("X")==1) && (Pos.h2.compare("X")==1) && (Pos.i3.compare("X")==1)){
					//cout <<endl <<g <<  "Player 1 is the Winner!\n" << endl;  
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
			///////////////////////////////////////////////////////////////////////////////	
				if ((Pos.g4.compare("O")==1) && (Pos.h4.compare("O")==1) && (Pos.i4.compare("O")==1)){
					//cout << endl << g << "Player 2 is the Winner!\n"<< endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.g5.compare("O")==1) && (Pos.h5.compare("O")==1) && (Pos.i5.compare("O")==1)){
					//cout << endl << g << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.g6.compare("O")==1) && (Pos.h6.compare("O")==1) && (Pos.i6.compare("O")==1)){
					//cout << endl << g << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.g4.compare("O")==1) && (Pos.g5.compare("O")==1) && (Pos.g6.compare("O")==1)){
					//cout <<endl << g << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.h4.compare("O")==1) && (Pos.h5.compare("O")==1) && (Pos.h6.compare("O")==1)){
					//cout <<endl << g << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.i4.compare("O")==1) && (Pos.i5.compare("O")==1) && (Pos.i6.compare("O")==1)){
					//cout <<endl << g << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.g4.compare("O")==1) && (Pos.h5.compare("O")==1) && (Pos.i6.compare("O")==1)){
					//cout <<endl << g << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.g6.compare("O")==1) && (Pos.h5.compare("O")==1) && (Pos.i4.compare("O")==1)){
					//cout <<endl << g <<  "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}else{
					return true;
				}
			}
	//000000000000000000000000000000000000000000000000000000000000
			if (whichGrid(m) == 7){
				string z = "On Grid 7: \n";
				//cout << "Im in Grid 7: \n";
				if ((Pos.a7.compare("X")==1) && (Pos.b7.compare("X")==1) && (Pos.c7.compare("X")==1)){
					//cout << endl << z <<  "Player 1 is the Winner!\n"<< endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.a8.compare("X")==1) && (Pos.b8.compare("X")==1) && (Pos.c8.compare("X"))){
					//cout << endl << z << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.a9.compare("X")==1) && (Pos.b9.compare("X")==1) && (Pos.c9.compare("X")==1)){
					//cout << endl << z << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.a7.compare("X")==1) && (Pos.a8.compare("X")==1) && (Pos.a9.compare("X")==1)){
					//cout <<endl << z << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.b7.compare("X")==1) && (Pos.b8.compare("X")==1) && (Pos.b9.compare("X")==1)){
					//cout <<endl << z << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.c7.compare("X")==1) && (Pos.c8.compare("X")==1) && (Pos.c9.compare("X")==1)){
					//cout <<endl << z << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.a7.compare("X")==1) && (Pos.b8.compare("X")==1) && (Pos.c9.compare("X")==1)){
					//cout <<endl << z << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.a9.compare("X")==1) && (Pos.b8.compare("X")==1) && (Pos.c7.compare("X")==1)){
					//cout <<endl <<z <<  "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
		///////////////////////////////////////////////////////////////////////////////////////
				if ((Pos.a7.compare("O")==1) && (Pos.b7.compare("O")==1) && (Pos.c7.compare("O")==1)){
					//cout << endl << z << "Player 2 is the Winner!\n"<< endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.a8.compare("O")==1) && (Pos.b8.compare("O")==1) && (Pos.c8.compare("O")==1)){
					//cout << endl << z <<  "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.a9.compare("O")==1) && (Pos.b9.compare("O")==1) && (Pos.c9.compare("O")==1)){
					//cout << endl << z << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.a7.compare("O")==1)&& (Pos.a8.compare("O")==1) && (Pos.a9.compare("O")==1)){
					//cout <<endl << z << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.b7.compare("O")==1) && (Pos.b8.compare("O")==1) && (Pos.b9.compare("O")==1)){
					//cout <<endl << z << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.c7.compare("O")==1) && (Pos.c8.compare("O")==1) && (Pos.c9.compare("O")==1)){
					//cout <<endl << z << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.a7.compare("O")==1) && (Pos.b8.compare("O")==1) && (Pos.c9.compare("O")==1)){
					//cout <<endl << z << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.a9.compare("O")==1) && (Pos.b8.compare("O")==1) && (Pos.c7.compare("O")==1)){
					//cout <<endl << z << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}else{ 
					return true;
				}
			}
	//000000000000000000000000000000000000000000000000000000000000000		
			if (whichGrid(m) == 8){
				//cout << "Im in Grid 8:  \n";
				string y = "On Grid 8: \n";
				if ((Pos.d7.compare("X")==1) && (Pos.e7.compare("X")==1) && (Pos.f7.compare("X")==1)){
					//cout << endl << y <<  "Player 1 is the Winner!\n"<< endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.d8.compare("X")==1) && (Pos.e8.compare("X")==1) && (Pos.f8.compare("X")==1)){
					//cout << endl << y <<  "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.d9.compare("X") ==1) && (Pos.e9.compare("X")==1) && (Pos.f9.compare("X")==1)){
					//cout << endl << y <<  "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.d7.compare("X")==1) && (Pos.d8.compare("X")==1) && (Pos.d9.compare("X")==1)){
					//cout <<endl << y <<  "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.e7.compare("X")==1) && (Pos.e8.compare("X")==1) && (Pos.e9.compare("X")==1)){
					//cout <<endl << y << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.f7.compare("X")==1) && (Pos.f8.compare("X")==1) && (Pos.f9.compare("X")==1)){
					//cout <<endl << y << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.d7.compare("X")==1) && (Pos.e8.compare("X")==1) && (Pos.f9.compare("X")==1)){
					//cout <<endl << y << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.d9.compare("X")==1) && (Pos.e8.compare("X")==1) && (Pos.f7.compare("X")==1)){
					//cout <<endl <<  y << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
			//////////////////////////////////////////////////////////////////////////////	
				if ((Pos.d7.compare("O")==1) && (Pos.e7.compare("O")==1) && (Pos.f7.compare("O")==1)){
					//cout << endl << y << "Player 2 is the Winner!\n"<< endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.d8.compare("O")==1) && (Pos.e8.compare("O")==1) && (Pos.f8.compare("O")==1)){
					//cout << endl << y <<  "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.d9.compare("O")==1) && (Pos.e9.compare("O")==1) && (Pos.f9.compare("O")==1)){
					//cout << endl << y <<  "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false;
				}
				if ((Pos.d7.compare("O")==1) && (Pos.d8.compare("O")==1) && (Pos.d9.compare("O")==1)){
					//cout <<endl << y << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.e7.compare("O")==1) && (Pos.e8.compare("O")==1) && (Pos.e9.compare("O")==1)){
					//cout <<endl << y << "Player 2 is there Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.f7.compare("O")==1) && (Pos.f8.compare("O")==1) && (Pos.f9.compare("O")==1)){
					//cout <<endl << y <<  "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					//displayGrid();
					return false; 
				}
				if ((Pos.d7.compare("O")==1) && (Pos.e8.compare("O")==1) && (Pos.f9.compare("O")==1)){
					//cout <<endl << y <<  "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					////displayGrid();
					return false; 
				}
				if ((Pos.d9.compare("O")==1) && (Pos.e8.compare("O")==1) && (Pos.f7.compare("O")==1)){
					//cout <<endl << y << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					////displayGrid();
					return false; 
				}else{
					return true;
				}
			}
	//0000000000000000000000000000000000000000000000000000000000000000
			if (whichGrid(m) == 9){
				//cout << "Im in Grid 9\n";
				string x = "On Grid 9: \n";
				if ((Pos.g7.compare("X")==1) && (Pos.h7.compare("X")==1) && (Pos.i7.compare("X")==1)){
					//cout << endl << x << "Player 1 is the Winner!\n"<< endl;
					Player1Win.push_back(whichGrid(m));
					////displayGrid();
					return false;
				}
				if ((Pos.g8.compare("X")==1) && (Pos.h8.compare("X")==1) && (Pos.i8.compare("X")==1)){
					//cout << endl << x << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					////displayGrid();
					return false;
				}
				if ((Pos.g9.compare("X")==1) && (Pos.h9.compare("X")==1) && (Pos.i9.compare("X")==1)){
					//cout << endl << x <<  "Player 1 is there Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					////displayGrid();
					return false;
				}
				if ((Pos.g7.compare("X")==1) && (Pos.g8.compare("X")==1) && (Pos.g9.compare("X")==1)){
					//cout <<endl << x <<  "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					////displayGrid();
					return false; 
				}
				if ((Pos.h7.compare("X")==1) && (Pos.h8.compare("X")==1) && (Pos.h9.compare("X")==1)){
					//cout <<endl << x <<  "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					////displayGrid();
					return false; 
				}
				if ((Pos.i7.compare("X")==1) && (Pos.i8.compare("X")==1) && (Pos.i9.compare("X")==1)){
					//cout <<endl << x << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					////displayGrid();
					return false; 
				}
				if ((Pos.g7.compare("X")==1) && (Pos.h8.compare("X")==1) && (Pos.i9.compare("X")==1)){
					//cout <<endl << x << "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					////displayGrid();
					return false; 
				}
				if ((Pos.g9.compare("X")==1) && (Pos.h8.compare("X")==1) && (Pos.i7.compare("X")==1)){
					//cout <<endl << x <<  "Player 1 is the Winner!\n" << endl;
					Player1Win.push_back(whichGrid(m));
					////displayGrid();
					return false; 
				}
		///////////////////////////////////////////////////////////////////////
				if ((Pos.g7.compare("O")==1) && (Pos.h7.compare("O")==1) && (Pos.i7.compare("O")==1)){
					//cout << endl << x << "Player 2 is the Winner!\n"<< endl;
					Player2Win.push_back(whichGrid(m));
					////displayGrid();
					return false;
				}
				if ((Pos.g8.compare("O")==1) && (Pos.h8.compare("O")==1) && (Pos.i8.compare("O")==1)){
					//cout << endl << x << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					////displayGrid();
					return false;
				}
				if ((Pos.g9.compare("O")==1) && (Pos.h9.compare("O")==1) && (Pos.i9.compare("O")==1)){
					//cout << endl << x << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					////displayGrid();
					return false;
				}
				if ((Pos.g7.compare("O")==1) && (Pos.g8.compare("O")==1) && (Pos.g9.compare("O")==1)){
					//cout <<endl << x << "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					////displayGrid();
					return false; 
				}
				if ((Pos.h7.compare("O")==1) && (Pos.h8.compare("O")==1) && (Pos.h9.compare("O")==1)){
				//	cout <<endl << x <<"Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					////displayGrid();
					return false; 
				}
				if ((Pos.i7.compare("O")==1) && (Pos.i8.compare("O")==1) && (Pos.i9.compare("O")==1)){
					//cout <<endl << x <<  "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					////displayGrid();
					return false; 
				}
				if ((Pos.g7.compare("O")==1) && (Pos.h8.compare("O")==1) && (Pos.i9.compare("O")==1)){
					//cout <<endl << x <<  "Player 2 is there Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					////displayGrid();
					return false; 
				}
				if ((Pos.g9.compare("O")==1) && (Pos.h8.compare("O")==1) && (Pos.i7.compare("O")==1)){
					//cout <<endl <<  x <<  "Player 2 is the Winner!\n" << endl;
					Player2Win.push_back(whichGrid(m));
					////displayGrid();
					return false; 
				}else{
					return true;
				}
			}
	//000000000000000000000000000000000000000000000000000000	
		}
		
		/*
		bool catsGame(){	
			if(!Pos.a1.find_first_not_of("1234567890") && !Pos.b1.find_first_not_of("1234567890") && !Pos.c1.find_first_not_of("1234567890") && !Pos.d1.find_first_not_of("1234567890") && !Pos.e1.find_first_not_of("1234567890") && !Pos.f1.find_first_not_of("1234567890") && !Pos.g1.find_first_not_of("1234567890") && !Pos.h1.find_first_not_of("1234567890") && !Pos.i1.find_first_not_of("1234567890")){
				cout << endl << "Its a Tie!" << endl;
				return false;
			}else{
				return true;
			}
		}
		*/	
		void displayGrid(){
			cout << endl
				   <<"      "; colorAdd(Pos.a1); cout << BOLDCYAN <<"   |   " <<RESET;  colorAdd(Pos.b1); cout << BOLDCYAN <<  "   |   "<< RESET; colorAdd(Pos.c1); cout<<BOLDGREEN <<"  | |  " <<RESET; colorAdd(Pos.d1); cout <<BOLDCYAN <<  "   |   "<<RESET;  colorAdd(Pos.e1); cout <<BOLDCYAN << "   |   "<<RESET; colorAdd(Pos.f1); cout <<BOLDGREEN <<  "  | |   "<<  RESET; colorAdd(Pos.g1); cout<<BOLDCYAN <<  "   |   " <<RESET; colorAdd(Pos.h1); cout <<BOLDCYAN<<  "   |   " <<RESET; colorAdd(Pos.i1); cout << endl
				   <<BOLDCYAN << "    ...... + ...... + ..... " <<BOLDGREEN<< "| |" <<BOLDCYAN <<  " ..... + ...... + ..... " <<BOLDGREEN <<  "| |" <<BOLDCYAN <<  " ...... + ...... + ...... " << RESET<< endl
				   <<"      "; colorAdd(Pos.a2); cout << BOLDCYAN<< "   |   " << RESET; colorAdd(Pos.b2); cout << BOLDCYAN <<  "   |   " <<RESET; colorAdd(Pos.c2); cout << BOLDGREEN <<  "  | |  " << RESET;  colorAdd(Pos.d2); cout <<BOLDCYAN <<  "   |   " <<RESET; colorAdd(Pos.e2); cout <<BOLDCYAN<< "   |   " RESET; colorAdd(Pos.f2); cout <<BOLDGREEN<< "  | |   "<< RESET; colorAdd(Pos.g2); cout<<BOLDCYAN <<  "   |   " <<RESET; colorAdd(Pos.h2); cout << BOLDCYAN << "   |   " <<RESET;  colorAdd(Pos.i2); cout << endl
				   <<BOLDCYAN<< "    ...... + ...... + ..... " <<BOLDGREEN <<  "| |" << BOLDCYAN " ..... + ...... + ..... " << BOLDGREEN << "| |" <<BOLDCYAN<< " ...... + ...... + ...... " <<RESET << endl
				   <<"      "; colorAdd(Pos.a3); cout<< BOLDCYAN << "   |   " << RESET; colorAdd(Pos.b3); cout <<BOLDCYAN<< "   |   " <<RESET;  colorAdd(Pos.c3); cout<< BOLDGREEN <<  "  | |  " <<RESET; colorAdd(Pos.d3); cout << BOLDCYAN<<  "   |   "<<RESET; colorAdd(Pos.e3); cout << BOLDCYAN<<"   |   "<<RESET; colorAdd(Pos.f3); cout <<BOLDGREEN <<  "  | |   " << RESET;  colorAdd(Pos.g3); cout<<BOLDCYAN << "   |   "  <<RESET; colorAdd(Pos.h3); cout <<BOLDCYAN <<  "   |   " << RESET; colorAdd(Pos.i3); cout << endl
				   <<BOLDGREEN<<"    -------------------------------------------------------------------------------" << endl
				   <<"    -------------------------------------------------------------------------------" << RESET << endl
				   <<"      "; colorAdd(Pos.a4); cout <<BOLDCYAN <<  "   |   " <<RESET; colorAdd(Pos.b4); cout <<BOLDCYAN <<  "   |   " << RESET;  colorAdd(Pos.c4); cout<<BOLDGREEN <<  "  | |  " <<RESET; colorAdd(Pos.d4); cout << BOLDCYAN << "   |   " << RESET; colorAdd(Pos.e4); cout <<BOLDCYAN << "   |   "<<RESET; colorAdd(Pos.f4); cout <<BOLDGREEN <<  "  | |   "<<RESET; colorAdd(Pos.g4); cout<<BOLDCYAN <<  "   |   " <<RESET; colorAdd(Pos.h4); cout <<BOLDCYAN <<  "   |   " <<RESET; colorAdd(Pos.i4); cout << endl
				   <<BOLDCYAN<<"    ...... + ...... + ..... " <<BOLDGREEN <<  "| |" <<BOLDCYAN <<  " ..... + ...... + ..... " <<BOLDGREEN <<  "| |" <<BOLDCYAN<< " ...... + ...... + ...... " <<RESET<< endl
				   <<"      "; colorAdd(Pos.a5); cout <<BOLDCYAN << "   |   " <<RESET; colorAdd(Pos.b5); cout << BOLDCYAN<<  "   |   " << RESET; colorAdd(Pos.c5); cout <<BOLDGREEN <<  "  | |  " <<RESET; colorAdd(Pos.d5); cout << BOLDCYAN << "   |   " << RESET;  colorAdd(Pos.e5); cout <<BOLDCYAN << "   |   "<< RESET; colorAdd(Pos.f5); cout << BOLDGREEN << "  | |   " << RESET; colorAdd(Pos.g5); cout<< BOLDCYAN<< "   |   " <<RESET; colorAdd(Pos.h5); cout <<BOLDCYAN <<  "   |   " <<RESET; colorAdd(Pos.i5); cout << endl
				   <<BOLDCYAN << "    ...... + ...... + ..... " <<BOLDGREEN<< "| |" << BOLDCYAN<<" ..... + ...... + ..... " <<BOLDGREEN<< "| |" << BOLDCYAN<<" ...... + ...... + ...... " << RESET<<endl
				   <<"      "; colorAdd(Pos.a6); cout << BOLDCYAN<<"   |   " <<RESET; colorAdd(Pos.b6); cout <<BOLDCYAN<< "   |   "<<RESET; colorAdd(Pos.c6); cout<<BOLDGREEN<< "  | |  " <<RESET; colorAdd(Pos.d6); cout << BOLDCYAN<<"   |   "<<RESET; colorAdd(Pos.e6); cout <<BOLDCYAN<<"   |   "<<RESET; colorAdd(Pos.f6); cout << BOLDGREEN<<"  | |   "<<RESET; colorAdd(Pos.g6); cout<<BOLDCYAN<<  "   |   " <<RESET; colorAdd(Pos.h6); cout << BOLDCYAN<<"   |   " <<RESET; colorAdd(Pos.i6); cout << endl
				   <<BOLDGREEN<< "    -------------------------------------------------------------------------------" << endl
				   <<"    -------------------------------------------------------------------------------" << RESET<< endl
				   <<"      " ; colorAdd(Pos.a7); cout << BOLDCYAN<< "   |   "<<RESET; colorAdd(Pos.b7); cout <<BOLDCYAN<<  "   |   "<< RESET; colorAdd(Pos.c7); cout<< BOLDGREEN << "  | |  "  <<RESET; colorAdd(Pos.d7); cout <<BOLDCYAN<<  "   |   "<<RESET; colorAdd(Pos.e7); cout <<BOLDCYAN<< "   |   "<<RESET; colorAdd(Pos.f7); cout <<BOLDGREEN<<  "  | |   "<<RESET; colorAdd(Pos.g7 ); cout<< BOLDCYAN<< "   |   " <<RESET; colorAdd(Pos.h7); cout << BOLDCYAN<< "   |   " <<RESET; colorAdd(Pos.i7); cout << endl
				   <<BOLDCYAN<<"    ...... + ...... + ..... " <<BOLDGREEN<< "| |" <<BOLDCYAN<< " ..... + ...... + ..... " <<BOLDGREEN<< "| |" <<BOLDCYAN<< " ...... + ...... + ...... " << RESET << endl
				   <<"      ";  colorAdd(Pos.a8); cout << BOLDCYAN<< "   |   " <<RESET; colorAdd(Pos.b8); cout << BOLDCYAN<<"   |   " <<RESET; colorAdd(Pos.c8); cout<<BOLDGREEN<< "  | |  " <<RESET; colorAdd(Pos.d8); cout << BOLDCYAN<<"   |   "<<RESET; colorAdd(Pos.e8); cout << BOLDCYAN<< "   |   " << RESET; colorAdd(Pos.f8); cout <<BOLDGREEN<<  "  | |   "<<RESET; colorAdd(Pos.g8); cout<< BOLDCYAN<< "   |   " << RESET; colorAdd(Pos.h8); cout << BOLDCYAN << "   |   " <<RESET; colorAdd(Pos.i8); cout << endl
				   <<BOLDCYAN<< "    ...... + ...... + ..... " <<BOLDGREEN<<  "| |" <<BOLDCYAN<< " ..... + ...... + ..... " <<BOLDGREEN<<  "| |" <<BOLDCYAN<<  " ...... + ...... + ...... " <<RESET<<  endl
				   <<"      "; colorAdd(Pos.a9); cout << BOLDCYAN << "   |   " << RESET; colorAdd(Pos.b9); cout << BOLDCYAN << "   |   " <<RESET; colorAdd(Pos.c9) ; cout<< BOLDGREEN<< "  | |  " <<RESET; colorAdd(Pos.d9); cout <<BOLDCYAN <<  "   |   " <<RESET; colorAdd(Pos.e9); cout <<BOLDCYAN<< "   |   "<<RESET; colorAdd(Pos.f9); cout << BOLDGREEN << "  | |   "<<RESET; colorAdd(Pos.g9); cout<<BOLDCYAN<<  "   |   " RESET; colorAdd(Pos.h9); cout << BOLDCYAN<< "   |   " RESET; colorAdd(Pos.i9); cout << endl << endl << endl;
				  
		}
};
int main(){
	bool check1 = true;
	bool check4 = true;
	int count = 0;
	int move, prevMove;
	string player;
	cout << "\n                  Welcome to ULTIMATE TIC TAC TOE!!!!!!!!!!!!!!!!\n\n    The Rules:\n   1. You must win 3 large squares in a row to win \n   2. to win a large square you must win a standard game of tic tac toe in the little squares\n   3. Heres the catch where ever your opponent plays on the saller grid you much play in that square on the large grid\n\n\n";
	//cout << "Please choose a game mode, 1 or 2 players (enter 1 or 2): ";
	Game GameBoy;
	
	GameBoy.Pos.a1 = "1."; GameBoy.Pos.b1 = "2."; GameBoy.Pos.c1 = "3.";GameBoy.Pos.d1 = "4."; GameBoy.Pos.e1 = "5."; GameBoy.Pos.f1 = "6.";GameBoy.Pos.g1 = "7."; GameBoy.Pos.h1 = "8."; GameBoy.Pos.i1 = "9.";
	GameBoy.Pos.a2 = "10"; GameBoy.Pos.b2 = "11"; GameBoy.Pos.c2 = "12";GameBoy.Pos.d2 = "13"; GameBoy.Pos.e2 = "14"; GameBoy.Pos.f2 = "15";GameBoy.Pos.g2 = "16"; GameBoy.Pos.h2 = "17"; GameBoy.Pos.i2 = "18";
	GameBoy.Pos.a3 = "19"; GameBoy.Pos.b3 = "20"; GameBoy.Pos.c3 = "21";GameBoy.Pos.d3 = "22"; GameBoy.Pos.e3 = "23"; GameBoy.Pos.f3 = "24";GameBoy.Pos.g3 = "25"; GameBoy.Pos.h3 = "26"; GameBoy.Pos.i3 = "27";
	GameBoy.Pos.a4 = "28"; GameBoy.Pos.b4 = "29"; GameBoy.Pos.c4 = "30";GameBoy.Pos.d4 = "31"; GameBoy.Pos.e4 = "32"; GameBoy.Pos.f4 = "33";GameBoy.Pos.g4 = "34"; GameBoy.Pos.h4 = "35"; GameBoy.Pos.i4 = "36";
	GameBoy.Pos.a5 = "37"; GameBoy.Pos.b5 = "38"; GameBoy.Pos.c5 = "39";GameBoy.Pos.d5 = "40"; GameBoy.Pos.e5 = "41"; GameBoy.Pos.f5 = "42";GameBoy.Pos.g5 = "43"; GameBoy.Pos.h5 = "44"; GameBoy.Pos.i5 = "45";
	GameBoy.Pos.a6 = "46"; GameBoy.Pos.b6 = "47"; GameBoy.Pos.c6 = "48";GameBoy.Pos.d6 = "49"; GameBoy.Pos.e6 = "50"; GameBoy.Pos.f6 = "51";GameBoy.Pos.g6 = "52"; GameBoy.Pos.h6 = "53"; GameBoy.Pos.i6 = "54";
	GameBoy.Pos.a7 = "55"; GameBoy.Pos.b7 = "56"; GameBoy.Pos.c7 = "57";GameBoy.Pos.d7 = "58"; GameBoy.Pos.e7 = "59"; GameBoy.Pos.f7 = "60";GameBoy.Pos.g7 = "61"; GameBoy.Pos.h7 = "62"; GameBoy.Pos.i7 = "63";
	GameBoy.Pos.a8 = "64"; GameBoy.Pos.b8 = "65"; GameBoy.Pos.c8 = "66";GameBoy.Pos.d8 = "67"; GameBoy.Pos.e8 = "68"; GameBoy.Pos.f8 = "69";GameBoy.Pos.g8 = "70"; GameBoy.Pos.h8 = "71"; GameBoy.Pos.i8 = "72";
	GameBoy.Pos.a9 = "73"; GameBoy.Pos.b9 = "74"; GameBoy.Pos.c9 = "75";GameBoy.Pos.d9 = "76"; GameBoy.Pos.e9 = "77"; GameBoy.Pos.f9 = "78";GameBoy.Pos.g9 = "79"; GameBoy.Pos.h9 = "80"; GameBoy.Pos.i9 = "81";
	GameBoy.displayGrid();

	while (check4 ){
		
		if (count%2 == 0){
			bool check2 = true;
			int count2 = 0;
			player = "X.";
			while(check2){ // will cycle until a valid move is played
				move = 0;
				if (count2 == 0){
					cout << BOLDRED<<"Player 1 " << RESET <<"Make Your Move! (pick a number on the board)" << RESET<< endl;
				}else{
					cout << "Invalid Input! re-enter move" << endl;
				}
				cin >> move;
				//cout << "\nchar num:  "<<move<<endl;
				cout << endl;
				if (GameBoy.deathGrid(prevMove)){ // checks for death grid senerio
					check2 = false;
				}else{
					check2 = GameBoy.validMove(move, prevMove); // checks for valid move
				}
				count2++;
			}
			GameBoy.setMove(move, player); // saves players move
			GameBoy.displayGrid();	
			check1 = GameBoy.isWinner(move); // checks for a winner of a smaller grid and saves grid location in vector
			prevMove = move;
			GameBoy.nextGrid2(prevMove); // displays where the next player should play
		}else{
			bool check3 = true;
			int count3 = 0;
			player = "O.";
			while(check3){ // will cycle untill a valid move is played
				move = 0;
				if (count3 == 0){
					cout << BOLDBLUE <<"Player 2 " << RESET <<"Make Your Move! (pick a number on the board)" << endl;
				}else{
					cout << "Invalid Input! re-enter move" << endl;
				}
				cin >> move;
				cout << endl;
				
				if (GameBoy.deathGrid(prevMove)){ // checks for a death grid senerio
					check3 = false;
				}else{
					check3 = GameBoy.validMove(move, prevMove); // checks for a valid move 
				}
				count3++;
			}
			GameBoy.setMove(move, player); // saves players move
			GameBoy.displayGrid();	
			check1 = GameBoy.isWinner(move); // checks for a winner of a smaller grid and saves grid location in a vector 
			prevMove = move;
			GameBoy.nextGrid2(prevMove); // displays where the next player should play
		}
		
		if (move == 42){ //easter egg
			cout << BLUE << "                                                                                                                   Congratulations you found the meaning of life\n" << RESET;
		}
		
		check4 = (GameBoy.winGame()); // checks for game winning senerio
		//GameBoy.debug();
		//	check1 = GameBoy.catsGame();
		//}
		count++;
		if (count == 81){  // Checks for a cats game
			cout << BOLDWHITE << "\nIts a Tie!\n\n" << RESET;
			check4 = false;
		}
		
	}	
}

