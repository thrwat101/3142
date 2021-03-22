// Cisc 3142
// Homework 2.2
// Thrwat Najjar 

//#include <iostreaclTabCtrlm>
#include <cstring>
#include <iostream>

#include "ordPair.hpp"

using namespace std;

enum class Gender{ female, male};

class TTPlayer {
    public:
        // change these back to private?
        const char *name; // not supposed to have const but constructor giving an error cuz assigning to const, have to figure this out
        Gender gen;
        
        TTPlayer(const char* s = "default", Gender g = Gender::male); // I added the defaults cuz ordPair kept asking for the basic TTPlayer() constructor idk why
        
        // copy constructor
        TTPlayer(const TTPlayer& ttp) : name{ttp.name}, gen{ttp.gen} {}
        
        // copy assignment
//        TTPlayer& operator=(const TTPlayer& rhs); // doesn't work
        
        std::string toString() {
            std::string sname = "";
            for (int i = 0; name[i] != '\0'; i++) { 
                sname = sname + name[i]; 
            }
            
            std::string sgender = gen == Gender::male ? "M" : "F";
            
            return sname + ", " + sgender;
        }
        
        bool operator<(const TTPlayer& rhs) const {
            return rhs.gen > gen;
        }
        
        bool operator==(const TTPlayer& rhs) const {
            return &rhs == this;
        }
        
        ~TTPlayer() { delete name; }
};

// not inline constructor
TTPlayer::TTPlayer(const char* s, Gender g) {
//    int length = sizeof(s)/sizeof(char);
//    name = new char[length + 1]; // I think we have to do it like this, but then how do you populate char?
    name = &s[0];
    gen = {g};
}

int main(){
    TTPlayer players[] = {
        {"Player1", Gender::male},
        {"Player2", Gender::female},
        {"Player3", Gender::male},
        {"Player4", Gender::female},
        {"Player5", Gender::male}
    };
    
    int n = sizeof(players) / sizeof(TTPlayer);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            // don't compare with itself
            if (players[i] == players[j]) continue;
            
            try {
                ordPair<TTPlayer> pair(players[i], players[j]); // this was working with Gender, but not with TTPlayer unless we have the basic TTPlayer constructor for some reason
                cout << pair.toString() << endl;
                
            } catch(std::invalid_argument) {}
        }
    }
    
    return 0;
}