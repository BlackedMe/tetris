#pragma once
#include <glm/vec2.hpp>
#include <board.hpp>
#include <linkedList.hpp>
//stores the game states(previous frame and current frame)
class GameState{
public:
  ListNode * current;
  ListNode * previous;

  void init(Board board);

  void setTileId(int id);
  int getTileId();

  void setTileOffset(int offset);
  int getTileOffset();

  void setGridPos(glm::ivec2 aGridPos);
  glm::ivec2 getGridPos();

  const std::vector<int> &getHeight();
  void setHeight(int index, int value);

  const float getTime();
  void setTime(float val);

private:
  //the id of the current tile displaying on the screen
  int tileId = 1;

  //select the orientation of the current tile
  int tileOffset = 0;

  //the grid position of the center of the current moving tile on the screen
  glm::ivec2 gridPos = glm::ivec2(0, 0);
  
  //for each column j, a 1x1 pixel on the same column would land on (j, height[j])
  std::vector<int> height;

  //how much time has elasped to get to the previous state
  float timeElasped = 0;
};
