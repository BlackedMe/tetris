#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class glfwHandler{
public:
  glfwHandler(const int SCR_WIDTH, const int SCR_HEIGHT);

  ~glfwHandler();
  //initalize GLFW stuff
  void init();

  void initCallback();

  GLFWwindow * getWindow();
  
  const int SCR_HEIGHT, SCR_WIDTH;
  const float aspectRatio;

private:
  GLFWwindow * window;
};
