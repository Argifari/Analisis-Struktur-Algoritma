// Muhammad Firdaus Argifari
// 24060124130107

#include <iostream>
using namespace std;

int main () {
    int N;
    cin >> N;
    int A[N];

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i] < A[j]) {
                int temp = A[j];
                A[j] = A[i];
                A[i] = temp;
            }
        }
    }

    int totalPower = A[0] + A[1];

    cout << totalPower << endl;
    return 0;
}