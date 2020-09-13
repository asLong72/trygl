//extern "C" __declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
#include <Windows.h>
extern "C" {
	_declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
}
#include <vector>
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#define STB_IMAGE_IMPLEMENTATION
//预处理器会修改头文件，让其只包含相关的函数定义源码
//等于是将这个头文件变为一个 .cpp 文件了
//现在只需要在你的程序中包含stb_image.h并编译就可以了
#include "stb-master/stb_image.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Camera.h"
#include "Shader.h"
#include "math.h"


class TextureBuffer
{
public:
	TextureBuffer() { TexetureID = 0; if_array = false; };
	TextureBuffer(std::string);
	TextureBuffer(std::vector<std::string>);
	inline void Enabletexture() {
		if (if_array)
		{
			glBindTexture(GL_TEXTURE_2D_ARRAY, TexetureID);
		}
		else
		{
			glBindTexture(GL_TEXTURE_2D, TexetureID);
		}
	};
	inline void Disabletexture() {
		if (if_array)
		{
			glBindTexture(GL_TEXTURE_2D_ARRAY, NULL);
		}
		else
		{
			glBindTexture(GL_TEXTURE_2D, NULL);
		}
	};
	~TextureBuffer() { };

private:
	bool if_array;
	unsigned TexetureID;
};
TextureBuffer::TextureBuffer(std::string Texture_path)
{
	if_array = false;
	glGenTextures(1, &this->TexetureID);
	glBindTexture(GL_TEXTURE_2D, this->TexetureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	int width, height, nrChannels;
	GLenum format = 0;
	unsigned char* data = stbi_load(Texture_path.c_str(), &width, &height, &nrChannels, 0);
	if (data)
	{
		switch (nrChannels)
		{
		case 1:
			format = GL_RED;
			break;
		case 3:
			format = GL_RGB;
			break;
		case 4:
			format = GL_RGBA;
			break;
		default:
			format = 0;
			break;
		}
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cerr << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
	glBindTexture(GL_TEXTURE_2D, NULL);
}
TextureBuffer::TextureBuffer(std::vector<std::string> Texture_path)
{
	if_array = true;
	glCreateTextures(GL_TEXTURE_2D_ARRAY, 1, &this->TexetureID);
	glBindTexture(GL_TEXTURE_2D_ARRAY, this->TexetureID);
	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	int width = 0, height = 0, nrChannels = 0;
	int texture_num = 0;
	GLenum format = 0;
	unsigned char* data = NULL;
	while (texture_num < Texture_path.size())
	{
		data = stbi_load(Texture_path[texture_num].c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			switch (nrChannels)
			{
			case 1:
				format = GL_RED;
				break;
			case 3:
				format = GL_RGB;
				break;
			case 4:
				format = GL_RGBA;
				break;
			default:
				break;
			}
			if (texture_num == 0)
			{
				glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, format, width, height, Texture_path.size(), 0, format, GL_UNSIGNED_BYTE, NULL);
			}
			glTexSubImage3D(GL_TEXTURE_2D_ARRAY, // target
				0,					// level
				0,					// x offset
				0,					// y offset
				texture_num,		// z offset
				width,				// width
				height,				// height
				1,					// depth
				format,				// format
				GL_UNSIGNED_BYTE,	// type
				data);				// zeroed memory
			//std::cerr << glGetError();
			glGenerateMipmap(GL_TEXTURE_2D_ARRAY);
		}
		else
		{
			std::cerr << "Failed to load texture" << std::endl;
		}

		stbi_image_free(data);
		texture_num++;
	}

	glBindTexture(GL_TEXTURE_2D, NULL);
}

unsigned num = 0;

class CubeModel :public Shader
{
public:
	CubeModel();
	CubeModel(std::string, std::string);
	inline unsigned getVAO() { return VAO; };
	inline unsigned getVBO() { return VBO; };
	inline unsigned getEBO() { return EBO; };
	~CubeModel() { };

protected:
	unsigned VAO;
	unsigned VBO;
	unsigned EBO;

private:
	unsigned posInctanceVBO;
	unsigned texInctanceVBO;
};
CubeModel::CubeModel()
{
	progID = 0;
	VAO = 0;
	VBO = 0;
	posInctanceVBO = 0;
	texInctanceVBO = 0;
	EBO = 0;
};
CubeModel::CubeModel(std::string vertexShader_path, std::string fragmentShader_path) :Shader(vertexShader_path, fragmentShader_path)
{

	float vertex[]
	{
		//正面
		0.0f,	0.0f,	1.0f,	0.0f,	0.0f,		//左下
		1.0f,	0.0f,	1.0f,	0.0f,	1.0f,		//右下
		1.0f,	1.0f,	1.0f,	1.0f,	1.0f,		//右上
		0.0f,	1.0f,	1.0f,	1.0f,	0.0f,		//左上
		//
		1.0f,	0.0f,	0.0f,	0.0f,	0.0f,		//左下
		0.0f,	0.0f,	0.0f,	0.0f,	1.0f,		//右下
		0.0f,	1.0f,	0.0f,	1.0f,	1.0f,		//右上
		1.0f,	1.0f,	0.0f,	1.0f,	0.0f,		//左上
		//顶面
		0.0f,	1.0f,	1.0f,	0.0f,	0.0f,		//左下
		1.0f,	1.0f,	1.0f,	0.0f,	1.0f,		//右下
		1.0f,	1.0f,	0.0f,	1.0f,	1.0f,		//右上
		0.0f,	1.0f,	0.0f,	1.0f,	0.0f,		//左上
		//
		0.0f,	0.0f,	0.0f,	0.0f,	0.0f,		//左下
		1.0f,	0.0f,	0.0f,	0.0f,	1.0f,		//右下
		1.0f,	0.0f,	1.0f,	1.0f,	1.0f,		//右上
		0.0f,	0.0f,	1.0f,	1.0f,	0.0f,		//左上
		//左面
		0.0f,	0.0f,	0.0f,	0.0f,	0.0f,		//左下
		0.0f,	0.0f,	1.0f,	0.0f,	1.0f,		//右下
		0.0f,	1.0f,	1.0f,	1.0f,	1.0f,		//右上
		0.0f,	1.0f,	0.0f,	1.0f,	0.0f,		//左上
		//
		1.0f,	0.0f,	1.0f,	0.0f,	0.0f,		//左下
		1.0f,	0.0f,	0.0f,	0.0f,	1.0f,		//右下
		1.0f,	1.0f,	0.0f,	1.0f,	1.0f,		//右上
		1.0f,	1.0f,	1.0f,	1.0f,	0.0f,		//左上
	};
	unsigned indicat[] =
	{
		//
		0,	1,	3,
		1,	2,	3,
		//
		4,	5,	7,
		5,	6,	7,
		//
		8,	9,	11,
		9,	10,	11,
		//
		12,	13,	15,
		13,	14,	15,
		//
		16,	17,	19,
		17,	18,	19,
		//
		20,	21,	23,
		21,	22,	23,
	};

	std::vector<glm::mat4> mv;
	short x = 0, y = 0, z = 0, pos = 0;
	short a[16][16][16] = { 0 };
	std::vector<short> text_ID;
	srand(glfwGetTime());
	while (x < 16)
	{
		while (z < 16)
		{
			while (y < 16)
			{
				switch (y)
				{
				case 13:
				case 14:
				case 15:
					a[x][y][z] = 0;
					break;
				default:
					a[x][y][z] = 1;
					break;
				}
				y++;
			}
			z++, y = 0;
		}
		x++, z = 0;
	}
	x = 0, y = 0, z = 0;
	while (x < 16)
	{
		while (z < 16)
		{
			while (y < 16)
			{
				if (a[x][y][z] >= 0)
				{
					mv.push_back(glm::translate(glm::mat4(), glm::vec3(x, y, z)));
					text_ID.push_back((short)(a[x][y][z]));
					num++;
				}

				y++;
			}
			z++, y = 0;
		}
		x++, z = 0;
	}
	std::cerr << a[15][15][15] << std::endl;

	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);



	glGenBuffers(1, &posInctanceVBO);
	glBindBuffer(GL_ARRAY_BUFFER, posInctanceVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::mat4) * mv.size(), mv.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(2, glm::vec4().length(), GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)0);
	glEnableVertexAttribArray(2);
	glVertexAttribDivisor(2, 1);

	glVertexAttribPointer(3, glm::vec4().length(), GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4)));
	glEnableVertexAttribArray(3);
	glVertexAttribDivisor(3, 1);

	glVertexAttribPointer(4, glm::vec4().length(), GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(2 * sizeof(glm::vec4)));
	glEnableVertexAttribArray(4);
	glVertexAttribDivisor(4, 1);

	glVertexAttribPointer(5, glm::vec4().length(), GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(3 * sizeof(glm::vec4)));
	glEnableVertexAttribArray(5);
	glVertexAttribDivisor(5, 1);


	glGenBuffers(1, &texInctanceVBO);
	glBindBuffer(GL_ARRAY_BUFFER, texInctanceVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(short) * text_ID.size(), text_ID.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(6, 1, GL_UNSIGNED_INT, GL_FALSE, sizeof(GLuint), (void*)0);
	glEnableVertexAttribArray(6);
	glVertexAttribDivisor(6, 1);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicat), indicat, GL_STATIC_DRAW);

	glBindVertexArray(NULL);
};

