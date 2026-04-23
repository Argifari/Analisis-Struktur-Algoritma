
#include <iostream>
#include <vector>

using namespace std;



int fallingArena(int left, int right) {

    if (left < right) {
        int mid = (left + right) / 2;
        int antenaKiri = fallingArena(left, mid + 1);
        int antenaKanan = fallingArena(mid + 1, right);



    

    }else {
        return 0;
    }

}

int main () {


    return 0;
}
