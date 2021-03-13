#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

// Homework question 1.2
// Thrwat Najjar

void reverseArray(int a[], int n);

int main(){
    try{
        ifstream inFile("input.txt");
        if (!inFile.good())
            throw string("Failure opening input.txt");
        ofstream outFile("output.txt");
        if (!outFile)
            throw string("Failure opening output.txt");
        
        int num;
        int factors[1000];
        int count = 0;
        bool isFirst = true;
        while (inFile >> num){

            double sq = sqrt(num);
            outFile << num << ": ";
            for(int i = 2; i <= sq; i++){
                if(num % i == 0){
                    outFile << (isFirst ? "" : ", ") << i;
                    factors[count++] = i; 
                    isFirst = false;
                    
                }
            }
            if(isFirst)
                outFile << "None" ;
            outFile << "\n";
            isFirst = true;

        }
        inFile.close();
        outFile.close();
        return 0;
    }
    catch(string message){
        cerr << message << endl;
        exit(1);
    }
}
void reverseArray(int a[], int n){
    for (int i=0; i< n/2; i++){
        int temp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = temp;
    }
}