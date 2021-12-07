#include "Interface.h"
#include<iostream>
#include <cmath>
using namespace std;


//Generate Nodes
void EightPuzzle::node::GenerateNode(node &old, char action, bool &heu)
{
    parent = &old;
    act = action;
    Successor(old.state, old.emptyTile); //Generate Successor State
    
    //Select approriate heuristic
    if (heu)
    {
        heuristic = ManhattanDistance();
    }
    else
    {
        heuristic = MisplacedTiles();
    }

    numOfmoves = (old.numOfmoves) + 1;
    totalCost = numOfmoves + heuristic;
}


//Generate Successor' state
void EightPuzzle::node::Successor(char st[3][3], int blank[2])
{
    char swapElement;

    //select which action to perform
    switch (act)
    {
    case 'L':
    {
        emptyTile[0] = blank[0];
        emptyTile[1] = blank[1] - 1;
        break;
    }
    case 'R':
    {
        emptyTile[0] = blank[0];
        emptyTile[1] = blank[1] + 1;
        break;
    }
    case 'U':
    {
        emptyTile[0] = blank[0] - 1;
        emptyTile[1] = blank[1];
        break;
    }
    case 'D':
    {
        emptyTile[0] = blank[0] + 1;
        emptyTile[1] = blank[1];
        break;
    }
    default:
    {
        cout << "Error" << endl;
        exit(0);
    }
    }

    swapElement = st[emptyTile[0]][emptyTile[1]];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == emptyTile[0] && j == emptyTile[1])
            {
                state[i][j] = '_';
            }
            else if (i == blank[0] && j == blank[1])
            {
                state[i][j] = swapElement;
            }
            else
            {
                state[i][j] = st[i][j];
            }
        }
    }

}


//Heuristic function = Number of Misplaced Tiles
int EightPuzzle::node::MisplacedTiles()
{
    int noOfmisplacedTiles = 0;

    //ASCII Value of 1 and onwards
    //starting from one value less to compensate '_' iteration. 
    int goalvalue = 48; 

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 0 && j == 0)
            {
                if (state[i][j] != '_')
                {
                    noOfmisplacedTiles++;
                }
            }
            else
            {
                if (state[i][j] != goalvalue)
                {
                    noOfmisplacedTiles++;
                }
            }
            goalvalue++;
        }
    }

    return noOfmisplacedTiles;
}

//Heuristic Function = Manhattan Distance
int EightPuzzle::node::ManhattanDistance()
{

    int distance = 0;
    int index[2];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tempDistance(state[i][j], index);
            distance = distance + (abs(index[0] - i) + abs(index[1] - j));
        }
    }
    return distance;
}

//temporary function for calculating manhattan distance
//compare element with goal state and return corresponding indexes of goal state
void EightPuzzle::node::tempDistance(char &element, int index[2])
{
    bool check = false;
    
    //ASCII Value of 1 and onwards
    //starting from one value less to compensate '_' iteration. 
    int goalvalue = 48;

    
    for (int k = 0; k < 3; k++)
    {
        for (int l = 0; l < 3; l++)
        {
            if (k == 0 && l == 0)
            {
                if (element == '_')
                {
                    index[0] = k;
                    index[1] = l;
                    check = true;
                    break;
                }
            }
            else
            {
                if (element == goalvalue)
                {
                    index[0] = k;
                    index[1] = l;
                    check = true;
                    break;
                }
            }
            goalvalue++;
        }
        if (check)
        {
            break;
        }
    }
}
