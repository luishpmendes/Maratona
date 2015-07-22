#include <iostream>
#include <string>
#include <vector>

#define BLACK 0
#define WHITE 1

using namespace std;

int d, rWhite, cWhite, rBlack, cBlack;
vector <string> board;

bool readBoard () {
    board.clear();
    int i = 0;
    string line;
    for (i = 0; i < 8 && (getline(cin, line)); i++) {
        board.push_back(line);
    }
    getline(cin, line);
    return (i >= 8);
}

bool isEmpty () {
    for (int i = 0; i < (int) board.size(); i++) {
        for (int j = 0; j < (int) board[i].length(); j++) {
            if (board[i][j] != '.') {
                return false;
            }
        }
    }
    return true;
}

void findKings (int * rWhite, int * cWhite, int * rBlack, int * cBlack) {
    (* rWhite) = (* cWhite) = (* rBlack) = (* cBlack) = -1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((* rWhite) >= 0 && 
                (* cWhite) >= 0 && 
                (* rBlack) >= 0 && 
                (* cBlack) >= 0) {
                return;
            }
            if (board[i][j] == 'K') {
                (* rWhite) = i;
                (* cWhite) = j;
            } else if (board[i][j] == 'k') {
                (* rBlack) = i;
                (* cBlack) = j;
            }
        }
    }
}

bool inCheckByPawn (int row, int col, char piece, int color) {
    if (color == BLACK) {
        if (row < 8 - 1) {
            if (col >= 1) {
                if (board[row + 1][col - 1] == piece) {
                    return true;
                }
            }
            if (col < 8 - 1) {
                if (board[row + 1][col + 1] == piece) {
                    return true;
                }
            }
        }
    } else {
        if (row >= 1) {
            if (col >= 1) {
                if (board[row - 1][col - 1] == piece) {
                    return true;
                }
            }
            if (col < 8 - 1) {
                if (board[row - 1][col + 1] == piece) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool inCheckByKnight (int row, int col, char piece) {
    if (row >= 2 && col < 8 - 1) {
        if (board[row - 2][col + 1] == piece) {
            return true;
        }
    }
    if (row >= 1 && col < 8 - 2) {
        if (board[row - 1][col + 2] == piece) {
            return true;
        }
    }
    if (row < 8 - 1 && col < 8 - 2) {
        if (board[row + 1][col + 2] == piece) {
            return true;
        }
    }
    if (row < 8 - 2 && col < 8 - 1) {
        if (board[row + 2][col + 1] == piece) {
            return true;
        }
    }
    if (row < 8 - 2 && col >= 1) {
        if (board[row + 2][col - 1] == piece) {
            return true;
        }
    }
    if (row < 8 - 1 && col < 8 - 2) {
        if (board[row + 1][col + 2] == piece) {
            return true;
        }
    }
    if (row >= 1 && col < 8 - 2) {
        if (board[row - 1][col + 2] == piece) {
            return true;
        }
    }
    if (row >= 2 && col >= 1) {
        if (board[row - 2][col - 1] == piece) {
            return true;
        }
    }
    return false;
}

bool inCheckByBishop (int row, int col, char piece) {
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == piece) {
            return true;
        } else if (board[i][j] != '.') {
            break;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < 8; i--, j++) {
        if (board[i][j] == piece) {
            return true;
        } else if (board[i][j] != '.') {
            break;
        }
    }
    for (int i = row + 1, j = col - 1; i < 8 && j >= 0; i++, j--) {
        if (board[i][j] == piece) {
            return true;
        } else if (board[i][j] != '.') {
            break;
        }
    }
    for (int i = row + 1, j = col + 1; i < 8 && j < 8; i++, j++) {
        if (board[i][j] == piece) {
            return true;
        } else if (board[i][j] != '.') {
            break;
        }
    }
    return false;
}

bool inCheckByRook (int row, int col, char piece) {
    for (int i = row - 1, j = col; i >= 0; i--) {
        if (board[i][j] == piece) {
            return true;
        } else if (board[i][j] != '.') {
            break;
        }
    }
    for (int i = row + 1, j = col; i < 8; i++) {
        if (board[i][j] == piece) {
            return true;
        } else if (board[i][j] != '.') {
            break;
        }
    }
    for (int i = row, j = col - 1; j >= 0; j--) {
        if (board[i][j] == piece) {
            return true;
        } else if (board[i][j] != '.') {
            break;
        }
    }
    for (int i = row, j = col + 1; j < 8; j++) {
        if (board[i][j] == piece) {
            return true;
        } else if (board[i][j] != '.') {
            break;
        }
    }
    return false;
}

bool inCheckByQueen (int row, int col, char piece) {
    return (inCheckByBishop(row, col, piece) || 
            inCheckByRook(row, col, piece));
}

bool inCheckByKing (int row, int col, char piece) {
    if (row >= 1) {
        if (col >= 1) {
            if (board[row - 1][col - 1] == piece) {
                return true;
            }
        }
        if (col < 8 - 1) {
            if (board[row - 1][col + 1] == piece) {
                return true;
            }
        }
        if (board[row - 1][col] == piece) {
            return true;
        }
    }
    if (row < 8 - 1) {
        if (col >= 1) {
            if (board[row + 1][col - 1] == piece) {
                return true;
            }
        }
        if (col < 8 - 1) {
            if (board[row + 1][col + 1] == piece) {
                return true;
            }
        }
        if (board[row + 1][col] == piece) {
            return true;
        }
    }
    if (col >= 1) {
        if (board[row][col - 1] == piece) {
            return true;
        }
    }
    if (col < 8 - 1) {
        if (board[row][col + 1] == piece) {
            return true;
        }
    }
    return false;
}

bool blackInCheck (int row, int col) {
    return (inCheckByPawn(row, col, 'P', BLACK) || 
            inCheckByKnight(row, col, 'N') || 
            inCheckByBishop(row, col, 'B') || 
            inCheckByRook(row, col, 'R') || 
            inCheckByQueen(row, col, 'Q') || 
            inCheckByKing(row, col, 'K'));
}

bool whiteInCheck (int row, int col) {
    return (inCheckByPawn(row, col, 'p', WHITE) || 
            inCheckByKnight(row, col, 'n') || 
            inCheckByBishop(row, col, 'b') || 
            inCheckByRook(row, col, 'r') || 
            inCheckByQueen(row, col, 'q') || 
            inCheckByKing(row, col, 'k'));
}

int main () {
    int d = 0;
    while (readBoard() && !isEmpty()) {
        int rWhite, cWhite, rBlack, cBlack;
        findKings(&rWhite, &cWhite, &rBlack, &cBlack);
        cout << "Game #" << ++d << ": ";
        if (blackInCheck(rBlack, cBlack)) {
            cout << "black king is in check." << endl;
        } else if (whiteInCheck(rWhite, cWhite)) {
            cout << "white king is in check." << endl;
        } else {
            cout << "no king is in check." << endl;
        }
    }
    return 0;
}
