#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

const int maxLegitimateScore = 100; //if the score is more than 100...

//The following spamRule1~spamRule5 indicates the number of points added against the legitimacy of email.
const int spamRule1_score = 30; //30 pionts if the subject line has at least one word and if 90% of the words are uppercase.
const int spamRule2_score = 40; //40 points if the subject line if LAST WORD contains more than 3 consecutive consonants.
const int spamRule3_score = 20; //20 points if the subject line contains 3 or more continguous '!' (i.e. exclamation point)
const int spamRule4_score = 40; //40 points if the body contains more than 50% of the words in entirely uppercase
const int spamRule5_score = 5; //5 points for EACH TIME following words are found in the body: buy, cheap, click, diploma, enlarge, free, limited, money, now, offer, only, pills, sex (*SeX = sex)


//function prototypes

//functions required by the Project 3 specs
string getFirstWord(string text); //This function returns the first word in the string variable text. If text has no word, this function returns the empty string (i.e. "").
string getLastWord(string text); //This function returns the last word in the string variable text. If text has no word, this function returns the empty string (i.e. "").
string extractWord(string& text); //this function returns the first word in the string that text is a reference to. If that string has no words, this function returns the empty string
bool isUppercase(string text); //This function returns true iff every letter in the string text is uppercase. For a string with no letters, this means the function returns true. Non-letter characters in the string text, if any, have no effect on the result of this function.
string makeUppercase(string text); //This function returns a new string identical to the value of the string txt, except that each lowercase letter of text appears as its uppercase equivalent in the result string.
bool hasMultipleExclamations(string text); //This function returns true iff the string text contains three consecutive exclamation marks.
bool isGibberishWord(string text); //This function returns true iff the string text contains more than three consecutive consonants.

//functions not required by the Project 3 specs but necessary
int spamRule1(string email_subject);
int spamRule2(string email_subject);
int spamRule3(string email_subject);
int spamRule4(string email_body);
int spamRule5(string email_body);

bool checkConsonant(char ch);
int checkNumberOfWords(string text);
int checkNumberOfUpperWords(string text);

