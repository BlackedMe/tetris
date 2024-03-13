#include <program.hpp>
#include <uniform.hpp>

GLuint compileShader(const char* shaderSource, GLenum shaderType)
{
  GLuint shaderObj = glCreateShader(shaderType); 
  glShaderSource(shaderObj, 1, &shaderSource, 0);
  glCompileShader(shaderObj);
  return shaderObj;
}


GLuint createProgram(const char* vShaderSrc, const char* fShaderSrc, float aspectRatio)
{
  GLuint program = glCreateProgram();
  GLuint vShader = compileShader(vShaderSrc, GL_VERTEX_SHADER), fShader = compileShader(fShaderSrc, GL_FRAGMENT_SHADER);
  glAttachShader(program, vShader);
  glAttachShader(program, fShader);
  glLinkProgram(program);

  glUseProgram(program);
  glm::mat4 model(1.0f), view(1.0f), proj(1.0f);
  proj = glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 100.0f); 
  view = glm::translate(view, glm::vec3(0.0f, 0.0f, -2.0f));
  uniformMatrix4fv(program, "model", 1, GL_FALSE, &model[0][0]);
  uniformMatrix4fv(program, "view", 1, GL_FALSE, &view[0][0]);
  uniformMatrix4fv(program, "proj", 1, GL_FALSE, &proj[0][0]);
  uniform4f(program, "a_color", 1.0f, 0.0f, 0.0f, 1.0f);
  glUseProgram(0);
  return program;
}

