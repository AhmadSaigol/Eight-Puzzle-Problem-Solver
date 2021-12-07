#include "Interface.h"
#include <iostream>
#include <string>
using namespace std;


//Takes Initial Configuration from the User.
//Takes the heuristic to be used.
void EightPuzzle::UserInput(char input[3][3], int blank[2], bool &h)
{

    string in;
    int element;

    //Instructions on how to input data
    cout << "Welcome to 8-puzzle problem solver using A* Search" << endl
         << endl;

    cout << "Please Select the Heuristic Function ( h(n) ):" << endl;
    cout << "Enter 0 for Number of Misplaced Tiles" << endl;
    cout << "Enter 1 for Manhattan Distance" << endl;
    cout << "h(n): ";
    cin >> h;
    cin.ignore(256, '\n'); // remaining input characters up to the next newline character               // are ignored
    
    cout<<endl;
    cout << "Enter each row one by one with each number separated by single space." << endl;
    cout << "Use underscore (_) for denoting empty title" << endl;
    cout << endl;
    cout << "For example:" << endl
         << endl;
    cout << "Enter Row Number 1: 1 8 2" << endl;
    cout << "Enter Row Number 2: _ 4 3" << endl;
    cout << "Enter Row Number 3: 7 6 5" << endl
         << endl;
    ;

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter Row Number " << i + 1 << ":";
        getline(cin, in);

        element = 0;

        for (int k = 0; k < in.size(); k++)
        {
            if (in[k] == ' ')
            {
                continue;
            }
            else
            {
                //error checking
                if (element == 3)
                {
                    cout << "Too many elements in one row." << endl;
                    exit(0);
                }
                input[i][element] = in[k];
                if (in[k] == '_')
                {
                    blank[0] = i;
                    blank[1] = element;
                }
                element++;
            }
        }
        //error checking
        if (element < 3)
        {
            cout << "Not enough elements in one row." << endl;
            exit(0);
        }
    }
}


//prints the state
void EightPuzzle::printState(char state[3][3])
{
    cout <<endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << state[i][j];
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;

}