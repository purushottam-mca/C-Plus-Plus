/*
    Problem Statement: Maximum Cost Journey in a Matrix

    You are given a 2D integer matrix of size n x m.

    You may start your journey from any cell (i, j) in the matrix.

    From a cell (i, j), you may jump to any cell (u, v) such that u >= i and v >= j. This means movement is allowed only to the right or downward. Jumps are not restricted to adjacent cells, and you may skip cells.

    The cost of a jump from cell (i, j) to cell (u, v) is defined as:
    a[u][v] - a[i][j]

    You may perform multiple jumps during a journey and may end your journey at any cell.

    The total cost of a journey is the sum of the costs of all jumps performed.

    Your task is to find the maximum possible total cost over all valid journeys.

    Notes:
    Starting and ending cells can be any cells in the matrix.
    You may skip cells while jumping.
    Movement is restricted to right and down directions only.
    A journey may consist of zero or more jumps.

    Input:
    A 2D integer matrix of size n x m.

    Output:
    An integer representing the maximum possible total cost.

*/

#include <bits/stdc++.h>
using namespace std;

int maxTotalCost(const vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty())
        return 0;

    int n = grid.size();
    int m = grid[0].size();

    // DP array to store minimum value reachable till (i, j)
    vector<vector<int>> minDP(n, vector<int>(m));

    minDP[0][0] = grid[0][0];
    int answer = 0;

    // First row
    for (int j = 1; j < m; j++) {
        minDP[0][j] = min(minDP[0][j - 1], grid[0][j]);
        answer = max(answer, grid[0][j] - minDP[0][j]);
    }

    // First column
    for (int i = 1; i < n; i++) {
        minDP[i][0] = min(minDP[i - 1][0], grid[i][0]);
        answer = max(answer, grid[i][0] - minDP[i][0]);
    }

    // Remaining cells
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            minDP[i][j] = min({
                grid[i][j],
                minDP[i - 1][j],
                minDP[i][j - 1]
            });

            answer = max(answer, grid[i][j] - minDP[i][j]);
        }
    }

    return answer;
}

int main() {
    vector<vector<vector<int>>> testCases = {

        // Test Case 1: Normal mixed values
        {
            {5, 3, 1},
            {4, 6, 2},
            {7, 8, 9}
        },

        // Test Case 2: Strictly decreasing (no profit)
        {
            {9, 8, 7},
            {6, 5, 4},
            {3, 2, 1}
        },

        // Test Case 3: Single cell
        {
            {10}
        },

        // Test Case 4: Negative values
        {
            {-5, -10, -3},
            {-6, -2, -8}
        },

        // Test Case 5: One row
        {
            {1, 2, 10, 3, 20}
        },

        // Test Case 6: One column
        {
            {7},
            {1},
            {5},
            {12}
        }
    };

    vector<int> expected = {
        8,   // 1 -> 9
        0,   // no profitable move
        0,   // same start & end
        8,   // -10 -> -2
        19,  // 1 -> 20
        11   // 1 -> 12
    };

    for (int i = 0; i < testCases.size(); i++) {
        int result = maxTotalCost(testCases[i]);
        cout << "Test Case " << i + 1 << ": ";
        cout << "Output = " << result;
        cout << ", Expected = " << expected[i];

        if (result == expected[i])
            cout << "  ✅ PASS";
        else
            cout << "  ❌ FAIL";

        cout << endl;
    }

    return 0;
}
