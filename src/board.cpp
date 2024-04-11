#include <cstring>
#include <glad/glad.h>
#include <boxVertex.hpp>
#include <board.hpp>
#include <linkedList.hpp>
#include <box.hpp>

Board::Board(const int n, const int m, const float boxWidth, const float borderWidth) : n(n), m(m), width(m * boxWidth), height(n * boxWidth), boxWidth(boxWidth), borderWidth(borderWidth) {};

//initalizes the board
void Board::init()
{
  GLuint vbo = 0, ebo = 0;
  
  float vertices[sizeof(boxVertex)/sizeof(float) * 4 * n * m];
  unsigned int indices[6 * n * m];

  glm::vec2 start((-width + boxWidth)/2, (height - boxWidth)/2);
  for(int i = 0, offset = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++, offset += (sizeof(boxVertex)/sizeof(float) * 4))
    {
      boxVertex * box = Box::genBox(borderWidth / boxWidth, boxWidth, 0, glm::vec2(start.x + j * (boxWidth - borderWidth), start.y - i * (boxWidth - borderWidth))); 
      memcpy(vertices + offset, box, sizeof(boxVertex) * 4);
    }
  }

  for(int i = 0, j = 0; i < 6 * n * m; i += 6, j += 4)
  {
    indices[i] = j;
    indices[i + 1] = j + 1;
    indices[i + 2] = j + 2;

    indices[i + 3] = j + 2;
    indices[i + 4] = j + 3;
    indices[i + 5] = j;
  }

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_DYNAMIC_DRAW);

  glGenBuffers(1, &ebo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);

  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) offsetof(boxVertex, texCoord));

  glEnableVertexAttribArray(2);
  glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void  *) offsetof(boxVertex, texIndex));


}

//renders the board (updates the board)
void Board::render(ListNode * current)
{
  // glBindVertexArray(vao);
  
  ListNode *ptr = current;
  for(int i = 0, offset = 1; i < n; i++, ptr = ptr->next)
  {
    for(int j = 0; j < m; j++, offset += 4)
    {
      //a single box
      glBufferSubData(GL_ARRAY_BUFFER, offset * sizeof(boxVertex) - sizeof(float), sizeof(float), &ptr->vec[0] + j);
      glBufferSubData(GL_ARRAY_BUFFER, (offset + 1) * sizeof(boxVertex) - sizeof(float), sizeof(float), &ptr->vec[0] + j);
      glBufferSubData(GL_ARRAY_BUFFER, (offset  + 2) * sizeof(boxVertex) - sizeof(float), sizeof(float), &ptr->vec[0] + j);
      glBufferSubData(GL_ARRAY_BUFFER, (offset + 3) * sizeof(boxVertex) - sizeof(float), sizeof(float), &ptr->vec[0] + j);
      //
    }
  }
  glDrawElements(GL_TRIANGLES, 6 * n * m, GL_UNSIGNED_INT, 0);
}

