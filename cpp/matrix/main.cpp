#include <iostream>
using namespace std;

// https://www.aiasoft.ge/problem/395
int spiral_matrix() {
    int number, n;
    cin >> number;

    bool foundSquareRoot = false;

    for (int i = 1; i * i <= number; i++) {
        if (i * i == number) {
            foundSquareRoot = true;
            n = i;
            break;
        }
    }

    if (!foundSquareRoot) {
        cout << "Impossible";
        return 0;
    }
    // Write Grid
    int grid[n][n], num = 1;
    int top = 0, left = 0;
    int right = n - 1,
        bottom = n - 1; // top index, right index, bottom index, left index

    int direction = 0; // 0: right, 1: bottom, 2: left, 3: top
    while (num <= n * n) {
        if (direction == 0) { // MOVING RIGHT NEGGA
            for (int i = left; i <= right; i++) {
                grid[top][i] = num++;
            }
            top++;
        } else if (direction == 1) { // MOVING DOWN NEGGA
            for (int i = top; i <= bottom; i++) {
                grid[i][right] = num++;
            }
            right--;
        } else if (direction == 2) { // MOVING LEFT

            for (int i = right; i >= left; i--) {
                grid[bottom][i] = num++;
            }
            bottom--;
        } else if (direction == 3) { // moving top

            for (int i = bottom; i >= top; i--) {
                grid[i][left] = num++;
            }
            left++;
        }

        direction = (direction + 1) % 4;
    }

    // Read Grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// https://www.aiasoft.ge/problem/581
int sympathetic_matrix() {
    int test;
    cin >> test;

    while (test > 0) {
        int n, m;
        cin >> n >> m;

        int g[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
            }
        }

        string output = "YES";
        int left = 0, top = 0;
        while (left + 2 <= n || top + 2 <= m) {
            if (g[top][left] == g[top][left + 1] == g[top + 1][left] == g[top + 1][left + 1]) {
                output = "NO";
            }

            if (top + 2 <= n) {
                top++;
            } else if (left + 2 <= m) {
                left++;
            }
        }
        cout << output << endl;

        test--;
    }

    return 0;
}

int main() {
    // spiral_matrix();
    return 0;
}
