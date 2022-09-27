#include <iostream>
#include <stdlib.h>
using namespace std;
#define RESET "\033[0m"
#define GREEN "\033[32m"
// Edit version 1: Added the code for printing ASCII text in red and blue
#define RED "\033[31m"
#define BLUE "\033[34m"

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int choicesForComputer[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

// To change color on board
void color_text(char s)
{
    if (s == 'X')
    {
        cout << BLUE << "X" << RESET;
    }
    else if (s == '0')
    {
        cout << GREEN << "O" << RESET;
    }
    else
        cout << s;
}
// If option 1 is chosen then :
// computer uses this function to make it's move
int ChoiceOfComputer()
{
    srand(time(0));
    int k;
    bool valid = false;
    if (square[1] == square[2] && square[3] == '3')
    {
        return 3;
    }
    else if (square[2] == square[3] && square[1] == '1')
    {
        return 1;
    }
    else if (square[1] == square[3] && square[2] == '2')
    {
        return 2;
    }
    else if (square[4] == square[5] && square[6] == '6')
    {
        return 6;
    }
    else if (square[4] == square[6] && square[5] == '5')
    {
        return 5;
    }
    else if (square[5] == square[6] && square[4] == '4')
    {
        return 4;
    }
    else if (square[7] == square[8] && square[9] == '9')
    {
        return 9;
    }
    else if (square[8] == square[9] && square[7] == '7')
    {
        return 7;
    }
    else if (square[9] == square[7] && square[8] == '8')
    {
        return 8;
    }
    else if (square[7] == square[4] && square[1] == '1')
    {
        return 1;
    }
    else if (square[7] == square[1] && square[4] == '4')
    {
        return 4;
    }
    else if (square[1] == square[4] && square[7] == '7')
    {
        return 7;
    }
    else if (square[2] == square[5] && square[8] == '8')
    {
        return 8;
    }
    else if (square[2] == square[8] && square[5] == '5')
    {
        return 5;
    }
    else if (square[5] == square[8] && square[2] == '2')
    {
        return 2;
    }
    else if (square[6] == square[3] && square[9] == '9')
    {
        return 9;
    }
    else if (square[9] == square[3] && square[6] == '6')
    {
        return 6;
    }
    else if (square[9] == square[6] && square[3] == '3')
    {
        return 3;
    }
    else if (square[5] == square[9] && square[1] == '1')
    {
        return 1;
    }
    else if (square[1] == square[9] && square[5] == '5')
    {
        return 5;
    }
    else if (square[5] == square[1] && square[9] == '9')
    {
        return 9;
    }
    else if (square[5] == square[3] && square[7] == '7')
    {
        return 7;
    }
    else if (square[7] == square[3] && square[5] == '5')
    {
        return 5;
    }
    else if (square[5] == square[7] && square[3] == '3')
    {
        return 3;
    }

    else
    {
        while (!valid)
        {
            k = rand() % 9 + 1;
            for (int i = 0; i < 9; i++)
            {
                if (k == choicesForComputer[i])
                {
                    valid = true;
                    return k;
                }
            }
        }
    }
    return 0;
}


// Checks the given arrangement satisfies the winning condition or not.
// if returns 1 : game over
// if returns -1 : game is in progress
// if returns 0 : game is over but no one is winner
int checkwin()
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
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}

// Draws and maintains the board of tic-tac-toe
void board(string a, string b)
{

    cout << "\n\n\tTic Tac Toe\n\n";

    cout << a << " (X)  &  " << b << " (O)" << endl
         << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  ";
    color_text(square[1]);
    cout << "  |  ";
    color_text(square[2]);
    cout << "  |  ";
    color_text(square[3]);
    cout << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  ";
    color_text(square[4]);
    cout << "  |  ";
    color_text(square[5]);
    cout << "  |  ";
    color_text(square[6]);
    cout << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  ";
    color_text(square[7]);
    cout << "  |  ";
    color_text(square[8]);
    cout << "  |  ";
    color_text(square[9]);
    cout << endl;

    cout << "     |     |     " << endl
         << endl;
}

