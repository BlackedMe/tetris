#version 420 core
uniform vec4 a_color;
out vec4 color;
in vec2 texCoord;
uniform sampler2D tex;

void main()
{
  if(a_color != vec4(1.0f))
  {
    color = a_color;
  }
  else color = texture(tex, texCoord);
}
