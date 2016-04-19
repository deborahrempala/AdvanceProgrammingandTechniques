/* 
Deborah Rempala
CSCI 122
Assignment #7: Fraction tutor
Due: Wednesday October 9th, 2013
*/

#include <cmath>
#include <iomanip>
#include <iostream>
#include <time.h>
#include <ctime>
#include <dos.h>
// function prototypes
void ShowMenu();
using namespace std;
class Fraction
{
      // making friends
      friend Fraction operator+(const Fraction &f1, const Fraction &f2);
      friend Fraction operator-(const Fraction &f1, const Fraction &f2);
      friend Fraction operator*(const Fraction &f1, const Fraction &f2);
      friend Fraction operator/(const Fraction &f1, const Fraction &f2);
      friend  bool operator==(const Fraction &f1, const Fraction &f2);
   friend   bool  operator >(const Fraction &f1, const Fraction &f2);
    
      
      // private variables
      private:
              int numerator;
              int denominator;
              
              // public functions
              public:
                    void  Input();
                    void  Show () const;
                     int getnumerator () const;
                     int getdenominator () const;
                     void setnumerator(int n);
                     void setdenominator(int d);
                     int Result() const;
                     bool setvalue (int n, int d =1);
                     Fraction ();
                     Fraction (int n, int d=1);
                     double Evaluate () const;
                   int randomize ();
                   int reduce();
                   int GCD();
               void MySleep(int);
                     };
                     // friend functions
               // addition operator
 Fraction operator+ (const Fraction &f1, const Fraction &f2)
 {
          Fraction r;
          r.numerator = f1.numerator * f2.denominator + f2.numerator * 
          f1.denominator;
          r.denominator = f1.denominator * f2.denominator;
          return r;
          }
          // subtraction operator
 Fraction operator-(const Fraction &f1, const Fraction &f2)
 {
          Fraction r;
          r.numerator = (f1.numerator * f2.denominator) - (f2.numerator * 
          f1.denominator);
          r.denominator = f1.denominator * f2.denominator;
          return r;
          }
          // mutiplication opearator
  Fraction operator*(const Fraction &f1, const Fraction &f2) 
  {
           Fraction r;
           r.numerator = f1.numerator * f2.numerator;
           r.denominator = f1.denominator *  f2. denominator;
           return r;
           }
           // divison operator
  Fraction operator/(const Fraction &f1, const Fraction &f2)   
  {
           Fraction r;
           r.numerator = f1.denominator * f1.numerator;
           r. denominator = f2.denominator * f2.numerator;
           return r;
           }
           // for subtraction problems
           // putting the larger one in front
 bool operator>( const Fraction &f1, const Fraction &f2)
 {
      if((f1.numerator * f2.denominator) >(f2.numerator * f1.denominator))
      {
                       return true;
                       }
                       else
                       {return false;}
                       }
bool operator ==(const Fraction &f1, const Fraction &f2)
{
  float fraction1, fraction2;
  fraction1 = f1.numerator * f2.numerator;
  fraction2= f1.denominator * f1.denominator;
  return true;
        
        
         }
         
         
         
                      
// setting the numerator
void Fraction::setnumerator(int n)
{
     numerator =n;
}
// setting the denominator
void Fraction::setdenominator(int d)
{
     denominator =d;
     }
     
    // sleep function      
    // in order to get different functions
  void mySleep(int delay)
{
   float t1 = clock(), t2;
   
   fflush(stdout);
   
   do
   {
      t2 = clock();
      
   }while(((t2 - t1) / CLK_TCK) < delay);
}                           
 // set values
 Fraction::Fraction ()
 {
                    numerator =0;
                    denominator =1;
                    }
 // making sure denominator is correct
 Fraction:: Fraction ( int n, int d)
 {
            if(setvalue (n,d) == false)
            setvalue (0,1);
            }
            // setting more values
 bool Fraction:: setvalue(int n, int d)
 {
      if( d<= 0)
      return false;
      numerator =n; 
      denominator =d;
      return true;
      }
  // input function
   void Fraction :: Input()
  {
     
         char divSign;	// used to consume the '/' character during input
  
      cin >> numerator >> divSign >> denominator;
    
            }
       // random number generaotor
       int Fraction :: randomize() 
{
    srand(time(0));
    denominator = 2 + rand () %10;
    mySleep(1);
    numerator = 1 + rand () % (denominator -1);
}
            // return num
