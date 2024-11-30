#include <iostream>
using namespace std;

int recursiveSummation(const int inputNumber) {
    if (inputNumber == 0) {
        return 0;
    }
    return inputNumber + recursiveSummation(inputNumber-1);
}

string findBinary(int decimal, string  result){

    if (decimal ==0){
        return result;
    }

    result = decimal % 2 ? result + '0' : result + '1';
    return findBinary(decimal/2, result);
}

bool isPalindrome(string input) {
    if (input.length() ==0 || input.length() == 1) {
        return true;
    }


    if (input.substr(0,1) == input.substr(input.length()-1)) {
        return isPalindrome(input.substr(1, input.length()-2));
    }

    return false;
}

string reverseString(const string& input) {
    if (input.length() == 0) {
        return "";
    }

    return reverseString(input.substr(1, input.length()-1)) + input.substr(0,1);
}

int main() {
    cout << reverseString("Hello,") << endl;
    cout << isPalindrome("rar");
    return 0;
}