// Main TIC_TAC_TOE function. Carry outs each procedure.
int TIC_TAC_TOE(){
string players[2];
    bool q = true;
    int choices;
    while (q)
    {
        cout << BLUE << "Select the option:" << RESET << endl;
        cout << GREEN << "     Single player" << RESET << "(second player will be COMPUTER) : Enter 1" << endl;
        cout << GREEN << "     Double player" << RESET << " : Enter 2" << endl;

        cin >> choices;
        if (choices < 1 || choices > 2)
        {
            cout << "Invalid Option" << endl;
        }
        else
        {
            q = false;
        }
    }
    if (choices == 2)
    {
        cout << BLUE << "Please enter Player 1 Name: " << RESET;
        cin >> players[0];
        cout << BLUE << "Please enter Player 2 Name: " << RESET;
        cin >> players[1];
        int player = 1, i = -1, choice;
        char mark;
        bool invalid = false;
        while (i == -1)
        {
            board(players[0], players[1]);
            if (player % 2 == 1)
            {
                player = 1;
            }
            else
            {
                player = 2;
            }
            if (invalid)
            {
                cout << "Your move was " << RED << "INVALID" << RESET << " enter again." << endl;
                invalid = false;
            }
            cout << players[player - 1] << " it's your turn, please enter a number:  ";
            cin >> choice;

            if (player == 1)
            {
                mark = 'X';
            }
            else
            {
                mark = '0';
            }

            if (choice == 1 && square[1] == '1')

                square[1] = mark;
            else if (choice == 2 && square[2] == '2')

                square[2] = mark;
            else if (choice == 3 && square[3] == '3')

                square[3] = mark;
            else if (choice == 4 && square[4] == '4')

                square[4] = mark;
            else if (choice == 5 && square[5] == '5')

                square[5] = mark;
            else if (choice == 6 && square[6] == '6')

                square[6] = mark;
            else if (choice == 7 && square[7] == '7')

                square[7] = mark;
            else if (choice == 8 && square[8] == '8')

                square[8] = mark;
            else if (choice == 9 && square[9] == '9')

                square[9] = mark;
            else
            {
                invalid = true;
                player--;
            }
            i = checkwin();

            player++;
        }
        board(players[0], players[1]);
        if (i == 1){
            if (player == 2)
            {
                cout << ">>> " << RED << players[0] << RESET << " won the game :)" << endl;
            }
            if (player == 3)
            {
                cout << ">>> " << RED << players[1] << RESET << " won the game :)" << endl;
            }
        }
        else
            cout << "==>\aGame draw :(";

        return 0;
    }

    if (choices == 1)
    {
        cout << BLUE << "Please enter Player Name: " << RESET;
        cin >> players[0];
        players[1] = "COMPUTER";
        int player = 1, i = -1, choice;
        char mark;
        bool invalid = false;
        while (i == -1)
        {

            if (player % 2 == 1)
            {
                player = 1;
                board(players[0], players[1]);
                if (invalid)
                {
                    cout << "Your move was " << RED << "INVALID" << RESET << " enter again." << endl;
                    invalid = false;
                }
                cout << players[player - 1] << " it's your turn, please enter a number:  ";
            }
            else
            {
                player = 2;
            }
            if (player == 1)
            {
                cin >> choice;
            }
            else
            {
                choice = ChoiceOfComputer();
            }
            if (player == 1)
            {
                mark = 'X';
            }
            else
            {
                mark = '0';
            }

            if (choice == 1 && square[1] == '1')
            {

                square[1] = mark;
                choicesForComputer[0] = mark;
            }
            else if (choice == 2 && square[2] == '2')
            {

                square[2] = mark;
                choicesForComputer[1] = mark;
            }
            else if (choice == 3 && square[3] == '3')
            {

                square[3] = mark;
                choicesForComputer[2] = mark;
            }
            else if (choice == 4 && square[4] == '4')
            {

                square[4] = mark;
                choicesForComputer[3] = mark;
            }
            else if (choice == 5 && square[5] == '5')
            {

                square[5] = mark;
                choicesForComputer[4] = mark;
            }
            else if (choice == 6 && square[6] == '6')
            {

                square[6] = mark;
                choicesForComputer[5] = mark;
            }
            else if (choice == 7 && square[7] == '7')
            {

                square[7] = mark;
                choicesForComputer[6] = mark;
            }
            else if (choice == 8 && square[8] == '8')
            {

                square[8] = mark;
                choicesForComputer[7] = mark;
            }
            else if (choice == 9 && square[9] == '9')
            {

                square[9] = mark;
                choicesForComputer[9] = mark;
            }
            else
            {
                invalid = true;
                player--;
            }
            i = checkwin();

            player++;
        }
        board(players[0], players[1]);
        if (i == 1)
        {
            if (player == 2)
            {
                cout << ">>> " << RED << players[0] << RESET << " won the game :)" << endl;
            }
            if (player == 3)
            {
                cout << ">>> " << RED << players[1] << RESET << " won the game :)" << endl;
            }
        }
        else
            cout << "==>\aGame draw :(" << endl;

        return 0;
    }
    return 0;
}


int main()
{
    cout << RED << "*********************************************************" << RESET << endl;
    cout << BLUE << "Welcome to Tic Tac Toe" << RESET << endl;
    cout << RED << "*********************************************************" << RESET << endl;
    TIC_TAC_TOE();
    return 0;
}
