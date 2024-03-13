#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <parser.hpp>
#include <graphics.hpp>
#include <program.hpp>
#include <math.hpp>
#include <shapes.hpp>

//renders a n * m grid
void renderGrid()
{
  float gridSize = 0.06f;
  int n = 22, m = 10;

  //top left
  float x_1 = -(float) m/2 * gridSize, y_1 = (float) n/2 * gridSize; 

  //bottom right
  float x_2 = -x_1, y_2 = -y_1;

  //starts rendering horizontal line and vertical line, starting from (x_1, y_1)
  
  //renders horizontal lines
  float y = y_1; //y coordinate for the current horizontal line to be drawn
  for(int i = 0; i <= n; i++) 
  {
    vec3 start(x_1, y, 0);
    vec3 end(x_2, y, 0);
    GLuint vao = line(start, end);
    glBindVertexArray(vao);
    glDrawArrays(GL_LINES, 0, 2);
    y -= gridSize;
  }

  //renders vertical lines
  float x = x_1;
  for(int i = 0; i <= m; i++) 
  {
    vec3 start(x, y_1, 0);
    vec3 end(x, y_2, 0);
    GLuint vao = line(start, end);
    glBindVertexArray(vao);
    glDrawArrays(GL_LINES, 0, 2);
    x += gridSize;
  }
}

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
    renderGrid();
    glfwSwapBuffers(window);

    glfwPollEvents();
  }
}