int main()
{
    string email_subject;
    string email_body;
    string userResponse; //"Would you like to classifiy another email?" (y or n)
    
    int spamScore = 0; //total spam score
    int count_spam = 0;
    int count_legitimate =0;
    
    
    
    
    do
    {
        spamScore = 0;
        
        cout <<"Enter the subject line of the email: ";
        getline(cin, email_subject);
        
        cout <<"Enter the body of the email. Please Enter on an empty line to finish. ";
        getline(cin, email_body);
    
        spamScore = spamRule1(email_subject) + spamRule2(email_subject) + spamRule3(email_subject) + spamRule4(email_body) + spamRule5(email_body);
        
        if(spamScore > maxLegitimateScore)
        {
            cout <<"This email is classified as spam, because its spam score is " <<spamScore <<endl;
            count_spam++;
        }
        else
        {
            cout <<"This email is classified as legitimate, because its spam score is " <<spamScore <<endl;
            count_legitimate++;
        }
        
        
        
        //the following lines iterate behavior of each function with the respective argument/parameter:
        //***PERSONAL NOTE*** It only checks for the given input!! You need to pass all test cases!!!!
        
        ////////BEGIN//////
        
        //cerr << "The first word is: " <<getFirstWord(email_subject) <<endl;
        //cerr << "The last word is: " <<getLastWord(email_subject)<<endl;
        //cerr << email_subject <<endl;
        //cerr << email_body <<endl;
        
        //cerr <<"is every letter uppercase(uses email subject)?" <<isUppercase(email_subject) <<endl;
        /*
         cout <<"the text has been changed to all uppercase: \n";
         string test = makeUppercase(email_subject);
         cout << test <<endl;
         */
        //cerr << "has exclamation(uses email subject)?" <<hasMultipleExclamations(email_subject) <<endl;
        //cerr << "has three consecutive consonants (uses email subject)" << isGibberishWord(email_subject) <<endl;
        
        //cerr << "Spam Rule 1: "<<spamRule1(email_subject) <<endl;
        //cerr << "Spam Rule 2: "<<spamRule2(email_subject) <<endl;
        //cerr << "Spam Rule 3: " <<spamRule3(email_subject) <<endl;
        //cerr << "Spam Rule 4: " <<spamRule4(email_body) <<endl;
        //cerr << "Spam Rule 5: " <<spamRule5(email_body)<<endl;
        
        //cerr <<"The number of words = "<< checkNumberOfWords(email_subject) <<endl;
        //cerr <<"The number of uppercase words = " << checkNumberOfUpperWords(email_subject) <<endl;
        
        
        //////////END///

        
        cout <<"Would you like to classify another email? (y or n)? ";
        getline(cin, userResponse);
        //the program assumes that the user will either entier y or n.
        
        if(userResponse == "n")
        {
            cout << "Number of spam messages: " <<count_spam <<endl;
            cout << "Number of legitimate messages: " <<count_legitimate <<endl;
            break;
        }
        
        
        
        
    }
    while (userResponse == "y");
    
    //Look at course website for input testcases (1~28)
    
    /* Test case 28 */ assert(getFirstWord("") == "");
    /* Test case 29 */ assert(getFirstWord("    ") == "");
    /* Test case 30 */ assert(getFirstWord("@!-$%") == "");
    /* Test case 31 */ assert(getFirstWord("Hello") == "Hello");
    /* Test case 32 */ assert(getFirstWord("--Hello--") == "Hello");
    /* Test case 33 */ assert(getFirstWord(" Hello") == "Hello");
    /* Test case 34 */ assert(getFirstWord("Hello ") == "Hello");
    /* Test case 35 */ assert(getFirstWord("Hello there ") == "Hello");
    /* Test case 36 */ assert(getLastWord("") == "");
    /* Test case 37 */ assert(getLastWord("    ") == "");
    /* Test case 38 */ assert(getLastWord("@!-$%") == "");
    /* Test case 39 */ assert(getLastWord("Hello") == "Hello"); //PROBLEM with Attempt 1
    /* Test case 40 */ assert(getLastWord("--Hello--") == "Hello");
    /* Test case 41 */ assert(getLastWord(" Hello") == "Hello");
    /* Test case 42 */ assert(getLastWord("Hello ") == "Hello"); //PROBLEM with Attempt 1
    /* Test case 43 */ assert(getLastWord(" Hello there") == "there");
    /* Test case 44 */ string s1 = ""; assert(extractWord(s1) == ""  &&  s1 == "");
    /* Test case 45 */ string s2 = "    "; assert(extractWord(s2) == ""  &&  s2 == "");
    /* Test case 46 */ string s3 = "@!-$%"; assert(extractWord(s3) == ""  &&  s3 == "");
    /* Test case 47 */ string s4 = "Hello"; assert(extractWord(s4) == "Hello"  &&  s4 == "");
    /* Test case 48 */ string s5 = "--Hello--!!"; assert(extractWord(s5) == "Hello"  &&  s5 == "--!!");
    /* Test case 49 */ string s6 = " Hello"; assert(extractWord(s6) == "Hello"  &&  s6 == "");
    /* Test case 50 */ string s7 = "Hello "; assert(extractWord(s7) == "Hello"  &&  s7 == " ");
    /* Test case 51 */ string s8 = "Hello there, everyone!"; assert(extractWord(s8) == "Hello"  && s8 == " there, everyone!");
    /* Test case 52 */ assert(isUppercase(""));
    /* Test case 53 */ assert(isUppercase(" @!-$%"));
    /* Test case 54 */ assert(isUppercase("HELLO"));
    /* Test case 55 */ assert(isUppercase("HELLO THERE, EVERYONE!"));
    /* Test case 56 */ assert( ! isUppercase("HELLO THERE, eVERYONE!"));
    /* Test case 57 */ assert( ! isUppercase("hello"));
    /* Test case 58 */ assert(makeUppercase("") == "");
    /* Test case 59 */ assert(makeUppercase(" @!-$%") == " @!-$%");
    /* Test case 60 */ assert(makeUppercase("HELLO") == "HELLO");
    /* Test case 61 */ assert(makeUppercase("Hello there, everyone!") == "HELLO THERE, EVERYONE!");
    /* Test case 62 */ assert(makeUppercase("hello") == "HELLO");
    /* Test case 63 */ assert( ! hasMultipleExclamations(""));
    /* Test case 64 */ assert( ! hasMultipleExclamations("!!"));
    /* Test case 65 */ assert(hasMultipleExclamations("!!!"));
    /* Test case 66 */ assert(hasMultipleExclamations("!!!!"));
    /* Test case 67 */ assert( ! hasMultipleExclamations("!!x!!x!!x!!"));
    /* Test case 68 */ assert( ! hasMultipleExclamations("!! !! !! !!"));
    /* Test case 69 */ assert(hasMultipleExclamations("hello!!!!there"));
    /* Test case 70 */ assert( ! isGibberishWord(""));
    /* Test case 71 */ assert( ! isGibberishWord("axaxaxax"));
    /* Test case 72 */ assert( ! isGibberishWord("xxx"));
    /* Test case 73 */ assert(isGibberishWord("xxxx"));
    /* Test case 74 */ assert(isGibberishWord("axXxXbcQq"));
    /* Test case 75 */ assert( ! isGibberishWord("x x x x x"));
    

    
    return 0;
}

