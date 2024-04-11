#include <gameState.hpp>
#include <board.hpp>
#include <resource.hpp>
#include <input.hpp>

InputHandler::InputHandler(GameState &gameState, Board &board, Resource &resource)
{
  //keybinds
  buttonSpace = new LandCommand(gameState, board, resource);
  buttonUp = new RotateClock(gameState);
  buttonDown = new RotateAnti(gameState);
}

void InputHandler::processInput(glfwHandler &hwnd, Board &board, GameState &gameState, std::vector<std::vector<float>> &tile)
{
  double x, y;
  glfwGetCursorPos(hwnd.getWindow(), &x, &y);
  
  x = -hwnd.aspectRatio + 2 * hwnd.aspectRatio * (x / hwnd.SCR_WIDTH);
  y = 1 - 2 * (y / hwnd.SCR_HEIGHT);

  glm::vec2 start((-board.width + board.borderWidth) / 2, (board.height - board.borderWidth) / 2);

  int gridPosX = (x - start.x) / (board.boxWidth - board.borderWidth);

  //sets the tile's x coordinate to be the same as the mouse coordinate
  gameState.setGridPos(glm::ivec2(gridPosX, gameState.getGridPos().y));

  if(glfwGetKey(hwnd.getWindow(), GLFW_KEY_SPACE)) buttonSpace->execute();
  else if(glfwGetKey(hwnd.getWindow(), GLFW_KEY_UP)) buttonUp->execute();
  else if(glfwGetKey(hwnd.getWindow(), GLFW_KEY_DOWN)) buttonDown->execute();
}
