#include <iostream>
#include <cstdlib>
using namespace std;
class TicTacToe_Game {
private:
    string player1, player2;
    char player1_char, player2_char;
    char position[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool check_char;

    void Game() const {
        cout << "\t\t\t\t         -----------------------------------" << endl << endl;
        cout << "\t\t\t\t***************( This TicTacToe_Game )***************\n" << endl;
        cout << "\t\t\t\t         -------Made By Saeed Youseef-------\n\n\n" << endl;
    }

    void welcome() const {
        cout << endl << endl << "------------------------------------" << endl;
        cout << " Welcome player1: " << player1 << endl;
        cout << " Your Char: " << player1_char << endl;
        cout << " Welcome player2: " << player2 << endl;
        cout << " Your Char: " << player2_char << endl;
        cout << "------------------------------------" << endl;
    }

    void definition_player() {
        Game();
        cout << "Enter Player1 Name: ";
        cin >> player1;
        cout << endl;

        cout << "Choose Your Char(X Or O): ";
        cin >> player1_char;
        cout << endl;

        cout << "Enter Player2 Name: ";
        cin >> player2;
        cout << endl;

        player1_char = toupper(player1_char);
        if (player1_char == 'X') {
            player2_char = 'O';
            check_char = true;
        } else {
            player2_char = 'X';
            check_char = false;
        }

        clear_screen();
        Game();
        welcome();
    }

    void grid() const {
        cout << "-------------" << endl;
        cout << "| " << position[1] << " | " << position[2] << " | " << position[3] << " |" << endl;
        cout << "-------------" << endl;
        cout << "| " << position[4] << " | " << position[5] << " | " << position[6] << " |" << endl;
        cout << "-------------" << endl;
        cout << "| " << position[7] << " | " << position[8] << " | " << position[9] << " |" << endl;
        cout << "-------------" << endl;
    }

    void play() {
        int number_of_plays = 9, pos = 0;
        bool no_winner = true;
        grid();
        while (number_of_plays) {
            if (number_of_plays % 2 == 1) {
                cout << "Player1 Choose Position: ";
            } else {
                cout << "Player2 Choose Position: ";
            }
            cin >> pos;

            if (pos < 1 || pos > 9 || position[pos] == 'X' || position[pos] == 'O') {
                cout << "Invalid position! Choose a position from 1 to 9 that is not already taken." << endl;
                continue;
            }

            if (number_of_plays % 2 == 1) {
                position[pos] = player1_char;
            } else {
                position[pos] = player2_char;
            }

            number_of_plays--;
            clear_screen();
            Game();
            welcome();
            grid();

            if (check_winner()) {
                if (number_of_plays % 2 == 1) {
                    cout << "The Player " << player2 << " Is Winner" << endl;
                } else {
                    cout << "The Player " << player1 << " Is Winner" << endl;
                }
                no_winner = false;
                break;
            }
        }

        if (no_winner) {
            cout << "NO WINNER HARD LUCK !!" << endl;
        }
    }

    bool check_winner() const {
        static const int win_conditions[8][3] = {
            {1, 2, 3}, {4, 5, 6}, {7, 8, 9},
            {1, 4, 7}, {2, 5, 8}, {3, 6, 9},
            {1, 5, 9}, {3, 5, 7}
        };

        for (const auto &condition : win_conditions) {
            if (position[condition[0]] == position[condition[1]] &&
                position[condition[1]] == position[condition[2]]) {
                return true;
            }
        }
        return false;
    }

    static void clear_screen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

public:
    static void Play_the_game() {
        int again;
        do {
            TicTacToe_Game play;
            play.definition_player();
            play.play();
            cout << "\nENTER 1 IF YOU WANT TO PLAY AGAIN, ELSE 0: ";
            cin >> again;
            clear_screen();
        } while (again);
        cout << "GOOD BYE" << endl;
    }
};

int main() {
    TicTacToe_Game::Play_the_game();
    return 0;
}
