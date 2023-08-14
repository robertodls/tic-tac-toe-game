#include <iostream>
#include "ttt_functions.hpp"

// This is the main function that executes the game code
int main() {
  // These are the variables that we are using and need within the code to do different things
  bool status_game = false;
  char mark = 'X';
  std::string actual_player = "Player 1";
  std::string winner;
  int position;
  int turn = 0;
  char board[9] = {'1' ,'2', '3', '4', '5', '6', '7', '8', '9'};

  introduction();

  // This while loop executes until someone has won or the grid/board is complete
  while (status_game == false) {
    draw_board(board);

    // Here the player inputs a position on the grid/board
    std::cout << actual_player << " it's your turn!\n\nWhat position in the grid do you want to mark?\n";
    std::cin >> position;

    // This while loop checks that the player inputs a valid grid position and a position that has not been already marked
    while ((position > 9 || position < 1) || check_board(board, position)) {
      std::cout << "ERROR. Enter a valid grid position or a position that has not been occupied.\n";
      std::cin >> position;
    }

    // This updates the board with the corresponding mark of the actual player
    board[position - 1] = mark;

    // This variable calls the function change_player and returns the next player
    actual_player = change_player(actual_player);
    
    // This variable calls the function change_mark and returns the next player's mark
    mark = change_mark(mark);

    // Checks if someone won
    status_game = end_win_condition(board);

    // If someone won, then we check who was
    if (status_game == true) {
      winner = check_winner(board);
    }

    // We add 1 to the variable turn
    turn++;

    // If turn equals 9 it means the grid/board is full marked
    if (turn == 9) {
      status_game = true;
    }
  }
  // We print to the terminal one last time to show the resulting grid/board
  draw_board(board);

  // We check if it's a tie or a player has won to print it to the terminal
  if (winner == "Player 1" || winner == "Player 2") {
    std::cout << "The winner is " << winner << ". Congratulations!\n";
  }
  else {
    std::cout << "It's a tie!\n";
  }
}
