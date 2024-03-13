#include <shapes.hpp>
#include <math.hpp>
#include <glad/glad.h>
GLuint line(vec3 start, vec3 end){
  float vertices[] = {
    start.x, start.y, start.z,
    end.x, end.y, end.z
  };
  GLuint vbo = 0, vao = 0;

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  return vao;
}
