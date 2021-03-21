// Cisc 3142
// Homework 2.2
// Thrwat Najjar 

#include <iostream>
#include <cstring>

using namespace std;

enum class Gender{ male = 1 , female = 2 };

class TTPlayer {
    char *name;
    Gender gender;
    
    public:
        TTPlayer(const char* s, Gender g);
        TTPlayer(const TTPlayer& ttp);
        std::string toString();
        bool operator<(const TTPlayer& rhs);

    
    
};

int main(){
    TTPlayer players[] = {
        {"Player1", Gender::male},
        {"Player2", Gender::female},
        {"Player3", Gender::male},
        {"Player4", Gender::female},
        {"Player5", Gender::male}
    };

    return 0;
}