int Fraction:: getnumerator () const
{
    return numerator;
}
// return denominator
int Fraction:: getdenominator () const
{
    return denominator;
}     
int Fraction:: Result () const
{ 
           return numerator;
           cout<<"/";
           return denominator;
}



 // show fraction
  void Fraction :: Show() const
 {
      cout<< numerator<<"/"<<denominator;
}
double Fraction:: Evaluate() const
{
       return static_cast<double>(numerator)/ denominator;
       }
int Fraction:: GCD()
{
       if((numerator%denominator) == 0)
       return numerator;
       else
       return GCD();
     
       }
 

   int main()
   // variables
   { Fraction f1,f2, f3(3,4);
       int choice,m,n;
       char answer;
      
       Fraction Result(0,0);
       double numproblems=0, addcorrect=0, addwrong=0, numcorrect =0, subcorrect=0,
       subwrong=0,mcorrect =0, mwrong=0,dcorrect=0,dwrong=0;
       do{
       ShowMenu();
      cout<<"Enter Your Choice: ";
       cin >> choice;
       switch (choice)
       
       {
              case 1:
                   {
                        cout<<"You have chosen Addition"<<endl;
                        // adding fractions
                        do{
                                  
                        Result = (3,4);
                          f3 = (3,4); 
                        numproblems ++;       
                        f1.randomize();
                        f2.randomize(); 
                        f1.Show();
                        
                        cout<<"+";
                        f2.Show();
                        
                        cout<<"=";
                        f3.Input();
                       f3.Evaluate();
                   
                       Result= f1 + f2;
                       Result.Evaluate();
                       
                       // checking to see if answer is right
                       if(f3.Evaluate() ==  Result.Evaluate())
                       {
                                        cout<<"Correct"<<endl;
                                        addcorrect ++;
                                        
                                        }
                                        
                     else
                  {
                     cout<<"You are wrong"<<endl;
                   
                   addwrong ++;
                     cout<<"The correct Answer is: ";
                     Result.Show();
                     cout<<endl;
                    
                    // f1.Show()+ f2.Show();
                     
                     
                    
                     }   
                   
                       cout<<"Anymore (Y/N): ";
                       cin>> ws;
                       cin>> answer;
                       
                    }while( answer != 'N');
                    
                    break;
                   }
              case 2:
                   {
                          cout<<"You have chosen Subtraction"<<endl;
              // subtract function
              do{
                          numproblems ++;
                        f1.randomize();
                        f2.randomize(); 
                        if(f2 > f1)
                        {
                              Fraction temp;
                              temp.setnumerator(f2.getnumerator());
                              temp.setdenominator(f2.getdenominator());
                              
                              f2.setnumerator(f1.getnumerator());
                              f2.setdenominator(f1.getdenominator());
                              
                              f1.setnumerator(temp.getnumerator());
                              f1.setdenominator(temp.getdenominator());
                              }
                        f1.Show();
                        cout<<"-";
                        f2.Show();
                        cout<<"=";
                        f3.Input();
                        Fraction Result;
                        Result = f1 - f2;
                        Result.Evaluate();
                        
                        // checking to see if answer is right 
                        if(f3.Evaluate() == Result.Evaluate())
                       {
                                        cout<<"Correct"<<endl;
                                        subcorrect ++;
                                        
                                        }
                                        
                     else
                  {
                     cout<<"You are wrong"<<endl;
                     cout<<"The correct answer is: ";
                     Result.Show();
                     subwrong ++;
                     cout<<endl;
                     }   
                        cout<<"Anymore (Y/N): ";
                        cin>>ws;
                        cin>> answer;    
                }
                        while( answer !='N');
                        break;
                  }
              case 3:
                   {
                        cout<<"You have chosen Mutiplication"<<endl;
              // mutiply function
              do{
                           numproblems ++;
                        f1.randomize();
                        f2.randomize(); 
                        f1.Show();
                        cout<<"*";
                        f2.Show();
                        cout<<"=";
                        f3.Input();
                       
                       Result = (f1 * f2);
                       Result.Evaluate();
                     Result.Show();
                        if(f3.Evaluate() == Result.Evaluate())
                       {
                                        cout<<"Correct"<<endl;
                                        mcorrect ++;
                                        
                                        }
                                        
                     else
                  {
                     cout<<"You are wrong"<<endl;
                     cout<<"The correct Answer is: ";
                     Result.Show();
                     mwrong ++;
                     cout<<endl;
                     }   
                      
                       
                        cout<<"Anymore (Y/N): ";
                       cin>> answer;
                       }
                       while(answer !='N');
                       break;
                    }
              case 4:
                   {
                       cout<<"You have chosen Divison"<<endl;
               // divide  Function
               do{
                          numproblems ++;
               f1.randomize();
                        f2.randomize(); 
                        f1.Show();
                        cout<<"(/)";
                        f2.Show();
                        cout<<"=";
                        f3.Input();
                       f3.Evaluate();
                       Result = f1 /f2;
                       Result.Evaluate();
                        if(f3.Evaluate() == Result.Evaluate())
                       {
                                        cout<<"Correct"<<endl;
                                        dcorrect ++;
                                        
                                        }
                                        
                     else
                  {
                     cout<<"You are wrong"<<endl;
                     dwrong ++;
                     cout<<"The correct Answer is: ";
                     Result.Show();
                     cout<<endl;
                     }   
                         cout<<"Anymore (Y/N): ";
                       cin>> answer;
                       }
                       while(answer !='N');
                       break;
                    }
                        
               case 5:
                    {// progress report 
                    cout<<"Here is your progress Report"<<endl;
                        cout<<"Number of Problems: "<<numproblems<<endl;
                        cout<<"Addition"<<endl;
                         cout<<"Percent Correct:%"<<(addcorrect/numproblems)*100<<endl;
                          cout<<"Percent Wrong:%"<<(addwrong/numproblems)*100<<endl<<endl;
                          cout<<"Subtraction"<<endl;
                         cout<<"Percent Correct:%"<<(subcorrect/numproblems)*100<<endl;
                          cout<<"Percent Wrong:%"<<(subwrong/numproblems)*100<<endl<<endl;
                          cout<<"Mutiplicaton"<<endl;
                         cout<<"Percent Correct:%"<<(mcorrect/numproblems)*100<<endl;
                          cout<<"Percent Wrong:%"<<(mwrong/numproblems)*100<<endl<<endl;
                          cout<<"Divison"<<endl;
                         cout<<"Percent Correct:%"<<(dcorrect/numproblems)*100<<endl;
                          cout<<"Percent Wrong:%"<<(dwrong/numproblems)*100<<endl;
                    
                    }
                    
                    }
                    }
                    while( choice !=6);
                    {
                           cout<<"Good Bye";
                           system("PAUSE");
                    return 0;
                    }
                    
       
   
   }     
   // menu function         
void ShowMenu ()
{
         cout<<"Welcome to Fraction Tutor"<<endl;
         cout<< "The Options are......." <<endl;
         cout<<"1. Add Fractions"<<endl;
         cout<<"2. Subtract Fractions"<<endl;
         cout<<"3. Mutiply Fractions"<<endl;
         cout<<"4. Divide Fractions" <<endl;
         cout<<"5. Progress Report"<<endl;
         cout<<"6. Quit the Program"<<endl;
         }
         
