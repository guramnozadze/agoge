#include <iostream>
using namespace std;

int main(){
    string pos;
    cin >> pos;

    int col = pos[0] - 'A' + 1; // აწარმოებს ასოს ციფრში (A = 1, B = 2, C = 3)
    int row = pos[1] - '0'; // გადაყავს Char ციფრი => ინტში, ASCII - ს ცხრილის მიხედვით.

    int count = 0;
    while (col - 1 > 0 && row + 1 < 9) {
        count++;
        col--; // Ertit marcxniv
        row++; // Ertit zevit
    }

    cout << count;

    return 0;
}