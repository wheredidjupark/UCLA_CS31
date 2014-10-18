//
//  main.cpp
//  CS31_project5_scratch1
//
//  Created by Ju Hyeon Park on 10/12/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char characters[10] = "Hellooooo"; //if whitespace occupies elements of the array, 
    for(int i = 0; i < 10; i++)
    {
        cerr <<i << "th" << characters[i] <<endl;
    }
    
    char input_directory[] = "/Users/wheredidjupark/Documents/CS/CS31_Project5/CS31_Project5/text.txt";
    ifstream input_file(input_directory);
    
    if(!input_file)
    {
        cout << "Cannot Open" <<endl;
    }
    else
        cout <<"success!" <<endl;
    
    char line[100];
    while(input_file.getline(line, 100)) //if successfully read the line up to 6 characters...
       cout << "Data: " <<line <<endl; //if failed to read the line up to 6 characters.... (bc the line has more than 6 or stuff like that)
    
        cout <<"End of File!";

    
}
