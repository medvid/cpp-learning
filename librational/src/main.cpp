#include <iostream>
#include "rational.h"

using std::cin;
using std::cout;
using std::endl;
using librational::rational;

void eval()
{
    rational r = rational::NaN;
    cout << "Enter rational number (X/Y): ";
    cin >> r;
    cout << "You entered: " << r << endl;
}

int main()
{
    while(true)
    {
        eval();
    }
    return 0;
}
