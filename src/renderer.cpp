#include <renderer.hpp>

void Renderer::render(glfwHandler &hwnd, Board &board, Shader &shader, GameState &gameState)
{
  shader.useProgram();
  //rendering
  board.render(gameState.current);
  gameState.current->copyData(gameState.previous, board.n, board.m);
  //
  glfwSwapBuffers(hwnd.getWindow());
}
