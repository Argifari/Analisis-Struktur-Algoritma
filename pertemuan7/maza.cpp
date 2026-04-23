#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef struct{
    int i,j;
} Point;

typedef struct{
    Point p;
    int currentK, step;

    void set(Point a, int b, int c) {
        p = a;
        currentK = b;
        step = c;
    }

}Status;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, M, K;
    cin >> N >> M >> K;

    if (N == 1 && M == 1) {

        cout<<-1<<endl;
        return 0;
    }

    string matrik[N];

    for (ll i = 0; i < N; i++) {
        cin>>matrik[i];
    }

    queue<Status>node;

    Point start, end;
    start.i = -1; start.j = -1;
    end.i = -1; end.j = -1;


    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M; j++) {
            if (matrik[i][j] == 'S') {
                start.i = i; start.j = j;
            }else if (matrik[i][j] == 'E') {
                end.i = i; end.j = j;
            }
        }
    }

    if (start.i == -1 || end.i == -1) {
        cout<<-1<<endl;
        return 0;
    }
    Status startPoint;
    startPoint.set(start,K,0);


    node.push(startPoint);

    while (!node.empty()) {
        Status currentNode = node.front();
        node.pop();

        
    }




    
    


    return 0;
}