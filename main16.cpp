/*Deborah Rempala
CSCI 122
Assignment 16: pointers
build a program that lets a user run various operations on pointers
Due: Wedsenday, December 4th, 2013
*/ 
#include <iostream>
#include <iomanip>
#include <cstddef>

using namespace std;
void Menu();
class IntNode
{
      private: 
               int data;
               IntNode *nextlink;
               IntNode *previouslink;
      public:
             IntNode (){}
             IntNode ( int thedata, IntNode* next, IntNode * previous)
             {
                     data = thedata;
                     nextlink = next;
                     previouslink = previous;
                     }
            int getData() const {return data;}
            IntNode* getnextlink() const {return nextlink;}
            IntNode* getpreviouslink() const{return previouslink;}
            void setdata( int thedata){data = thedata;}
            void setnextlink( IntNode* pointer){ nextlink = pointer;}
            void setpreviouslink( IntNode* pointer){previouslink = pointer;}
            
      
};



typedef IntNode* IntNodePtr;
void headinsert(IntNodePtr & head , int thedata);
void deletenode(IntNodePtr & head, IntNodePtr discard, int thedata);
IntNodePtr search(IntNodePtr head, int target);
  IntNode* root =  new IntNode(0,NULL,NULL);
int main()
{
 
    Menu();
    system("PAUSE");
    return 0;
}
// menu function
 void Menu()
   {
            int choice;
            int num =0;
            do{
   
      cout<<"LInked List Management Software"<<endl;
      cout<<"1.Display List"<<endl;
      cout<<"2.Add item to head of list"<<endl;
      cout<<"3.Delete an item from list"<<endl;
      cout<<"4.Display number of items in the list"<<endl;
      cout<<"5. Quit program"<<endl;
      cout<<"Enter choice: ";
      cin >> choice;
       switch (choice)
       {
              case 1:
                   {
                  // display list
                  
                  IntNode * i =root;
                  cout<<"[head] ";
                  while (i !=NULL)
                  {
                        cout<<i->getData()<<endl;
                        i= i->getnextlink();
                   }
                   cout<<endl;
                   break;
                   }
              case 2:
                   {
                  //add items
                  int value =0;  
                  cout<<"Please enter a value: ";
                  cin >> value;
                  headinsert(root,value);
                  cout<<"[head]->["<<value<<"]"<<endl<<endl;
                  num++;
                  break;
                   }
              case 3:
                   {
                  // delete items
                 
                   int  temp;
                   IntNodePtr head;
                  cout<<"Please enter a value: ";
                  cin>> temp;
                   search(root,temp);
                   
             //  deletenode(root, head,);
                  num --;
                  break;
                  
                   }
              case 4:
                   {
                   // display number of items
                   cout<<"The number of items in the list is "<<num<<endl<<endl;
                   }
              case 5:
                   {
                   //quit
                   break;
                   }
        }
        }
        while( choice !=5);
}   // insert a new value           
void  headinsert ( IntNodePtr& head, int thedata)
{   
     IntNode* newhead = new IntNode(thedata, NULL, head);
     head->setpreviouslink(newhead);
     head = newhead;
                  
}
// delete a value
void deletenode(IntNodePtr & head, IntNodePtr discard, IntNodePtr temp)
{     
      temp = head;
     if( head == discard)
     {
         head = head->getnextlink();
         delete head ->getpreviouslink();
         head ->setpreviouslink(NULL);
         }
         else 
         {
              IntNodePtr prev = discard->getpreviouslink();
              IntNodePtr next = discard->getnextlink();
              prev->setnextlink(next);
              if(next != NULL)
              {
                      next->setpreviouslink(prev);
                      }
                      delete discard;   
                            }                   
                            }
// search for the proper value
IntNodePtr search(IntNodePtr head, int target)
{
           IntNodePtr here = head;
           if( here ==NULL)
           return NULL;
           while(here ->getData()!=target &&here->getnextlink() !=NULL)
           here = here->getnextlink();
           if(here ->getData() == target)
           return here;
           else
           cout<<"That item could not be found"<<endl;
           }   
