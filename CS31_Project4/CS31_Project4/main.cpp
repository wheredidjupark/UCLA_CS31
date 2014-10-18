#include <iostream>
#include <string>
#include <cassert>
#include <algorithm> //needed for testcases; provided
#include <cstdlib> //needed for testcases; provided

using namespace std;

/////////////////Prototypes of functions that you must implement//////////

int appendToAll(string a[], int n, string value); //Append value to the end of each of the n elements of the array and return n. [Of course, in this and other functions, if n is negavtive, the paragraph above that starts "notwithstanding" trumps this by requiring that the function return -1. Also, in the description of this function and the others, when we say "the array", we mean n elements that the function is aware of.]
/*For example:
    string folk[6] = {"george","lucille", "gob", "michael",lindsay","buster"};
 int j = appendToAll(folks, 6, "!!!"): //returns 6
 and now folks[0] is "gorge!!!", folks[1] is "lucille!!!", ...,
 
 */

int lookup(const string a[], int n, string target); //Return the position of the first string in the array that is equal to target. Return -1 if there is no such string. As noted above, case matters: Do not consider "GeORge" to be equal to "gEoRgE"

int positionOfMax(const string a[], int n); //return the position of a string in the array such that string is >= every string in the array. If there is more than one such string, return the smalest position of such a string. Return -1 if the array has no elements.
/*For example:
 string folks[6] = {"george","lucille", "gob", "michael",lindsay","buster"};
 int k = positionOfMax(folks, 6); //return 3, since michael is latest in alphabetic order
 */

int rotateLeft(string a[], int n , int pos); //Eliminate the item at position pos by copying all elements after it one place to the left. Put the item that was thus eliminated into the last position of the array. Return the original position of the item that was moved to the end.

/*
 Here's an example:
 string humans[5] = { "homer", "marge", "bart", "lisa", "maggie" };
 int m = rotateLeft(humans, 5, 1);  // returns 1
 // humans now contains:  "homer"  "bart"  "lisa"  "maggie"  "marge"
 
 */

int rotateRight(string a[], int n , int pos); //Eliminate the item at position pos by copying all elements before it one place to the right. Put the item that was thus eliminated into the first position of the array. Return the original position of the item that was moved to the beginning.
/*
 Here's an example:
 string humans[5] = { "homer", "marge", "bart", "lisa", "maggie" };
 int p = rotateRight(humans, 5, 2);  // returns 2
 // humans now contains:  "bart"  "homer"  "marge"  "lisa"  "maggie"
 */

int flip(string a[], int n ); //reverse the order of the elements of the array and return n.
/*Here's an example:
 string beings[6] = { "claire", "phil", "", "haley", "alex", "luke" };
 int q = flip(beings, 4);  // returns 4
 // beings now contains:  "haley"  ""  "phil"  "claire"  "alex"  "luke"
 */

int differ(const string a1[], int n1, const string a2[], int n2);//Return the position of the first corresponding elements of a1 and a2 that are not equal. n1 is the number of interesting elements in a1, and n2 is the number of interesting elements in a2. If the arrays are equal up to the point where one or both runs out, return the smaller of n1 and n2.
/*For example,
 string beings[6] = { "claire", "phil", "", "haley", "alex", "luke" };
 string group[4] = { "claire", "phil", "mitchell", "luke" };
 int r = differ(beings, 6, group, 4);  //  returns 2
 int s = differ(beings, 2, group, 1);  //  returns 1
 */

int subsequence(const string a1[], int n1, const string a2[], int n2); //If all n2 elements of a2 appear in a1, consecutively and in the same order, then return the position in a1 where that subsequence begins. If the subsequence appears more than once in a1, return the smallest such beginning position. Return −1 if a1 does not contain a2 as a contiguous subsequence.
/*
 For example,
 string family[10] = { "elyse", "steven", "alex", "mallory", "jennifer", "andrew" };
 string names1[10] = { "steven", "alex", "mallory" };
 int t = subsequence(family, 6, names1, 3);  // returns 1
 string names2[10] = { "elyse", "mallory" };
 int u = subsequence(family, 5, names2, 2);  // returns -1
 */

