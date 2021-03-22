// Cisc 3142
// Homework 2.2
// Thrwat Najjar 

//#include <iostreaclTabCtrlm>
#include <cstring>
#include <iostream>

#include "ordPair.hpp"

using namespace std;

enum class Gender{ male = 1 , female = 2 };

class TTPlayer {
    public:
        // change these back to private
        const char *name;
        Gender gender;
        
        // not inline, see below
        TTPlayer(const char* s, Gender g);
        
        // copy constructor
        TTPlayer(const TTPlayer& ttp) :name{ttp.name}, gender{ttp.gender} {}
        
        std::string toString() {
            std::string sname = "";
            for (int i = 0; i < sizeof(name); i++) { 
                sname = sname + name[i]; 
            }
            
            std::string sgender = gender == Gender::male ? "M" : "F";
            
            return sname + ", " + sgender;
        }
        
        bool operator<(const TTPlayer& rhs) const {
            cout << "hello" << endl;
            return rhs.gender > gender;
        }
        
        
};

// not inline constructor
TTPlayer::TTPlayer(const char* s, Gender g) {
    name = &s[0];
    gender = {g};
}

int main(){
    TTPlayer players[] = {
        {"Player1", Gender::male},
        {"Player2", Gender::female},
        {"Player3", Gender::male},
        {"Player4", Gender::female},
        {"Player5", Gender::male}
    };
    
    cout << players[1].name << endl;
    if (players[2] < players[1]) {
        cout << "trueeee" << endl;
    }

    return 0;
}