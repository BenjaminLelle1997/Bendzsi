#include<iostream>
using namespace std;

int main(int argc, char** argv) {

   if (argc < 3) {
      std::cerr << "Not enough parameters! Your quantity or expression is missing!" << endl;
      return 1;
   }

   else if (argc > 3) {
      std::cerr << "You typed too much parameters !" << endl;
      return 1;
   }

   for (int i = 0; i < stoi(argv[1]); ++i) {
      cout << argv[2] << endl;
   }
   return 0;
}
