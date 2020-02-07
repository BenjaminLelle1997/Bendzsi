#include "input.h"

/*
Input::Input():
         argc(argc),
         argv(argv)
{

}*/

/*
Input::~Input()
{
        for(int i=0; i<argc; ++i)
        
            delete argv[i];
        
        delete [] argv;
}*/

void Input::start()
{
    int ok=scan_examing(); 
}

int Input::getArgc()
{
	return argc;
}


char Input::getArgv()
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
		 for (int i = 0; i < stoi(argv[1]); ++i) {
      		 cout << argv[2] << endl;
  		  }
   		 return 0;
        }


}
