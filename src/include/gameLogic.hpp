#include <vector>
#include <glm/vec2.hpp>
#include <board.hpp>
#include <gameState.hpp>
#include <linkedList.hpp>
namespace GameLogic {
  void replace(ListNode *src, std::vector<std::vector<float>> &data, glm::ivec2 gridPos, Board &board);
  void removeRow(ListNode *&src);
  void addRow(ListNode *&src, Board &board);
  void updateHeight(GameState &gameState, std::vector<std::vector<float>> &tile);
  void checkForRemoval(GameState &gameState, Board &board);
}; 
