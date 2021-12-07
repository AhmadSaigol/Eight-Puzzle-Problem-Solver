#include "Interface.h"
using namespace std;


//Check whether input state is equal to goal state
bool EightPuzzle::CheckGoal(char input[3][3])
{
    int goalvalue = 48;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 0 && j == 0)
            {
                if (input[i][j] != '_')
                {
                    return false;
                }
            }
            else
            {
                if (input[i][j] != goalvalue)
                {
                    return false;
                }
            }
            goalvalue++;
        }
    }

    return true;
}