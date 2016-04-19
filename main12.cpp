/* Deborah Rempala
CSCI 122
Battleship 
Due: Wednesday, November 13,2013
*/


#include <iomanip>
#include <fstream>
#include <string>
#include <iostream>

void menu();
void newbattle(char[5]);
void savebattle(char[5]);
void viewbattle(char[5]);
 void initialize_board(int [10][10]);
using namespace std;
int main()

{ // read in choice
    char choice;
    char move[5];
    int board [10][10];
    // show menu
     menu();
     // read in choice
  
     cin >> choice;
     choice = toupper(choice);
     switch(choice)
     {
     case 'N':
     {
     newbattle(move);
      system("PAUSE");
          }
          case 'V':
               {
                   viewbattle(move);
                   system("PAUSE");
                   }
                   
          // quit the game
      case 'Q':
      {
          // cout<<"TEST";
           return 0;
           } 
           }   
    system("PAUSE");
    
}
// menu function
void menu()
{
     cout<<"BATTLESHIP"<<endl<<endl;
     cout<<"Menu options:"<<endl;
     cout<<"N - New Battle"<<endl;
     cout<<"V - View Battle"<<endl;
     cout<<"P - Play Game"<<endl;
     cout<<"Q - Quit"<<endl<<endl;
     cout<<"Enter Choice: ";
     }
     // new battle function
 void newbattle(char move[1])
 { int size =5;
  string position= " ";
    char column[1];
     char  *const letter[5] = {"C","B","K","S","D"};

        int space;
      int holes[5] = {5,4,3,2,2};
      string ships[5] = {"Carrier","Battleship","Kruiser","Submarine","Destroyer"};
     cout<<"NEW BATTLE"<<endl<<endl;
     cout<<"Instructions: For each ship, you will enter its position"<<endl<<
     "by specifying its orientation ( H for horizontal, V for vertical),"<<endl
     <<"a comma, and then the coordinates of the top left corner of the"<<endl
     <<"ship(row letter, dash, column number)."<<endl<<endl;
     for( int i =0; i<size; i++)
     {
          cout<<"Enter position of "<<holes[i]<<"-hole "<<ships[i]<<":";
          cin>> position;
          for( int i =0; i < size; i++)
          {
      if(position.at(0)=='H')
          {
         
              cout<<letter[i];
              }
              
              
              
     }
     }
     
     
     
     savebattle(move);
     }
void savebattle(char move[5])
{ int num =1;
     fstream output;
     output.open("game.txt",ios::out | ios::app);
     for( int i =0; i <num; i++)
     {
     int gsize =10;
     int lsize = 10;
     for( int i=0; i<gsize;i++)
     {
     output<<endl;
     output<<"0";
     
      for( int i=0; i<lsize;i++)
      {
      output<<"0";
     
      }
      cout<<endl;
      
     
      }
      }
       output.close();
      }
        
 void viewbattle ( char move[5])
 { 
      int stop =10;
      
      string alpha[10]={"A","B","C","D","E","F","G","H", "I","J"};
      cout<<"   1 2 3 4 5 6 7 8 9 10"<<endl;
      for( int i=0; i<stop;i++)
      {
           cout<<alpha[i]<<"  ";
           for( int i=0; i<stop;i++)
          {
                 cout<<"0"<<" ";
                 }
                 cout<<endl;
           }
           
}
 void initialize_board( int array1[ 10 ][ 10 ] ) // Function to initialize the gameboard.
{
      int occupied;
  // create a blank board   
  for (int i=0; i<10; i++)
   {
     for (int j=0; j<10; j++)
      {
          array1[i][j] = occupied;
           }     
     }     
}
    
