# include <iostream>
using namespace std;

int main() {
    int N; 
    cin >> N;

    char papan[N][N];

    for (int i = 0; i < N;i++) {
        for (int j = 0; j < N; j++) {
            papan[i][j] = '.';
        }
    }

    int nQueen = N;
    if (nQueen == 2 || nQueen == 3) {
        cout<<"Kerajaan tidak dapat dilindungi!"<<endl;
        return 0;
    }
    if (nQueen % 2 == 1) {
        int start = 0;
        int j = 0;
        for (int i = 0; i < N; i++) {
            if (j >= N) { 
                if (start == 2) {
                break;
            }
            start++;
            j = start;
        }
        papan[i][j] = 'Q';
        nQueen--;
        j += 2;
    }
        if (nQueen == 0) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cout <<papan[i][j];
                }
                cout<<endl;
            }
        }else {
            cout<<"Kerajaan tidak dapat dilindungi!"<<endl;
        }
    
    }else {
        int start = 1;
        int j = 1;
        for (int i = 0; i < N; i++) {
            if (j >= N) { 
                if (start == 0) {
                    break;
                }
                start--;
                j = start;
            }
            papan[i][j] = 'Q';
            nQueen--;
            j += 2;
        }
        if (nQueen == 0) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cout <<papan[i][j];
                }
                cout<<endl;
            }
        }else {
            cout<<"Kerajaan tidak dapat dilindungi!"<<endl;
        }
    
    }
    



    return 0;
}