string getFirstWord(string text)//This function returns the first word in the string variable text. If text has no word, this function returns the empty string (i.e. "")
//if the text has no word, then it means it doesn't contain any alphabet letter...
{
    
    //Solution; refer to extractWord
    
    return extractWord(text);
    
}

string getLastWord(string text) //This function returns the last word in the string variable text. If text has no word, this function returns the empty string (i.e. "").
{
    
    //Attemp 1: Success?? Actually... error on test case 39 and 42.
    /*
    string lastWord;
    string emptyString ="";
    int word_lastPos = text.length()-1; //what if it's an empty string...
    
    for(; word_lastPos > 0 && !isalpha(text[word_lastPos]); word_lastPos--)
        ;
    
    if(word_lastPos <= 0) //if you've looked through the entire text backwards and couldn't find any word, return an empty strign (i.e. "")
        // <= because if the text is an empty string, text_lastPos becomes -1!
    {
        return "";
    }
    
    int word_firstPos = word_lastPos-1;
    for(;word_firstPos > 0 && isalpha(text[word_firstPos]) ;word_firstPos-- );
    
    lastWord = text.substr(word_firstPos+1, word_lastPos-word_firstPos); //try to visualize and understand why word_firstPos + 1 is used instead of word_firstPos
    return lastWord;
     */
    
    //SOLUTION//
    string lastWord = "";
    
    for (;;)
    {
        string word = extractWord(text);
        if (word == "")
            break;
        lastWord = word;  // This is the last word we've seen so far.
    }
    return lastWord;


}

