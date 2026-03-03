#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// Muhammad Firdaus Argifari 
// 24060124130107

struct Points {
    int X, Y;
};
typedef Points Titik;

int main() {
    int N;
    cin >> N;
    Titik T[N];
    for (int i = 0;i < N; i++) {
        cin >> T[i].X >>T[i].Y;
    }
    
    int maksTot = -1;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j<N; j++) {
            int cekTitik = 0;
            int maksSem = -1;
            int x1 = T[i].X, y1 = T[i].Y;
            int x2 = T[j].X, y2 = T[j].Y;
            if (x1 != x2 && y1 != y2) {
                for (int l = 0; l < N; l++) {
                    if (i != l && j != l) {
                        if (x1 == T[l].X && y2 == T[l].Y  ) {
                            cekTitik +=1;
                        }
                        if (x2 == T[l].X && y1 == T[l].Y  ) {
                            cekTitik += 1;
                        }
                        
                    }
                }
                if (cekTitik == 2) {
                    maksSem = abs(x2-x1) * abs(y2-y1);
                    if (maksTot < maksSem) {
                        maksTot = maksSem;
                    }
                }
            }
        }
    }
    cout << maksTot << endl;
    return 0;
}
