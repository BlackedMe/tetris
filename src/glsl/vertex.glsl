#version 420 core
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;
layout (location = 0) in vec2 pos;
layout (location = 1) in vec2 aTexCoord;
out vec2 texCoord;

void main()
{
  gl_Position = proj * view * model * vec4(pos, 0.0f, 1.0f);
  texCoord = aTexCoord;
}
