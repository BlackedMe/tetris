#include <glfwHandler.hpp>

glfwHandler::glfwHandler(const int SCR_WIDTH, const int SCR_HEIGHT) : SCR_WIDTH(SCR_WIDTH), SCR_HEIGHT(SCR_HEIGHT), aspectRatio((float) SCR_WIDTH/SCR_HEIGHT) {};
glfwHandler::~glfwHandler()
{
  glfwTerminate();
}

void glfwHandler::init()
{
  glfwInit();
  
  glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
  window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Tetris", glfwGetPrimaryMonitor(), 0);
  glfwMakeContextCurrent(window);
  
  //initalizes glad
  gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

  //initalize callback functions
  initCallback();
}

void glfwHandler::initCallback()
{
  glfwSetFramebufferSizeCallback(window, [](GLFWwindow *window, int w, int h) { glViewport(0, 0, w, h); }); 
}

GLFWwindow *glfwHandler::getWindow()
{
  return window;
}
