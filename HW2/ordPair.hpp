// Ordpair.hpp

//#ifndef ORDPAIR_HPP
//#define ORDPAIR_HPP

template <class T> class ordpair {
   private:
      T first;
      T second;
   
    public: 
        template<class T> ordpair<T>::ordpair(T &fir, T &sec){
            first = {std::move(fir)};
            second = {std::move(sec)};
            if (!(fir < sec)) 
                throw std::invalid_argument("Invalid order. First must be less than Second.");
        }

        template<class T>
        T ordpair<T>::getFirst(){ return first; }

        template<class T>
        T ordpair<T>::getSecond(){ return second; }

        template<class T>
        std::string ordpair<T>::toString() {
            return "(" + first.toString() + " | " + second.toString() + ")";
        }

        template<class T>
        bool ordpair<T>::operator==(const ordpair &other) {
            return ((first == other.getFirst()) && (second == other.getSecond()));
        }

        template<class T>void ordpair<T>::setFirst(T fir)
        {
            if (fir < second) first = fir;
            else throw std::invalid_argument ("Invalid number");
        }

        template<class T>
        void ordpair<T>::setSecond(T sec)
        {
            if (first < sec) second = sec;
            else throw std::invalid_argument ("Invalid number");
        }
        //#endif
};