int lookupAny (const string a1[], int n1, const string a2[], int n2);
//Return the smallest position in a1 of an element that is equal to any of the elements in a2. Return -1 if no element of a1 is equal to any element of a2
/*For example,
 string family[10] = { "elyse", "steven", "alex", "mallory", "jennifer", "andrew" };
 string set1[10] = { "skippy", "jennifer", "mallory", "steven" };
 int v = lookupAny(family, 6, set1, 4);  // returns 1 (a1 has "steven" there)
 string set2[10] = { "skippy", "nick" };
 int w = lookupAny(family, 6, set2, 2);  // returns -1 (a1 has none)
 */

int split(string a[], int n , string splitter); //Rearrange the elements of the array so that all the elements whose value is < splitter come before all the other elements, and all the elements whose value is > splitter come after all the other elements. Return the position of the first element that, after the rearrangement, is not <splitter, or n if there are none.
/*For example,
 string kin[6] = { "hal", "lois", "francis", "reese", "malcolm", "dewey" };
 int x = split(kin, 6, "jamie");  //  returns 3
 // kin might now be
 //      "hal"  "dewey"  "francis"  "reese"  "malcolm"  "lois"
 // or   "francis"  "hal"  "dewey"  "malcolm"  "lois"  "reese"
 // or one of several other orderings.
 // The first 3 elements are < "jamie"; the last 3 aren't.
 string sibs[4] = { "francis", "reese", "malcolm", "dewey" };
 int y = split(sibs, 4, "francis");  //  returns 1
 // sibs must now be either
 //      "dewey"  "francis"  "reese"  "malcolm"
 // or   "dewey"  "francis"  "malcolm"  "reese"
 // All elements < "francis" (i.e., "dewey") come before all others.
 // All elements > "francis" (i.e., "malcolm" and "reese") come
 //      after all others.
 */

///////************************** For each of the functions rotateLeft, rotateRight, flip, and split, if the function is correctly implemented, you will earn one bonus point for that function if it does its job without creating any additional array.



////////////////////END OF REQUIRED FUNCTION PROTOTYPES//////////////////////

void swap(string& s1, string& s2);

//Function Prototypes for other functions that you need to run the program///
/*
bool match(string a1, const string a2[], int n2); /
*/
///END//







string c[6] = {"alpha", "beta", "beta", "delta", "gamma", "gamma"}; //for checking test cases; provided by class
bool splitcheck(const string a[], int n, int p, string splitter)//for checking test cases; provided by class
{
    for (int k = 0; k < p; k++)
        if (a[k] >= splitter)
            return false;
    for ( ; p < n  &&  a[p] == splitter; p++)
        ;
    for (int k = p; k < n; k++)
        if (a[k] <= splitter)
            return false;
    string b[100];
    copy(a,a+n,b);
    sort(b,b+n);
    return equal(b,b+n,c);
}

