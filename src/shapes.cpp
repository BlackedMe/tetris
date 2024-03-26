#include <shapes.hpp>
#include <math.hpp>
#include <glad/glad.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

GLuint line(vec3 start, vec3 end){
  float vertices[] = {
    start.x, start.y, start.z,
    end.x, end.y, end.z
  };
  GLuint vao = 0, vbo = 0;

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  return vao;
}

GLuint square(float l)
{
  l /= 2;
  float vertices[] = {
    -l, -l,
     l, -l,
     l, l,
    -l, l,
  };

  unsigned int indices[] = {0, 1, 2, 2, 3, 0};

  GLuint vao = 0, vbo = 0, ebo = 0;
  
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

  glGenBuffers(1, &ebo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
  return vao;
}

GLuint rectangle(float l, float h)
{
  l /= 2;
  h /= 2;
  
  float vertices[] = {
    -l, -h,
    l, -h,
    l, h,
    -l, h,
  };

  unsigned int indices[] = {0, 1, 2, 2, 3, 0};

  GLuint vao = 0, vbo = 0, ebo = 0;
  
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

  glGenBuffers(1, &ebo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

  return vao;
}

