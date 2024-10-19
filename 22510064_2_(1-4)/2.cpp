#include <iostream>
#include <tuple>
using namespace std;

int findBoxIndex(int N, int K) {
    int currentCandy = 0;
    int step = 1;
    int position = 1;
    
    while (currentCandy < K) {
        position += step;
        currentCandy++;

        if (position == N || position == 1) {
            step = -step;
        }
    }
    
    return position;
}

tuple<int, int> getBoxCandyInput() {
    int N, K;
    cout << "Enter the number of boxes (N) and candies (K): ";
    cin >> N >> K;
    return make_tuple(N, K);
}

int main() {
    int N, K;
    
    tie(N, K) = getBoxCandyInput();

    int boxIndex = findBoxIndex(N, K);
    cout << "The K-th candy is placed in box number: " << boxIndex << endl;

    return 0;
}
