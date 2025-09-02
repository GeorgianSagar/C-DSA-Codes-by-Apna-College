#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to find the celebrity using stack elimination method
int getCelebrity(vector<vector<int>>& arr) {
    stack<int> s;
    int n = arr.size();
    // Push all people to stack
    for (int i = 0; i < n; ++i) {
        s.push(i);
    }
    // Eliminate non-celebrities
    while (s.size() > 1) {
        int i = s.top(); s.pop();
        int j = s.top(); s.pop();
        if (arr[i][j] == 1) {
            // a knows b, so a can't be celebrity
            s.push(j);
        } else {
            // a doesn't know b, so b can't be celebrity
            s.push(i);
        }
    }
    if (s.empty()) return -1;
    int candidate = s.top();
    // Verify candidate
    for (int i = 0; i < n; ++i) {
        if (i != candidate) {
            if (arr[candidate][i] == 1 || arr[i][candidate] == 0)
                return -1;
        }
    }
    return candidate;
}

int main() {
    vector<vector<int>> arr = {
        {0,1,0},
        {0,0,0},
        {0,1,0}
    };
    // int n = M.size();
    // int celeb = findCelebrity(M, n);
    // if (celeb == -1)
    //     cout << "No celebrity found" << endl;
    // else
    //     cout << "Celebrity is person " << celeb << endl;

    int ans= getCelebrity(arr);
    cout << "Celebrity is person " << ans << endl;

    return 0;
}