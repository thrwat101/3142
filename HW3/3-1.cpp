// Cisc 3142
// Homework 3.1
// Thrwat Najjar and Manahil Sher
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
        str = "BEGIN";
        auto i = vect.begin();
        while(i != vect.end()){
            auto iter = obj.insert(obj.begin(), *i);
            ++i;
        }

    }
    else {
        str = "END";
        auto i = vect.begin();
        while(i != vect.end()){
            auto iter = obj.insert(obj.end(), *i);
            ++i;
        }

    }
    
    auto end_time = chrono::steady_clock::now();
    
    cout << typeid(obj).name() << " INSERT AT " << str << " TIME: " 
        << fixed << std::setprecision (10) 
        << chrono::duration_cast<chrono::nanoseconds>(end_time - start_time ).count()
        << " nano seconds " << endl;
}

int main(){
    int total_elems = 100000;

    // 1. Creating vector of 100,000 elements.
    auto start_time = chrono::steady_clock::now();
    
    vector<int> vect;
    for(int i = 1; i <= total_elems; i++)
        vect.insert(vect.end(), i);

    auto end_time = chrono::steady_clock::now();

    cout << "STARTING VECTOR CREATION TIME: " << fixed << std::setprecision(10) 
    << chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count() 
    << " nano seconds\n" << endl;

    // 2. Randomizing the order of values so they are shuffled.
    start_time = chrono::steady_clock::now();
    
    int rand1, rand2, temp;
    for(int i = 1; i <= total_elems/2; i++){
        rand1 = rand() % total_elems;
        rand2 = rand() % total_elems;
        if(rand1 != rand2){
            temp = vect[rand1];
            vect[rand1] = vect[rand2];
            vect[rand2] = temp;
        }

    }

    end_time = chrono::steady_clock::now();

    /* 3. Measure the time to insert all elements of vect into another 
    vector, list, set, and unordered_set, at the end of the container. */
    bool start = true;
    bool end = false;

    vector<int> other_vect1;
    insertAt(vect, other_vect1, start);

    list<int> list1;
    insertAt(vect, list1, start);

    set<int> set1;
    insertAt(vect, set1, start);

    unordered_set<int> uset1;
    insertAt(vect, uset1, start);

    cout << endl;

    vector<int> other_vect2;
    insertAt(vect, other_vect2, end);

    list<int> list2;
    insertAt(vect, list2, end);

    set<int> set2;
    insertAt(vect, set2, end);

    unordered_set<int> uset2;
    insertAt(vect, uset2, end);

    // 4. 


    



}
