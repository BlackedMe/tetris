#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <parser.hpp>
#include <graphics.hpp>
#include <program.hpp>

int main()
{
  const uint SCR_WIDTH = 1280;
  const uint SCR_HEIGHT = 800;
  const float aspectRatio = (float) SCR_WIDTH/SCR_HEIGHT;
  const glm::vec4 clearColor(0, 0, 0, 1);
  GLFWwindow *window;

  glfwInit();
  window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Hello World", glfwGetPrimaryMonitor(), 0);

  glfwMakeContextCurrent(window);
  gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
  glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback); 
  const char * vShaderSrc = parseFromFile("../src/glsl/vertex.glsl"), *fShaderSrc = parseFromFile("../src/glsl/fragment.glsl");

  GLuint program = createProgram(vShaderSrc, fShaderSrc, aspectRatio);
  
  while(!glfwWindowShouldClose(window))
  {

    glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(program);

    glfwSwapBuffers(window);

    glfwPollEvents();
  }
}