string extractWord(string& text) //this function returns the first word in the string that text is a reference to. If that string has no words(e.g. "" Or "@# *#@$ ^ #"), this function returns the empty string
{
    // ATTEMPT 1; BUG!
    /*
     for(int i = 0; i < text.size();)
     {
     if(isalpha(text[i]))
     {
     word_firstPos = i;
     word_lastPos = word_firstPos;
     do
     {
     word_lastPos++;
     }
     while(isalpha(text[word_lastPos]));
     
     firstWord = text.substr(word_firstPos,word_lastPos);
     return firstWord;
     
     }
     else //if not an alphabet, skip to the next letter
     {
     i++;
     continue;
     }
     }
     */
    
    //ATTEMPT 2; INCOMPLETE CODE
    /* ATTEMPT 2;ABORTED.
     do
     {
     if(isalpha(text[word_firstPos]))
     {
     
     }
     }
     while(isalpha(text[i]));
     */
    
    
    //Attempt 3; After many revisions, SUCCESSFUL!!!!!
    string firstWord;
    string emptyString = ""; //not being used....
    int word_firstPos=0;
    
    
    //find the starting position of the first word.
    for(word_firstPos = 0;word_firstPos < text.length() && !isalpha(text[word_firstPos]); word_firstPos++) //it will skip all non-letters.
    {
        /*
        if(isalpha(text[word_firstPos]))
        {
            break;
        }
         */
        
    }
    
    if(word_firstPos == text.length()) // if you've looked through the entire text and couldn't find any word, then return an empty string (i.e. "")
    {
        text = "";
        return text;
    }
    //else

    
    int word_lastPos=0;
    for(word_lastPos = word_firstPos+1; isalpha(text[word_lastPos]) && word_lastPos < text.length(); word_lastPos++) //be aware of the word_lastPos++. The implementation is very implicit. Be cautious when you are tracking down
    {
    }
    
    firstWord = text.substr(word_firstPos, word_lastPos-word_firstPos); //substring length in the second parameter...
    text = text.substr(word_lastPos, text.size()-word_lastPos);
    return firstWord;
    
    //Solution
    /*
     // Find start of word by skipping past leading non-letters.
     
     int start;
     for (start = 0; start != text.size()  &&  !isalpha(text[start]); start++)
     ;
     if (start == text.size())  // No letters in text, so no word
     {
     text = "";
     return "";
     }
     
     // Find first position just after end of word
     
     int end;
     for (end = start+1; end != text.size()  &&  isalpha(text[end]); end++)
     ;
     
     // Remove first word from text and return it.
     
     string word = text.substr(start, end-start);
     text = text.substr(end, text.size()-end);
     return word;
     */
    
    
}

bool isUppercase(string text) //This function returns true iff every letter in the string text is uppercase. For a string with no letters, this means the function returns true. Non-letter characters in the string text, if any, have no effect on the result of this function.
{
    
    //Attempt 1: Success!!!
    if(text.length() ==0)
        return true;
    
    int i =0;
    while(i < text.length() )
    {
        if(isalpha(text[i])) //if the character of the i-th position is a letter, is it an uppercase? if it's an uppercase, check for then next letter. If not an uppercase, then every letter in the string is NOT uppercase.
        {
            if(isupper(text[i]))
            {
                i++;
                continue;
            }
            else
            {
                return false;
            }
        }
        else //if the i-th character is not a letter(e.g. symbol, whitespace, etc), then skip to the next letter.
        {
            i++;
            continue;
        }
    }
    return true; //TEMPORARY
}

string makeUppercase(string text) //This function returns a new string identical to the value of the string txt, except that each lowercase letter of text appears as its uppercase equivalent in the result string.
{
    //Attempt 1:
    string textUppercase = text;
 
    for(size_t i =0; i < textUppercase.size(); i++)
    {
        if(isalpha(textUppercase[i])) //if the character of the i-th position is a letter, is it an uppercase? if it's an uppercase, check for then next letter. If not an uppercase, then every letter in the string is NOT uppercase.
        {
            if(!(isupper(textUppercase[i])))
            {
                textUppercase[i] = toupper(text[i]);
                // tried toupper(textUppercase[i]); didn't workout...
            }
        }
        //else... if the i-th character is not a letter(e.g. symbol, whitespace, etc), then skip to the next letter.

    }
    
    return textUppercase;
}

