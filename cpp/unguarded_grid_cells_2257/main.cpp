#include <cwchar>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    const int UNGUARDED = 0;
    const int GUARDED = 1;
    const int GUARD = 2;
    const int WALL = 3;

    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls) {

        int grid[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = UNGUARDED;
            };
        }
        // vector<vector<int>> grid(m, vector<int>(n, UNGUARDED));

        for (int i = 0; i < (int)walls.size(); i++) {
            vector<int> wall = walls[i];
            grid[wall[0]][wall[1]] = WALL;
        }
        for (const vector<int> &guard : guards) {
            grid[guard[0]][guard[1]] = GUARD;
        }
        for (int i = 0; i < (int)guards.size(); i++) {
            vector<int> guard = guards[i];
            int y = guard[0];
            int x = guard[1];
            if (grid[y][x] == GUARD) {
                // move down
                for (int r = y + 1; r < m; r++) {
                    if (grid[r][x] != WALL && grid[r][x] != GUARD) {
                        grid[r][x] = GUARDED;
                    } else {
                        break;
                    }
                }
                // move up
                for (int r = y - 1; r >= 0; r--) {
                    if (grid[r][x] != WALL && grid[r][x] != GUARD) {
                        grid[r][x] = GUARDED;
                    } else {
                        break;
                    }
                }
                // move right
                for (int r = x + 1; r < n; r++) {
                    if (grid[y][r] != WALL && grid[y][r] != GUARD) {
                        grid[y][r] = GUARDED;
                    } else {
                        break;
                    }
                } // move left
                for (int r = x - 1; r >= 0; r--) {
                    if (grid[y][r] != WALL && grid[y][r] != GUARD) {
                        grid[y][r] = GUARDED;
                    } else {
                        break;
                    }
                }
            }
        }

        int count_green = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == UNGUARDED) {
                    count_green++;
                }

                cout << grid[i][j] << " ";
            };
            cout << endl;
        }

        return count_green;
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
