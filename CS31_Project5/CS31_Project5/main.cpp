// Project 5

#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream> //to load files...
#include <cstring> //for cstrings...
#include <cctype> //for islower
#include <cstdlib> //for rand, srand(), RAND_MAX
#include <ctime> //for time

using namespace std;

const int MIN_WORD_LENGTH = 4;
const int MAX_WORD_LENGTH= 6;
const int MAXTRIALLEN = 100;
const int MAXWORDS = 9000; //max number of words stored in

int loadWords(char words[][MAX_WORD_LENGTH+1], int maxWords);
int manageOneRound(char words[][MAX_WORD_LENGTH+1], int num, int wordnum); //num = the number of words in the array. wordnum = the chosen mystery word
int checkWord(char words[][MAX_WORD_LENGTH+1], int num, char user_word[100]);
//int numberInCommon(char words[][MAX_WORD_LENGTH+1], int wordnum, char user_word[100]); //the chosen mystery word
int numberOfMatchingLetters(const char word1[], const char word2[]);

int main()
{
    srand(time(0));
    
    char list_of_mystery_words[MAXWORDS][MAX_WORD_LENGTH+1]; //e.g. s[3] can be used to refere to the string in position 3.
    //s[3][5] can be used to refer to the letter in position 5 of the string in position 3.
    
    int number_of_words_loaded = loadWords(list_of_mystery_words, MAXWORDS);
    
    //the following lines check whether the words have been loaded successfully into the array: list_of_words (first 10 ONLY)
    /*
    for(int i = 0; i < 100; i++)
    {
        cerr <<"The " <<i+1 << "th word is " << list_of_mystery_words[i] <<endl;
    }
    */
    
    if(number_of_words_loaded < 1) //if no words were loaded, quit the program
    {
        cout <<"No words were loaded, so I can't play the game" <<endl;
        return 0;
    }
    //else.... continue with the program
    
    int number_of_rounds = 0;
    cout << "How many rounds do you want to play? ";
    cin >> number_of_rounds;
    cin.clear();
    cin.ignore(1000, '\n');
    
    double average_attempts = 0;
    double accumulated_score = 0;
    int min_attempt =0;
    int max_attempt = 0;
    
    for(int rounds_played = 0; rounds_played < number_of_rounds; rounds_played++)
    {
        int random_number = rand()%number_of_words_loaded; //I don't know if I'm doing this right...
        
        //cerr << "Random Number: "<<random_number <<endl; //checks for the random number.
        
        cout <<"Round " << rounds_played+1 <<endl;
        cerr <<"This mystery word is " <<strlen(list_of_mystery_words[random_number]) << " letters long" <<endl;
        int score = manageOneRound(list_of_mystery_words, number_of_words_loaded, random_number);
        
        if(rounds_played ==0)
        {
            average_attempts = score;
            accumulated_score = score;
            min_attempt = score;
            max_attempt = score;
        }
        else
        {
            accumulated_score += score;
            average_attempts = accumulated_score/(rounds_played+1);
            if(score < min_attempt)
                min_attempt = score;
            if(score > max_attempt)
                max_attempt = score;
        }
        cout <<"You got it in " <<score <<" tries" <<endl;
        cout <<"Average: " <<average_attempts <<", " <<"minimum: " <<min_attempt << ", maximum: " <<max_attempt <<endl;
    }
    
    return 0;
    
}