void testone(int n) //for testcases; provided by class
{
    const int N = 6;
    
    // Act as if  a  were declared:
    //   string a[6] = {
    //       "alpha", "beta", "gamma", "gamma", "beta", "delta"
    //   };
    // This is done in a way that will probably cause a crash if
    // a[-1] or a[6] is accessed:  We place garbage in those positions.
    string aa[1+N+1] = {
        "", "alpha", "beta", "gamma", "gamma", "beta", "delta", ""
    };
    string* a = &aa[1];
   // a[-1].string::~string();
    //a[N].string::~string();
    fill_n(reinterpret_cast<char*>(&a[-1]), sizeof(a[-1]), 0xEF);
    fill_n(reinterpret_cast<char*>(&a[N]), sizeof(a[N]), 0xEF);
    
    string b[N] = {
        "alpha", "beta", "gamma", "delta", "beta", "delta"
    };
    
    switch (n)
    {
        case  1: {
            assert(appendToAll(a, -1, "rho") == -1 && a[0] == "alpha");
        } break; case  2: {
            assert(appendToAll(a, 0, "rho") == 0 && a[0] == "alpha");
        } break; case  3: {
            assert(appendToAll(a, 1, "rho") == 1 && a[0] == "alpharho" &&
                   a[1] == "beta");
        } break; case  4: {
            assert(appendToAll(a, 6, "rho") == 6 && a[0] == "alpharho" &&
                   a[1] == "betarho" && a[2] == "gammarho" &&
                   a[3] == "gammarho" && a[4] == "betarho" &&
                   a[5] == "deltarho");
        } break; case  5: {
            assert(lookup(a, -1, "alpha") == -1);
        } break; case  6: {
            assert(lookup(a, 0, "alpha") == -1);
        } break; case  7: {
            assert(lookup(a, 1, "alpha") == 0);
        } break; case  8: {
            assert(lookup(a, 6, "delta") == 5);
        } break; case  9: {
            assert(lookup(a, 6, "beta") == 1);
        } break; case 10: {
            assert(lookup(a, 6, "zeta") == -1);
        } break; case 11: {
            assert(positionOfMax(a, -1) == -1);
        } break; case 12: {
            assert(positionOfMax(a, 0) == -1);
        } break; case 13: {
            assert(positionOfMax(a, 1) == 0);
        } break; case 14: {
            assert(positionOfMax(a, 3) == 2);
        } break; case 15: {
            assert(positionOfMax(a, 6) == 2);
        } break; case 16: {
            assert(positionOfMax(a+3, 3) == 0);
        } break; case 17: {
            a[0] = "";
            a[1] = " ";
            a[2] = "";
            assert(positionOfMax(a, 3) == 1);
        } break; case 18: {
            assert(rotateLeft(a, -1, 0) == -1 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 19: {
            assert(rotateLeft(a, 6, -1) == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 20: {
            assert(rotateLeft(a, 6, 6) == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 21: {
            assert(rotateLeft(a, 0, 0) == -1 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 22: {
            assert(rotateLeft(a, 1, 0) == 0 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 23: {
            assert(rotateLeft(a, 6, 0) == 0 &&
                   a[0] == "beta" && a[1] == "gamma" && a[2] == "gamma" &&
                   a[3] == "beta" && a[4] == "delta" && a[5] == "alpha");
        } break; case 24: {
            assert(rotateLeft(a, 6, 5) == 5 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 25: {
            assert(rotateLeft(a, 6, 3) == 3 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "beta" && a[4] == "delta" && a[5] == "gamma");
        } break; case 26: {
            assert(rotateLeft(a, 5, 3) == 3 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "beta" && a[4] == "gamma" && a[5] == "delta");
        } break; case 27: {
            assert(rotateRight(a, -1, 0) == -1 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 28: {
            assert(rotateRight(a, 6, -1) == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 29: {
            assert(rotateRight(a, 6, 6) == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 30: {
            assert(rotateRight(a, 0, 0) == -1 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 31: {
            assert(rotateRight(a, 1, 0) == 0 &&
                   a[0] == "alpha" && a[1] == "beta");
        } break; case 32: {
            assert(rotateRight(a, 6, 0) == 0 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 33: {
            assert(rotateRight(a, 6, 5) == 5 &&
                   a[0] == "delta" && a[1] == "alpha" && a[2] == "beta" &&
                   a[3] == "gamma" && a[4] == "gamma" && a[5] == "beta");
        } break; case 34: {
            assert(rotateRight(a, 5, 3) == 3 &&
                   a[0] == "gamma" && a[1] == "alpha" && a[2] == "beta" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 35: {
            assert(flip(a, -1) == -1 && a[0] == "alpha");
        } break; case 36: {
            assert(flip(a, 0) == 0 && a[0] == "alpha");
        } break; case 37: {
            assert(flip(a, 1) == 1 && a[0] == "alpha" &&
                   a[1] == "beta");
        } break; case 38: {
            assert(flip(a, 2) == 2 && a[0] == "beta" &&
                   a[1] == "alpha" && a[2] == "gamma");
        } break; case 39: {
            assert(flip(a, 5) == 5 && a[0] == "beta" &&
                   a[1] == "gamma" && a[2] == "gamma" && a[3] == "beta" &&
                   a[4] == "alpha" && a[5] == "delta");
        } break; case 40: {
            a[2] = "zeta";
            assert(flip(a,6) == 6 && a[0] == "delta" && a[1] == "beta" &&
                   a[2] == "gamma" && a[3] == "zeta" && a[4] == "beta" &&
                   a[5] == "alpha");
        } break; case 41: {
            assert(differ(a, -1, b, 6) == -1);
        } break; case 42: {
            assert(differ(a, 6, b, -1) == -1);
        } break; case 43: {
            assert(differ(a, 0, b, 0) == 0);
        } break; case 44: {
            assert(differ(a, 3, b, 3) == 3);
        } break; case 45: {
            assert(differ(a, 3, b, 2) == 2);
        } break; case 46: {
            assert(differ(a, 2, b, 3) == 2);
        } break; case 47: {
            assert(differ(a, 6, b, 6) == 3);
        } break; case 48: {
            assert(subsequence(a, -1, b, 6) == -1);
        } break; case 49: {
            assert(subsequence(a, 6, b, -1) == -1);
        } break; case 50: {
            assert(subsequence(a, 0, b, 6) == -1);
        } break; case 51: {
            assert(subsequence(a, 6, b, 0) == 0);
        } break; case 52: {
            assert(subsequence(a, 6, b, 1) == 0);
        } break; case 53: {
            assert(subsequence(a, 6, b+4, 2) == 4);
        } break; case 54: {
            assert(subsequence(a, 6, b+3, 1) == 5);
        } break; case 55: {
            assert(subsequence(a, 6, b+3, 2) == -1);
        } break; case 56: {
            assert(subsequence(a, 6, b+2, 2) == -1);
        } break; case 57: {
            assert(subsequence(a, 6, a, 6) == 0);
        } break; case 58: {
            assert(lookupAny(a, 6, b, -1) == -1);
        } break; case 59: {
            assert(lookupAny(a, -1, b, 6) == -1);
        } break; case 60: {
            assert(lookupAny(a, 0, b, 1) == -1);
        } break; case 61: {
            assert(lookupAny(a, 6, b, 0) == -1);
        } break; case 62: {
            assert(lookupAny(a, 1, b, 1) == 0);
        } break; case 63: {
            assert(lookupAny(a, 6, b+3, 3) == 1);
        } break; case 64: {
            assert(lookupAny(a, 4, b+3, 3) == 1);
        } break; case 65: {
            assert(lookupAny(a, 2, b+2, 2) == -1);
        } break; case 66: {
            assert(split(a, -1, "beta") == -1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 67: {
            assert(split(a, 0, "beta") == 0 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 68: {
            assert(split(a, 1, "aaa") == 0 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 69: {
            assert(split(a, 1, "alpha") == 0 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 70: {
            assert(split(a, 1, "zeta") == 1 &&
                   a[0] == "alpha" && a[1] == "beta" && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 71: {
            assert(split(a, 2, "aaa") == 0 &&
                   splitcheck(a, 2, 0, "aaa") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 72: {
            assert(split(a, 2, "alpha") == 0 &&
                   splitcheck(a, 2, 0, "alpha") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 73: {
            assert(split(a, 2, "beta") == 1 &&
                   splitcheck(a, 2, 1, "beta") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 74: {
            assert(split(a, 2, "zeta") == 2 &&
                   splitcheck(a, 2, 2, "zeta") && a[2] == "gamma" &&
                   a[3] == "gamma" && a[4] == "beta" && a[5] == "delta");
        } break; case 75: {
            assert(split(a, 6, "aaa") == 0 && splitcheck(a, 6, 0, "aaa"));
        } break; case 76: {
            assert(split(a, 6, "alpha") == 0 &&
                   splitcheck(a, 6, 0, "alpha"));
        } break; case 77: {
            assert(split(a, 6, "beta") == 1 &&
                   splitcheck(a, 6, 1, "beta"));
        } break; case 78: {
            assert(split(a, 6, "delta") == 3 &&
                   splitcheck(a, 6, 3, "delta"));
        } break; case 79: {
            assert(split(a, 6, "gamma") == 4 &&
                   splitcheck(a, 6, 4, "gamma"));
        } break; case 80: {
            assert(split(a, 6, "zeta") == 6 &&
                   splitcheck(a, 6, 6, "zeta"));
        } break; case 81: {
            a[2] = "mu";
            c[5] = "mu";
            assert(split(a, 6, "mu") == 5 && splitcheck(a, 6, 5, "mu"));
        } break; case 82: {
            assert(split(a, 6, "chi") == 3 && splitcheck(a, 6, 3, "chi"));
        } break; case 83: {
            // This case tested whether rotateLeft used an extra array
        } break; case 84: {
            // This case tested whether rotateRight used an extra array
        } break; case 85: {
            // This case tested whether flip used an extra array
        } break; case 86: {
            // This case tested whether split used an extra array
        } break;
    }
    
    new (&a[-1]) string;
    new (&a[N]) string;
}


int main() //main function; provided by class
{
    cout << "Enter a test number (1 to 86): ";
    int n;
    cin >> n;
    if (n < 1  ||  n > 86)
    {
        cout << "Bad test number" << endl;
        return 1;
    }
    testone(n);
    cout << "Passed test " << n << endl;

}



int appendToAll(string a[], int n, string value)
{
    if(n < 0)
        return -1;
    
    int i =0;
    for( i = 0 ; i < n ; i++)
    {
        a[i] = a[i] + value;
    }
    return i;

}

int lookup(const string a[], int n, string target)
{
    if(n<0)
    return -1; //Temporary
    
    int i = 0;
    for(i=0; i <n; i++ )
    {
        if(a[i] == target)
        {
            return i;
        }
    }
    return -1; // if you cannot find any element in a[] that matches the string target
    
}

int positionOfMax(const string a[], int n)
{
    
    /*Attempt 1: bug. you are only comparing the elements next to each other.... dumb...
     
     if(n <=0)
     return -1;
    int max =0;
    int i =0;
    for(;i <n && i+1 < n; i++)
    {
        if(a[i] < a[i+1] )
        {
            max = i+1;
        }
        else //if equal or less, leave the max alone!
        {
        }
    }
    return max;
     */
    
    //Attempt 2: Success!
    if(n <=0)
        return -1;

    int max = 0;
    
    for(int i =0; i < n && max < n;i++) //max < n is not necessary? but just in case...
    {
        if(a[max] <a[i])
            max = i;
    }
    return max;
}

int rotateLeft(string a[], int n , int pos)
{
    if (n < 0 || pos <0 || pos >= n) //n cannot be negative. pos cannot be negative. pos cannot be >= than n because you are leaving the bounds of the array. (pos is strictly less than n)
        return -1;
    
    string temp = a[pos];
    int i = 0;
    for(i =pos; i < n && i+1 <n ; i++)
    {
        a[i] = a[i+1];
    }
    a[n-1] = temp;
    return pos;
}

int rotateRight(string a[], int n , int pos)
{
    
    if(n<0 || pos < 0|| pos >= n)
    return -1;
    
    string temp = a[pos];
    int i =0;
    for(i = pos; i > 0 ; i--) //condition: i > 0 && i-1 >= 0
    {
        a[i] = a[i-1];
    }
    a[0] = temp;
    return pos;
    
}

int flip(string a[], int n )
{
    //ATTEMPT 1
    if (n < 0)
    return -1;
    
    if (n ==0)
    return 0;
    
    int numberOfOperations = n/2; //the division by 2 truncated... It will repeat the process this many times!
    
    int start = 0; //beginning position of the array
    int end = n-1; //end position of the array
    
    string temp;
    
    for(int i =0; i < numberOfOperations; i++)
    {
        temp = a[end];
        a[end] = a[start];
        a[start] = temp;
        end--;
        start++;
    }
    return n;
}

int differ(const string a1[], int n1, const string a2[], int n2)
{
    if( n1 < 0 || n2 < 0)
        return -1;
    int i =0;
    
    for(i=0; i < n1 || i < n2; i++) //find the pos of where a1 and a2 that are not equal.
    {
        if(a1[i] != a2[i])
            return i;
    }
    
    if(n1 >= n2)
        return n2;
    else
        return n1;
    
    return -1; //Temporary
    
}

int subsequence(const string a1[], int n1, const string a2[], int n2)
{
    
    
//Also, n1 and n2 cannot be 0?
    
    
//Attempt 2: similar to the solution. but has bug.
    
    
    /*
     
     
     //if(n2>n1) //if you are trying to find a2 within a1, how can a2 be bigger than a1? CANNOT HAPPEN. return -1
     //return -1;
     
     if(n1 < 0 || n2 < 0) //n1 and n2 cannot be negative. n1 cannot be 0?
     return -1;
     
    int a1_pos = 0;
    for( ;a1_pos < n1;)
    {
        for(int a2_pos = 0; a2_pos < n2 && a1_pos < n1;)
        {
            if(a1[a1_pos]==a2[a2_pos])
            {
                a1_pos++;
                a2_pos++;
            }
            else
            {
                break;
            }
            
            if(a2_pos == n2-1)
                return a1_pos;
        }
        
        a1_pos++;
    }

    return -1;
    
     */
    //ATTEMPT 1: I don't even know what's going on with this code... too complex and messy...
    /*
     
     int a1_pos =0;
     int a2_pos = 0;

     for(; a1_pos < n1 ; a1_pos++ )
    {
        if(a1[a1_pos] == a2[0])
        {
            for(a2_pos = 0; a2_pos < n2 && a1_pos < n1 ;a2_pos++, a1_pos++)
            {
                if(a1[a1_pos] == a2[a2_pos])
                {
                    ///continue....
                }
                else
                {
                    continue;
                }
                }
                
                if(a2_pos == n2)
                {
                    return a1_pos;
                }

            }

        }
        //else
    }

    return -1; //if a1 does not contain a2....
     */
    
    
    
    //Solution
     if (n1 < 0  ||  n2 < 0)
     return -1;
     
     // Try matching the a2 sequence starting at each position of a1 that
     // could be the start of sequence of length n2
     
     for (int k1 = 0; k1 < n1 - n2 + 1; k1++)
     {
     // See if the a2 sequence matches starting at k1 in a1
     
     bool match = true;  // Assume they match until proved otherwise
     for (int k2 = 0; k2 < n2; k2++)
     {
     if (a1[k1+k2] != a2[k2])
     {
     match = false;
     break;
     }
     }
     if (match)  // We never found a mismatch, so they match
     return k1;
     }
     return -1;
     
}

int lookupAny (const string a1[], int n1, const string a2[], int n2)
{
    
    //ATTEMPT 1: // works fine. but it's not great compared to attempt 2 bc it rewrites lookup function in match function....
    /*
    if (n1 <= 0 || n2 <= 0)
        return -1;
    
    int a1_pos = 0;
///////// Need to work on this....
    
    for(a1_pos = 0; a1_pos < n1; a1_pos++)
    {
        string temp = a1[a1_pos];
        if (match(temp, a2, n2) == true)
        {
            return a1_pos;
        }

    }
    
    return -1; //if no match after checking every position of a1...
*/
    
    //Solution: //essentially same as Attempt 1
    if (n1 < 0  ||  n2 < 0)
        return -1;
    for (int k = 0; k < n1; k++)
        if (lookup(a2, n2, a1[k]) != -1)
            return k;
    return -1;
}

int split(string a[], int n , string splitter)
{
    
    //Attempt 1: Failed because the function stops without arrangement when a[i] >= splitter.
    /*
    if(n < 0)
    return -1;
    
    string temp;
    
    for(int i = 0; i < n; i++)
    {
        if(a[i] >= splitter)
            return i;
        else //a[i] < splitter, move everything to the right.
        {
            rotateRight(a, n, i);
        }
    }
    return -1;
    */
    
    


    
    //Attempt 2: 99% successful. testcases 77 & 78 dont work for some reason. it returns proper int pos. Identified the problem. rotateRight isn't working to rearrange the arrays properly.... Also, see attempt 3.
    /*
    if(n<0)
    return -1;
    
    for(int i =0; i <n; i++)
    {
        if(a[i] < splitter)
            rotateRight(a, n, i);
    }
    
    for (int i =0; i <n; i++)
    {
        cerr << a[i] << " ";
    }
    
    int pos = 0; //find the position of the first element that after the rearrangement is not < splitter, or n if there are none
    
    for(; pos < n; pos++)
    {
        if((a[pos] >= splitter))
        {
            //cerr << pos;
            return pos;

        }
    }
    
    return pos;
    */
    


    //Attempt 3:forgot to address that 'all the lements whose value is > splitter come after all the other elements.
    /*
    if(n<0)
        return -1;
    
    string temp;
    for(int i =0; i <n; i++)
    {
        if(a[i] < splitter) //if a[i] < splitter... move the element to the 0th.. and move all the elements before the element one place to the right
        {
            temp = a[i];
            for(int k = i; k > 0 ; k--)
            {
                a[k] = a[k-1];
            }
            a[0] = temp;
        }
    }
    
    for (int i =0; i <n; i++)
    {
        cerr << a[i] << " ";
    }
    
    int pos = 0; //find the position of the first element that after the rearrangement is not < splitter, or n if there are none
    
    for(; pos < n; pos++)
    {
        if((a[pos] >= splitter))
        {
            cerr << pos;
            return pos;
            
        }
    }
    
    return pos;
     */

     
    //Solution from the class.
    
    if (n < 0)
        return -1;
    
    // It will always be the case that just before evaluating the loop
    // condition:
    //  firstNotLess <= firstUnknown and firstUnknown <= firstGreater
    //  Every element earlier than position firstNotLess is < splitter
    //  Every element from position firstNotLess to firstUnknown-1 is
    //    == splitter
    //  Every element from position firstUnknown to firstGreater-1 is
    //     not known yet
    //  Every element at position firstGreater or later is > splitter
    
    int firstNotLess = 0;
    int firstUnknown = 0;
    int firstGreater = n;
    
    while (firstUnknown < firstGreater)
    {
        if (a[firstUnknown] > splitter)
        {
            firstGreater--;
            swap(a[firstUnknown], a[firstGreater]);
        }
        else
        {
            if (a[firstUnknown] < splitter)
            {
                swap(a[firstNotLess], a[firstUnknown]);
                firstNotLess++;
            }
            firstUnknown++;
        }
    }
    for (int i =0; i <n; i++)
    {
        cerr << a[i] << " ";
    }
    return firstNotLess;
    
    
}

void swap(string& s1, string& s2)
{
    string t = s1;
    s1 = s2;
    s2 = t;
}

//my personal solution for solving part of lookupAny function... but it's essentially lookup function.
/*
bool match(string a1, const string a2[], int n2) //Used with lookupAny function...
{
    for(int i =0; i < n2; i++)
    {
        if (a1 == a2[i])
            return true;
    }
    return false;
}
*/