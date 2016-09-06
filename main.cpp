#include <iostream>
char square[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player[2] = {'X', 'O'};
int turn = 0;
bool arduinoisconnected = false;
void board();
int checkwin = 0;
int idx =0;
int choice;
int checkForWinner();
int main()
{
    do {
        idx = (turn%2==0) ? 1:2;
        std::cout << "Turn:" << turn << ", Player " << idx << ", enter a number:  ";
	std::cin >> choice;
	square[choice-1] = player[idx-1];
	board();
	checkwin = checkForWinner();
	turn++;
    } while(checkwin == 0);
    if(checkwin==1)
		std::cout << "The player " << idx << " win.";
	else
		std::cout << "Game draw.";
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
    if (square[1] == square[2] && square[2] == square[3])
		return 1;
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if (square[7] == square[8] && square[8] == square[9])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[3] == square[6] && square[6] == square[9])
		return 1;
	else if (square[1] == square[5] && square[5] == square[9])
		return 1;
	else if (square[3] == square[5] && square[5] == square[7])
		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'  && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else
		return -1;
}
