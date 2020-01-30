#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    if (argc != 2) {
       std::cerr << "Not enough parameters" << endl;
       return 1;
    }

    /*string input;
    cout << "Please enter what you would like: ";
    cin>>input;*/
    
    for (int i = 0; i < stoi(argv[1])  ; i++) { //argc
    cout << argv[i] << endl;
    }
    

    return 0;
}

//ne hellowordot írjon hanem második paraméterben megadott akarmit
