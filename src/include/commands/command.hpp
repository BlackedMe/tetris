#include <gameState.hpp>
#include <resource.hpp>
#include <commands/land.hpp>
class Command{
public:
  virtual void execute() = 0;
  static float timer;
};

class LandCommand : public Command{
public:
  LandCommand(GameState &gameState, Board &board, Resource &resource);
  virtual void execute();
private:
  GameState &gameState;
  Board &board;
  Resource &resource;
};


class RotateClock : public Command{
public:
  RotateClock(GameState &gameState);
  virtual void execute();
private:
  GameState &gameState;
};

class RotateAnti : public Command{
public:
  RotateAnti(GameState &gameState);
  virtual void execute();
private:
  GameState &gameState;
};
