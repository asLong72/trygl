//#include "glad/glad.h"
//#include "GLFW/glfw3.h"
//#include "iostream"
//#include "fstream"
//#include "strstream"
//#define STB_IMAGE_IMPLEMENTATION
////Ԥ���������޸�ͷ�ļ�������ֻ������صĺ�������Դ��
////�����ǽ����ͷ�ļ���Ϊһ�� .cpp �ļ���
////����ֻ��Ҫ����ĳ����а���stb_image.h������Ϳ�����
//#include "stb-master/stb_image.h"
//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//#include "glm/gtc/type_ptr.hpp"
//#include "Camera.h"
//#include "Shader.h"
//#include "math.h"
//
//
//class cubemodel :public Shader
//{
//public:
//	cubemodel();
//	cubemodel(std::string, std::string);
//	inline unsigned getVAO() { return VAO; };
//	inline unsigned getVBO() { return VBO; };
//	inline unsigned getEBO() { return EBO; };
//	~cubemodel() {};
//
//protected:
//	unsigned VAO;
//	unsigned VBO;
//	unsigned EBO;
//};
//void framebufferSize_callback(GLFWwindow*, int, int);
//void key_callback(GLFWwindow*, int, int, int, int);
////glfwSetMouseButtonCallback(window, mouseButton_callback);
//void mousePosition_callback(GLFWwindow*, double, double);
//
//
//cubemodel test;
//Camera c;
//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	GLFWwindow* window = glfwCreateWindow(1080, 720, "test", NULL, NULL);
//	while (window == NULL)
//	{
//		std::cout << "" << std::endl;
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		exit(-1);
//	}
//	glfwSetFramebufferSizeCallback(window, framebufferSize_callback);
//	glfwSetKeyCallback(window, key_callback);
//	//glfwSetMouseButtonCallback(window, mouseButton_callback);
//	glfwSetCursorPosCallback(window, mousePosition_callback);
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
//	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//
//	unsigned textureID;
//	glGenTextures(1, &textureID);
//	glBindTexture(GL_TEXTURE_2D, textureID);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
//	int width, height, nrChannels;
//	unsigned char* data;
//	data = stbi_load("375px-Mr._Quin.jpg", &width, &height, &nrChannels, 0);
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, nrChannels == 3 ? GL_RGB : GL_RGBA, width, height, 0, nrChannels == 3 ? GL_RGB : GL_RGBA, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "Failed to load texture" << std::endl;
//	}
//	stbi_image_free(data);					//�ͷ�ͼ����ڴ�
//
//	glBindVertexArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//	glBindTexture(GL_TEXTURE_2D, 0);
//
//	test = cubemodel("Shader_try.vs", "Shader.fs");
//	c = Camera(glm::vec3(0.0f, 0.0f, 4.0f));
//	glm::mat4 model = glm::translate(glm::mat4(), glm::vec3(0, 0, -1)), view, projection;
//	projection = glm::perspective(/*glm::radians(45.0f)*/45.0f, (float)1080 / (float)720, 0.1f, 100.0f);
//
//	while (!glfwWindowShouldClose(window))
//	{
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//
//
//		test.useShaderProg();
//		glBindVertexArray(test.getVAO());
//		glBindBuffer(GL_ARRAY_BUFFER, test.getVBO());
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, test.getEBO());
//		glBindTexture(GL_TEXTURE_2D, textureID);
//		test.setMat4("model", glm::value_ptr(model));
//		view = c.GetViewMatrix();
//		test.setMat4("view", glm::value_ptr(view));
//		test.setMat4("projection", glm::value_ptr(projection));
//
//		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
//		glBindVertexArray(NULL);
//		glBindTexture(GL_TEXTURE_2D, NULL);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//	glfwTerminate();
//	return 0;
//}
//
//cubemodel::cubemodel()
//{
//	progID = 0;
//	VAO = 0;
//	VBO = 0;
//	EBO = 0;
//}
//cubemodel::cubemodel(std::string vertexshader_path, std::string fragmentshader_path)
//{
//	float vertices[] = {
//		//����
//		1.0f,	0.0f,	0.0f,	0.0f,	0.0f,		//����
//		0.0f,	0.0f,	0.0f,	1.0f,	0.0f,		//����
//		0.0f,	1.0f,	0.0f,	1.0f,	1.0f,		//����
//		1.0f,	1.0f,	0.0f,	0.0f,	1.0f,		//����
//		//����
//		0.0f,	0.0f,	1.0f,	0.0f,	0.0f,		//����
//		1.0f,	0.0f,	1.0f,	1.0f,	0.0f,		//����
//		1.0f,	1.0f,	1.0f,	1.0f,	1.0f,		//����
//		0.0f,	1.0f,	1.0f,	0.0f,	1.0f,		//����
//		//����
//		0.0f,	0.0f,	0.0f,	0.0f,	0.0f,		//����
//		0.0f,	0.0f,	1.0f,	1.0f,	0.0f,		//����
//		0.0f,	1.0f,	1.0f,	1.0f,	1.0f,		//����
//		0.0f,	1.0f,	0.0f,	0.0f,	1.0f,		//����
//		//����
//		1.0f,	0.0f,	1.0f,	0.0f,	0.0f,		//����
//		1.0f,	0.0f,	0.0f,	1.0f,	0.0f,		//����
//		1.0f,	1.0f,	0.0f,	1.0f,	1.0f,		//����
//		1.0f,	1.0f,	1.0f,	0.0f,	1.0f,		//����
//		//����
//		0.0f,	1.0f,	1.0f,	0.0f,	0.0f,		//����
//		1.0f,	1.0f,	0.0f,	1.0f,	0.0f,		//����
//		1.0f,	1.0f,	0.0f,	1.0f,	1.0f,		//����
//		0.0f,	1.0f,	0.0f,	0.0f,	1.0f,		//����
//		//����
//		0.0f,	0.0f,	0.0f,	0.0f,	0.0f,		//����
//		1.0f,	0.0f,	0.0f,	1.0f,	0.0f,		//����
//		1.0f,	0.0f,	1.0f,	1.0f,	1.0f,		//����
//		0.0f,	0.0f,	1.0f,	0.0f,	1.0f,		//����
//	};
//	unsigned indicat[] =
//	{
//		//����
//		0,	1,	3,		//����
//		1,	2,	3,		//����
//		//����
//		0,	0,	0,		//����
//		0,	0,	0,		//����
//		//����
//		0,	0,	0,		//����
//		0,	0,	0,		//����
//		//����
//		0,	0,	0,		//����
//		0,	0,	0,		//����
//		//����
//		0,	0,	0,		//����
//		0,	0,	0,		//����
//		//����
//		0,	0,	0,		//����
//		0,	0,	0,		//����
//	};
//	this->progID = Shader(vertexshader_path, fragmentshader_path).getProgID();
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(VBO, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glGenBuffers(1, &EBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO);
//	glBufferData(EBO, sizeof(indicat), indicat, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	std::cout<< VAO<<"|" << VBO << "|" << EBO << "|"<<std::endl;
//	glBindVertexArray(NULL);
//	glUseProgram(NULL);
//}
//
//void framebufferSize_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
//{
//	if (action == GLFW_REPEAT || action == GLFW_PRESS)
//	{
//		switch (key)
//		{
//		case GLFW_KEY_W:
//
//			break;
//		case GLFW_KEY_S:
//
//			break;
//		case GLFW_KEY_A:
//
//			break;
//		case GLFW_KEY_D:
//
//			break;
//		case GLFW_KEY_SPACE:
//
//			break;
//		case GLFW_KEY_LEFT_SHIFT:
//
//			break;
//		default:
//			break;
//		}
//
//	}
//
//}
////glfwSetMouseButtonCallback(window, mouseButton_callback);
//void mousePosition_callback(GLFWwindow* window, double xpos, double ypos)
//{
//
//
//}