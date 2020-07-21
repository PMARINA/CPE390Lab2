#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

void welcome_message() {
  cout << "-----------------------" << endl;
  cout << "Welcome to tic tac toe!" << endl;
  cout << "-----------------------" << endl;
}

uint8_t get_player_symbol() {
  char symbol = 0;
  while (symbol != 'X' && symbol != 'O') {
    cout << "Select your symbol: (X or O): " << endl;
    cin >> symbol;
    if (symbol != 'X' && symbol != 'O') {
      cout << "Not a valid option" << endl;
    }
  }
  switch (symbol) {
    case 'X':
      return 1;
      break;
    case 'O':
      return 2;
      break;
    default:
      return 0;
      break;
  }
}

bool get_player_plays_first() {
  uint8_t choice = 0;
  // !( Cond1 || Cond2 )
  // !Cond1  && !Cond2
  /*
   * Cond1  Cond2   Output    Output
   * True   True    False     False
   * True   False   False     False
   * False  False   True     True
   */
  while (choice != '1' && choice != '2') {
    cout << "Enter 1 if you would like to go first, Enter 2 if you would like "
            "to go second"
         << endl;
    std::cin >> choice;
    if (choice != '1' && choice != '2') {
      cout << "Invalid choice, please try again" << endl;
    }
  }
  if (choice == '1') {
    cout << "You will go first" << endl;
    return true;  // go first
  } else {
    cout << "You will go second" << endl;
    return false;  // go second
  }
}

bool is_game_over(uint8_t* board) {
  // horizontal checking
  for (int i = 0; i < 9; i += 3) {
    if (board[i] == board[i + 1] && board[i + 1] == board[i + 2] &&
        board[i] != 0) {
      cout << "HORIZONTAL WIN" << endl;
      return true;
    }
  }
  // vertical checking
  for (int i = 0; i < 3; i++) {
    if (board[i] == board[i + 3] && board[i + 3] == board[i + 6] &&
        board[i] != 0) {
      cout << "VERTICAL WIN" << endl;
      return true;
    }
  }

  // diagonals
  if (board[0] == board[4] && board[4] == board[8] && board[0] != 0) {
    return true;
    cout << "DIAG WIN" << endl;
  } else if (board[2] == board[4] && board[4] == board[6] && board[2] != 0) {
    return true;
    cout << "DIAG WIN" << endl;
  }
  // // 0 1 2
  // // 3 4 5
  // // 6 7 8
  // uint8_t box1;
  // uint8_t box2;
  // uint8_t box3;
  // // check diagonal wins
  // box1 = board[0];
  // box2 = board[4];
  // box3 = board[8];
  // if ((box1 == 1) && (box2 == 1) && (box3 = 1)) {
  //   return true;  // X wins
  // } else if ((box1 == 2) && (box2 == 2) && (box3 = 2)) {
  //   return true;  // O wins
  // }
  // box1 = board[2];
  // box2 = board[4];
  // box3 = board[6];
  // if ((box1 == 1) && (box2 == 1) && (box3 = 1)) {
  //   return true;  // X wins
  // } else if ((box1 == 2) && (box2 == 2) && (box3 = 2)) {
  //   return true;  // O wins
  // }
  // // check vertical wins
  // for (int i = 0; i < 9; i = i + 3) {
  //   box1 = board[i];
  //   box2 = board[i + 3];
  //   box3 = board[i + 6];
  //   if ((box1 == 1) && (box2 == 1) && (box3 = 1)) {
  //     return true;  // X wins
  //   } else if ((box1 == 2) && (box2 == 2) && (box3 = 2)) {
  //     return true;  // O wins
  //   }
  // }
  // // check horizontal wins
  // for (int i = 0; i < 9; i = i + 3) {
  //   box1 = board[i];
  //   box2 = board[i + 1];
  //   box3 = board[i + 2];
  //   if ((box1 == 1) && (box2 == 1) && (box3 = 1)) {
  //     return true;  // X wins
  //   } else if (box1 == 2 && box2 == 2 && (box3 = 2)) {
  //     return true;  // O wins
  //   }
  // }
  // check if board is full
  bool empty = false;
  for (int i = 0; i < 9; i++) {
    if (board[i] == 0) {
      empty = true;
    }
  }
  if (empty == false) {
    return true;  // board is full
  }
  return false;  // the game is not over
}

