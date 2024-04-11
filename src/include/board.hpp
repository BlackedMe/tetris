//a board is composed of n * m boxes
#pragma once
#include <vector>
#include <linkedList.hpp>
#include <glm/vec2.hpp>
#include <glad/glad.h>
class Board{
public:
  Board(const int n, const int m, const float boxWidth, const float borderWidth);

  void init();

  void render(ListNode * current);

  const float width, height, boxWidth, borderWidth;
  const int n, m;
private:

  GLuint vao = 0;
};
