#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValid(vector<vector<int>> &grid, int r, int c, int n, int Exp_Val)
    {
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != Exp_Val)
        {
            return false;
        }
        if (Exp_Val == (n * n) - 1)
        {
            return true;
        }

        int ans1 = isValid(grid, r - 2, c + 1, n, Exp_Val + 1);
        int ans2 = isValid(grid, r - 1, c + 2, n, Exp_Val + 1);
        int ans3 = isValid(grid, r + 1, c + 2, n, Exp_Val + 1);
        int ans4 = isValid(grid, r + 2, c + 1, n, Exp_Val + 1);
        int ans5 = isValid(grid, r + 2, c - 1, n, Exp_Val + 1);
        int ans6 = isValid(grid, r + 1, c - 2, n, Exp_Val + 1);
        int ans7 = isValid(grid, r - 1, c - 2, n, Exp_Val + 1);
        int ans8 = isValid(grid, r - 2, c - 1, n, Exp_Val + 1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }
    bool checkValidGrid(vector<vector<int>> &grid)
    {
        return isValid(grid, 0, 0, grid.size(), 0);
    }
};

int main()
{
    vector<vector<int>> grid = {
        {0, 11, 16, 5, 20},
        {17, 4, 19, 10, 15},
        {12, 1, 8, 21, 6},
        {3, 18, 23, 14, 9},
        {24, 13, 2, 7, 22}};

    Solution sol;
    bool result = sol.checkValidGrid(grid);

    cout << (result ? "Valid Knight Tour" : "Invalid Knight Tour") << endl;

    return 0;
}