#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector <vector<int>> result;
vector <int> blockBit;

void placeBit(int iterator, int remainK){
    if (iterator == N) {
        if (remainK == 0){
            result.push_back(blockBit);
            return;
        }
    }
    else {
        if (remainK > (N - iterator + 1) / 2) {
            return;
        }

        blockBit[iterator] =  0;
        placeBit(iterator+1,remainK);

        bool isSafe = (iterator == 0 || blockBit[iterator-1] == 0);

        if (isSafe && remainK > 0){
            blockBit[iterator] = 1;
            placeBit(iterator+1, remainK-1);
            blockBit[iterator] = 0;
        }
    }
}


int main () {
    cin >> N >> K;
    blockBit.assign(N,0);

    placeBit(0,K);

    if (result.empty()) {
        cout<<-1<<endl;
        return 0;
    }

    for (const auto& i: result) {
        for (int j = 0; j < N;j++) {
            cout << i[j] << " ";
        }
        cout << endl;
    }

}
