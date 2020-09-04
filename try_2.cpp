#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "iostream"
#include "fstream"
#include "strstream"
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
	TextureBuffer() { TexeturreID = 0; };
	TextureBuffer(std::string);
	inline void Enabletexture() { glBindTexture(GL_TEXTURE_2D, TexeturreID); };
	inline void Disabletexture() { glBindTexture(GL_TEXTURE_2D, NULL); };
	~TextureBuffer() { };

private:
	unsigned TexeturreID;
};
TextureBuffer::TextureBuffer(std::string Texture_path)
{
	glGenTextures(1, &this->TexeturreID);
	glBindTexture(GL_TEXTURE_2D, this->TexeturreID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	int width, height, nrChannels;
	unsigned char* data = stbi_load(Texture_path.c_str(), &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, nrChannels == 3 ? GL_RGB : GL_RGBA, width, height, 0, nrChannels == 3 ? GL_RGB : GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cerr << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
	glBindTexture(GL_TEXTURE_2D, NULL);
}

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
};
CubeModel::CubeModel()
{
	progID = 0;
	VAO = 0;
	VBO = 0;
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
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicat), indicat, GL_STATIC_DRAW);
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
float deltatime;

int main()
{
	GLFWwindow* window;
	GLinti(window);
	m = CubeModel("Shader_try.vs", "Shader.fs");
	c = Camera(glm::vec3(0, 0, 4));
	TextureBuffer t("grass_top.png");

	glm::mat4 model(glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, 0.0f))), view = c.GetViewMatrix(), projection = glm::perspective(/*glm::radians(45.0f)*/45.0f, (float)WIN_WIDTH / (float)WIN_HEIGHT, 0.1f, 100.0f);

	float now, lastframetime;
	lastframetime = glfwGetTime();
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		processInput(window);

		m.useShaderProg();
		glBindVertexArray(m.getVAO());
		t.Enabletexture();
		m.setMat4("model", glm::value_ptr(model));
		view = c.GetViewMatrix();
		m.setMat4("view", glm::value_ptr(view)); 
		m.setMat4("projection", glm::value_ptr(projection));
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, NULL);
		t.Disabletexture();

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