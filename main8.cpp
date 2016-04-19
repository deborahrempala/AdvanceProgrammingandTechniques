/* Deborah Rempala
CSCI 122:Programming Tools And Techniques
Assignment 8: Rainfall Stats using Vectors
Due: Friday October 18, 2013
*/


#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;


int main()
{
    // variables
    const int month =12;
    vector <double> rain;
    double amount[month];
    double sum =0;
    double mean =0;
    double high =0;
    double low =0;
    int lmonth;
    int smonth;
    // entering information
    for ( int num=0; num < month ; num++)
    {
        cout<<"Enter the Rainfall amount for month # "<<(num+1)<<" : ";
       cin >> amount[num];
       // enter into correct place for vector
       rain.push_back(amount[num]);
       }
       // average and total rainfall
      for( int i =0; i< month; i++)
      {
           sum += amount[i];
           mean = (1.0*(sum) /(month));
           }
           // high month for rainfall
high = amount [1];
for( int count =1; count <month; count++)
{
     if(amount[count] > high)
     {
     high = amount[count];
     lmonth = count;
     }
     }
     // low month for rainfall
low = amount [1];
for( int count =1; count <month; count++)
{
     if(amount[count] < low)
     {
     low = amount[count];
     smonth = count;
     }

}     
        // ending information
 cout<<"The Total Rainfall for the year is: "<<sum<<endl;
 cout<<"The average Rainfall for the year is: "<<mean<<endl;
 cout<<"The Highest Rainfall total occured in Month: "<<(lmonth+1)<<endl;
 cout<<"The lowest Rainfall total occured in Month: "<<(smonth +1)<<endl;   
        system("PAUSE");
        }
        
        
