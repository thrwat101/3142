// Cisc 3142
// Homework 2.1
// Thrwat Najjar 

#include <iostream>
using namespace std;

int strLen(const char* source);
int strCmp(const char* s1, const char* s2);
void strSwap(char* s1, char* s2);
void strBubbleSort(char* arrStr[], int array_size);

int main(int argc, char* argv[]) {
   if(argc == 1){
        cout << "No input was provided. " << endl;
        return 0;
   }
   /*Step 1: Create an array called arrStr 
        and add each word from the input as an element in the array*/
    char** arrStr = new char*[argc - 1];
    for(int i {0}; i < argc; i++)
        arrStr[i] = argv[i + 1];

    // Step 2: print the input.
    cout << "Your input is: " << endl;
    for (int i {0}; i < argc - 1; i++)
        cout << arrStr[i] << endl;
    
    // Step 3: sort the input.
    strBubbleSort(arrStr, argc - 1);
    
    // Step 4: print the output. 
    cout << "Your output is: " << endl;
    for (int i {0}; i < argc - 1; i++) 
        cout << arrStr[i] << endl;
    
    return 0;

}

// Finds string length
int strLen(const char* str) {
    int i {0};
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

// Compares two strings
int strCmp(const char* s1, const char* s2) {
    // if s1 is shorter
    if (strLen(s1) < strLen(s2))
        return 1;
    
    // if s2 is shorter
    else if (strLen(s1) > strLen(s2))
        return -1;

    // the two strings are equal in length
    else return 0;
    
}

// Swaps two pointers
void strSwap(char** s1, char** s2) {
    char* temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

// Bubble sort
void strBubbleSort(char* arrStr[], int size) {
    bool swapped {true};
    
    for (auto i {0}; i < size - 1 && swapped; i++) {
        swapped = {false};
        for (auto j {0}; j < size - i - 1; j++) {    
            if (strCmp(arrStr[j], arrStr[j + 1]) < 0) {
                strSwap(&arrStr[j], &arrStr[j + 1]);
                swapped = {true};
            }
        }
    }

}



