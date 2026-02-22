#include <iostream>
using namespace std;

int main () {
    int N,T;
    cin >> N;
    cin >> T;
    int A[N];

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int maksimalKali = -1;
    int cek;

    for (int i = 0; i < N; i++) {
        cek = abs(T - A[i]);
        for (int j = i + 1; j < N; j++) {
            if (cek == A[j]) {
                if (A[j]*A[i] > maksimalKali) {
                    maksimalKali = A[j] * A[i];
                }
            }
        }    
    }

    cout << maksimalKali << endl;

    return 0;
}