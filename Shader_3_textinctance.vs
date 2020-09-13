//������ɫ������
#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;//��������
layout (location = 2) in mat4 modelIntance;//
layout (location = 6) in unsigned int text_ID;

out DATA
{
    vec3 TexCoord;
    vec3 normal;
} data;

uniform mat4 view;
uniform mat4 projection;


void main()
{
	gl_Position = projection * view * modelIntance * vec4 (aPos, 1.0f);
	data.TexCoord.st = aTexCoord.st;
	data.TexCoord.p = float(text_ID);
}
