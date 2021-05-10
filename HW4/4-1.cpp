// Cisc 3142
// Homework 4.1
// Thrwat Najjar and Manahil Sher
#include<iostream>
#include<string.h>
using namespace std;

int main() {
   char message[10000];
   int shift;

   // Getting character set input.
   cout << "Enter set of text: " << endl;
   cin.getline(message, 10000);

   // Getting fixed number to shift the character set.
   cout << "Enter shift number: " << endl;
   cin >> shift;

   // ENCRYPTION
      char enc;
      for(int i = 0; message[i] != '\0'; i++) {
         enc = message[i];

         // Lowercase encryption
         if(enc >= 'a' && enc <= 'z'){
            enc = enc + shift;
            if (enc > 'z')
               enc = enc - 'z' + 'a' - 1;
               
            message[i] = enc;
         }

         // Uppercase encryption
         else if (enc >= 'A' && enc <= 'Z'){
            enc = enc + shift;
            if (enc > 'Z')
               enc = enc - 'Z' + 'A' - 1;

            message[i] = enc;
         }

      }
      printf("Encryption complete: %s", message);
      
   return 0;

}
