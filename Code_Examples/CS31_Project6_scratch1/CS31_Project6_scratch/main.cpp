#include <iostream>
using namespace std;





int main()
{
    //arrays are essentially pointers!
    // arr holds the memory address.
    int arr[5] = { 1, 2, 3, 4, 5};
    cerr << *arr <<endl;
    cerr << *(arr+1) <<endl;
    cerr << *(arr+2) <<endl;
    cerr << *(arr+3) <<endl;
    cerr << *(arr+4) <<endl;
    return 0;
}