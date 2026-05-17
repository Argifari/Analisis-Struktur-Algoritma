#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define jago ios_base::sync_with_stdio(0);
#define bgt cin.tie(0);
#define whenyah return 0;

// Muhammad Firdaus Argifari

// 24060124130107

ll N, K, C;
ll konflik[40][40];
vector<ll>musisi;

ll hasil = 0;

bool isSafe(ll currentMusisi, vector<ll>& tim) {

    for (int nextMusisi : tim) {
        if (konflik[currentMusisi][nextMusisi] == 1) {
            return false;
        }
    }
    return true;
}


void backtrack(ll currentMusisi,ll ambil, ll total, vector<ll>& tim ) {
    if (ambil == K) {
        hasil = max(total, hasil);
        return;
    }

    if (currentMusisi > N || (N - currentMusisi + 1) < (K - ambil)) return;

    if (isSafe(currentMusisi, tim)) {
        tim.push_back(currentMusisi);
        backtrack(currentMusisi + 1, ambil + 1, total + musisi[currentMusisi-1], tim);
        tim.pop_back();
    }
    backtrack(currentMusisi + 1, ambil, total, tim);
}


int main () {
    jago bgt

    cin >> N >> K >> C;

    for (ll i = 0; i < N; i++) {
        ll a;
        cin >> a;
        musisi.push_back(a);
    }
    for (ll i = 0; i < C; i++) {
        ll a, b;
        cin >> a >> b;
        konflik[a][b] = 1;
        konflik[b][a] = 1;
    }


    vector<ll> tim;
    backtrack(1,0,0, tim);

    cout << hasil << endl;

    whenyah
}