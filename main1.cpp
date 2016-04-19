/* Deborah Rempala 
   CSCI 122: Programming tools and techniques
   Assignemt # 1: Store data with bar graph
   Due: Friday, August 30, 2013
   */
   
#include <iostream>
#include <istream>
using namespace std;

int main ()
{
     // variables 
    int store_amount=0;
     double money_amount[store_amount];
      const char* star = "*";
      int stars;
    // ask user for how many stores
   cout << "How many stores would you like to enter data for? ";
   cin >> store_amount; 
 for( int i = 1; i<= 1; i++)
 {
      
 // for loop for counting
 for ( int i =1 ; i<= store_amount; i++)
  {   money_amount[i]=0;
        // enter store data 
       cout<<"Enter the store data for store # "<< i<<":";
       cin >> money_amount[i];
       money_amount[i] = money_amount[i] /100;
        
       // formula to convert to stars
       
            



}



}
// ending information
cout<<"////////////////////////////////////"<<endl;
cout<< "Sales Bar Graph"<<endl;
cout<<"(Each * = $100)"<<endl;

for( int i =1; i<= store_amount; i++)
{
   
 
  for( int i = money_amount[i]; i >= 0; i--)
    {
     
   }
  
   cout<<"The data for store "<< i <<":";
   stars = money_amount[i];
   for( int i = stars; i>= 1; i--)
   {
        cout<< "*";
       }
       cout<< endl;
}
        
         
         
        
        
  system("PAUSE");      
} 
       
       







