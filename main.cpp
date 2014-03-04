#include <iostream>
#include <string>
#include <vector>


#include "text_overlap.hpp"

using namespace std;



int main(int argc, char *argv[])
{



    cout << text_overlap("/tmp/1.txt", "/tmp/2.txt") << endl;

    return 0;
}
