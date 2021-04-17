// Cisc 3142
// Homework 3.1
// Thrwat Najjar and Manahil Sher
#include <iostream>
#include<bits/stdc++.h>
#include <sstream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

int main(){
    // creating map which has integer for key (ID#) and string for value (phone#)
    map<int, string> mp;

    // opening the file.
    ifstream phone;
    phone.open("phoneno.txt");

    // check file.
    if(!phone.good())
        cout << "Trouble opening file. ";

    int id = 0;
    string number = "";
    string area_code = "";
    string line;

    while(phone){ 
        getline(phone, line);
        
    



        

    }
    phone.close();
    return 0;
}