void print_board(const uint8_t* board) {  //   A B C
  // 1
  // 2
  // 3
  // 0 = empty
  // 1 = X
  // 2 = O
  int columns = 3;
  int rows = 3;
  cout << " ";
  for (int i = 0; i < columns; i++) {
    cout << "    " << char('A' + i);
    cout << "\t";
  }
  cout << endl;
  for (int i = 0; i < rows; i++) {
    cout << " " << char('1' + i);
    for (int k = 0; k < columns; k++) {
      string str = "";
      switch (board[k + i * columns]) {
        case 0:
          str = "\t";
          break;
        case 1:
          str = "  X   ";
          break;
        case 2:
          str = "  O   ";
      }
      if (k <= 1) str += "|";
      cout << str;
    }
    cout << endl;
  }
  cout << endl;
}

uint8_t get_move() {
  /*
   * A1 A2 A3
   * B1 B2 B3
   * C1 C2 C3
   *
   * 0  1  2
   * 3  4  5
   * 6  7  8
   *
   * A = 65
   *
   *
   */
  uint8_t return_value = 0;
  bool not_done = true;
  char letter;
  char number;
  while (not_done) {
    cout << "Enter the coordinate you'd like to make your move on (i.e. A1, "
            "C2): "
         << endl;
    cin >> letter >> number;
    not_done = letter < 'A' || letter > 'C' || number < '1' || number > '3';
  }
  return_value = (letter - 'A') + 3 * (number - '1');
  return return_value;
}

bool is_valid(uint8_t* board, uint8_t move) {
  // if the space is empty then its a valid position
  if (board[move] == 0) {
    return true;
  } else {
    return false;
  }
}

void run_player_turn(uint8_t& board, uint8_t player_symbol) {
  print_board(&board);

  uint8_t move = get_move();
  while (!is_valid(&board, move)) {
    move = get_move();
  }

  (&board)[move] = player_symbol;
  // ask the player for their move
  // check if legal
  // if so, return the board
}

void run_AI(uint8_t& board, uint8_t player_symbol) {
  uint8_t ai_symbol;
  if (player_symbol == 1)
    ai_symbol = 2;
  else
    ai_symbol = 1;

  // AI works by running all possibilities and CANNOT lose
  // 1. try to win
  // 2. block the player from winning
  // 3. pick whatever spot is left.
  cout << "STARTING CHECKING" << endl;
  for (uint8_t i = 0; i < 9; i++) {
    uint8_t copy_board[9];
    memcpy(copy_board, &board, sizeof(uint8_t) * 9);
    if (copy_board[i] == 0) {
      copy_board[i] = ai_symbol;
      if (is_game_over(copy_board)) {
        (&board)[i] = ai_symbol;
        return;
      }
    }
  }
  cout << "Checking block" << endl;
  for (uint8_t i = 0; i < 9; i++) {
    uint8_t copy_board[9];
    memcpy(copy_board, &board, sizeof(uint8_t) * 9);
    if (copy_board[i] == 0) {
      copy_board[i] = player_symbol;
      if (is_game_over(copy_board)) {
        (&board)[i] = ai_symbol;
        return;
      }
    }
  }
  cout << "Picking available cell" << endl;
  for (uint8_t i = 0; i < 9; i++) {
    if ((&board)[i] == 0) {
      (&board)[i] = ai_symbol;
      return;
    }
  }
}

int main() {
  welcome_message();
  uint8_t board[9] = {0};
  // 0 = empty
  // 1 = X
  // 2 = O
  uint8_t player_symbol = get_player_symbol();
  bool is_players_turn = get_player_plays_first();
  print_board(board);
  bool done = is_game_over(board);
  cout << done << endl;
  while (!done) {
    if (is_players_turn) {
      run_player_turn(*board, player_symbol);
      cout << "DONE WITH PLAYERTURN" << endl;
      is_players_turn = false;
    } else {
      run_AI(*board, player_symbol);
      is_players_turn = true;
      cout << "DONE WITH AI TURN" << endl;
    }
    done = is_game_over(board);
    cout << done << endl;
  }
  print_board(board);
}
