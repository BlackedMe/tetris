#include <gameState.hpp>
#include <commands/command.hpp>

RotateAnti::RotateAnti(GameState &gameState) : gameState(gameState) {};

void RotateAnti::execute()
{
  if(Command::timer > 0.0f) return; 
  gameState.setTileOffset((gameState.getTileOffset() + 1) % 4);
  timer = 0.5f;
}
