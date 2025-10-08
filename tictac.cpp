6 -'[000#include <iostream>
using namespace std;
//funtion prototypes
void instructions();
void inputplayers(int* players);
void boardsize(int* row, int* col);
void initialize(int row, int col, char* board);
void display(int row, int col, char* board);
void checkturn(char* board, int row, int col, int &m, int &n, char sym);
bool ifWin(char* board, int &m, int &n , int row, int col, char sym);
bool ifDraw(char* board, int row, int col);
//main function
int main() {
    instructions();//calling for the instructions to display
    
    int players;
    int* play= &players;//making pointer to pass to function that takes the number of players
    
   inputplayers(play);//pass by reference function call

    char sym[5] = { 'X', 'O', '#', '$', '&' };//initializing array for symbols to be assigned to players
    
    //assigning symbols t players and displaying
    for (int i = 0; i < players; i++) 
    {
        cout << "\nPlayer " << (i + 1) << " : " << *(sym+i) << "\n";
    }

    int col, row;
    
    //poiniters to pass to function that takes board size
    int* c = &col;
    int* r = &row;
    
    boardsize(r, c);//pass by reference function call to take the board size from user

    char* board = new char[row * col]; //creating a 2D dynamic array for the game board of tic tac toe

   initialize(row, col, board);//function call to initialize the 2D array

    int m, n;
    //while loop to keep the game running until won or draw
    while (1) 
    {
        for (int i = 0; i < players; i++) //loop for giving turn to each player
        {
        
          cout<<"\nPlayer "<<(i+1)<<" 's turn symbol "<<*(sym+1)<<"\n";//displaying which player's turn it is
          checkturn(board, row, col, m, n, *(sym+i) );//call to function to take input from player to make a valid move
           
                    if (ifWin(board, m, n, row, col, *(sym+i)))//check and bool function call to chcek that if any player has won after each move
                    {
                        cout << "\nPlayer " << (i + 1) << " with Symbol " << *(sym+i) << " has won!!\n";//if someone has won dexclare it and end game
                        cout<<"\n~~~~~~~~~~~~~~~~~~~THANK YOU FOR PLAYING!!~~~~~~~~~~~~~~~~~~\n";
                        delete[] board;
                        return 0;
                    }

            
            if (ifDraw(board, row, col)) //check and bool function call to check if the game is Draw or not
            {
                cout << "\nThe match is Draw!!\n";//if the game is draw display it and end the game
                cout<<"\n~~~~~~~~~~~~~~~~~~~THANK YOU FOR PLAYING!!~~~~~~~~~~~~~~~~~~\n";
                delete[] board;
                board = NULL;
                return 0;
            }
        }
    }

    delete[] board;
    board = NULL;
    return 0;
}
void instructions()//all the instructions of the game being displayed by this function
{
   cout<<"~~~~~~~WELCOME TO TIC TAC TOE!!~~~~~~~\n";
   cout<<"\nEnjoy playing with your friends.\n";
   cout<<"\n~~~~~~~~~DIRECTIONS~~~~~~~~~~\n";
   cout<<"\n1-Select the number of players between 2 and 5.\n";
   cout<<"2-Enter the number of rows and columns that you want in the game board.\n";
   cout<<"3-The minimum number of rows and columns in the board is 3.\n";
   cout<<"4-Regardless of the board size any player who fills 3 consective slots of the board vertically , horizontally, or diagonally with his symbol will WIN the game.\n";
   cout<<"5-if no players meets the condition to win and the game board is filled than the game will DRAW.\n";
}

void inputplayers(int* players)//taking the number of players from the user
{
      int check=0;//introducing check for valid number of players
    
    do
   { 
     cout << "\nEnter the number of players between 2 and 5: ";
     cin >> *(players);

     if (*(players) < 2 || *(players) > 5) //check if the input if between 2 and 5 or not
         cout << "\nInvalid number of players select between 2 and 5.\n";
     if(*(players)>=2 && *(players)<=5)//if input if valid giving check 1 to end the loop
       check=1;  
   }
    while(check==0);//do while loop to repeatedlt take the number of players from the user until they have entered a valid input
}

void boardsize(int* row, int* col)//taking the number of rows and columns for the board size from the user
{
 int check2=0;//introducing check for valid number of rows and columns
    do
    {
	 cout << "\nEnter number of columns and rows in the board minimum 3 rows and 3 columns: \n";
	 cin >> *(row) >> *(col);

    if (*(row) < 3 || *(col) < 3) //chceking if the number of rows and columns are less than 3 or not
        cout << "\nInvalid input minimum rows and columns should be 3.Try again\n";
    if(*(row)>=3 && *(col) >=3)// if the input is greater or equal to 3 giving check2 1 to end the loop
      check2=1;   
    }
    while(check2==0);//do while loop to repeatedly take the board size from user until they have entered valid input 
}

