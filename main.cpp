#include <iostream>
char square[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player[2] = {'X', 'Y'};
int turn = 0;
bool arduinoisconnected = false;
void board();
int checkwin = 0;
void board();
int main()
{
    board();
    return 0;
}
void board()
{
    // a lot of shit
    std::cout << "Player's turn: " << player[turn] << std::endl;
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
