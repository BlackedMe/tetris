#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

#include <shader.hpp>
#include <uniform.hpp>
#include <parser.hpp>

Shader::Shader(std::string &&vShaderPath, std::string &&fShaderPath)
{
  vShaderSrc = parseFromFile(vShaderPath);
  fShaderSrc = parseFromFile(fShaderPath);
}

void Shader::init(float aspectRatio)
{
  
  program = glCreateProgram();
  GLuint vShader = compileShader(vShaderSrc, GL_VERTEX_SHADER), fShader = compileShader(fShaderSrc, GL_FRAGMENT_SHADER);
  glAttachShader(program, vShader);
  glAttachShader(program, fShader);
  glLinkProgram(program);

  glUseProgram(program);
  glm::mat4 model(1.0f), view(1.0f), proj(1.0f);
  proj = glm::ortho(-aspectRatio, aspectRatio, -1.0f, 1.0f);
  // view = glm::translate(view, glm::vec3(0.0f, 0.0f, 0.0f));
  uniformMatrix4fv(program, "model", 1, GL_FALSE, &model[0][0]);
  uniformMatrix4fv(program, "view", 1, GL_FALSE, &view[0][0]);
  uniformMatrix4fv(program, "proj", 1, GL_FALSE, &proj[0][0]);
  glUniform1i(glGetUniformLocation(program, "tex"), 0);
  uniform4f(program, "a_color", 1.0f, 0.0f, 0.0f, 1.0f);
  glUseProgram(0);
}

void Shader::useProgram()
{
  glUseProgram(program);
}

GLuint Shader::compileShader(const char* shaderSrc, GLenum shaderType)
{
  GLuint shaderObj = glCreateShader(shaderType); 
  glShaderSource(shaderObj, 1, &shaderSrc, 0);
  glCompileShader(shaderObj);
  return shaderObj;
}



