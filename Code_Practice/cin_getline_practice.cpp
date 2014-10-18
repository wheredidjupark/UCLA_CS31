#include <iostream>

using namespace std;

int main()
{
   
    string input1;
    string input2;
    string input3;
    string input4;
    
    cout <<"Enter either words or phrases\n";
    //write the following: this is a test
    cin >> input1;
    getline(cin, input2);
    cin >> input3;
    /* 
     cases:
     1) cin >> input1;    output: "this"
     
     2) cin >> input1 >> input2; output: "thisis"
     
     3) cin >> input1 >> input2 >> input3 >> input4;  output: "thisisatest"
     
     4) cin >> input1;
     getline(cin, input2);
     output: "this is a test"
     
     5) cin >> input1;
     getline (cin, input2);
     cin >> input3;    // write "the test works!"
     ****CHANGE cout according to the number of variables we use.
     */
    cout << endl << input1 << input2 <<input3 <<input4;
    /*

     
     */

    
    
    return 0;
}
