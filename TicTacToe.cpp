#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Board{
	string S1,S2,S3,S4,S5,S6,S7,S8,S9,S10,S11,S12,S13,S14,S15,S16;
	string A,B,C,A1,A2,A3,B1,B2,B3,C1,C2,C3;
	string num1,num2,num3;
};

class AI{
	
};

class Game{
	private:
		string test;
		vector <Board> Grid;		
		//vector <string> fair = {"A1","A2","A3","B1","B2","B3","C1","C2","C3"};
	public:
		
		vector <string> Valid;
	
		void fillGrid(){
			ifstream Infile;
			Infile.open("TicTacToeBoard.txt");
			
			Board temp;
			while (!Infile.eof()){
				Infile >> temp.S1 
					    >> temp.A
						>> temp.S2
						>> temp.B
						>> temp.S3
						>> temp.C
						>> temp.S4
						>> temp.num1
						>> temp.S5
						>> temp.A1
						>> temp.S6
						>> temp.B1
						>> temp.S7
						>> temp.C1
						>> temp.S8
						>> temp.num2
						>> temp.S9
						>> temp.A2
						>> temp.S10
						>> temp.B2
						>> temp.S11
						>> temp.C2
						>> temp.S12
						>> temp.num3
						>> temp.S13
						>> temp.A3
						>> temp.S14
						>> temp.B3
						>> temp.S15
						>> temp.C3
						>> temp.S16;
				
				Grid.push_back(temp);
			}
			Infile.close();
		}
		void displayGrid(){
			cout 
			<< Grid[0].S1 << Grid[0].A << Grid[0].S2 << Grid[0].B << Grid[0].S3 << Grid[0].C << Grid[0].S4 << endl
			<< Grid[0].num1 << Grid[0].S5 << Grid[0].A1 << Grid[0].S6 << Grid[0].B1 << Grid[0].S7 << Grid[0].C1 << Grid[0].S8 << endl
			<< Grid[0].num2 << Grid[0].S9 << Grid[0].A2 << Grid[0].S10 << Grid[0].B2 << Grid[0].S11 << Grid[0].C2 << Grid[0].S12 <<endl
			<< Grid[0].num3 << Grid[0].S13 << Grid[0].A3 << Grid[0].S14 << Grid[0].B3 << Grid[0].S15 << Grid[0].C3 << Grid[0].S16 <<endl;
			
		}
		bool validMove(string pos){
			bool check3 = true;
			unsigned y =0;
			string fair[10] = {"A1","A2","A3","B1","B2","B3","C1","C2","C3", " "};
			while (check3){
				if (pos == fair[y]){
					check3 = false;
				}
				if (y == 8){
					check3 = false;
				}
				y++;
				if (y == 10){
					return true;
				}
			}
							
			for (unsigned z = 0; z < Valid.size(); z++){
				if (pos == Valid[z]){
					return true;
				}
			}
			Valid.push_back(pos);
			return false;
		}
		void Move(string pos, string player){
			// Bug: seems to be checking first charactor for boolean then second character for pos
			if (pos == "A1"){
				Grid[0].A1 = player;
			}
			if (pos == "B1"){
				Grid[0].B1 = player;
			}
			if (pos == "C1"){
				Grid[0].C1 = player;
			}
			if (pos == "A2"){
				Grid[0].A2 = player; 
			}
			if (pos == "B2"){
				Grid[0].B2 = player;
			}
			if (pos == "C2"){
				Grid[0].C2 = player;
			}
			if (pos == "A3"){
				Grid[0].A3 = player;
			}
			if (pos == "B3"){
				Grid[0].B3 = player;
			}
			if (pos == "C3"){
				Grid[0].C3 = player;
			}
		}
		bool Winner(string player){
			test = player;
			string Player;
			if (test == "X."){
				Player = "Player 1";
			}
			if (test == "O."){
				Player = "Player 2";
			}
			if (Grid[0].A1 == test && Grid[0].B1 == test && Grid[0].C1 == test){
				cout << endl << Player << "'s WIN!" << endl;
				return false;
			}
			if (Grid[0].A2 == test && Grid[0].B2 == test && Grid[0].C2 == test){
				cout << endl <<  Player << "'s WIN!" << endl;
				return false;
			}
			if (Grid[0].A3 == test && Grid[0].B3 == test && Grid[0].C3 == test){
				cout << endl <<  Player << "'s WIN!" << endl;
				return false;
			}
			if (Grid[0].A1 == player && Grid[0].A2 == player && Grid[0].A3 == player){
				cout << endl << Player << "'s WIN!" << endl;
				return false;
			}
			if (Grid[0].B1 == player && Grid[0].B2 == player && Grid[0].B3 == player){
				cout << endl << Player << "'s WIN!" << endl;
				return false;
			}
			if (Grid[0].C1 == player && Grid[0].C2 == player && Grid[0].C3 == player){
				cout << endl <<  Player << "'s WIN!" << endl;
				return false;
			}
			if (Grid[0].A1 == player && Grid[0].B2 == player && Grid[0].C3 == player){
				cout << endl <<  Player << "'s WIN!" << endl;
				return false;
			}
			if (Grid[0].A3 == player && Grid[0].B2 == player && Grid[0].C1 == player){
				cout << endl <<  Player << "'s WIN!" << endl;
				return false;
			}else{
				return true;
			}
		}
		
};

int main(){
	cout <<endl<< "Welcome to the Tic-Tac-Toe Game" << endl << endl;
	Game GameBoy;
	
	GameBoy.fillGrid();
	GameBoy.displayGrid();
	int count = 0;
	string move;
	string player;
	bool check = true;

	while (check){
		bool check2 = true;
		if (count%2 == 0){
			while (check2){
				player = "X.";
				cout << endl << "Player 1 Make Your Move:  " << endl;
				cin >> move;
				cout << endl;
				check2 = GameBoy.validMove(move); // returns false if its a valid move
				if (!check2){
					GameBoy.Move(move, player);
				}
			}
		}else{
			while (check2){
				player = "O.";
				cout << endl << "Player 2 Make Your Move:  " << endl;
				cin >> move;
				cout << endl;
				check2 =GameBoy.validMove(move);
				if (!check2){
					GameBoy.Move(move, player);
				}
			}
		}
	 GameBoy.displayGrid();	
	 count++;
	 check = GameBoy.Winner(player);
	}		
}
