#include <glad/glad.h>
#include <GLFW/glfw3.h>
void frameBufferSizeCallback(GLFWwindow *window, int w, int h)
{
  glViewport(0, 0, w, h);
}


