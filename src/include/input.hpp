#include <glfwHandler.hpp>
#include <board.hpp>
#include <gameState.hpp>
#include <commands/command.hpp>

class InputHandler{
public:
  InputHandler(GameState &gameState, Board &board, Resource &resource);
  void processInput(glfwHandler &hwnd, Board &board, GameState &gameState, std::vector<std::vector<float>> &tile);
private:
  Command * buttonSpace;
  Command * buttonUp;
  Command * buttonDown;
};
