//ƬԪ��ɫ������
#version 330 core

out vec4 FragColor;

in DATA
{
    vec2 TexCoord;
    vec3 normal;
} data;

uniform sampler2D ourTexture;

void main()
{
    FragColor = texture(ourTexture, data.TexCoord);  //������ָ��λ�ý��в���
}