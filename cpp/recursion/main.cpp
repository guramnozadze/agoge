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
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.

    cout << reverseString("Hello,") << endl;
    cout << isPalindrome("rar");
    return 0;
    auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    for (int i = 1; i <= 5; i++) {
        // TIP Press <shortcut actionId="Debug"/> to start debugging your code.
        // We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/>
        // breakpoint for you, but you can always add more by pressing
        // <shortcut actionId="ToggleLineBreakpoint"/>.
        std::cout << "i = " << i << std::endl;
    }

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.