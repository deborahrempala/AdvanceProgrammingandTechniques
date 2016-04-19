/* Deborah Rempala
CSCI 122
Battleship
Due: Wednesday, November 13,2013
*/


#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void menu();
void newbattle(char[5]);
void savebattle(char[5]);
void viewbattle(char[5]);
void loadbattle(char[5]);

int main()

{

            // read in choice
    char choice;
    char move[5];
    char enter [1];
    int board [10][10];
    string alpha[11]={"A","B","C","D","E","F","G","H", "I","J"};
    string numcol[11] ={"1","2","3","4","5","6","7","8","9","10"};
    // show menu

     menu();
     // read in choice

     cin >> choice;
     choice = toupper(choice);

     if(choice =='N')
     {
         newbattle(move);

     }
     if(choice=='S')
     {
         loadbattle(move);
     }

if(choice =='Q')
return 0;

}

// menu function
void menu()
{
     cout<<"BATTLESHIP"<<endl<<endl;
     cout<<"Menu options:"<<endl;
     cout<<"N - New Battle"<<endl;
     cout<<"S - See Battle"<<endl;
     cout<<"P - Play Game"<<endl;
     cout<<"Q - Quit"<<endl<<endl;
     cout<<"Enter Choice: ";
     }
     // new battle function
 void newbattle(char move[1])
 { int size =5;
 int shipsize =5;
  string temp= " ";
    char column;
    char grid [11][11];
    char row;
    char position;
    int column1;
    char shiposition;
    string
shipname[5]={"C","C","C","C","C"};
    string alpha = " ";
string letter[5]={"C","B","K","S","D"};
        for(int i =0; i <10; i++)
        {
            for ( int j =0; j <10; j++)
            {
                grid[i][j]='0';
            }
        }

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
          getline(cin,temp);
          temp[0] = position;
          temp[2] = column;
          temp[4]= row;
          cin>>ws;
     }
     for(int i=0; i <5; i++)
     {
         shipname[i];

     }
       if(position=='H')
       {

       }
    if(column =='A')
    {   grid.at(2);
        grid.insert(2,shipname);
    }
 if(position=='V')
       {

       }


 }

void savebattle(char move[5])
{ cout<<endl;
    int num =1;
     fstream output;
     output.open("game2.txt",ios::out | ios::app);

      cout<<endl;
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


      output<<endl;

       output.close();
      }
void loadbattle(char move[5])
{
    int size;
    char enter[1];
    fstream input;
    input.open("game2.txt",ios::in);
    while(!input.eof());
    {

            input.getline(enter,1);


    }
    input.close();
}
void viewbattle(char enter[1])
{
    cout<<enter;
}
