/* Deborah Rempala
CSCI 122: Assignment 3
bookstore database using classes
Due: Wednesday, September 11th, 2013
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

// class structure
class bookstore
{
      private:
              // variables
              char ISBN[20];
              char Title[20];
              char Author[20];
              int numbooks;
              int yearspublished;
              int stock;
              double price;
    public:
           // functions
           // intialize
           void intailize(char[],char[],char[],int,int, int, double);
           char getisbn() const;
           char gettitle() const;
           char getauthor() const;
           int getyears() const;
           int getstock() const;
           double getprice() const;
           // display
           void display ( ) const;
           // add book
           void addbook( int &);
           // delete book
           void deletebook(int &);
           // update book
           void updatebook( int &);
           
           
};
// intailize function
void bookstore::intailize(char I[], char T[], char A[], int y, int s, int n, double p)
{
     strcpy(ISBN,I);
     strcpy(Title,T);
     strcpy(Author,A);
     numbooks =n;
     n= 0;
     yearspublished =y;
     stock = s;
     price =p;
}
char bookstore::getisbn() const
{
     return 'ISBN';
}
char bookstore::gettitle() const
{
     return 'Title';
}
char bookstore::getauthor() const
{
     return 'Author';
}
int bookstore::getyears() const
{
    return yearspublished;
}
int bookstore::getstock() const
{
    return stock;
}
double bookstore::getprice () const
{
       return price;
}

// display function
void bookstore::display() const
{
  cout<<"ISBN"<<" "<<"Title"<<" "<<"Author"<<" "<<"Year published"<<" "
     <<"In stock"<<" "<<"Price"<<endl;

}   
void bookstore::addbook(int &num)
{
     cout<<"Enter the ISBN Number: ";
     cin >> ws;
     cin>> ISBN;
     cout<<"Enter the Title: ";
     cin >> ws;
     cin>> Title;
     cout<<"Enter the Author: ";
     cin>> ws;
     cin>> Author;
     cout<<"Enter the Year it was Published: ";
     cin>> yearspublished;
     cout<<"Enter the Quanity: ";
     cin>> stock;
     cout<<"Enter the Price: ";
     cin>> price;
     }
 // delete a book
 void bookstore::deletebook (int &num)
 {
char key;
 char isbn;
 int position = 0;
 bool found = false;
 cout<<"Enter the ISBN: "<<endl;
 cin >>key;

      }
void bookstore::updatebook(int &num)
{
     cout<<"Enter the ISBN: " <<endl;
     cin >> ISBN;
     cout<<"Enter the stock: "<<endl;
     cin >> stock;
     cout<<"Enter the price: "<<endl;
     cin >> price;
     
     }
     
// main program

  // function prototype
     void readbookstorefile(bookstore book[], int&);
     void menu();
     void displaybook( bookstore book[], int);
     void savebook(bookstore book [], int &num);
     // main program
 int main ()
 {
     bookstore book[100];
    int num =0;
    int choice;
    readbookstorefile(book,num);
    do{
                                
    menu();
    cin>> choice;
    switch(choice)
    {
                  // display the book
          case 3:
               {
    displaybook(book, num);
    break;
           }
           // add book
           case 1:
                {
                      cout<<"Add  a Book"<<endl<<endl;
                      book[num].addbook(num);
                      break;
                      }
           
           
           case 2:
                {
                      book[num].deletebook( num);
                      int linersearch( num);
                      }
                      case 5:
                           {
                                       book[num].updatebook(num);
                                         int linersearch( num);
                                         }
                                       
                                       
                      }  
                      }    
           // quitting a program
           while( choice != 4);
           {
    
                 savebook(book ,num);
                 system("PAUSE");
                 return 0;
                 }
           
}



      


// menu function
void menu()
{
     cout<<"Welcome to the bookstore"<<endl;
     cout<<"Please chose a selection"<<endl;
     cout<<"1). Add a Book"<<endl;
     cout<<"2). Delete a Book"<<endl;
     cout<<"3). Display all Books"<<endl;
     cout<<"5). Update a Book"<<endl;
     cout<<"4). Quit"<<endl;
     
     }
     // display function
     void displaybook(bookstore book[], int num)
     {
            book[num].display();
     for( int i= 0; i < num; i++)
     {
           book[i].getisbn();
            book[i].gettitle();
             book[i].getauthor();
             book[i].getyears();
             book[i].getstock();
             book[i].getprice ();
           
           }
           }
     
// read bookstore file 
 void readbookstorefile(bookstore book[], int &num)
 {
      num =0;
     
      char I[20],T[20],A[20];
      int y, s, n;
      double p;
 
      ifstream Input;
      Input.open("books.dat");
      while ( !(Input.eof()))
      {
            n=0;
            Input.getline(I,20);
            Input.getline(T,20);
            Input.getline(A,20);
            Input>>y;
            Input>>s;
            Input>>p;
            Input>>ws;
       book[num].intailize( I,  T,  A,  y,  s,  n,  p);
       
            
            if( Input.eof())
            num++;
            // check to see if file was read
             // cout<<"done";
            }
            
            Input.close();
     
          
   
          
 }
 // save the book data
 void savebook( bookstore book[], int &num)
 {
       char I[20],T[20],A[20];
      int y, s, n;
      double p;
      fstream output;
      output.open("books.dat", ios::out | ios::app);
      for( int i =0; i <num; i++)
      {
           output<<(I,20)<< endl;
           output<<(T,20)<<endl;
           output<<(A,20)<<endl;
           output<< y << endl;
           output<< s <<endl;
           output<< p <<endl;
           }
              
           output.close();
           }
           
   int linearsearch( bookstore book [], int num, int key)
   {
       int position =0;
       bool found = false;
       while( position < num);
       if (('bookstore.setisbn') == key)
       return position;
       else 
       position ++;
       return -1;
       }
               
               

