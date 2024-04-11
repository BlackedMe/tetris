#include <commands/command.hpp>

RotateClock::RotateClock(GameState &gameState) : gameState(gameState) {};

void RotateClock::execute()
{
  if(Command::timer > 0.0f) return; 
  gameState.setTileOffset(((gameState.getTileOffset() - 1) % 4 + 4) % 4);
  timer = 0.5f;
}
