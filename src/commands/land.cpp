#include <gameState.hpp>
#include <GLFW/glfw3.h>
#include <gameLogic.hpp>
#include <commands/land.hpp>
#include <commands/command.hpp>
#include <iostream>

LandCommand::LandCommand(GameState &gameState, Board &board, Resource &resource) : gameState(gameState), board(board), resource(resource) {};

void LandCommand::execute()
{
  if(Command::timer > 0.0f) return; 
  land(gameState, board, resource.tiles[4 * gameState.getTileId() + gameState.getTileOffset()]);
  timer = 0.5f;
}

void land(GameState &gameState, Board &board, std::vector<std::vector<float>> &tile)
{
  //the minimum displacement allowed in grids (i.e how much grid in the y axis before the tile lands)
  int yOffset = INT32_MAX;
  for(int j = 0; j < 3; j++) 
  {
    for(int i = 2; i >= 0; i--) 
    {
      if(tile[i][j] != 0) 
      {
        yOffset = std::min(yOffset, (int) (gameState.getHeight()[gameState.getGridPos().x - 1 + j] - (gameState.getGridPos().y - 1 + i)));
        break;
      }
    }
      
  }
  gameState.setGridPos(glm::ivec2(gameState.getGridPos().x, gameState.getGridPos().y + yOffset));
  GameLogic::replace(gameState.current, tile, gameState.getGridPos(), board); 

  //update the current state after the tile landed

  //for each column j, update the coordinate a 1x1 pixel would land on
  GameLogic::updateHeight(gameState, tile);
  GameLogic::checkForRemoval(gameState, board);
  gameState.previous->copyData(gameState.current, board.n, board.m);
  gameState.setTileId((gameState.getTileId() + 1) % 5); 
  gameState.setTime(glfwGetTime());

  //
}
