#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include "test.h"
using namespace std;

class Input
{
	
		int argc;
		char ** argv;

	public:
		Input(int argc, char ** argv);
		
        void setArgc(int num);
        
        void setArgv(char** argumentums);
        
        int getArgc();
		
		char** getArgv();
        
       	int scan_examing();


     public:
         void print_text(int count, char* what_to_print, char *text);

		
};

#endif
