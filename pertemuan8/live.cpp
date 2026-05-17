#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define jago ios_base::sync_with_stdio(0);
#define bgt cin.tie(0);
#define whenyah return 0;

int N,M,E;

vector<ll> jalanDesa[20];
ll fasilitas[25];

ll hasil = 0;

bool isSafe(int desa, int i) {
    if (desa % 2 == 1 && i == 1) {
        return false;
    }

    for (int tetanggaDesa : jalanDesa[desa]) {
        if (fasilitas[tetanggaDesa] == i) {
            return false;
        }
    }
    return true;
}



void backtrack(int currentDesa) {
    if (currentDesa > N) {
        hasil++;
        return;
    }

    for (int i = 1; i <= M; i++) {
        if (isSafe(currentDesa, i)) {
            fasilitas[currentDesa] = i;
            backtrack(currentDesa + 1);
            fasilitas[currentDesa] = 0;
        }
    }
}


int main () {
    jago bgt

    cin >> N >> M >> E;

    for (int i = 0; i < E; i++) {
        ll a, b;
        cin >> a >> b;
        jalanDesa[a].push_back(b);
        jalanDesa[b].push_back(a);
    }

    for (int i = 0; i <= M; i++) {
        fasilitas[i] = 0;
    }

    backtrack(1);

    cout << hasil << endl;

    whenyah
}