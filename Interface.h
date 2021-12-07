//Contains all functions and classes placed in different files which are being used at different points of the program.

#pragma once
#include<vector>

namespace EightPuzzle
{
   void UserInput(char input[3][3], int blank[2], bool &h);
   void printState(char state[3][3]);
   bool CheckGoal(char input[3][3]);
   void possibleActions(char action[4], int blank[2]);
   

   class node
   {
   public:
      node *parent;
      char state[3][3];
      int emptyTile[2]; //contain index of empty tile
      int heuristic;
      int numOfmoves;
      int totalCost;
      char act;


      void GenerateNode(node &old, char action, bool &heu);
      int MisplacedTiles();
      int ManhattanDistance();

      void Successor(char st[3][3], int blank[2]);

   private:
      void tempDistance(char &element, int index[2]);
   };


   void AddtoFrontierSet(node newlyCreated, std::vector<node> &FrontierSet);
   void AddtoExploredSet(node inputNode, std::vector<node> &ExploredSet);
   bool CheckInSet(node &newlyCreated, std::vector<node> &FrontierSet);


} // namespace EightPuzzle