#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    if (argc != 2) {
       std::cerr << "Not enough parameters" << endl;
       return 1;
    }

    for (int i = 0; i < stoi(argv[1]); i++) {
        cout << "Hello World!\n";
    }

    return 0;
}
