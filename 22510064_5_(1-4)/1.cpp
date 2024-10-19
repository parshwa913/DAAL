#include <iostream>
using namespace std;

int minimum_connections(int A, int B) {
    int x = A / B;
    int y = A % B;
    int min_connections = (B - y) * (x * (x - 1)) / 2 + y * (x * (x + 1)) / 2;
    return min_connections;
}

int maximum_connections(int A) {
    return A * (A - 1) / 2;
}

int main() {
    int A, B;
    cin >> A >> B;
    cout << "Minimum Connections: " << minimum_connections(A, B) << endl;
    cout << "Maximum Connections: " << maximum_connections(A) << endl;
    return 0;
}