void initialize(int row, int col, char* board)//initializing all the slots of the board with '*' to show thta they are empty
{
   for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            board[i * col + j] = '*';//assigning '*' to the entire 2D dynamic array of the board
            cout << " | " << board[i * col + j] << " | ";//Displaying the initial board
        }
        cout << "\n";
    }
}

void display(int row, int col, char* board)//function to display the game board
{
   for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) 
        {
            cout << " | " << board[i * col + j] << " | ";//diplaying the 2D dynamic array of the board
        }
        cout << "\n";
    }
} 

void checkturn(char* board, int row, int col, int &m, int &n, char sym)//function to take input of each player for the move and validate it
{
  cout << " \nSelect a row and column to make a move: \n";
            cin >> m >> n;//taking the row and column number from player to make his move

            if (m <= row && n <= col) //check to see if the input of the player is valid acording to the board size or not
            {
                if (board[(m - 1) * col + (n - 1)] == '*') //checking to see if the slot selected by player is empty or already occupied
                {
                    board[(m - 1) * col + (n - 1)] = sym;//if slot is empty and valid place the symbol of the user in that slot so the move can be made
			display(row, col, board);// then displaying the game board after a valid move
                    
                } 
                else //if the slot is already taken prompt to select a slot again
                {
                    cout << "\nAlready occupied select again.\n";
                     checkturn(board, row, col, m, n, sym );//do a recursive call to the checkturn function to take input from user again
                }
            } 
            else //if the number of rows and columns is not valid prompt the player to give a valid input
            {
                cout << "\nInvalid input try again.\n";
                 checkturn(board, row, col, m, n, sym );//recursice call to the checkturn function to take input from user again
            }
}

bool ifWin(char* board, int &m, int &n , int row, int col, char sym)//function to check Win 
{
  return(//horizontal wins
         (n - 2 >= 0 && board[(m - 1) * col + (n - 2)] == sym && board[(m - 1) * col + (n - 3)] == sym) || // checking the left 2 slots of the current move for a win
         (n + 2 < col && board[(m - 1) * col + (n)] == sym && board[(m - 1) * col + (n + 1)] == sym) || // checking the right 2 slots of the current move for a win
         //vertical wins
         (m - 2 >= 0 && board[(m - 2) * col + (n - 1)] == sym && board[(m - 3) * col + (n - 1)] == sym) || // checking upward 2 slots of the current move for a win
         (m + 2 < row && board[(m) * col + (n - 1)] == sym && board[(m + 1) * col + (n - 1)] == sym) || // checking downward 2 slots of the current move for a win
         //diagonal wins
         (m - 2 >= 0 && n - 2 >= 0 && board[(m - 2) * col + (n - 2)] == sym && board[(m - 3) * col + (n - 3)] == sym) || //checking  Top-left 2 slots of the current move for a win
         (m + 2 < row && n + 2 < col && board[(m) * col + (n)] == sym && board[(m + 1) * col + (n + 1)] == sym) || //  checking Bottom-right 2 slots of the current move for a win
         (m - 2 >= 0 && n + 2 < col && board[(m - 2) * col + (n)] == sym && board[(m - 3) * col + (n + 1)] == sym) || //checking  Top-right 2 slots of the current move for a win
         (m + 2 < row && n - 2 >= 0 && board[(m) * col + (n - 2)] == sym && board[(m + 1) * col + (n - 3)] == sym) // checking  Bottom-left 2 slots of the current move for a win
        ); //if any of the win conditions gets true the function will return true else false
}

bool ifDraw(char* board, int row, int col)//function to check if the game is draw
{
  int checkfull=0;//introducing checkfull to see if the entire board is filled symbols other than '*'
            for (int f = 0; f < row; f++) 
            {
                for (int e = 0; e < col; e++) 
                {
                    if (board[f * col + e] == '*') //if a '*' is found means that there is an empty slot present and the game is not draw
                    {
                        checkfull=1;//if empty slot is found give checkfull 1 
                    }
                }
                
            }
   if(checkfull==0)//if checkfull is 0 means that the board is filled and game is draw so return true 
      return true;
   else//if checkfull is not zero that means game is not draw return false
      return false;
}
