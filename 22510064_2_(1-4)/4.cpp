#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

int countPossiblePositions(int X, int Y, int s, int T) {
    int count = 0;

    int min_x = max(0, X);          
    int max_x = min(T, X + s);      
    int min_y = max(0, Y);          
    int max_y = min(T, Y + s);      

    for (int x = min_x; x <= max_x; ++x) {
        for (int y = min_y; y <= max_y; ++y) {
            if (x + y <= T) {
                count++;
            }
        }
    }

    return count;
}

tuple<int, int, int, int> getFrogInput() {
    int X, Y, s, T;
    cout << "Enter X, Y, s, and T: ";
    cin >> X >> Y >> s >> T;
    return make_tuple(X, Y, s, T);
}

int main() {
    int X, Y, s, T;
    
    tie(X, Y, s, T) = getFrogInput();

    int result = countPossiblePositions(X, Y, s, T);
    cout << "Number of possible positions: " << result << endl;

    return 0;
}
