#include <iostream>
#include <string>
using namespace std;
const int ROWS = 3;
const int COLS = 3;
void runGame();
void initializeGameBoard(string gameBoard[ROWS][COLS]);
void printCurrentBoard(string gameBoard[ROWS][COLS]);
void getUserInput(bool xTurn, string gameBoard[ROWS][COLS]);
bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]);
string getWinner(string gameBoard[ROWS][COLS]);
bool isBoardFull(string gameBoard[ROWS][COLS]);
//error finding
void runGame(){
	//main loop
	
	string winner="";//empty string no winner yet
	bool xTurn=true;
	int theRow=0;
	int theCol=0;
	string gameBoard[ROWS][COLS];
	initializeGameBoard(gameBoard);
	//printing board
	printCurrentBoard(gameBoard);
	while(winner==""){//game loop continues as long as no winner found
		if(xTurn){
			cout<<"its X turn";
		}
		else{
			cout<<"its O turn";
		}
		getUserInput(xTurn,gameBoard);
		cout<<endl;
		printCurrentBoard(gameBoard);//updated board;
		winner=getWinner(gameBoard);
		xTurn=!xTurn;//flip turn after ek game completes
		while(winner=="" && isBoardFull(gameBoard)){
			winner="C";
		}
	}
	cout<<endl;
	if(winner=="C"){
		cout<<"game draw"<<endl;
	}
	else{
		cout<<"The winner is"<<" "<<winner<<endl;
	}
	cout<<endl;
}

void initializeGameBoard(string gameBoard[ROWS][COLS]){
		for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){
		gameBoard[i][j]=" ";//empty space
		
		
		
		} }
	
}

void getUserInput(bool xTurn, string gameBoard[ROWS][COLS]){
	int row=-1;
	int col=-1;
	bool keepAsking=true;
	
	while(keepAsking){
		//validations
		cout<<endl;
		cout<<"write row and column separated by space for positions or coordinates  0 1 2:"<<endl;
		cin>>row;
		cin>>col;
		cout<<endl;
		if(row>=0 && col>=0 && row<=2 && col<=2){
			
			if(!cellAlreadyOccupied(row, col, gameBoard)){
				keepAsking=false;
			}
			else{
				cout<<"The cell is already occupied"<<endl;
			}
		
		}
		
	}
	
	if(xTurn){
		gameBoard[row][col]="X";
	}
	else{
		gameBoard[row][col]="O";	
	}
}

//prnting the board--
void printCurrentBoard(string gameBoard[ROWS][COLS]){
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){
			cout<<gameBoard[i][j];
			
			
			cout<<"  |"<<"";
	
			
		
	}
    cout<<endl;
	cout<<"- - - - - - -"<<endl;
	}
}

bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]){
return gameBoard[row][col]!=" ";//no spc means occupied
}

string getWinner(string gameBoard[ROWS][COLS]){
	for(int i=0;i<ROWS;i++){
	
	if(gameBoard[i][0]!=" " && gameBoard[i][0]==gameBoard[i][1] && gameBoard[i][1]==gameBoard[i][2]){
		return gameBoard[i][0];//horizontal
	}}
	
	for(int j=0;j<COLS;j++){
	
	if(gameBoard[0][j]!=" " && gameBoard[0][j]==gameBoard[1][j] && gameBoard[1][j]==gameBoard[2][j]){
		return gameBoard[0][j];//vertical
	}}
	
	if(gameBoard[0][0]!=" " && gameBoard[0][0]==gameBoard[1][1] && gameBoard[1][1]==gameBoard[2][2]){
		return gameBoard[0][0];//diagonal--upper left to bottom right
	}
   if(gameBoard[2][0]!=" " && gameBoard[2][0]==gameBoard[1][1] && gameBoard[1][1]==gameBoard[0][2]){
		return gameBoard[2][0];//diagonal--lower left to upper right
	}
	
	return "";//no winner
}

bool isBoardFull(string gameBoard[ROWS][COLS]){
	int count=0;
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){

			
		   if(gameBoard[i][j]!=" "){//non-spaces
		   	count++;
		   }
		   	
			
	
			
		
	}
    
	}
	
	return count == 9;
}
int main(){
	runGame();
	
	return 0;
}
