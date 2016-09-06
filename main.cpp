#include <stdio.h> // Should be removed later when all the stdio related stuff like prinf has been replace with c out
#include "SerialClass.h"	// Library described above
#include <string>
#include <tchar.h>
#include <iostream>
char square[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player[2] = {'X', 'O'};
int turn = 0;
bool arduinoisconnected = false;
void board();
int checkwin = 0;
int idx =0;
int choice;
int c1, c2 ,c3, c4, c5, c6, c7, c8, c9 = 0;
int checkForWinner();



// application reads from the specified serial port and reports the collected data
int _tmain(int argc, _TCHAR* argv[])
{
	printf("Welcome to the serial test app!\n\n");

	Serial* SP = new Serial("\\\\.\\COM3");    // adjust as needed

	if (SP->IsConnected())
		printf("We're connected");

	char incomingData[256] = "";			// don't forget to pre-allocate memory
	//printf("%s\n",incomingData);
	int dataLength = 255;
	int readResult = 0;

	while(SP->IsConnected())
	{
		readResult = SP->ReadData(incomingData,dataLength);
		// printf("Bytes read: (0 means no data available) %i\n",readResult);
                incomingData[readResult] = 0;

        	printf("%s",incomingData);

		Sleep(500);
	}
	return 0;


// ACTUAL CODE *******************************************************************************
    do {
        idx = (turn%2==0) ? 1:2;
        board();
        std::cout << "Turn:" << turn << ", Player " << idx << ", enter a number:  ";
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

		std::cout << "The player " << idx << " win.";
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
    // a lot of shit
    std::cout << "Player's turn: " << player[1] << std::endl;
    std::cout << " _____ _____ _____ " << std::endl;
    std::cout << "|     |     |     |" << std::endl;
    std::cout << "|  " << square[0] <<   "  |  " << square[1] <<"  |  " << square[2] << "  |" << std::endl;
    std::cout << "|_____|_____|_____|" << std::endl;
    std::cout << "|     |     |     |" << std::endl;
    std::cout << "|  " << square[3] <<   "  |  " << square[4] <<"  |  " << square[5] << "  |" << std::endl;
    std::cout << "|_____|_____|_____|" << std::endl;
    std::cout << "|     |     |     |" << std::endl;
    std::cout << "|  " << square[6] <<   "  |  " << square[7] <<"  |  " << square[8] << "  |" << std::endl;
    std::cout << "|_____|_____|_____|" << std::endl;
    std::cout << "Connected to Arduino: " << arduinoisconnected << std::endl;
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