int loadWords(char words[][MAX_WORD_LENGTH+1], int maxWords)
{
    const char file_name[]= "/Users/wheredidjupark/Documents/CS/CS31/CS_Project5/CS31_Project5/text.txt";
    ifstream file_input(file_name); //file_input.open(file_name, ios::in); works fine as well after declaring the ifstream variable
    
    if(!file_input) //if the file is opened successfully
    {
        cout <<"File failed to load successfully" <<endl;
        return -1; //to show error
    }
    
    //after the file is loaded successfully, save the words into each element of the array...
    //things to check for:
 
    
    // 1) the word is 4~6 letters.
    // 2) the word is all lowercase
    // 3) we have to return the number of words that are stored by the function
    
    int maxLineLength = 100; //maximum line that can be read from getline...
    //Q: so what happens if the actual line outnumbers the maxLineLength? cannot be read because you reached the end of file.
    char line[maxLineLength];
    
    int number_of_words = 0;
    
    while (file_input.getline(line, maxLineLength)) //saves the line of file_input into cstring line
    {
        //cerr <<line <<endl; //to check
        
        //the following lines check whether each letter is lowercase alphabet. if it's not, stop reading and make the last-checked character into zerobyte
        int k = 0;
        while(islower(line[k]))
        {
            k++;
        }
        //now if we found that the last-checked character is not lowercase alphabet, change that to null character '\0'
        line[k] = '\0';

        //now check for the boundary of the word length (i.e. 4~6 letters long)
        //copy the line into the list_of_mystery_words if it's
        //1) 4~6 letters long
        //2) the last character is zerobyte
        //3) the letters are lowercase.
        if(line[k] == '\0' && k <= MAX_WORD_LENGTH && k >= MIN_WORD_LENGTH) //kth element starts from 0...
        {
            strcpy(words[number_of_words], line);
            //cerr <<words[number_of_words] <<endl;
            number_of_words++;
        }
    }
    
    return number_of_words;
}



int manageOneRound(char words[][MAX_WORD_LENGTH+1], int num, int wordnum)
//your progrma must call this function to play each round of the game.
//returns the score for that round
//num = the number of words in the array. wordnum = the chosen mystery word
{
    int score = 0;
    int location_trialword = 0;
    char user_input[100]; //the project spec assumes that any line entered in response to the trial word prompt will contain fewer than 100 characters, not counting the newline at the end. 99 characters + newline.
    cerr << "The mystery word is: " <<words[wordnum] << endl;

    
    //enters the user input for trial word....
    do
    {
        cout <<"Trial word: ";
        cin >> user_input; //gets only word at a time!
        //cerr << "User entered the following trial word: "<<user_input <<endl;
        location_trialword = checkWord(words, num, user_input);
         if(location_trialword == -1) //if the word is not in the list
         {
             score++;
         }
         else //if the word is in the list, check
         {
             score++;
             if(strcmp(words[wordnum], user_input) == 0) //if it's a match.... then it doesn't need to indicate the number of letters contained in the mystery word
             {
                 break;
             }
             else
             {
                 int numberOfCommonLetters = numberOfMatchingLetters(words[wordnum], user_input);//originally.... numberInCommon(words, wordnum, user_input);
                 cout << numberOfCommonLetters << endl;
             }
         }
    }
    while (strcmp(words[wordnum], user_input) != 0);
    
    return score;
}

int checkWord(char words[][MAX_WORD_LENGTH+1], int num, char user_word[100]) //identifies the position of the user_word in the array words[]
{
    int position = 0;
    for(position = 0; position < num; position++)
    {
        if(strcmp(user_word, words[position]) == 0)
        {
            break;
        }
    }
    
    if(position == num)
    {
        cout <<"I don't know that word\n";
        return -1; //to indicate the word is not in the file
    }
    
    return position;
    
}

//Attempt 1... Too complicated and messy and doesn't omit letters that are already matched....
//int numberInCommon(char words[][MAX_WORD_LENGTH+1], int wordnum, char user_word[100])
/*
int numberOfMatchingLetters(const char word1[], const char word2[]) //word1 = mystery word. word2 = user_input
{
    char word1copy[strlen(word1)];
    strcpy(word1copy, word1);
    
    int count = 0;
    int number[MAX_WORD_LENGTH]; //stores letter positions that needed to be omitted from checking
    const char NOMATCHCHAR = '!';
    
    for(int i =0; i < strlen(word2);i++) //replaced maximu length
    {
        for(int j =0; j < strlen(word1); j++)
        {
            if(word2[i] == word1[j]) //if there's match between trial word's ith letter to mystery word's jth letter.
            {
 
                for(int numberCheck = 0; numberCheck < i; numberCheck++)
                {
                    if(number[numberCheck] == j)
                    {
                        j++;
                        break;
                    }
                    else
                    {
                        number[i] = j;
                        count++;
                    }
                }
                
                number[i] = j;
                count++;
                break;

            }
        }
    }
    return count; //temporary
}
*/
 
