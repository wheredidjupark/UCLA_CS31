#include <iostream>
using namespace std;

////Problem 1.a
//Fix it: Compilation Error
/*
#include <iostream>
using namespace std;

int main()
{
    int arr[3] = {5, 10, 15};
    int *ptr = arr;
    
    *ptr = 10;
    *ptr+1 = 20;
    ptr += 2;
    ptr[0] = 30;
    
    while(ptr >= arr)
    {
        cout <<*ptr <<std::endl;
        ptr--;
    }
    
    return 0;
}
*/

//Problem 1.a.1 (i.e. First step)
//Prints out 30 20 10, one per line.
/*
#include <iostream>
using namespace std;

int main()
{
    int arr[3] = {5, 10, 15};
    int *ptr = arr;
    
    *ptr = 10;
    *(ptr+1) = 20;
    ptr += 2;
    ptr[0] = 30;
    
    //cerr << arr <<std::endl; //gives out array address
    while(ptr >= arr)
    {
        cout <<*ptr <<std::endl;
        ptr--;
    }
    
    return 0;
}
*/

//Problem 1.a.2 (i.e. Second step; Solution)
//Prints out 10, 20, 30, one per line
/*
#include <iostream>
using namespace std;

int main()
{
    int arr[3] = {5, 10, 15};
    int *ptr = arr;
    
    *ptr = 10;
    *(ptr+1) = 20;
    ptr += 2;
    ptr[0] = 30;

    //cerr << arr <<std::endl; //gives out array address
    for(ptr = arr; ptr <= arr+2; ptr++)
    {
        cout <<*ptr <<std::endl;
    }
    
    return 0;
}
*/


////Problem 1.b.
//The findMax function is supposed to find the maximum item in an array and set the pToMax parameter to point to that item so that the caller knows its location. Explain why this function won't do that, and show how to fix it. Your fix must be to the function only; you must not change the main routine below in any way, yet as a result of your fixing the function, the main routine below must work correctly.
/*
#include <iostream>
using namespace std;

void findMax(int arr[], int n, int* pToMax)
{
    if (n <= 0)
        return;      // no items, no maximum!
    
    pToMax = arr;
    
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > *pToMax)
        {
            cerr << arr[i] << " " << *pToMax <<endl;
    
            pToMax = arr + i; //pToMax
        }
        
    }
}

int main() //DO NOT CHANGE ANYTHING IN THE MAIN ROUTINE...
{
    int nums[4] = { 5, 3, 15, 6 };
    int* ptr;
    
    findMax(nums, 4, ptr);
    cout << "The maximum is at address " << ptr << endl;
    cout << "It's at index " << ptr - nums << endl;
    cout << "Its value is " << *ptr << endl;
}
*/

//Problem 1.b Solution
//findMax puts the corect value of pToMax, but pToMax is a copy of the caller's variable ptr, so the function findMax has no effect on ptr.
/*
#include <iostream>
using namespace std;

void findMax(int arr[], int n, int* &pToMax) //pToMax is passed by reference now!!! NO MORE COPY that gets erased!
{
    if (n <= 0)
        return;      // no items, no maximum!
    
    pToMax = arr;
    
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > *pToMax)
        {
            cerr << arr[i] << " " << *pToMax <<endl;
            
            pToMax = arr + i; //pToMax
        }
        
    }
}

int main() //DO NOT CHANGE ANYTHING IN THE MAIN ROUTINE...
{
    int nums[4] = { 5, 3, 15, 6 };
    int* ptr;
    
    findMax(nums, 4, ptr);
    cout << "The maximum is at address " << ptr << endl;
    cout << "It's at index " << ptr - nums << endl;
    cout << "Its value is " << *ptr << endl;
}
*/


////Problem 1.b
//The computeCube function is correct, but the main function has a problem. Explain why it may not work and show how to fix it. Your fix must be to the main function only; you must not change computeCube in any way.
/*
 #include<iostream>
 using namespace std;
void computeCube(int n, int* ncubed)
{
    *ncubed = n * n * n;
}

int main()
{
    int* ptr;
    computeCube(5, ptr);
    cout << "Five cubed is " << *ptr << endl;
}
*/

