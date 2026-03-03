#include <iostream>
#include <vector>
using namespace std;

// Muhammad Firdaus Argifari
// 24060124130107

int main() {
    int N; 
    cin >> N;
    
    vector <int> posQueen(N, -1);
    int row = 0;

    while (row >= 0) {
        bool isFound = false;
        for (int column = posQueen[row] + 1; column < N; column++) {
            bool aman = true;
            
            for (int i = 0; i < row; i++) {
                bool isDiagonal = abs(i-row) == abs(posQueen[i] - column);
                if (posQueen[i] == column || isDiagonal) {
                    aman = false;
                    break;
                }
            }
            if (aman) {
                posQueen[row] = column;
                isFound = true;
                break;
            }
        }
        if (isFound) {
            if (row == N - 1) {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        if (j == posQueen[i]) {
                            cout << 'Q';
                        }else {
                            cout << '.';
                        }
                    }cout << endl;
                }return 0;
            }else {
                row++;
                posQueen[row] = -1;
            }
        }else {
            row--;
        }
    }
    cout << "Kerajaan tidak dapat dilindungi!" << endl;
    return 0;
}