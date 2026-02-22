#include <bits/stdc++.h>
using namespace std;

int main () {

    int N, berat = -1;
    int ganjil = 0;
    int genap = 0;

    cin>>N;
    
    
    
    long long W[N];
    for (int i = 0; i < N; i++) {
        cin>>W[i];
        if (W[i] % 2 == 1) {
            ganjil++;
        }else {
            genap++;
        }
    }
    
    int WGenap[genap];
    int WGanjil[ganjil];
    int iGenap = 0;
    int iGanjil = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (W[i] > W[j] ) {
                int temp = W[j];
                W[j] = W[i];
                W[i] = temp;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (W[i] % 2 == 0) {
            WGenap[iGenap] = W[i];
            iGenap++;
        }else {
            WGanjil[iGanjil] = W[i];
            iGanjil++;
        }
    }

    if (ganjil >= 3) {
        if (WGanjil[0] + WGanjil[1] + WGanjil[2] > berat) {
            berat = WGanjil[0] + WGanjil[1] + WGanjil[2];
        }
    }
    if (ganjil >= 2 && genap >= 1) {
        if (WGanjil[0] + WGanjil[1] + WGenap[0] > berat) {
            berat = WGanjil[0] + WGanjil[1] + WGenap[0];
        }
    }

    cout << berat << endl;



    return 0;
}