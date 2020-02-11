#include "input.h"
#include <string.h>


Input::Input(int argc, char** argv):
         argc(argc),
         argv(argv)
{

}

void Input::setArgc(int num)
{
	argc=num;
}


void Input::setArgv(char** argumentums)
{
	argv=argumentums;
}

int Input::getArgc()
{
	return argc;
}


char** Input::getArgv()
{
	return argv;
}




int Input::scan_examing() {
    
   	if (getArgc() < 3) {
        
                
    	std::cerr << "Not enough parameters! Your quantity or expression is missing!" << endl;
    
          
	return 1;

    }

    else if (getArgc() > 3) {
        
    std::cerr << "You typed too much parameters!" << endl;

    return 1;
    
    }

    else
    {
        cout << "You typed well." << endl;
        
        char text_array[10];
        
        print_text(stoi(argv[1]), argv[2], text_array);
        
        cout << text_array; 
        
        return 0;
    }


}


void Input::print_text(int count, char* what_to_print,  char *text)
{
   int position = 0; //lehessen mellé más szöveget írni

   for (int i = 0; i < count; ++i) {
      //int n = sprintf(text + pos, "%s\r\n", what_to_print);
      position += sprintf(text + position, "%s\r\n", what_to_print);
   }
}
