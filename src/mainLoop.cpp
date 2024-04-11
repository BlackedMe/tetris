#include <mainLoop.hpp>
#include <texture.hpp>
#include <resource.hpp>
#include <board.hpp>
#include <input.hpp>
#include <renderer.hpp>
#include <update.hpp>

void Tetris::run()
{
  //initalizes the glfwHandler
  glfwHandler hwnd(1280, 800);  
  hwnd.init();

  //initalizes the board
  Board board(22, 10, 0.08, 0.004);
  board.init();
  
  //initalizes shaders and program
  Shader shader("../src/glsl/vertex.glsl", "../src/glsl/fragment.glsl");
  shader.init(hwnd.aspectRatio);

  //initalizes textures
  std::string texSrc[4] = {"../sprites/Sprite-0001.png", "../sprites/Sprite-0003.png", "../sprites/Sprite-0004.png", "../sprites/Sprite-0005.png"};
  Texture::init(sizeof(texSrc) / sizeof(std::string), texSrc);
  
  //initalizes the necessary states of the game
  GameState gameState;
  gameState.init(board);
  //setup the necessary resources
  Resource resource;

  float lastFrame = glfwGetTime(), dt;
  //Setup the game loop
  InputHandler inputHwnd(gameState, board, resource);

  while(!glfwWindowShouldClose(hwnd.getWindow()))
  {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    dt = glfwGetTime() - lastFrame;
    lastFrame = glfwGetTime();

    inputHwnd.processInput(hwnd, board, gameState, resource.tiles[4 * gameState.getTileId() + gameState.getTileOffset()]);

    updateHandler::update(gameState, board, resource.tiles[4 * gameState.getTileId() + gameState.getTileOffset()], dt);
    // 
    Renderer::render(hwnd, board, shader, gameState);
    
  }
}
