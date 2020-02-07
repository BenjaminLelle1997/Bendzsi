#ifndef INPUT_H
#define INPUT_H

#include <iostream>
using namespace std;

class Input
{
	
		int argc;
		char** argv;

	public:
		//Input();
		
        //~Input();
        
        void start();
        
		int getArgc();
		
		char getArgv();

		int scan_examing();

		
};

#endif
