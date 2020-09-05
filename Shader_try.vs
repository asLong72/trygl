//顶点着色器代码
#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;//纹理坐标
layout (location = 2) in mat4 modelIntance;//

out vec2 TexCoord;

uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * modelIntance * vec4 (aPos, 1.0f);
    TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}