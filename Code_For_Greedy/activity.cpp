#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Structure to represent an activity
struct Activity {
    int start, finish;
};

// Comparator function to sort activities based on their finish time
bool activityCompare(Activity s1, Activity s2) {
    return (s1.finish < s2.finish);
}

void printMaxActivities(vector<Activity> activities, int n) {
    // Sort the activities based on their finish time
    sort(activities.begin(), activities.end(), activityCompare);

    cout << "Selected activities are:" << endl;

    // The first activity always gets selected
    int i = 0;
    cout << "Activity " << i + 1 << ": [" << activities[i].start << ", " << activities[i].finish << ")" << endl;

    // Consider the rest of the activities
    for (int j = 1; j < n; j++) {
        // If this activity has a start time greater than or equal to the finish
        // time of the previously selected activity, then select it
        if (activities[j].start >= activities[i].finish) {
            cout << "Activity " << j + 1 << ": [" << activities[j].start << ", " << activities[j].finish << ")" << endl;
            i = j;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<Activity> activities(n);

    cout << "Enter the start and finish times of the activities:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].finish;
    }

    printMaxActivities(activities, n);

    return 0;
}
