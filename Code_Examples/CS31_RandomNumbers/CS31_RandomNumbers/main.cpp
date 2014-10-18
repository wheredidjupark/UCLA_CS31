#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int randInt(int lowest, int highest);


int main()
{
    srand(time(0));
    
    for(int i =0; i < 100; i++)
    {
        cout << rand() %4 <<" ";
    }
    ///gives the output of the following: 0, 1, 2, 3
    
    return 0;
}


int randInt(int lowest, int highest)
{
    if (highest < lowest)
        swap(highest, lowest);
    return lowest + (rand() % (highest - lowest + 1));
}