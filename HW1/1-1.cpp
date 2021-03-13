#include <iostream>
using namespace std;
// Cisc 3142
// Homework 1.1
// Thrwat Najjar 

void outputBorder();
void outputRow(string s);
void makeBox(string name, string langauges);

int longest_row {0};

int main() {
    string name {"Thrwat najjar"};
    string languages {"Java C++ Javascript Scheme"};
    
    makeBox(name, languages);
    
    return 0;
}

void makeBox(string name, string languages) {
    string hello_from {"Hello from " + name};
    string have_programmed {"Have programmed in:"};
    
    // determines which is the longest row
    longest_row = max(max(hello_from.length(), have_programmed.length()), languages.length());
    
    // top row dashes
    outputBorder();

    // rows
    outputRow(hello_from);
    outputRow(have_programmed);
    outputRow(languages);
    
    // buttom row dashes
    outputBorder();
}

// creates a horizontal border
void outputBorder() {
    for (int i {0}; i < longest_row + 4; i++) {
        cout << ((i == 0 || i == longest_row + 3) ? "+" : "-");
    }
    cout << endl;
}

// outputs the string along with appropriate number of spaces
void outputRow(string s) {
    cout << "| " << s;
    int num_spaces = longest_row - s.length();
    for (int i {0}; i < num_spaces; i++) {
        cout << " ";
    }
    cout << " | " << endl;
}

