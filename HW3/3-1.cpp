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
    << " nano seconds" << endl;

    cout << endl;

    // 2. Randomizing the order of values so they are shuffled.
    start_time = chrono::steady_clock::now();
    
    int r1, r2, temp;
    for(int i = 1; i <= total_elems/2; i++){
        r1 = rand() % total_elems;
        r2 = rand() % total_elems;
        if(r1 != r2){
            temp = vect[r1];
            vect[r1] = vect[r2];
            vect[r2] = temp;
        }

    }

    end_time = chrono::steady_clock::now();

    /* 3. Measure the time to insert all elements of vect into another 
    vector, list, set, and unordered_set, at the end of the container. */
    bool end = false;

    vector<int> other_vect1;
    insertAt(vect, other_vect1, end);

    list<int> list1;
    insertAt(vect, list1, end);

    set<int> set1;
    insertAt(vect, set1, end);

    unordered_set<int> uset1;
    insertAt(vect, uset1, end);
    
    cout << endl;

    // 4. inserting elements at the beginning of the container.
    bool start = true;

    vector<int> other_vect2;
    insertAt(vect, other_vect2, start);

    list<int> list2;
    insertAt(vect, list2, start);

    set<int> set2;
    insertAt(vect, set2, start);

    unordered_set<int> uset2;
    insertAt(vect, uset2, start);

    cout << endl;

    // 5. Measuring the time to find each value of 1 - 10k.
    int num = 10000;
    
    //vect
    start_time = chrono::steady_clock::now();
    for(int i = 1; i <= num; i ++)
        auto elems = find(other_vect1.begin(), other_vect1.end(), i);
    end_time = chrono::steady_clock::now();

    cout << "Time to find 10k numbers in vector: " 
        << chrono::duration_cast<chrono::nanoseconds>(end_time - start_time ).count() 
        << " nano seconds " << endl;

    //list
    start_time = chrono::steady_clock::now();
    for(int i = 1; i <= num; i ++)
        auto elems = find(list1.begin(), list1.end(), i);
    end_time = chrono::steady_clock::now();
    
    cout << "Time to find 10k numbers in list: " 
        << chrono::duration_cast<chrono::nanoseconds>(end_time - start_time ).count() 
        << " nano seconds " << endl;

    //set
    start_time = chrono::steady_clock::now();
    for(int i = 1; i <= num; i ++)
        auto elems = set1.find(i);
    end_time = chrono::steady_clock::now();

    cout << "Time to find 10k numbers in set: " 
        << chrono::duration_cast<chrono::nanoseconds>(end_time - start_time ).count() 
        << " nano seconds " << endl;

    //unordered set
    start_time = chrono::steady_clock::now();
    for(int i = 1; i <= num; i ++)
        auto elems = uset1.find(i);
    end_time = chrono::steady_clock::now();

    cout << "Time to find 10k numbers in unordered set: " 
        << chrono::duration_cast<chrono::nanoseconds>(end_time - start_time ).count() 
        << " nano seconds " << endl;

    return 0;

}
