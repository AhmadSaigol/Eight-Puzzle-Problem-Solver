#include <iostream>
#include "Interface.h"
#include <vector>
using namespace std;

int main()
{
    bool check;
    char actions[4];
    
    vector <EightPuzzle::node> ExploredSet;
    vector <EightPuzzle::node> FrontierSet;
    
    EightPuzzle::node newNode;

    bool HeuristicSelector;

    // Setting Up Initial Node
    EightPuzzle::node root;
    
    EightPuzzle::UserInput(root.state, root.emptyTile, HeuristicSelector);

    cout<<"Initial Coniguration:"<<endl;
    EightPuzzle::printState(root.state);

    if (HeuristicSelector)
    {
        root.heuristic = root.ManhattanDistance();
    }
    else
    {
        root.heuristic = root.MisplacedTiles();
    }
    root.numOfmoves = 0;
    root.totalCost = root.numOfmoves + root.heuristic;

    //Add inital state to frontierSet
    FrontierSet.push_back(root);


    while(true)
    {
        //If no states left to explore
        if (FrontierSet.size() == 0)
        {
            cout << "Solution doesn't Exist.";
            break;
        }

        //select node with least totalCost
        root = FrontierSet[FrontierSet.size()-1];


        EightPuzzle::printState(root.state);

        //Add node to ExploredSet
        EightPuzzle::AddtoExploredSet(root, ExploredSet);

        //remove the selected node from  frontier
        FrontierSet.pop_back();

        //check whether the state is goal or not
        if (EightPuzzle::CheckGoal(root.state)){
            cout<<"Success!"<<endl;
            cout<<"Number of Moves taken: "<<root.numOfmoves<<endl;
            cout<<"Number of Nodes Explored: "<<ExploredSet.size()<<endl;
            break;
        }
        
        //calculate possible actions
        EightPuzzle::possibleActions(actions, root.emptyTile); 
        
        for (int i = 0; i < 4; i++) //since max 4 actions possible at any state 
        {
            
            if (actions[i] == 'C') //move not possible
            { 
                continue;
            }
            else
            {
                //generate successor node
                newNode.GenerateNode(root, actions[i], HeuristicSelector);

                //check whether the state is in Frontier set or not
                //if yes, is the cost higher than the node in the set or not
                //if yes, skip that successor
                check=EightPuzzle::CheckInSet(newNode, FrontierSet);
                if (check)
                {
                    continue;
                }
                
                //check whether the state is in Explored set or not
                //if yes, is the cost higher than the node in the set or not
                //if yes, skip that successor otherwise add to frontier set
                check=EightPuzzle::CheckInSet(newNode, ExploredSet);
                if (check){
                    continue;
                }
                else{
                    EightPuzzle::AddtoFrontierSet(newNode, FrontierSet);
                }
            }
        } 

        
    }

    return 0;
}