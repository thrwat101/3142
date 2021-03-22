// Cisc 3142
// Homework 2.2
// Thrwat Najjar

template <class T> class ordPair{
   private:
      T first;
      T second;

   public:
      ordPair(T&, T&);
      T getFirst();
      T getSecond();
      void setFirst (T);
      void setSecond (T);
      std::string toString ();
      bool operator==(const ordPair &other);
   
   ordPair<T>::ordPair(T &fir, T &sec){
      if(!(fir < sec))
         throw std::invalid_argument ("Invalid order. First must be less than Second.");
      
      else { 
         first { std::move(fir) };
         second { std::move(sec) };
      }
      
   }

   T ordPair<T>::getFirst(){ return first; }  

   T ordPair<T>::getSecond(){ return second; }

   void ordPair<T>::setFirst(T fir){
      if (fir < second) first = fir;
      else throw std::invalid_argument ("Invalid number.");
   }

   void ordPair<T>::setSecond(T sec){
    if (first < sec) second = sec;
    else throw std::invalid_argument ("Invalid number.");
   }
   
   std::string ordPair<T>::toString() {
      return first.toString () + " | " + second.toString ();
   }

   bool ordPair<T>::operator==(const ordPair &other) {
      return ((first == other.getFirst()) && (second == other.getSecond()));
   }

};