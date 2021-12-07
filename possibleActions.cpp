#include "Interface.h"
using namespace std;


//Generate Possible moves from the state

/*
C = NOT POSSBILE TO MOVE
U = MOVE TILE UP
D = MOVE TILE DOWN
R = MOVE TILE RIGHT
L = MOVE TILE LEFT
*/
// ACTION =[U, D, L, R]

void EightPuzzle::possibleActions(char actions[4], int blank[2])
{
    switch (blank[0])
    {
    case 0:
    {
        actions[0] = 'C';
        actions[1] = 'D';
        break;
    }
    case 1:
    {
        actions[0] = 'U';
        actions[1] = 'D';
        break;
    }
    case 2:
    {
        actions[0] = 'U';
        actions[1] = 'C';
        break;
    }
    }
    switch (blank[1])
    {
    case 0:
    {
        actions[2] = 'C';
        actions[3] = 'R';
        break;
    }
    case 1:
    {
        actions[2] = 'L';
        actions[3] = 'R';
        break;
    }
    case 2:
    {
        actions[2] = 'L';
        actions[3] = 'C';
        break;
    }
    }
}