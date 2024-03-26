#include <glad/glad.h>
#include <graphics.hpp>
#include <parser.hpp>
#include <program.hpp>
#include <render.hpp>

int main() {
  const uint SCR_WIDTH = 800;
  const uint SCR_HEIGHT = 800;
  const float aspectRatio = (float)SCR_WIDTH / SCR_HEIGHT;
  const glm::vec4 clearColor(0, 0, 0, 1);
  GLFWwindow *window;

  glfwInit();
  glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
  window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Hello World",
                            0, 0);

  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    return 1;
  glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);
  const char *vShaderSrc = parseFromFile("../src/glsl/vertex.glsl"),
             *fShaderSrc = parseFromFile("../src/glsl/fragment.glsl");

  GLuint program = createProgram(vShaderSrc, fShaderSrc, aspectRatio);

  while (!glfwWindowShouldClose(window)) {

    glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(program);

    renderGrid(program);

    glfwSwapBuffers(window);

    glfwPollEvents();
  }
}
