// Cisc 3142
// Homework 4.1
// Thrwat Najjar and Manahil Sher
#include<iostream>
#include<string.h>
using namespace std;

int main() {
   char set[10000];
   int shift;

   // Getting character set input.
   cout << "Enter set of text: " << endl;
   cin.getline(set, 10000);
   int length = strlen(set);

   // Getting fixed number to shift the character set.
   cout << "Enter shift number: " << endl;
   cin >> shift;
   
   /* Choosing whether we are Encrypting the given set
      or if we have an already encrypted text we are decrypting */
   int scheme;
   cout << "Enter '1' for Encryption or '2' for Decipher " << endl;
   cin >> scheme; 

   // ENCRYPTION
   if(scheme == 1){  
      char enc;
      for(int i = 0; set[i] != '\0'; ++i) {
         enc = set[i];

         // Lowercase encryption
         if(enc >= 'a' && enc <= 'z'){
            enc = enc + shift;
            if (enc > 'z')
               enc = enc - 'z' + 'a' - 1;
               
            set[i] = enc;
         }

         // Uppercase encryption
         else if (enc >= 'A' && enc <= 'Z'){
            enc = enc + shift;
            if (enc > 'Z')
               enc = enc - 'Z' + 'A' - 1;

            set[i] = enc;
         }

      }
      printf("Encryption complete: %s", set);
   }

   // DECRYPTION 
   else if (scheme == 2) { 
      char dec;
      for(int i = 0; set[i] != '\0'; ++i) {
         dec = set[i];
         
         // Lowercase 
         if(dec >= 'a' && dec <= 'z') {
            dec = dec - shift;
            if(dec < 'a')
               dec = dec + 'z' - 'a' + 1;
            
            set[i] = dec;
         }
         
         // Uppercase 
         else if(dec >= 'A' && dec <= 'Z') {
            dec = dec - shift;
            if(dec < 'A') 
               dec = dec + 'Z' - 'A' + 1;
            
            set[i] = dec;
         }

      }
      cout << "Deciphered text: " << set << endl;
   }
   return 0;
}
