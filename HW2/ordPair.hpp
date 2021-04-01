// Cisc 3142
// Homework 2.2
// Thrwat Najjar and Manahil Sher

#include <string>
#include <stdexcept>

template <typename T>
class ordPair{
   private:
      T first;
      T second;

   public:
       ordPair(T &fir, T &sec) {
          if(!(fir < sec))
             throw std::invalid_argument ("Invalid order. First must be less than Second.");
          
          else { 
             first = { std::move(fir) };
             second = { std::move(sec) };
          }
          
       }

       T getFirst(){ return first; }  

       T getSecond(){ return second; }

       void setFirst(T fir){
          if (fir < second) first = fir;
          else throw std::invalid_argument ("Invalid number.");
       }

       void setSecond(T sec){
        if (first < sec) second = sec;
        else throw std::invalid_argument ("Invalid number.");
       }
       
       std::string toString() {
          return "("+ first.toString () + " | " + second.toString () + ")";
       }

       bool operator==(const ordPair &other) {
          return ((first == other.getFirst()) && (second == other.getSecond()));
       }

};