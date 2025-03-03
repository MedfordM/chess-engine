#include <iostream>
#include <map>

enum COLUMNS {
  A = 1,
  B = 2,
  C = 3,
  D = 4,
  E = 5,
  F = 6,
  G = 7,
  H = 8
};

enum PIECES {
  EMPTY = 0,
  PAWN = 1,
  KNIGHT = 2,
  BISHOP = 3,
  ROOK = 4,
  QUEEN = 5,
  KING = 6
};

static const std::map<uint, char> COLUMN_LETTERS = {
  { A, 'A' },
  { B, 'B' },
  { C, 'C' },
  { D, 'D' },
  { E, 'E' },
  { F, 'F' },
  { G, 'G' },
  { H, 'H' },
};

static const std::map<uint, char> PIECE_LETTERS = {
  { EMPTY, ' ' },
  { PAWN, 'P' },
  { KNIGHT, 'K' },
  { BISHOP, 'B' },
  { ROOK, 'R' },
  { QUEEN, 'Q' },
  { KING, '+' }
};

void printBoard(uint board[8][8]) {
  std::cout << "   ";
  for (int i = A; i <= H; i++) {
    char colLetter = COLUMN_LETTERS.at(i);
    std::cout << "  " <<  colLetter << "   ";
  }
  std::cout << "\n  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐";
  for (int i = 0; i < 8; i++) {
    std::cout << "\n" << i + 1 << " │";
    for (int j = A; j <= H; j++) {
      uint piece = board[i][j];
      char pieceLetter = PIECE_LETTERS.at(piece);
      std::cout << "  " << pieceLetter << "  │";
    }
    if (i != 7) {
      std::cout << "\n  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤";
    } else {
      std::cout << "\n  └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘";
    }
  }
  std::cout << "\n";
}

void initBoard(uint board[8][8]) {
  std::cout << "Initializing board\n";
  for (int i = 0; i < 8; i++) {
    for (int j = A; j <= H; j++) {
      if (i > 1 && i < 6) {
        board[i][j] = EMPTY;
      } else if (i == 1 || i == 6) {
        board[i][j] = PAWN;
      } else if (j == A || j == H) {
        board[i][j] = ROOK;
      } else if (j == B || j == G) {
        board[i][j] = KNIGHT;
      } else if (j == C || j == F) {
        board[i][j] = BISHOP;
      } else if (j == D) {
        board[i][j] = QUEEN;
      } else if (j == E) {
        board[i][j] = KING;
      }
    }
  }
}

int main() {
  uint board[8][8];
  initBoard(board);
  printBoard(board);
  return 0;
}

