#version 420 core
uniform vec4 a_color;
uniform sampler2DArray tex;
out vec4 color;
in vec2 a_texCoord;
in float a_texIndex;

void main()
{
  color = texture(tex, vec3(a_texCoord, a_texIndex));
}
