#include <iostream>

// This is just the introduction message printed once at the beggining of the game
void introduction() {
  std::cout << "============================\n";
  std::cout << "Welcome a Tic-Tac-Toe Game!\n";
  std::cout << "============================\n";
  std::cout << "This is the classic Tic-Tac-Toe game where two players play in turns to place marks in a horizontal, vertical or diagonal row in a 3x3 grid.\n\nThe player who succeeds in placing three of their marks in a row wins the game.\n\n";
  std::cout << "Player 1 has following mark: X.\nPlayer 2 has the following mark: O.\n\n";
}

// This function prints the grid/board in the terminal
void draw_board(char board[]) {
  std::cout << "     |     |      \n";
  std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";
  std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";
  std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
  std::cout << "     |     |      \n";
  std::cout << "\n";
}

// Checks if the position selected by the player is already marked
bool check_board(char board[], int position) {
  // If the position - 1 in the vector is equal to X or O it means is already in use, so it is not a valid position to insert
  if (board[position - 1] == 'X' || board[position - 1] == 'O') {
    return true;
  }
  else {
    return false;
  }
}

// Checks if a player has won or the game has finished
bool end_win_condition(char board[]) {
  // Horizontal first row condition
  if ((board[0] == 'X' && board[1] == 'X' && board[2] == 'X') || (board[0] == 'O' && board[1] == 'O' && board[2] == 'O')) {
    return true;
  }
  // Horizontal second row condition
  else if ((board[3] == 'X' && board[4] == 'X' && board[5] == 'X') || (board[3] == 'O' && board[4] == 'O' && board[5] == 'O')) {
    return true;
  }
  // Horizontal third row condition
  else if ((board[6] == 'X' && board[7] == 'X' && board[8] == 'X') || (board[6] == 'O' && board[7] == 'O' && board[8] == 'O')) {
    return true;
  }
  // Vertical first row condition
  else if ((board[0] == 'X' && board[3] == 'X' && board[6] == 'X') || (board[0] == 'O' && board[3] == 'O' && board[6] == 'O')) {
    return true;
  }
  // Vertical second row condition
  else if ((board[1] == 'X' && board[4] == 'X' && board[7] == 'X') || (board[1] == 'O' && board[4] == 'O' && board[7] == 'O')) {
    return true;
  }
  // Vertical third row condition
  else if ((board[2] == 'X' && board[5] == 'X' && board[8] == 'X') || (board[2] == 'O' && board[5] == 'O' && board[8] == 'O')) {
    return true;
  }
  // Diagonal first condition
  else if ((board[0] == 'X' && board[4] == 'X' && board[8] == 'X') || (board[0] == 'O' && board[4] == 'O' && board[8] == 'O')) {
    return true;
  }
  // Diagonal second condition
  else if ((board[2] == 'X' && board[4] == 'X' && board[6] == 'X') || (board[2] == 'O' && board[4] == 'O' && board[6] == 'O')) {
    return true;
  }
  else {
    return false;
  }
}

std::string change_player(std::string actual_player) {
  if (actual_player == "Player 1") {
    return "Player 2";
    }
  else if (actual_player == "Player 2") {
    return "Player 1";
    }
}

char change_mark(char mark) {
  if (mark == 'X') {
    return 'O';
    }
  else if (mark == 'O') {
    return 'X';
    } 
}

std::string check_winner(char board[]) {
  // Checks if Player 1 (X mark) wins
  if ((board[0] == 'X' && board[1] == 'X' && board[2] == 'X') || (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') || (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') || (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') || (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') || (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') || (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') || (board[2] == 'X' && board[4] == 'X' && board[6] == 'X')) {
    return "Player 1";
  }
  else {
    return "Player 2";
  }
}
