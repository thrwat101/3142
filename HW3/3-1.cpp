#include <iostream>
#include <stdlib.h>
#include <set>
#include <unordered_set>
#include <vector>
#include <list>
#include <iomanip>
#include <typeinfo>
#include <algorithm>
#include <time.h>
#include <chrono>

using namespace std;

//Universal function that does inserting 
template <class T> 
void insertAt(vector<int> vect, T &obj, bool start){
    auto start_time = chrono::steady_clock::now();
    string str = "";
    if(start == true){
        str = "begin";
        auto i = vect.begin();
        while(i != vect.end()){
            auto iter = obj.insert(obj.begin(), *i);
            ++i;
        }

    }else{
        str = "end";
        auto i = vect.begin();
        while(i != vect.end()){
            auto iter = obj.insert(obj.end(), *i);
            ++i;
        }

    }
    
    auto end_time = chrono::steady_clock::now();
    //cout << typeid(obj).name() 
    cout << "Insert " << str << ": time - " 
        << fixed << std::setprecision (10) 
        << chrono::duration_cast<chrono::nanoseconds>(end_time - start_time ).count()
        << " nano seconds " << endl;
}

int main(){




}
