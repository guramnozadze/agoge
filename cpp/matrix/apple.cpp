#include <iostream>
#include <vector>
using namespace std;

// x = N = row
// y = M = column
int main(int argc, char *argv[]) {
    int N, M, x, y;

    cin >> N >> M >> x >> y;

    vector<vector<int>> grid(N, vector<int>(M, 0));
    grid[x - 1][y - 1] = 1;

    for (int row = 0; row < N; row++) {

        for (int column = 0; column < M; column++) {
            // Horizontal
            if ((column == y || column == y - 2) && row == x - 1) {
                grid[row][column]++;
            }

            // Vertical
            if ((row == x || row == x - 2) && column == y - 1) {
                grid[row][column]++;
            }

            // Diagonal
            if ((column == y || column == y - 2) && (row == x - 2 || row == x)) {
                grid[row][column]++;
            }

            cout << grid[row][column] << " ";
        }
        cout << endl;
    }
    int len = 8;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            cin >> grid[i][j];
        }
    }

    int sum = 0;
    for (int row = 0; row < len; row++) {
        for (int column = 0; column < len; column++) {
            if (row % 2 == 1 && column % 2 == 0) {
                sum += grid[row][column];
            }
            // cout << grid[row][column] << " ";
        }
        // cout << endl;
    }
    cout << sum;

    return 0;
    return 0;
}