bool hasMultipleExclamations(string text) //This function returns true iff the string text contains three consecutive exclamation marks.
{
    //Attempt 1: Success!
    int i =0;
    while ((i < text.length()) && (i+2 <text.length()))
    {
        if(!(text[i] == '!')) //skip to the next character if you can't find exclamation.
        {
            i++;
            continue;
        }
        else //if we find an exclamation, check and see if the next two characters are also '!'. If they are indeed '!', then the string text contains three consecutive exclamation marks (return true). If no
        {
                if((text[i] == text[i+1])&&(text[i]==text[i+2]))
                {
                    return true;
                }
                else
                {
                    i++;
                    continue;
                }

        }
    }
    
    return false;
    
}

bool isGibberishWord(string text) //This function returns true iff the string text contains more than three consecutive consonants. (i.e. 4 or more consecutive consonants!)
{
    //Attempt 1: semi-success.. needs to be simplified. and it doesn't check for more than three. it checks for three... also very messy....
    /*
    int i =0;
    string text_makeUppercase = makeUppercase(text); //turn string into ALL UPPERCASE.
    while ((i < text_makeUppercase.length()) && (i+2 <text_makeUppercase.length()))
    {
        if((isalpha(text_makeUppercase[i])&&isalpha(text_makeUppercase[i+1])&&isalpha(text_makeUppercase[i+2]))&&(!(text_makeUppercase[i]=='A'||text_makeUppercase[i]=='E' ||text_makeUppercase[i] =='I' || text_makeUppercase[i]=='O'||text_makeUppercase[i]=='U'))) //if they are consonant ALPHABET letters
        {
            if((!(text_makeUppercase[i+1]=='A'||text_makeUppercase[i+1]=='E' ||text_makeUppercase[i+1] =='I' || text_makeUppercase[i+1]=='O'||text_makeUppercase[i+1]=='U'))&&(!(text_makeUppercase[i+2]=='A'||text_makeUppercase[i+2]=='E' ||text_makeUppercase[i+2] =='I' || text_makeUppercase[i+2]=='O'||text_makeUppercase[i+2]=='U'))) //NOW CHECK IF THE NEXT 2 CHARACTERS ARE CONSONANTS
            {
                return true;
            }//check if the next letter is consonant
            else
            {
                i++;
                continue;
            }
        }
        else
        {
            i++;
        }
    }
    return false;
     */
    
    
    
    for (int i=0; i+3 < text.length(); i++) // check if the i+3 is within the bounds of the string.
    {
        if (checkConsonant(text[i])  &&  checkConsonant(text[i+1])  && checkConsonant(text[i+2])  &&  checkConsonant(text[i+3]))
        {
            return true;
        }
    }
    
    return false;
}

int spamRule1(string email_subject)
{
    string temp;
    double percentage = 0.9; //the max limit:  90% of the words are uppercase
    temp = getLastWord(email_subject); //gets a word.
    
    if(temp != "") //if the temp has at least a word
    {
        if(percentage < (static_cast<double>(checkNumberOfUpperWords(email_subject))/static_cast<double>(checkNumberOfWords(email_subject))))
        {
            return spamRule1_score;
        }
        else
        {
            return 0;
        }
    }
    else //if there is no word at all...
    {
        return 0;
    }
    
    return 1; //ERROR FlAG
}

int spamRule2(string email_subject)
{
    string temp = getLastWord(email_subject);
    if(isGibberishWord(temp))
    {
        return spamRule2_score;
    }
    //else...
    
    return 0;//Temporary
}

int spamRule3(string email_subject)
{
    if(hasMultipleExclamations(email_subject) == true) //== true...
        return spamRule3_score;
    else
        return 0;
}

