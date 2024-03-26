#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp> 
#include <glad/glad.h>
#include <shapes.hpp>
#include <uniform.hpp>
#include <stb_image.h>
#define STB_IMAGE_IMPLEMENTATION

// renders a n * m grid
void renderGrid(GLuint program) {
  //based on the box model

  int n = 22, m = 10;
  float contentSize = 0.05f, borderWidth = 0.0025f; 

  //Draws the board
  float boardLength = m * contentSize + (m+1) * borderWidth, boardHeight = n * contentSize + (n+1) * borderWidth;
  GLuint borderVAO = rectangle(boardLength, boardHeight);
  glBindVertexArray(borderVAO);
  glm::mat4 model(1.0f);
  uniformMatrix4fv(program, "model", 1, GL_FALSE, &model[0][0]);
  //color of the border
  uniform4f(program, "a_color", 50.2/255, 50.2/255, 50.2/255, 1.0f);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); 


  //Vao of content
  GLuint vao = square(contentSize), texture = 0; 

  //add a new attribute
  float textureCoords[] = {
    0.0, 0.0,
    1.0, 0.0,
    1.0, 1.0,
    0.0, 1.0,
  };
  
  //buffer for the texture coordinates
  GLuint vbo = 0;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo); 
  glBufferData(GL_ARRAY_BUFFER, sizeof(textureCoords), &textureCoords[0], GL_STATIC_DRAW);

  glBindVertexArray(vao);
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

  //Texture image
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  
  int length, height, comp; unsigned char *data = stbi_load("../sprites/Sprite-0001.png", &length, &height, &comp, 0);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, length, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &data[0]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
  glGenerateMipmap(GL_TEXTURE_2D);
  stbi_image_free(data);
  
  //top left 
  float x = (-boardLength + contentSize)/2 + borderWidth, y = (boardHeight - contentSize)/2 - borderWidth;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      glm::mat4 model(1.0f); 
      model = glm::translate(model, glm::vec3(x + j * (contentSize + borderWidth), y - i * (contentSize + borderWidth), 0));
      uniformMatrix4fv(program, "model", 1, GL_FALSE, &model[0][0]);

      glBindTexture(GL_TEXTURE_2D, texture);
      glBindVertexArray(vao);

      uniform4f(program, "a_color", 0.0f, 0.0f, 0.0f, 0.0f);
      glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
  }
}
