#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findEmployeeRating(const vector<int>& workload) {
    int max_streak = 0, current_streak = 0;
    
    for (int hours : workload) {
        if (hours > 6) {
            current_streak++;
            max_streak = max(max_streak, current_streak);
        } else {
            current_streak = 0;
        }
    }
    
    return max_streak;
}

vector<int> getWorkloadInput(int N) {
    vector<int> workload(N);
    cout << "Enter the workload for each day: ";
    for (int i = 0; i < N; ++i) {
        cin >> workload[i];
    }
    return workload;
}

int main() {
    int N;
    cout << "Enter the number of working days: ";
    cin >> N;
    
    vector<int> workload = getWorkloadInput(N);
    
    int rating = findEmployeeRating(workload);
    cout << "Employee Rating: " << rating << endl;
    
    return 0;
}
