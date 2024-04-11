#pragma once
#include <glad/glad.h>
#include <string>
class Shader{
public:

  Shader(std::string &&vShaderPath, std::string &&fShaderPath);
  void useProgram();
  void init(float aspectRatio);

private:
  const char *vShaderSrc, *fShaderSrc;
  GLuint program;


  GLuint compileShader(const char* shaderSrc, GLenum shaderType);
};