//Problem 1.c. Solution
//ptr is not pointing to any int variable..... so where does it point to????? I fixed it by making sure that ptr points to a int variable (i.e. v)
/*
#include<iostream>
using namespace std;

void computeCube(int n, int* ncubed)
{
    *ncubed = n * n * n;
}

int main()
{
    int v;
    int* ptr = &v;
    computeCube(5, ptr);
    cout << "Five cubed is " << *ptr << endl;
}
*/

//Problem 1.d
//The strequal function is supposed to return true if and only if its two C string arguments have exactly same text. What are the problems with the implementation of the function, and how can they be fixed?
/*
bool strequal(const char str1[], const char str2[])
{
    while (str1 != 0  &&  str2 != 0)
    {
        if (str1 != str2)  // compare corresponding characters
            return false;
        str1++;            // advance to the next character
        str2++;
    }
    return str1 == str2;   // both ended at same time?
}

int main()
{
    char a[15] = "Chen, B.";
    char b[15] = "Chen, Y.J.";
    
    if (strequal(a,b))
        cout << "They're the same person!\n";
}
*/
//Problem 1.d Explanation
/*
bool strequal(const char str1[], const char str2[])
{
    while (str1 != 0  &&  str2 != 0) //ok.... so you are looking at the memory address that is not equal to 0
    {
        if (str1 != str2) //so as long as the memory address is equal to each other....
            return false;
        str1++;
        str2++;
    }
    return str1 == str2;
}

int main()
{
    char a[15] = "Chen, B.";
    char b[15] = "Chen, Y.J.";
    
    if (strequal(a,b))
        cout << "They're the same person!\n";
}
 */
//Problem 1.d. Solution
/*
bool strequal(const char str1[], const char str2[])
{
    while (*str1 != '\0'  &&  *str2 != '\0') //ok.... so you are looking at the memory address that is not equal to 0
    {
        if (*str1 != *str2) //so as long as the memory address is equal to each other....
            return false;
        str1++;
        str2++;
    }
    return (*str1 == *str2);
}

int main()
{
    char a[15] = "Ju Park";
    char b[15] = "Chen, B.J.";
    
    if (strequal(a,b))
        cout << "They're the same person!\n";
}
*/

//Problem 1.e. Q & A
//This program is supposed to write 5 4 3 2 1, but it probably does not. What is the problem with this program? (We're not asking you to propose a fix to the problem.)
//The storage for the local variable anArray goes away when the function getPtrToArray returns. But that function returns a pointer to that storage. Attempting to follow that pointer in the main routine (implied by ptr[i]) yields undefined behavior.
/*
int* getPtrToArray(int& m)
{
    int anArray[5] = { 5, 4, 3, 2, 1 }; //this array disappears at the end of the function, so when we try to touch
    m = 5;
    return anArray;
}

void f()
{
    int junk[100];
    for (int k = 0; k < 100; k++)
        junk[k] = 123400000 + k;
}

int main()
{
    int n;
    int* ptr = getPtrToArray(n);
    f();
    for (int i = 0; i < n; i++)
        cout << ptr[i] << ' ';
    cout << endl;
}
*/

//Problem 2
/*
 For each of the following parts, write a single C++ statement that performs the indicated task. For each part, assume that all previous statements have been executed (e.g., when doing part e, assume the statements you wrote for parts a through d have been executed).
 
 Declare a pointer variable named cat that can point to a variable of type double.
 Declare mouse to be a 5-element array of doubles.
 Make the cat variable point to the last element of mouse.
 Make the double pointed to by cat equal to 17, using the * operator.
 Without using the cat pointer, and without using square brackets, set the fourth element (i.e., the one at position 3) of the mouse array to have the value 42.
 Move the cat pointer back by three doubles.
 Using square brackets, but without using the name mouse, set the third element (i.e., the one at position 2) of the mouse array to have the value 33.
 Without using the * operator, but using square brackets, set the double pointed to by cat to have the value 25.
 Using the * operator in the initialization expression, declare a bool variable named b and initialize it to true if the double pointed to by cat is equal to the double immediately following the double pointed to by cat, and false otherwise.
 Using the == operator in the initialization expression, declare a bool variable named d and initialize it to true if cat points to the double at the start of the mouse array, and false otherwise.

*/
//Problem 2 Solution
/*
int main()
{
    double *cat;
    double mouse[5];
    cat = mouse + 4;
    *cat = 17;
    *(mouse+3) = 42;
    cat = cat -3; //move back 3 elements... (i.e. mouse+1)
    cat[1] = 33; //not so sure...
    cat[0] = 25;
    bool b = ( *cat == *(cat+1)); //I didn't know you could do that
    cerr << b <<endl;
    bool d = ( cat == mouse);
    cerr << d <<endl;
}
*/

