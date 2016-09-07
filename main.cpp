#include <stdio.h> // Should be removed later when all the stdio related stuff like prinf has been replace with c out
#include <string>
#include "serial.h"
#include <iostream>
using std::cout;
using std::endl;
char square[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player[3] = {'X', 'O'};
int turn = 0;
bool arduinoisconnected = false;
void board();
int checkwin = 0;
int idx =0;
int choice;
int c1, c2 ,c3, c4, c5, c6, c7, c8, c9 = 0;
int checkForWinner();

// application reads from the specified serial port and reports the collected data
int main()
{
// ACTUAL CODE *******************************************************************************
    do {
        idx = (turn%2==0) ? 1:2;
        board();
	std::cin >> choice;

	if (choice == 1 && c1 == 0)
    {
        square[choice-1] = player[idx-1];
        c1 = 1;
        turn++;
    }
    else if(choice == 2 && c2 == 0)
    {
        square[choice-1] = player[idx-1];
        c2 = 1;
        c2 = 1;
        turn++;
    }
    else if(choice == 3 && c3 == 0)
    {
        square[choice-1] = player[idx-1];
        c3 = 1;
        turn++;
    }
    else if(choice == 4 && c4 == 0)
    {
        square[choice-1] = player[idx-1];
        c4 = 1;
        turn++;
    }
    else if(choice == 5 && c5 == 0)
    {
        square[choice-1] = player[idx-1];
        c5 = 1;
        turn++;
    }
    else if(choice == 6 && c6 == 0)
    {
        square[choice-1] = player[idx-1];
        c6 = 1;
        turn++;
    }
    else if(choice == 7 && c7 == 0)
    {
        square[choice-1] = player[idx-1];
        c7 = 1;
        turn++;
    }
    else if(choice == 8 && c8 == 0)
    {
        square[choice-1] = player[idx-1];
        c8 = 1;
        turn++;
    }
    else if(choice == 9 && c9 == 0)
    {
        square[choice-1] = player[idx-1];
        c9 = 1;
        turn++;
    }
    else
    {
        std::cout << "Invalid move" << std::endl;
    }

	board();
	checkwin = checkForWinner();
    } while(checkwin == -1);
    if(checkwin==1)
    {

		std::cout << "The player " << player[idx-1] << " win.";
    }
	else
    {

		std::cout << "Game draw.";
		std::cout << checkwin << std::endl;
    }
    return 0;
}
void board()
{
/* Grapichs of the text.
 _____ _____ _____
|     |     |     |
|  1  |  2  |  3  |
|_____|_____|_____|
|     |     |     |
|  4  |  5  |  6  |
|_____|_____|_____|
|     |     |     |
|  7  |  8  |  9  |
|_____|_____|_____|
*/

    cout << "Player's turn: " << player[idx-1] << endl;
    cout << " _________________" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << square[0] <<   "  |  " << square[1] <<"  |  " << square[2] << "  |" << endl;
    cout << "|_____|_____|_____|" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << square[3] <<   "  |  " << square[4] <<"  |  " << square[5] << "  |" << endl;
    cout << "|_____|_____|_____|" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << square[6] <<   "  |  " << square[7] <<"  |  " << square[8] << "  |" << endl;
    cout << "|_____|_____|_____|" << endl;
    cout << "Connected to Arduino: " << arduinoisconnected << endl;
}
// look for any possible winning combination
// returns 1 if there's a winner, 0 for a draw, -1 the game continues
int checkForWinner()
{
if (square[0] == square[1] && square[1] == square[2])
		return 1;
	else if (square[3] == square[4] && square[4] == square[5])
		return 1;
	else if (square[6] == square[7] && square[7] == square[8])
		return 1;
	else if (square[0] == square[3] && square[3] == square[6])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[0] == square[4] && square[4] == square[8])
		return 1;
	else if (square[2] == square[4] && square[4] == square[6])
		return 1;
	else if (square[0] != '1' && square[1] != '2' && square[2] != '3'  && square[3] != '4' && square[4] != '5' && square[5] != '6' && square[6] != '7' && square[7] != '8' && square[8] != '9')
		return 0;
	else
		return -1;
}
