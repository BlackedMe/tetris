#include <glad/glad.h>
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <uniform.hpp>
GLuint compileShader(const char* shaderSource, GLenum shaderType);

GLuint createProgram(const char* vShaderSrc, const char* fShaderSrc, float aspectRatio);
