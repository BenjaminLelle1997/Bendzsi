#ifndef INPUT_H
#define INPUT_H

#include <iostream>
using namespace std;

class Input
{
	
		int argc;
		char** argv;

	public:
		Input(int argc, char ** argv);
		
        //~Input();
        
        void start();
        
		int getArgc();
		
		char** getArgv();

		int scan_examing();


     protected:
         void print_text(int count, char* what_to_print, char *text);

		
};

#endif
