#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls) {

        int grid[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = 0;
            };
        }

        for (int i = 0; i < (int)walls.size(); i++) {
            vector<int> wall = walls[i];
            grid[wall[0]][wall[1]] = 1;
        }
        for (int i = 0; i < (int)guards.size(); i++) {
            vector<int> guard = guards[i];
            grid[guard[0]][guard[1]] = 1;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j] << " ";
            };
            cout << endl;
        }

        cout << "Solution" << endl;
        return 0;
    }
};

int main(int argc, char *argv[]) {

    Solution solution;

    int m = 4, n = 6;

    vector<vector<int>> guards = {{0, 0}, {1, 1}, {2, 3}};
    vector<vector<int>> walls = {{0, 1}, {2, 2}, {1, 4}};

    int result = solution.countUnguarded(m, n, guards, walls);

    cout << result;
    return 0;
}
