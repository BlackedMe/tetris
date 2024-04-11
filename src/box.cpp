#include <glm/vec2.hpp>
#include <box.hpp>

boxVertex * Box::genBox(float texBorderWidth, float boxWidth, float texIndex, glm::vec2 pos)
{
  boxWidth /=2;
  boxVertex *box = new boxVertex[4];

  box[0].pos = glm::vec2(pos.x-boxWidth, pos.y-boxWidth);
  box[0].texCoord = glm::vec2(-texBorderWidth, -texBorderWidth);
  box[0].texIndex = texIndex;

  box[1].pos = glm::vec2(pos.x + boxWidth, pos.y - boxWidth);
  box[1].texCoord = glm::vec2(1 + texBorderWidth, -texBorderWidth);
  box[1].texIndex = texIndex;

  box[2].pos = glm::vec2(pos.x + boxWidth, pos.y + boxWidth);
  box[2].texCoord = glm::vec2(1 + texBorderWidth, 1 + texBorderWidth);
  box[2].texIndex = texIndex;

  box[3].pos = glm::vec2(pos.x - boxWidth, pos.y + boxWidth);
  box[3].texCoord = glm::vec2(1 + texBorderWidth, -texBorderWidth);
  box[3].texIndex = texIndex;

  return box;
}

