#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
 
int main(int argc, char** argv) {

   if (argc < 3) {
      perror("Not enough parameters! Your quantity or expression is missing!\n");
      return 1;
   }

   else if (argc > 3) {
      perror("You typed too much parameters !\n");
      return 1;
   }

   for (int i = 0; i < atoi(argv[1]); ++i) {
      printf(argv[2]);
      printf("\n");
   }
   return 0;
}
