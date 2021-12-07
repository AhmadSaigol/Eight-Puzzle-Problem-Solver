#include "Interface.h"
using namespace std;

//Add node to the explored set
void EightPuzzle::AddtoExploredSet(node inputNode, std::vector<node> &ExploredSet)
{
    ExploredSet.push_back(inputNode);
}
