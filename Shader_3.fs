//片元着色器代码
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
    FragColor = texture(ourTexture, data.TexCoord);  //对纹理指定位置进行采样
}