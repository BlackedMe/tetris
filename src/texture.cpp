#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <glad/glad.h>
#include <string>
#include <texture.hpp>

void Texture::init(const int numTextures, std::string *src)
{
  int x, y, n;

  unsigned char ** data = new unsigned char*[numTextures];
  for(int i = 0; i < numTextures; i++) 
  {
    data[i] = stbi_load(src[i].c_str(), &x, &y, &n, 0);
  }
  GLuint texture = 0;
  glGenTextures(1, &texture);

  glBindTexture(GL_TEXTURE_2D_ARRAY, texture);
  glTexStorage3D(GL_TEXTURE_2D_ARRAY, 1, GL_RGBA8, x, y, 32);
  glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
  glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

  float color[4] = {128.0/255, 128.0/255, 128.0/255, 1};
  glTexParameterfv(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_BORDER_COLOR, color);

  glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
  glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);

  glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, 0, x, y, 1, GL_RGBA, GL_UNSIGNED_BYTE,0);
  for(int i = 0; i < numTextures; i++)
  {
    glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, i + 1, x, y, 1, GL_RGBA, GL_UNSIGNED_BYTE, &data[i][0]);
    glGenerateMipmap(GL_TEXTURE_2D_ARRAY);
  }
}
