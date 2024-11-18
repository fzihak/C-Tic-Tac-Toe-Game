#include <iostream>
#include <limits>
#include <cstdlib>
#include "tictactoe.h"

void clearScreen() {
#ifdef _WIN32
    if (system("cls") == -1) {
        std::cerr << "Error clearing screen" << std::endl;
    }
#else
    if (system("clear") == -1) {
        std::cerr << "Error clearing screen" << std::endl;
    }
#endif
}

int main() {
    TicTacToe game;
    int choice;

    while (true) {
        clearScreen();
        std::cout << "\n=== TIC-TAC-TOE GAME ===\n\n";
        std::cout << "1. Play against another player\n";
        std::cout << "2. Play against AI\n";
        std::cout << "3. View game statistics\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1-4): ";

        while (!(std::cin >> choice) || choice < 1 || choice > 4) {
            std::cout << "Invalid input. Please enter a number between 1 and 4: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                clearScreen();
                game.playGame(false);
                break;
            case 2:
                clearScreen();
                game.playGame(true);
                break;
            case 3:
                clearScreen();
                game.displayStatistics();
                break;
            case 4:
                clearScreen();
                std::cout << "Thanks for playing! Goodbye!\n";
                return 0;
        }

        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

    return 0;
}