// Muhammad Firdaus Argifari
// 24060124130107

#include <iostream>
#include <vector>
using namespace std;

int main () {
    
    long long D, M;
    cin >> D >> M;
    long long allAngka[D];
    long long vanishAngka[M];

    for (long long i = 0; i < D; i++) {
        cin >> allAngka[i];
    }
    for (long long i = 0; i < M; i++) {
        cin >> vanishAngka[i];
    }
    vector<long long> remainAngka;

    long long isVanish[D];
    for (long long i = 0; i < D; i++) {
        isVanish[i] = false;
    }

    long long remaining = 0;

    for (long long i = 0; i < M; i++) {
        for (long long j = 0; j < D; j++) {
            if (isVanish[j]) {
                continue;
            }
            if (vanishAngka[i] == allAngka[j]) {
                isVanish[j] = true;
            }
        }
    }
    for (long long i = 0; i < D; i++) {
        if (!isVanish[i]) {
            remaining++;
            remainAngka.push_back(allAngka[i]);
        }
    }
    if (remaining == 0) {
        cout << "KOSONG" << endl;
    }else {
        for (auto i : remainAngka) {
            cout << i << " ";
        }cout << endl;
    }

    return 0;
}