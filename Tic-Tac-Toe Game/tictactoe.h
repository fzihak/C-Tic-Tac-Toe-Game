#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <algorithm>
#include <limits>

class TicTacToe {
private:
    std::vector<char> board;
    char currentPlayer;
    int playerXWins;
    int playerOWins;
    int draws;

    void initializeBoard() {
        board = std::vector<char>(9, ' ');
        currentPlayer = 'X';
    }

    void displayBoard() const {
        std::cout << "\n";
        for (int i = 0; i < 9; i += 3) {
            std::cout << " " << board[i] << " | " << board[i + 1] << " | " << board[i + 2] << "\n";
            if (i < 6) std::cout << "---+---+---\n";
        }
        std::cout << "\n";
    }

    bool makeMove(int position) {
        if (position < 0 || position > 8 || board[position] != ' ') {
            return false;
        }
        board[position] = currentPlayer;
        return true;
    }

    bool checkWin() const {
        const int winPatterns[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // Rows
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // Columns
            {0, 4, 8}, {2, 4, 6}              // Diagonals
        };

        for (const auto& pattern : winPatterns) {
            if (board[pattern[0]] != ' ' &&
                board[pattern[0]] == board[pattern[1]] &&
                board[pattern[1]] == board[pattern[2]]) {
                return true;
            }
        }
        return false;
    }

    bool isBoardFull() const {
        return std::find(board.begin(), board.end(), ' ') == board.end();
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    int minimax(std::vector<char>& board, int depth, bool isMaximizing) {
        if (checkWin()) {
            return isMaximizing ? -10 : 10;
        }
        if (isBoardFull()) {
            return 0;
        }

        int bestScore = isMaximizing ? -1000 : 1000;
        char player = isMaximizing ? 'O' : 'X';

        for (int i = 0; i < 9; ++i) {
            if (board[i] == ' ') {
                board[i] = player;
                int score = minimax(board, depth + 1, !isMaximizing);
                board[i] = ' ';

                if (isMaximizing) {
                    bestScore = std::max(score, bestScore);
                } else {
                    bestScore = std::min(score, bestScore);
                }
            }
        }

        return bestScore;
    }

    int getBestMove() {
        int bestScore = -1000;
        int bestMove = -1;

        for (int i = 0; i < 9; ++i) {
            if (board[i] == ' ') {
                board[i] = 'O';
                int score = minimax(board, 0, false);
                board[i] = ' ';

                if (score > bestScore) {
                    bestScore = score;
                    bestMove = i;
                }
            }
        }

        return bestMove;
    }

public:
    TicTacToe() : playerXWins(0), playerOWins(0), draws(0) {
        initializeBoard();
    }

    void playGame(bool vsAI) {
        initializeBoard();
        bool gameWon = false;

        std::cout << "Game started! " << (vsAI ? "You are X, AI is O." : "X goes first.") << "\n";
        std::cout << "Board positions are numbered 0-8 as follows:\n";
        std::cout << " 0 | 1 | 2 \n";
        std::cout << "---+---+---\n";
        std::cout << " 3 | 4 | 5 \n";
        std::cout << "---+---+---\n";
        std::cout << " 6 | 7 | 8 \n\n";

        while (!gameWon && !isBoardFull()) {
            displayBoard();
            int move;

            if (vsAI && currentPlayer == 'O') {
                std::cout << "AI is thinking...\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                move = getBestMove();
                std::cout << "AI chose position " << move << "\n";
            } else {
                std::cout << "Player " << currentPlayer << ", enter your move (0-8): ";
                while (!(std::cin >> move) || move < 0 || move > 8 || board[move] != ' ') {
                    std::cout << "Invalid input. Please enter a number between 0-8 for an empty position: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }

            if (makeMove(move)) {
                if (checkWin()) {
                    displayBoard();
                    std::cout << "Player " << currentPlayer << " wins!\n";
                    gameWon = true;
                    if (currentPlayer == 'X') playerXWins++;