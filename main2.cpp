/* Deborah Rempala
CSCI 122 
Assignment 2: bookstore database
create a program that will keep a record for a bookstore
Due: Friday September 6th, 2013
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;
//book store structure
struct book {
              char ISBN[20];
              char Title[40];
              char Author[20];
              int yearsPublished;
              int stock;
              float price;
             
};
// function protypes
void readbookstorefile(book[], int&);
void displayMenu();
void displaydata(book [],int num);
void addBook(book [], int &);
void savebookstorefile(book[], int&);
void updatebook(book [], int);
void deletebook(book [], int&);
// variables

int main ()
{  
    int num_book;
int num;
char choice;
book bookstore[100];
readbookstorefile(bookstore,num_book);
                        
    
  do
  {
        displayMenu();
    cin>> (choice);  
    // to view books
    if( choice == 'V')
    {
        displaydata(bookstore, num_book);
        }
        
if( choice == 'A')
    {        addBook(bookstore,num_book);
            
        }
        
 
  if( choice == 'U')
    {        updatebook(bookstore, num_book);
            
        }
        
  if( choice == 'D')
    {        deletebook(bookstore, num_book);
            
        }
  // save bookstore
}
  while( choice != 'Q');
  {
         
  savebookstorefile(bookstore, num_book);
       system("PAUSE");
    return 0;
}
     

}

 


// functions
// read file
 void readbookstorefile(book bookstore[], int &num)
 {
      num =0;
      ifstream Input;
      Input.open("books.txt",ios::in | ios::binary);
      while ( !(Input.eof()))
      {
            Input.getline(bookstore[num].ISBN,20);
            Input.getline(bookstore[num].Title,40);
            Input.getline(bookstore[num].Author,20);
            Input>>bookstore[num].yearsPublished;
            Input>>bookstore[num].stock;
            Input>>bookstore[num].price;
            Input>>ws;
            num++;
            }
           
            Input.close();
 }
            
// display menu
void displayMenu()
{
     cout<<"Bookstore Menu"<<endl;
     cout<<"Select from the following:"<<endl;
     cout<<"V) View all Books"<<endl;
     cout<<"A) Add a new Book"<<endl;
     cout<<"D) Delete a Book"<<endl;
     cout<<"U) Update a book price and quantity"<<endl;
     cout<<"Q) Quit the program"<<endl;
     cout<<"Choice?";
}
//display books
void displaydata( book bookstore[], int num)
{ cout<<"Data For All Books"<<endl<<endl;


     
        cout<<left<<setw(15)<<"ISBN"<<" "<< setw(20)<<"Title"<<setw(15)<<"Author"<<"     "<<"Year"
        <<"       "<<"Stock"<<" "<<"Price"<<" "<<endl;
     for( int i=0; i < num; i++)
     {
          cout<<left<<setw(15)<<bookstore[i].ISBN<<setw(20)<<bookstore[i].Title<<" "<<
          setw(20)<<bookstore[i].Author<<bookstore[i].yearsPublished<<"        "
          <<bookstore[i].stock<<"   "<<right<<fixed<<setprecision(2)<<"  "
          <<bookstore[i].price<<right<<endl;
     
     }
     
}
     // add book
 void  addBook( book bookstore[], int &num_book)
 {      
      
       cout<<"Enter The ISBN Number: ";
       cin>>ws;
         cin.getline(bookstore[num_book].ISBN,20); 
                                                                             
        cout<<"Enter The Title:"<<endl;
        cin >> ws;
        cin.getline(bookstore[num_book].Title,20);
        cout<<"Enter The Author:"<<endl;
        cin >> ws;
        cin.getline(bookstore[num_book].Author,20);
        cout<<"Enter The Year It Was Published:"<<endl;
        cin >>(bookstore[num_book].yearsPublished);
        cout<<"Enter the Quanity:"<<endl;
        cin >>(bookstore[num_book].stock);
        cout<<"Enter the Price:"<<endl;
         cin >>(bookstore[num_book].price);
         
         num_book++;
         }
         

// save file
  void savebookstorefile( book bookstore[], int &num)
  {
       fstream output;
      
       output.open("books.txt",ios::out | ios::binary);
       for( int i =0; i < num; i++)
       {
            
       output<< bookstore[i].ISBN<<endl;
        output<< bookstore[i].Title<<endl;
         output<< bookstore[i].Author<<endl;
         output<< bookstore[i].yearsPublished<<endl;
         output<< bookstore[i].stock<<endl;
         output<< bookstore[i].price<<endl;
         }
         output.close();
         
         }
  // update book information
  void updatebook(book bookstore[], int num_book)
  {
        char isbn[20];
       
       int position =0;
       
       cout<<"Enter The ISBN Number: "<<endl;
       cin>>isbn;
      bool found = false;
          while(( position < num_book) && !(found))
             {
                  if(strcmp(isbn,bookstore[position].ISBN)==0)
                  {
                     found = true;
                     }
          else
          {
              position++;
              }
              }
              if( found ==true)
              {
               int newstock;
               float newprice;                                                                        
                           
        cout<<"Enter The Quanity:"<<endl;
        cin >>newstock;
        cout<<"Enter the Price:"<<endl;
         cin >>newprice;
         newstock = bookstore[position].stock;
         newprice= bookstore[position].price;
         num_book++;
         }
         
         else
         {
             cout<<"That ISBN Cannot be found"<<endl;
             }
       }
// delete a book
 void deletebook( book bookstore[], int &num)        
 {     int i;
     int j;
              char isbn[20];
       
       int position =0;
       
       cout<<"Enter The ISBN Number: "<<endl;
       cin>>isbn;
      for( int i =0; i< num; i++)
      if(bookstore[i].ISBN == isbn)
      {
                           for( int i=j; j <num; j++)
                           {
                                strncat(bookstore[j].ISBN,bookstore[j+1].ISBN,20);
                                strncat(bookstore[j].Title,bookstore[j+1].Title,20);
                                strncat(bookstore[j].Author,bookstore[j+1].Author,20);
                                 bookstore[j].yearsPublished=bookstore[j+1].yearsPublished;
                                 bookstore[j].stock=bookstore[j+1].stock;
                                 bookstore[j].price=bookstore[j+1].price;
                                 cout<<"That book was eliminated"<<endl;
        
        }
        num--;
        break;
        }
        else
        cout<<"That number was not found"<<endl;
        }
        
       

     
     

               
           
            
      
    
