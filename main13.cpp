/* Deborah Rempala
csci 122
assignment 13: password
due: November 8th, 2013
*/
#include <string>
#include <iomanip>
#include <iostream>
 using namespace std;
 
 int main()
 {
     string password;
     
     
     string upper;
     bool digita;
     bool spacea;
     bool upperc;
     bool lowerc;
 int space;
 int length;
     cout<<"The password must be six charcters long. It must include one lowercase, one uppercase and one digit."<<endl;
     cout<<"Enter a password: ";
     cin>> password;
   space = password.length();
    
           for( int i =0; i < password.length(); i++)
           {
                if(isdigit(password.at(i)))
                {
              digita = true;
                
                }
                
                if(isupper(password.at(i)))
            //    cout<<"correct";
                {upperc= true;
                }
                
                if(islower(password.at(i)))
               { lowerc = true;
               }
                }
                
          
          
       

if( lowerc != true)
{
cout<<"the password needs a lowercasse letrer"<<endl;
}


if( digita != true)
cout<<"The password needs a number"<<endl;

if( upperc != true)
{
cout<<"the password needs a uppercase letrer"<<endl;
}
    if( space < 6)
    {
    cout<<"The password is too short"<<endl;
}
     
     system("PAUSE");
     return 0;
     }
     
