#include <gameState.hpp>
#include <glm/vec2.hpp>
#include <gameLogic.hpp>
#include <board.hpp>
#include <iostream>

void GameLogic::replace(ListNode *src, std::vector<std::vector<float>> &data, glm::ivec2 gridPos, Board &board)
{
  for(int i = 0; i < gridPos.y - 1; i++) src = src->next;

  for(int i = gridPos.y - 1, j; i <= gridPos.y + 1; i++)
  {
    if(i < 0 || i >= board.n) continue;
    for(j = gridPos.x - 1; j <= gridPos.x + 1; j++)
    {
      if(j < 0 || j >= board.m) continue;
      if(src->vec[j] == 0) src->vec[j] = data[i - gridPos.y + 1][j - gridPos.x + 1];
    }
    src = src->next;
  }
}

void GameLogic::addRow(ListNode *&src, Board &board)
{
  ListNode *head = new ListNode;
  head->vec.resize(board.m, 0);
  head->next = src;
  src = head;
}

//remove the current line pointed by src
void GameLogic::removeRow(ListNode *&src)
{
  src = src->next;
}

void GameLogic::updateHeight(GameState &gameState, std::vector<std::vector<float>> &tile)
{
  for(int j = 0; j < 3; j++)  
  {
    for(int i = 0; i < 3; i++)
    {
      if(tile[i][j] != 0)
      {
        gameState.setHeight(gameState.getGridPos().x - 1 + j, gameState.getGridPos().y - 1 + i - 1);
        break;
      }
    }
  }
}

void GameLogic::checkForRemoval(GameState &gameState, Board &board)
{
  ListNode *ptr = gameState.current;
  for(int i = 0; i < gameState.getGridPos().y - 2; i++) ptr = ptr->next;

  //number of rows removed
  int count = 0;

  for(int i = 0, j; i < 3; i++)
  {
    for(j = 0; j < board.m; j++) 
    {
      if(ptr->next->vec[j] == 0) break;
    }
    if(j >= board.m) {
      //this only change what the pointer points to, it does not change the ancestor's pointer, this is the problem
      removeRow(ptr->next);
      addRow(gameState.current, board);
      count ++;
      continue;
    }
    ptr = ptr->next;
  }
  for(int j = 0; j < board.m; j++) gameState.setHeight(j, gameState.getHeight()[j] + count);
}
