/* Deborah Rempala 
assignment #10: morse code
csci 122
due: Friday, November 1, 2013 at 9:50 am
*/
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
 
 using namespace std;
 int main()
 {
     
     ifstream input;
     string letters;
     string converted;
     string sentence, morsecode;
     int StrSize =0;
     int size =0;
     int msize =0;
     int lsize =0;
     input.open("morse.txt", ios::in);
     string morse [50];
     while(!(input.eof()))
     {
         input>> ws;
        input>>letters[size];
       
        input>> morsecode;
       
        if(!(input.eof()))
        {
         msize ++;
         lsize ++;
        
        
          }
           cout<< morse[0]<<endl;
          cout<<"Enter a Sentence: ";
          getline(cin,sentence);
          
          StrSize = sentence.size();
          
        for( int n =0; n < StrSize; n++)
        {
             if( sentence.at(n) ==' ')
             converted.append(2,' ');
             continue;
         for( int m =0; m< lsize; m++)
         {
             if( sentence.compare(n,morsecode,letters[m] ==0)
              {
                 converted.append(morsecode[m]);
                 converted.append(', ' ');
                 continue;
                  cout<< morsecode;
                  }
                  }
                  
                   
               
          //cout<< sentence; 
          system("PAUSE");               
     return 0;
     }
     }
     
     }
