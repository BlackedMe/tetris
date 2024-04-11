#version 420 core
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;
layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in float texIndex;
out vec2 a_texCoord;
out float a_texIndex;

void main()
{
  gl_Position = proj * view * model * vec4(pos, 1.0f);
  a_texCoord = texCoord;
  a_texIndex = texIndex;
}
