#include <update.hpp>
#include <GLFW/glfw3.h>
#include <gameLogic.hpp>
#include <unistd.h>
#include <commands/command.hpp>

void updateHandler::update(GameState &gameState, Board &board, std::vector<std::vector<float>> &tile, float dt)
{
  glfwPollEvents();
  //move the tile one unit downwards every second
  GameLogic::replace(gameState.current, tile, glm::ivec2(gameState.getGridPos().x, glfwGetTime() - gameState.getTime()), board); 

  Command::timer -= dt;
}
