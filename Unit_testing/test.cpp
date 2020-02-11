#include <iostream>
#include "input.h"
#include <string.h>
//#include <cassert>
using namespace std;


// Version A  

int main()
{
   
  
   int num=2;
      
    const char *test_string = std::string("kiskutya").c_str();
    
    char* something[1] = {(char*)"kiskutya"};
    
/*
// Version B
int main(int num, char ** argument)
{ 
          
    const char *test_string = 
    std::string("").c_str();
    
    char* something[1] = {(char*)""};
*/    
    
//  Examing the first parameter and the text size
    Input s2(num,something);
    
 
    s2.scan_examing();
    
    char output[10];
    
    s2.print_text(num,(char*)test_string,output);
   
  
  
    if(strlen(output) ==  num*(strlen(test_string)+2))
    {
    
              
        if(num>0 || num>='1' && num<='9')
        {
            cout << "Your first character is a positive number" << endl;      
            cout << "and your text's length is also OK." << endl;
            
                       
        }
        else 
        {
            
        cout << "Your first character isn't a positive number or not a number" << endl;      
        cout << 
        "but your text's length is OK." << endl;
        }
        
        
    }
    
    else /*if (strlen(output) <=  num*(strlen(test_string)+2)|| strlen(test_string) == 0)*/
    
    {
        if(num>0 || num>='1' && num<='9')
        {
            cout << "Your first character is a positive number" << endl;      
            cout << "but your text's length is not good." << endl;
           
        }
        else 
        {
            cout << "Your first character isn't a positive number or not a number" << endl;      
            cout << "and your text's length is also not good." << endl;
        }
    }
    
    
 
    return 0;
}