int spamRule4(string email_body)
{
    string temp;
    double percentage = 0.5; //the max limit; only upto 50% of the words can be uppercase
    temp = getLastWord(email_body);
    
    if(temp!= "") //if the string temp has at least one word
    {
        if(percentage< static_cast<double>(checkNumberOfUpperWords(email_body))/static_cast<double>(checkNumberOfWords(email_body)) )
        {
            return spamRule4_score;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int spamRule5(string email_body)
{
    string email_body_copy = makeUppercase(email_body); //make ALL-UPPERCASE VERSION of email_body
    
    string spam_word[13] = {"BUY", "CHEAP", "CLICK", "DIPLOMA", "ENLARGE", "FREE", "LIMITED", "MONEY", "NOW","OFFER", "ONLY", "PILLS", "SEX"};
    string temp;
    int count = 0; //counts the number of matches
    do
    {
        temp = extractWord(email_body_copy);
        if(temp != "" ) //if the temp is indeed a word.. check and see if the temp matches with any item of the spam_word array
        {
            for(int i =0; i < 13; i++)
            {
                if(temp == spam_word[i])
                {
                    count++;
                }
            }
        }
        
    } while (temp != "" );
    
    return spamRule5_score * count;
}

bool checkConsonant(char ch)
{
    if (!isalpha(ch))
        return false;
    
    // A vowel is not a consonant
    
    ch = toupper(ch);               // Treat uppercase as lowercase
    const string vowels = "AEIOU";  // By the spec, these are the only vowels
    for (int k = 0; k != vowels.size(); k++)
    {
        if (ch == vowels[k])
            return false;
    }
    
    // A letter that's not a vowel is a consonant
    
    return true;
}

int checkNumberOfWords(string text)
{
    int count = 0;
    string temp = "";
    
    do
    {
        temp = extractWord(text);
        if(temp != "") //if the text contains word, the word is added to the counter
        {
            count++;
        }
        else //if the word doesn't have word anymore
        {
            break;
        }
    }
    while (text != "");
    
    return count;
    
    /*
    while(text != "")
    {
        extractWord(text);
        if(text != "")
        count++;
        else
        {
            return count;
        }
    }
     */
    
}

int checkNumberOfUpperWords(string text)
{
    int count = 0;
    string temp = "";
    
    do
    {
        temp = extractWord(text);
        if(temp != "") //if the text contains word and is uppercase, the word is added to the counter
        {
            if(isUppercase(temp))
            {
                count++;
            }
            else
            {
                continue;
            }
        }
        else //if the word doesn't have word anymore
        {
            break;
        }
    }
    while (text != "");
    
    return count;
}

/*Input and Output Specification
 
 The first line that your program must print out is exactly this (with one space after the colon):
 
 Enter the subject line of the email:
 
 Your program must then read the subject line the user types in. (It is not an error if the subject line is the empty string.) After that, your program must print out exactly this line:
 
 Enter the body of the email.  Press Enter on an empty line to finish.
 
 Your program must then read the message body lines the user types in. The message body consists of zero or more lines. After your program reads an empty line, which indicates the end of the message, it must print out exactly one of these two messages, depending on whether applying the spam rules classified the message as spam or not:
 
 This email is classified as spam, because its spam score is number.
 
 or
 
 This email is classified as legitimate, because its spam score is number.
 
 In these messages, number is to be replaced by the appropriate spam score, such as 115, or 0, or 5.
 
 After printing the classification message, your program must print exactly this (with one space after the question mark):
 
 Would you like to classify another email (y or n)?
 
 Your program must then read the line the user types in. If the user types only a lowercase y, the program must process another email, starting with the step where it prints the prompt for the subject line of the email.
 
 If instead, the user types only a lowercase n, the program must print an empty line, then print the following two lines, then terminate:
 
 
 Number of spam messages: number
 Number of legitimate messages: number
 
 In these messages, the first number is the number of messages that were classified as spam, and the second is the number that were classified as legitimate.
 
 If the user types anything other than a single lowercase y or n in response to the question, the program must print out exactly the line:
 
 Please enter y or n.
 
 and repeat the prompt about classifying another email. It must repeatedly prompt the user until y or n is selected.
*/