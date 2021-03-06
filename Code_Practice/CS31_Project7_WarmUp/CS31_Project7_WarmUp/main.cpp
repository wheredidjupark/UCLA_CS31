/*
 Project 7 Warmup
 Virtual Pets
 
 To help ease you into the world of classes you'll need for Project 7, we've designed these warmup exercises. (You will not turn in any of the code you write because of these warmups.)
 
 Did you have a Tamagotchi or Gigapet when you were young? Here's your chance to implement a very simple one. This program compiles and runs, but does not produce the output it should, because the implementations of the member functions are incomplete or incorrect. Fix them so that the program produces the desired output.
 
 The places to make a change are denoted by TODO comments. You must make no changes whatsoever to the reportStatus, careFor, or mainfunctions.
 
 After you get everything working, try the each of the following experiments to test your understanding of some of concepts:
 
 1. Try declaring the health member function private instead of public, and make sure you understand the resulting compilation error. 
 Answer: after you change the health member function to private, non-member functions cannot directly the health member function. Therefore, compilation error due to breaking the rule.
 
 2. Comment out the entire implementation of Pet::eat, all the way from the void Pet::eat(int amt) to its close curly brace. Make sure you understand the resulting build error.
 
 3. In main, try replacing myPets[0] = new Pet("Fluffy", 2); with myPets[0] = new Pet("Fluffy"); or myPets[0] = new Pet;, and make sure you understand the resulting compilation error.
 Answer: constructor is not set for one parameter.... 
 
 4. Try removing the const from the implementation, but not the declaration of the alive member function. Notice the compilation error.
 Answer: herp derp. the implementation has to match the declaration. the const in the end makes sure it doesn't change anything.
 
 5. Try removing the const from both the declaration and the implementation of the alive member function. Make sure you understand why the use of that function doesn't compile in reportStatus, but does compile in careFor and main.
 
 
 The desired output - Here is the output we would like the program to produce:
 
 ======= Day 1
 You fed Fluffy
 Fluffy has health level 2
 You fed Frisky
 Frisky has health level 4
 ======= Day 2
 You fed Fluffy
 Fluffy has health level 2
 You fed Frisky
 Frisky has health level 4
 ======= Day 3
 You forgot to feed Fluffy
 Fluffy has health level 1
 You forgot to feed Frisky
 Frisky has health level 3
 ======= Day 4
 You fed Fluffy
 Fluffy has health level 1
 You fed Frisky
 Frisky has health level 3
 ======= Day 5
 You fed Fluffy
 Fluffy has health level 1
 You fed Frisky
 Frisky has health level 3
 ======= Day 6
 You forgot to feed Fluffy
 Fluffy has health level 0, so has died
 You forgot to feed Frisky
 Frisky has health level 2
 ======= Day 7
 Fluffy is still dead
 You fed Frisky
 Frisky has health level 2
 ======= Day 8
 Fluffy is still dead
 You fed Frisky
 Frisky has health level 2
 ======= Day 9
 Fluffy is still dead
 You forgot to feed Frisky
 Frisky has health level 1
 =======
 Animal Control has come to rescue Frisky
 
*/

