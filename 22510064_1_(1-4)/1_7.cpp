#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Person {
    int height;
    int weight;

    bool operator<(const Person& other) const {
        return height < other.height || (height == other.height && weight < other.weight);
    }
};

int maxTowerLength(vector<Person>& people) {
    sort(people.begin(), people.end());
    int n = people.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (people[i].weight > people[j].weight) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int numPeople;
    cout << "Enter the number of people: ";
    cin >> numPeople;

    vector<Person> people(numPeople);
    cout << "Enter the height and weight of each person: ";
    for (int i = 0; i < numPeople; ++i) {
        cin >> people[i].height >> people[i].weight;
    }

    int maxLength = maxTowerLength(people);

    cout << "The longest person has height: " << maxLength << endl;
    return 0;
}