int numberOfMatchingLetters(const char word1[], const char word2[]) //word1 = mystery word. word2 = user_input
{
    char word1copy[strlen(word1)];
    strcpy(word1copy, word1);
    //cerr <<word1copy <<endl;
    
    int count = 0;
    const char NOMATCHCHAR = '!';
    
    for(int i =0; i < strlen(word2);i++) //word2[i] != '\0' also works.
    {
        for(int j =0; j < strlen(word1copy); j++) // word1copy[j] != '\0' also works
        {
            if(word2[i] == word1copy[j]) //if there's match between trial word's ith letter to mystery word's jth letter.
            {
                count++;
                word1copy[j] = NOMATCHCHAR;
                break;
            }
        }
    }
    return count; //temporary
}
//For testing purposes....
/*
 int loadWords(char words[][MAX_WORD_LENGTH+1], int maxWords)
 {
 strcpy(words[0], "eager");
 strcpy(words[1], "goose");
 return 2;
 }
 */

/*
 int loadWords(char words[][MAXWORDLEN+1], int maxWords)
 {   //Regarding words[][]
 //char list_of_words[MAXWORDS][MAXWORDLEN+1]; e.g. s[3] can be used to refer to the string in position 3.
 //s[3][5] can be used to refer to the letter in position 5 of the string in position 3.
 //locate the directory of the file
 
 const char filename[] = "/Users/wheredidjupark/Documents/CS/CS31_Project5/CS31_Project5/text.txt";
 
 //load the file into the ifstream by inserting its directory (i.e. input file stream)
 ifstream wordfile(filename);
 if (! wordfile)
 {
 cout << "Cannot open " << filename << "!" << endl;
 return -1; //to indicate there is an error
 }
 
 //cstring that stores 10000 characters
 //This will store a single word. => one of the elements of the words[].
 const int MAXFILELINELEN = 10000;
 char line[MAXFILELINELEN];
 
 //
 int numWords = 0;
 
 while (wordfile.getline(line, MAXFILELINELEN)) //successfully extract words from
 {
 if (numWords == maxWords)
 {
 cout << "Using only the first " << numWords << " words from "
 << filename << endl;
 break;
 }
 
 // For a word, store only lowercase letters.
 // Otherwise, skip to the next word.
 int k;
 for (k = 0; islower(line[k]); k++)
 ;
 
 // The following two lines fix things for non-Windows users (didn't learn this so now I know)
 if (line[k] == '\r')
 {
 line[k] = '\0';
 }
 
 //once you are
 if (line[k] == '\0'  &&  k >= MINWORDLEN  &&  k <= MAXWORDLEN)
 {
 strcpy(words[numWords], line);
 numWords++;
 }
 }
 return numWords;
 }
*/

/*
 int loadWords(char words[][MAXWORDLEN+1], int maxWords)
 {
 const char filename[] = "/Users/wheredidjupark/Documents/CS/CS31_Project5/CS31_Project5/text.txt";
 ifstream input;
 input.open(filename, ios::in);
 
 if(!input)
 {
 cout <<"Cannot open" <<endl;
 return -1;
 }
 
 size_t maxlength_line = 10000;
 char line[maxlength_line];
 
 int numberOfWords = 0;
 while(input.getline(line, maxlength_line))
 {
 int i =0;
 for(i =0;islower(line[i]) ;i++)
 {
 }
 
 
 strcpy(words[numberOfWords], line);
 numberOfWords++;
 }
 
 
 return numberOfWords;
 }
 
 */