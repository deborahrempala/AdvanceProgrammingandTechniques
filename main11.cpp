/* Deborah Rempala
CSCI 122
Assignment 11: pig latin conversion
Due: November 4th, 2013
*/
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
     string letter = " ";
     string first;
     int space;
     // enter a sentence 
    cout<<"Enter a Sentence: ";
    do{
    cin>> letter;
  // find the position of the first letter
    space=letter.find(' ',0);
    // print out the first letter position
   // cout<<space;
   // if the spacce =-1 it will do this
   if(space = -1)
   { 
            // puts the position at 1
      first = 1;
      // puts the first letter at the end
       first.append(letter,0,1);
       // erases the first letter
       letter.erase(0,1);
       }     
    cout<<letter<<first[1]<<"ay"<<" ";
}
// it will do this until it reads a .
while(letter != ".");
    system("PAUSE");
    return 0;
} 
    
