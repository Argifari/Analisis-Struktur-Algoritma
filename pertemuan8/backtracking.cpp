#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define jago ios_base::sync_with_stdio(0);
#define bgt cin.tie(0);

// Muhammad Firdaus Argifari

// 24060124130107


int N,M,E;
vector<int> jalanDesa[20];
int fasilitas[20];

ll hasil = 0;

bool isSafe(int desa, int i) {
    if (desa % 2 == 1 && i == 1) {
        return false;
    }

    for (int desaSebelah : jalanDesa[desa]) {
        if (fasilitas[desaSebelah] == i) {
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

    for (int i = 0; i < E;i++) {
        int u, v;
        cin >> u >> v;
        jalanDesa[u].push_back(v);
        jalanDesa[v].push_back(u);
    }

    for (int i = 0; i <= N; i++) {
        fasilitas[i] = 0;
    }

    backtrack(1);

    cout<< hasil << endl;

    return 0;
}