// Cisc 3142
// Homework 4.2
// Thrwat Najjar and Manahil Sher
#include <iostream>
#include <vector>
using namespace std;

//  ItemRecord class maintains books and other media records for a library.
class ItemRecord {
    private:
        // attributes include the title(string), price(double), rating(char)
        string title;
        double price;
        char rating;

    public:
        // 1. constructor that takes default values ("placeholder", 0.99, 'D')
        ItemRecord(string t = "placeholder", double p = 0.99, char r = 'D'){
            title = t;
            setPrice(p);
            rating = r;
        }

        // 2. individual getters that return the item's title, price, and rating
        string getTitle(){ return title; }
        double getPrice(){ return price; }
        char getRating(){ return rating; }
        
        // 3. overloaded “<<” operator which outputs the title only
        friend ostream& operator<<(ostream &out, const ItemRecord &ir){
            out << ir.title;
        }

        // 4. overloaded “==” operator which only compares the item's rating
        bool operator==(const ItemRecord &ir){ 
            return this -> rating == ir.rating;
        }

        // 5. setPrice(double), which throws a range_error exception 
        void setPrice(double p){
            if(p < 0)
                throw range_error("negative price");
            price = p;
        }

        // 6. a pure virtual function, to_string()
        virtual string to_string() = 0;

        // 7. a virtual destructor
        virtual ~ItemRecord(){}

};

class BookRecord: public ItemRecord {
    private:
        /* BookRecord has an extra data field, int* chPages.
            which is implemented as a dynamic array of integers */
        int* chPages;
        int size;

    public:
        BookRecord(vector<int> v, string t = "placeholder", double p = 0.99, char r = 'D'):
        
        ItemRecord(t, p, r){
            chPages = new int[size];
            size = v.size(); 
            for(int i = 0; i < size; i++)
                chPages[i] = v[i];
            
        }

        string to_string() {
            int pages = 0;
            for(int i = 0; i < size; i++)
                pages += chPages[i];
            
            return "Book[ " + this -> getTitle() + ", " + std::to_string(this -> getPrice())
            + ", " + this -> getRating() + ", " + std::to_string(pages) + " ]";

        }

        ~BookRecord(){ delete[]chPages; }

};

class CdRecord: public ItemRecord {
    private:
        /* CdRecord has a different extra data field, double* trackTimes.
            which is implemented as a dynamic array of doubles */
        double* trackTimes;
        int size;

    public:
        CdRecord(vector<double> v, string t = "placeholder", double p = 0.99, char r = 'D'):
        
        ItemRecord(t, p, r){
            size = v.size();
            trackTimes = new double[size];
            for(int i=0; i<size; i++)
                trackTimes[i] = v[i];
        }

        string to_string() {
            double minutes = 0;
            for(int i = 0; i < size; i++)
                minutes += trackTimes[i];
            
            return "CD[ " + this -> getTitle() + ", " + std::to_string(this -> getPrice())
            + ", " + this -> getRating() + ", " + std::to_string(minutes) + " ]";

        }

        ~CdRecord(){delete[]trackTimes;}

};

int main() {
    // instantiate an example of both a book and a cd
    BookRecord book1({2, 20, 30, 40, 30, 20}, "SampleBook", 10.99, 'A');
    CdRecord cd1({4.5, 15.0, 23.5, 4.3, 5.2, 20.3}, "SampleCD", 14.99, 'B');

    // display their individual titles by using your overloaded <<
    cout << "My book's title is: " << book1 << endl;
    cout << "My CD's title is: " << cd1 << endl;

    // reduce each item's price by $1, using setPrice()
    book1.setPrice(book1.getPrice() - 1);
    cd1.setPrice(cd1.getPrice() - 1);

    // show whether these two items have the same rating by using your overloaded ==
    cout << "Do they have the same rating? ";
    if(book1 == cd1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    /*make an array of ItemRecord* to store the two items, then iteratively 
        call the to_string() function using the pointer to display their detail */
    cout << endl;
    cout << "Their details in [title, price, rating, total pages/minutes]:" << endl;
    cout << book1.to_string() << endl;
    cout << cd1.to_string() << endl;

    return 0;
}