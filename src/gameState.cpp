#include <board.hpp>
#include <glm/vec2.hpp>
#include <gameState.hpp>

void GameState::init(Board board)
{
  current = new ListNode();
  previous = new ListNode();

  current->initalizeList(board.n, board.m);
  previous->initalizeList(board.n, board.m);
  //initalize the height vector with the value board.n - 1 
  height.resize(board.m, board.n - 1);
}

void GameState::setTileId(int id)
{
  tileId = id;
}
int GameState::getTileId()
{
  return tileId;
}

void GameState::setTileOffset(int offset)
{
  tileOffset = offset;
}

int GameState::getTileOffset()
{
  return tileOffset;
}

void GameState::setGridPos(glm::ivec2 aGridPos)
{
  gridPos = aGridPos;
}

glm::ivec2 GameState::getGridPos()
{
  return gridPos;
}

const std::vector<int> &GameState::getHeight()
{
  return height;
}

void GameState::setHeight(int index, int value)
{
  height[index] = value;
}

const float GameState::getTime()
{
  return timeElasped;
}

void GameState::setTime(float val)
{
  timeElasped = val; 
}
