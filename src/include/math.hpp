#pragma once
class vec3{
public:
  float x,y,z;

  vec3(float x, float y, float z) : x(x), y(y), z(z) {};

  vec3() {};

  vec3 operator + (vec3 tar){
    vec3 res;
    res.x = x + tar.x;
    res.y = y + tar.y;
    res.z = z + tar.z;
    return res;
  };
};
