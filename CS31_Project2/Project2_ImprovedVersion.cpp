#include <iostream>

using namespace std;

const int user_minutes_BASE = 400;
const int user_text_BASE = 250;
const double user_bill_BASE = 45.00;
const double user_minutes_over_cost = 0.40; //$0.40/minute for any minutes over 400 basic minutes.
const double user_text_nonsummerover_cost = 0.02; // $0.02/text for all texts between 251-500 during non-Summer (i.e. October ~ May)
const double user_text_summerover_cost = 0.01; // $0.01/text for all texts between 251-500 during Summer (i.e. June ~ September)
const double user_text_500over_cost = 0.11; // $0.11/text for all texts after 500 texts
int main()
{
    int user_minutes = 0;
    int user_text = 0;
    string user_name = "";
    int user_month = 0;
    
    cout <<"Minutes used: ";
    cin >> user_minutes;
    cin.ignore(1000,'\n');
    
    if(user_minutes < 0)
    {
        cout << "The number of minutes used must be nonnegative.\n";
        return 1; //to indicate something is wrong
    }
    
    cout <<"Text messages: ";
    cin >> user_text;
    cin.clear();
    cin.ignore(1000,'\n');
    
    if(user_text< 0)
    {
        cout << "The number of text messages must be nonnegative.\n";
        return 1; //to indicate something is wrong
    }
    
    cout <<"Customer name: ";
    getline(cin, user_name);
    
    if(user_name == "")
    {
        cout << "You must enter a customer name.\n";
        return 1; //to indicate something is wrong
    }
    
    cout <<"Month number (1=Jan, 2=Feb, etc.): ";
    cin >> user_month;
    cin.ignore(1000,'\n');
    
    if ( !((user_month <=12) && (user_month >=1)))
    {
        cout <<"The month number must be in the range 1 through 12.\n";
        return 1; //to indicate something is wrong with our program
    }

    double bill = 0;
    
    //////////////////////////////////
    //////////////////////////////////
    double user_bill_minutes_over = 0;
    int user_minutes_over = 0;
    if(user_minutes > user_minutes_BASE)
    {
        user_minutes_over = user_minutes - user_minutes_BASE;
    }
    
    user_bill_minutes_over = static_cast<double>(user_minutes_over) *user_minutes_over_cost;
    
    
    //////////////TEXTING///////////////
    //////////////TEXTING///////////////
    int user_text_over = 0;
    double user_bill_text_over = 0;
    
    if(user_text > user_text_BASE)
    {
        user_text_over = user_text - user_text_BASE;
        
        if((user_text_over<=250)&&(user_text_over>0))
        {
            if(((user_month >=1)&&(user_month <= 5))||((user_month >=10)&&(user_month <=12))) //October thru May
            {
                user_bill_text_over = user_text_over * user_text_nonsummerover_cost; //changed 0.02 with global variable for better coding style
            }
            else //June thru September
            {
                user_bill_text_over = user_text_over * user_text_summerover_cost; //changed 0.02 with global variable for better coding style
            }
        }
        else if (user_text_over > 250) //if over 500 messages
        {
            if(((user_month >=1)&&(user_month <= 5))||((user_month >=10)&&(user_month <=12))) //October thru May
            {
                user_bill_text_over = 250 * user_text_nonsummerover_cost; //changed 0.02 with global variable for better coding style
            }
            }
            else //June thru September
            {
                user_bill_text_over = 250 * user_text_summerover_cost; //changed 0.02 with global variable for better coding style 
            }
            
            user_bill_text_over = user_bill_text_over + (static_cast<double>(user_text-500)*user_text_500over_cost);
        }
    }
    
    
    bill = user_bill_BASE + user_bill_minutes_over + user_bill_text_over;
    //How do you print something out two decimal places??
    
    
    cout << "The bill for " <<user_name <<" is $" << bill;
    return 0;
}



//some comments
//needs to improve on programming habits!!!! compare it with your solution and discover weaknesses in ways I code.
