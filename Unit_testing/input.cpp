#include "input.h"


Input::Input(int argc, char **argv):
         argc(argc),
         argv(argv)
{

}

/*
Input::~Input()
{
        for(int i=0; i<argc; ++i)
        
            delete argv[i];
        
        delete [] argv;
}*/

void Input::start()
{
    int ok = scan_examing(); 
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

        std::cerr << "You typed too much parameters !" << endl;

        return 1;

        }

        else
        {
            char text[1000];
            print_text(stoi(argv[1]), argv[2], text);
            cout << text; 
             return 0;
        }


}

#include <string.h>

void Input::print_text(int count, char* what_to_print,  char *text)
{
   int pos = 0;

   for (int i = 0; i < count; ++i) {
      int n = sprintf(text + pos, "%s\r\n", what_to_print);
      pos += n;
   }
}
