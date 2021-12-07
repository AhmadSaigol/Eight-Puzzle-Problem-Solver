#include "Interface.h"
using namespace std;

// checks whther the node is in set or not
// return false if it is not
// if the node is in the set,
//return true if total cost of new node is greater than the one in the set
//otherwise return false
bool EightPuzzle::CheckInSet(node &newlyCreated, std::vector<node> &Set)
{

    bool equal=true;
    int index=-1;

    for (int i = 0; i < Set.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                //if any single element does not match, go to the next state in the set
                if (newlyCreated.state[j][k] != Set[i].state[j][k])
                {
                    equal= false; 
                    break;
                }

            }
            if (!equal){
                break;
            }
        }
        if (equal){

            index=i; //store index of the matching state in the vector
            break;
        }
        equal=true;
    }
    
    //no equal state in the state
    if (index==-1){
        return false;
    }

    //compare costs of both equal states.
    if (newlyCreated.totalCost > Set[index].totalCost){
        return true;
    }
    else{
        return false;
    }

}