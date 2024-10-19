#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id;   
    int profit; 
    int deadline; 
};

bool compare(Job a, Job b) {
    return (a.profit > b.profit);
}

void jobSequencing(vector<Job>& jobs, int n) {
    sort(jobs.begin(), jobs.end(), compare);

    vector<int> result(n, -1);
    vector<bool> slot(n, false); 

    int totalProfit = 0;

    for (int i = 0; i < jobs.size(); i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = i; 
                slot[j] = true; 
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Job sequence with maximum profit:\n";
    for (int i = 0; i < n; i++) {
        if (result[i] != -1)
            cout << jobs[result[i]].id << " ";
    }
    cout << "\nMaximum Profit: " << totalProfit << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter job ID, profit, and deadline for job " << i + 1 << ": ";
        cin >> jobs[i].id >> jobs[i].profit >> jobs[i].deadline;
    }

    jobSequencing(jobs, n);

    return 0;
}
