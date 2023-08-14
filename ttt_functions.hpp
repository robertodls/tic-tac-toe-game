// Here in the header file we are declaring all the functions we are using in the main file
void introduction();
void draw_board(char board[]);
bool check_board(char board[], int position);
bool end_win_condition(char board[]);
std::string change_player(std::string actual_player);
char change_mark(char mark);
std::string check_winner(char board[]);
