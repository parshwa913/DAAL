#include <iostream>
#define N 128  

using namespace std;

int board[N][N]; 
int tile = 1;

void tileBoard(int topX, int topY, int missingX, int missingY, int size) {
    if (size == 2) {
        for (int i = topX; i < topX + size; i++) {
            for (int j = topY; j < topY + size; j++) {
                if (i != missingX || j != missingY) {
                    board[i][j] = tile;
                }
            }
        }
        tile++;
        return;
    }

    int halfSize = size / 2;

    if (missingX < topX + halfSize && missingY < topY + halfSize) {
        tileBoard(topX, topY, missingX, missingY, halfSize);
    } else {
        board[topX + halfSize - 1][topY + halfSize - 1] = tile;
        tileBoard(topX, topY, topX + halfSize - 1, topY + halfSize - 1, halfSize);
    }

    if (missingX < topX + halfSize && missingY >= topY + halfSize) {
        tileBoard(topX, topY + halfSize, missingX, missingY, halfSize);
    } else {
        board[topX + halfSize - 1][topY + halfSize] = tile;
        tileBoard(topX, topY + halfSize, topX + halfSize - 1, topY + halfSize, halfSize);
    }

    if (missingX >= topX + halfSize && missingY < topY + halfSize) {
        tileBoard(topX + halfSize, topY, missingX, missingY, halfSize);
    } else {
        board[topX + halfSize][topY + halfSize - 1] = tile;
        tileBoard(topX + halfSize, topY, topX + halfSize, topY + halfSize - 1, halfSize);
    }

    if (missingX >= topX + halfSize && missingY >= topY + halfSize) {
        tileBoard(topX + halfSize, topY + halfSize, missingX, missingY, halfSize);
    } else {
        board[topX + halfSize][topY + halfSize] = tile;
        tileBoard(topX + halfSize, topY + halfSize, topX + halfSize, topY + halfSize, halfSize);
    }
}

int main() {
    int n, missingX, missingY;
    cout << "Enter the size of the board (2^k): ";
    cin >> n;
    cout << "Enter the coordinates of the missing cell (x y): ";
    cin >> missingX >> missingY;

    tileBoard(0, 0, missingX, missingY, n);

    cout << "Tiled board:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
