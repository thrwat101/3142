// Cisc 3142
// Homework 2.2
// Manahil Sher and Thrwat Najjar 
template <class T> class ordpair {
   private:
      T first;
      T second;
   
    public: 
        ordpair(T &fir, T &sec): first {std::move(fir)}, second {std::move(sec)}
        { 
        if (!(fir < sec)) 
            throw std::invalid_argument("Invalid order. First must be less than Second.");
        }

        T getFirst(){ return first; }
        
        T getSecond(){ return second; }

        void setFirst(T fir){
            if (fir < second) first = fir;
            else throw std::invalid_argument ("Invalid number");
        }

        void setSecond(T sec){
            if (first < sec) second = sec;
            else throw std::invalid_argument ("Invalid number");
        }

        std::string toString() {
            return "(" + first.toString() + " | " + second.toString() + ")";
        }

        bool operator==(const ordpair &other) {
            return ((first == other.getFirst()) && (second == other.getSecond()));
        }
};