//Skeleton Code
/*
#include <iostream>
#include <string>

using namespace std;

class Pet
{
public:
    Pet(string nm, int initialHealth);
    void eat(int amt);
    void play();
    string name() const;
    int health() const;
    bool alive() const;
private:
    string m_name;
    int m_health;
};

// Initialize the state of the pet
Pet::Pet(string nm, int initialHealth)
{
    m_name = nm;
    m_health = initialHealth;
}

void Pet::eat(int amt)
{
    // TODO: Increase the pet's health by the amount
}

void Pet::play()
{
    // TODO: Decrease pet's health by 1 for the energy consumed
}

string Pet::name() const
{
    // TODO: Return the pet's name.  Delete the following line and
    // replace it with the correct code.
    return ""; // This implementation compiles, but is incorrect
}

int Pet::health() const
{
    // TODO: Return the pet's current health level.  Delete the
    // following line and replace it with the correct code.
    return 99; // This implementation compiles, but is incorrect
}

bool Pet::alive() const
{
    // TODO: Return whether pet is alive.  (A pet is alive if
    // its health is greater than zero.)  Delete the following
    // line and replace it with the correct code.
    return true; // This implementation compiles, but is incorrect
}

/////////
// Do not change any code below this point
/////////

void reportStatus(const Pet* p)
{
    cout << p->name() << " has health level " << p->health();
    if ( ! p->alive())
        cout << ", so has died";
    cout << endl;
}

void careFor(Pet* p, int d)
{
    if ( ! p->alive())
    {
        cout << p->name() << " is still dead" << endl;
        return;
    }
    
    // Every third day, you forget to feed your pet
    if (d % 3 == 0)
        cout << "You forgot to feed " << p->name() << endl;
    else
    {
        p->eat(1);  // Feed the pet one unit of food
        cout << "You fed " << p->name() << endl;
    }
    
    p->play();
    reportStatus(p);
}

int main()
{
    Pet* myPets[2];
    myPets[0] = new Pet("Fluffy", 2);
    myPets[1] = new Pet("Frisky", 4);
    for (int day = 1; day <= 9; day++)
    {
        cout << "======= Day " << day << endl;
        for (int k = 0; k < 2; k++)
            careFor(myPets[k], day);
    }
    cout << "=======" << endl;
    for (int k = 0; k < 2; k++)
    {
        if (myPets[k]->alive())
            cout << "Animal Control has come to rescue "
            << myPets[k]->name() << endl;
        delete myPets[k];
    }
}

*/

#include <iostream>
#include <string>

using namespace std;

class Pet
{
public:
    Pet(string nm, int initialHealth);
    void eat(int amt);
    void play();
    string name() const;
    int health() const;
    bool alive() const;
private:
    string m_name;
    int m_health;
};

// Initialize the state of the pet
Pet::Pet(string nm, int initialHealth)
{
    m_name = nm;
    m_health = initialHealth;
}

void Pet::eat(int amt)
{
    // TODO: Increase the pet's health by the amount
    m_health += amt;
}

void Pet::play()
{
    // TODO: Decrease pet's health by 1 for the energy consumed
    m_health--;
}

string Pet::name() const
{
    // TODO: Return the pet's name.  Delete the following line and
    // replace it with the correct code.
    return m_name;
}

int Pet::health() const
{
    // TODO: Return the pet's current health level.  Delete the
    // following line and replace it with the correct code.
    return m_health; // This implementation compiles, but is incorrect
}

bool Pet::alive() const
{
    // TODO: Return whether pet is alive.  (A pet is alive if
    // its health is greater than zero.)  Delete the following
    // line and replace it with the correct code.
    if(m_health >= 1)
        return true;
    else
        return false;

}

/////////
// Do not change any code below this point
/////////

void reportStatus(const Pet* p)
{
    cout << p->name() << " has health level " << p->health();
    if ( ! p->alive())
        cout << ", so has died";
    cout << endl;
}

void careFor(Pet* p, int d)
{
    if ( ! p->alive())
    {
        cout << p->name() << " is still dead" << endl;
        return;
    }
    
    // Every third day, you forget to feed your pet
    if (d % 3 == 0)
        cout << "You forgot to feed " << p->name() << endl;
    else
    {
        p->eat(1);  // Feed the pet one unit of food
        cout << "You fed " << p->name() << endl;
    }
    
    p->play();
    reportStatus(p);
}

int main()
{
    Pet* myPets[2];
    myPets[0] = new Pet("Fluffy", 2);
    myPets[1] = new Pet("Frisky", 4);
    for (int day = 1; day <= 9; day++)
    {
        cout << "======= Day " << day << endl;
        for (int k = 0; k < 2; k++)
            careFor(myPets[k], day);
    }
    cout << "=======" << endl;
    for (int k = 0; k < 2; k++)
    {
        if (myPets[k]->alive())
            cout << "Animal Control has come to rescue "
            << myPets[k]->name() << endl;
        delete myPets[k];
    }
}
