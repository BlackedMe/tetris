#include <glad/glad.h>
#include <uniform.hpp>

void uniformMatrix4fv(GLuint program, const char* name, GLsizei count, GLboolean transpose, const GLfloat *value)
{
  GLint location = glGetUniformLocation(program, name);
  glUniformMatrix4fv(location, count, transpose, value);
}
void uniform4f(GLuint program, const char* name, float v0, float v1, float v2, float v3)
{
  glUniform4f(glGetUniformLocation(program, name), v0, v1, v2, v3);
}
