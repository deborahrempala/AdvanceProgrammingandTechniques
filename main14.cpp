/* Deborah Rempala
CSCI 122
Assignment 14: spam filter
Due: Friday, November 11th, 2013
*/
#include <string>
#include <iostream>
#include <iomanip> 
#include <fstream>
using namespace std;

int main()
{
    string message[300];
    string email = " ";
    string temp;
    fstream input;
    string filename;
    string emailmessage;
    int num =0;
  
    
    input.open("spam.txt",ios::in);
    {
      
         for ( int i =0; i <300; i++)
         {
            getline(input, message[i]);
             }
             input.close();
             }
             // test to make sure file read correctly
        /* for ( int j =0; j < 10 ; j++)
         {
             cout<<message[j]<<endl;
             }*/
             
            cout<<"Enter a file name: ";
            cin>> filename;
            fstream input1;
            input1.open(filename.c_str(), ios::in);
      if(input1.is_open())
      {
           do{             
          getline(input1,email);
           email.append(email);
           
          } while(!( input1.eof()));
           
            
          }
         input1.close();
          int found;
          int size;
          size = email.length();
       
            for( int i =0; i< 300; i++)
            {
          found = email.find(message[i],1);
       
              if ( !(found == -1))
              {
              num ++;
              }
              }
          cout<<"The Spam Value is: "<<num<<endl;
            cout<<"The message is: "<<endl;
           
             system("PAUSE");
             return 0;
             }
