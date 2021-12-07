#include "Interface.h"
using namespace std;

//Adds to frontier set and arranges the frontier in descending order
void EightPuzzle::AddtoFrontierSet(node newlyCreated, std::vector<node> &FrontierSet)
{
    //add the new node to the frontier set
    FrontierSet.push_back(newlyCreated);

    EightPuzzle::node temp;


    for (int i = 0; i < FrontierSet.size() - 1; i++)
    {
        for (int j = i + 1; j < FrontierSet.size(); j++)
        {

            //arranging the states in descending order
            if (FrontierSet[i].totalCost < FrontierSet[j].totalCost)
            {
                temp = FrontierSet[i];
                FrontierSet[i] = FrontierSet[j];
                FrontierSet[j] = temp;
            }
        }
    }

}