//Problem 3
//Rewrite the following function so that it returns the same result, but does not increment the variable ptr. Your new program must not use any square brackets, but must use an integer variable to visit each double in the array. You may eliminate any unneeded variable.
/*
double computeMean(const double* scores, int numScores)
{
    const double* ptr = scores;
    double tot = 0;
    while (ptr != scores + numScores)
    {
        tot += *ptr;
        ptr++;
    }
    return tot/numScores;
}
*/

//Problem 3 Personal Solution
/*
double computeMean(const double* scores, int numScores) //computes mean....
{
    int i = 0;
    const double* ptr = scores;
    double tot = 0;
    while (i != numScores)
    {
        tot += *(ptr+i);
        i++;
    }
    return tot/numScores;
}
*/

////Problem 4
//What does the following program print and why? Be sure to explain why each line of output prints the way it does to get full credit.
/*
int* maxwell(int* a, int* b)
{
    if (*a > *b)
        return a;
    else
        return b;
}

void swap1(int* a, int* b)
{
    int* temp = a;
    a = b;
    b = temp; //the a's and b's are copies of the actual a and b. Therefore, they get destroyed...
}

void swap2(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int array[6] = { 5, 3, 4, 17, 22, 19 };
    
    int* ptr = maxwell(array, &array[2]); // ptr points to array[0]
    *ptr = -1; //array[0] = -1
    ptr += 2; //ptr now points to array[2]
    ptr[1] = 9; //array[3] = 9
    *(array+1) = 79; //array[1] = 79
    
    cout << &array[5] - ptr << endl; //&array[5] - &array[2] = 3
    
    swap1(&array[0], &array[1]); //doesn't do anything (i didn't know....) Why? Passed by value the addresses... so it doesn't change the ptrs themselves...
    swap2(array, &array[2]); //array passed by reference. array[2] didn't t
    
    for (int i = 0; i < 6; i++)
        cout << array[i] << endl;
}
*/

////Problem 5
//Write a function named removeS that accepts one character pointer as a parameter and returns no value. The parameter is a C string. This function must remove all of the upper and lower case 's' letters from the string. The resulting string must be a valid C string. Your function must declare no more than one local variable in addition to the parameter; that additional variable must be of a pointer type. Your function must not use any square brackets and must not use the strcpy library function.

//Attempt 1
//DOES NOT FIT THE SPEC.... It should say, "he'll be a male prince." Not just removing the 's'.... (i.e. he'll be a ma  le   prince  .)
/*
void removeS(char* a)
{
    int i =0;
    while(*(a+i) != '\0')
    {
        if(*(a+i) == 's' || *(a+i) == 'S')
            *(a+i) = ' ';
        i++;
    }
}
*/

/*Solution 1
void removeS(char* msg)
{
    char* fixed_pos = msg; //saves the memory address of the fixed_pos.
    while(*msg != '\0')
    {
        if(*msg != 's' && *msg != 'S')
        {
            *fixed_pos = *msg;
            fixed_pos++;
        }
        msg++;
    }
    *fixed_pos = '\0';
}
 */

/*Solution 2
void removeS(char* source)
{
    char* destination = source;
    for ( ; *source != '\0'; source++)
    {
        if (*source != 's'  &&  *source != 'S')
        {
            *destination = *source;
            destination++;
        }
    }
    *destination = '\0';  // Don't forget the zero byte at the end
}
 */

void removeS(char* a)
{
    char *destination = a;
    for( ; *a != '\0' ;a++)
    {
        if(*a != 's' && *a != 'S')
        {
            *destination = *a;
            destination++;
        }
    }
    *destination = '\0';
    }


int main()
{
    char msg[50] = "She'll be a massless princess.";
    removeS(msg);
    cout << msg;  // prints   he'll be a male prince.
}