//顶点着色器代码
#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) in mat4 matrix;

out data
{
    vec2 TexCoord;
    vec3 normal;
} data;

uniform mat4 view;
uniform mat4 projection;

uniform samplerBuffer texture_TBO;
uniform samplerBuffer model_TBO;


void main()
{
    gl_Position = matrix * view * projection * vec4 (aPos, 1.0f);
    TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}