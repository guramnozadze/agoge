#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

    int m, n;
    cin >> m >> n;
    char g[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i - 1][j] == '#' || g[i][j - 1] == '#' || g[i - 1][j - 1] == '#') {
                cout << '#';
            } else {
                cout << g[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}