void GLinti(GLFWwindow*& window);
void FramebufferSize_callback(GLFWwindow*, int, int);
void Key_callback(GLFWwindow*, int, int, int, int);
void MouseButton_callback(GLFWwindow*, int, int, int);
void MousePosition_callback(GLFWwindow*, double, double);
void processInput(GLFWwindow*);


#define WIN_WIDTH 1080
#define WIN_HEIGHT 720
Camera c;
CubeModel m;
CubeModel m2;
float deltatime;



int main()
{
	GLFWwindow* window;
	GLinti(window);

	m = CubeModel("Shader_3.vs", "Shader_3.fs");
	m2 = CubeModel("Shader_3_textinctance.vs", "Shader_3_textinctance.fs");
	//i = Blocks("Shader_3_textinctance.vs", "Shader_3.fs");
	c = Camera(glm::vec3(0, 0, 20));
	TextureBuffer t("grass_top.png");
	//std::vector<std::string> pathvec = { "grass_top.png", "神必.jpg" };
	std::vector<std::string> pathvec;
	pathvec.push_back(std::string("grass_top.png"));
	pathvec.push_back(std::string("dirt.png"));
	TextureBuffer t2(pathvec);

	//char a[16 * 16 * 16] = { 0 };
	//for (size_t i = 0; i < 4096; i++)
	//{
	//	a[i] = 1;
	//}
	//i.blocksdata_update(a);
	glm::mat4 view = c.GetViewMatrix()
		, projection = glm::perspective(/*glm::radians(45.0f)*/45.0f, (float)WIN_WIDTH / (float)WIN_HEIGHT, 0.1f, 100.0f)
		, model = glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, 16.0f));

	float now, lastframetime;
	lastframetime = glfwGetTime();
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		processInput(window);

		m.useShaderProg();
		glBindVertexArray(m.getVAO());
		t.Enabletexture();
		view = c.GetViewMatrix();
		m.setMat4("view", glm::value_ptr(view));
		m.setMat4("projection", glm::value_ptr(projection));
		m.setMat4("model", glm::value_ptr(model));
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, NULL);
		t.Disabletexture();

		m2.useShaderProg();
		glBindVertexArray(m2.getVAO());
		t2.Enabletexture();
		view = c.GetViewMatrix();
		m2.setMat4("view", glm::value_ptr(view));
		m2.setMat4("projection", glm::value_ptr(projection));
		glDrawElementsInstanced(GL_TRIANGLES, 36, GL_UNSIGNED_INT, NULL, num);
		t2.Disabletexture();


		glfwSwapBuffers(window);
		now = glfwGetTime();
		deltatime = now - lastframetime;
		lastframetime = now;
		//std::cerr << 1 / deltatime << std::endl;
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
void GLinti(GLFWwindow*& window)
{
	glfwInit();
	glfwInitHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwInitHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwInitHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, " ", NULL, NULL);
	if (window == NULL)
	{
		std::cerr << "window" << std::endl;
		exit(-1);
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		exit(-1);
	}
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	glfwSetKeyCallback(window, Key_callback);
}
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);

	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		c.ProcessKeyboard(FORWARD, deltatime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		c.ProcessKeyboard(BACKWARD, deltatime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		c.ProcessKeyboard(LEFT, deltatime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		c.ProcessKeyboard(RIGHT, deltatime);
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		c.ProcessKeyboard(SHIFT, deltatime);
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		c.ProcessKeyboard(SPACE, deltatime);
	}

}
void FramebufferSize_callback(GLFWwindow* window, int width, int height)
{
	glfwSetWindowSize(window, width, height);
}
void Key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS || action == GLFW_REPEAT)
	{
		switch (key)
		{
		case GLFW_KEY_W:
			c.ProcessKeyboard(FORWARD, deltatime);
			break;
		case GLFW_KEY_S:
			c.ProcessKeyboard(BACKWARD, deltatime);
			break;
		case GLFW_KEY_A:
			c.ProcessKeyboard(LEFT, deltatime);
			break;
		case GLFW_KEY_D:
			c.ProcessKeyboard(RIGHT, deltatime);
			break;
		default:
			break;
		}
	}
}
void MouseButton_callback(GLFWwindow* window, int button, int action, int mods)
{

}
void MousePosition_callback(GLFWwindow* window, double xpos, double ypos)
{

}