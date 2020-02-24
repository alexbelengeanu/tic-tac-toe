// Version: 1.0
// A simple Tic Tac Toe game that I developed as my first 'project'.
// New features will be added in the future.

#include <iostream>
using namespace std;
char matrice[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
char player = 'X';
void displayShape() // this function displays the table/shape of the game
{
	system("cls");
	cout << "      T i c     T a c    T o e    v1.0\n\n";
	cout << "  Player 1: [X]\n";
	cout << "  Player 2: [O]\n";
	cout << "---------------------------------------------\n\n\n";
	cout << "\t       |       |       \n";
	cout << "\t   " << matrice[0][0] << "   |   " << matrice[0][1] << "   |   " << matrice[0][2] << "   \n";
	cout << "\t_______|_______|_______\n";
	cout << "\t       |       |       \n";
	cout << "\t   " << matrice[1][0] << "   |   " << matrice[1][1] << "   |   " << matrice[1][2] << "   \n";
	cout << "\t_______|_______|_______\n";
	cout << "\t       |       |       \n";
	cout << "\t   " << matrice[2][0] << "   |   " << matrice[2][1] << "   |   " << matrice[2][2] << "   \n";
	cout << "\t       |       |       \n\n\n";
}
int inputData() // it reads the input data considering the turn of which player it is
{
	int i, j, done=0;
	char option;
	if (player == 'X') cout << "Player 1 turn: ";
	else cout << "Player 2 turn: ";
	cin >> option;
	for (i = 0;i < 3;i++)
		for (j = 0;j < 3;j++)
		{
			if (matrice[i][j] == option)
			{
				matrice[i][j] = player;
				done = 1;
			}
		}
	
	return done;
}

int checkWinner() // it checks if there is any winner yet
{
	int i, j, checks=0;
	for(i=0;i<3;i++)
		if (matrice[i][0] == matrice[i][1] && matrice[i][0] == matrice[i][2] || matrice[0][i] == matrice[1][i] && matrice[0][i] == matrice[2][i] || matrice[0][0] == matrice[1][1] && matrice[0][0] == matrice[2][2] || matrice[0][2] == matrice[1][1] && matrice[0][2] == matrice[2][0])
		{
			if (player == 'X') return 1;
			else return 2;
		}
	for (i = 0;i < 3;i++)
		for (j = 0;j < 3;j++)
		{
			if (matrice[i][j] == 'X' || matrice[i][j] == 'O') checks++;
		}
	if (checks == 9) return 3;
	return 0;
}
void changePlayer() // it changes the turn of the players
{
	if (player == 'X')
		player = 'O';
	else player = 'X';
}
void continueGame()  // while there are still some fields left, the game continues until there is a winner or we have a draw
{
	int x;
	while (1)
	{
		x = inputData();
		while (x == 0)
		{
			cout << "You entered an invalid field for your option. Please try again!\n";
			if (player == 'X') cout << "Player 1 turn: ";
			else cout << "Player 2 turn: ";
			x = inputData();
		}
		displayShape();
		x = checkWinner();
		if (x == 1)
		{
			cout << "Player 1 [X] wins this one!";
			break;
		}
		else if (x == 2)
		{
			cout << "Player 2 [O] wins this time!";
			break;
		}
		else if (x == 3)
		{
			cout << "It's DRAW!!";
			break;
		}
		changePlayer();
	}
}
int main()
{
	displayShape();
	continueGame();
	system("pause");
	return 0;
}
