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
    // map to store id's (key) and phone numbers (value) from file
    map<int, string> mp;

    //vector to store all phone numbers with area code 212
    vector<string> ac212;
    //using a set will take out all duplicates.
    set<string> set212;

    // Opening file
    ifstream phoneno;
    phoneno.open("phoneno.txt");
     
    string line;
    int numbers = 0;
    // Reading file into our map
    while(phoneno) { 
        getline(phoneno, line); 

        stringstream geek(line); 
        int id = 0; 
        geek >> id;
        string phone_num = line.substr(6, 12);
        
        // Storing the data into the map
        mp[id] = phone_num;
        
        string area_code = line.substr(6, 3);
        
        // Counting all the numbers that has areaCode 347  
        if(area_code == "347")
            numbers++;
        
        /* finding all numbers with area code 212. 
        with and without duplicates */
        if(area_code == "212"){
            ac212.push_back(phone_num);
            set212.insert(phone_num);
        }

    } 
    
    // Finding the id's associated with number 212-536-6331
    vector<int> ids212;
    for(auto i : mp)
        if(i.second == "456-789-1234")
            ids212.push_back(i.first);
    
    cout << "Size of the map: " << mp.size() << endl;
    cout << "Count of phone# with area code 347: " << numbers << endl;
    cout << "The ID(s) with the given phone#: ";
    for(int i = 0; i < ids212.size(); i++)
        cout << ids212[i] << " ";
    cout << endl;
    cout << "Size of the vector with all (212) numbers: " << ac212.size() << endl;
    cout << "Size of the vector with unique (212) numbers: " << set212.size() << endl;
    
    // close file 
    phoneno.close(); 
}