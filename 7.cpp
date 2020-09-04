//#include <windows.h>
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
//
//class SHADER
//{
//public:
//	SHADER(std::string, std::string);
//	//������ɫ������
//	inline void useShaderProg() { glUseProgram(progID); };
//	//uniform�����޸ķ���
//	template<typename in_type>
//	inline void set(std::string name, in_type value) { glUniform1f(glGetUniformLocation(progID, name.c_str()), (float)value); };
//	//��ɫ���ھ����޸ķ���
//	/*
//		glUniformMatrix4fv����
//		����һ������λ��
//		�������������봫�ľ����������������ֻ����һ����������1
//		�������������Ƿ���ת�����󣬰��к��н�����OpenGL�еľ�����������ľ��󣨺�DX�еĲ�ͬ��������GLM�����ɵľ���Ҳ��������ģ������������ó�GL_FALSE����ʾ����ת��
//		�����ģ������������ݡ���������Ҫ�Ѿ���ת��������ĸ�ʽ����
//	*/
//	inline void setMat4(std::string name, float value[]) { glUniformMatrix4fv(glGetUniformLocation(progID, name.c_str()), 1, GL_FALSE, value); };
//	//
//	inline unsigned getProgID() { return progID; };
//
//
//private:
//	unsigned progID;
//};
//
//void processInput(GLFWwindow*);
//void framebuffer_size_callback(GLFWwindow*, int, int);
//void GLinit(GLFWwindow**, std::string);
//
//const int WINDOW_HEIGHT = 720;
//const int WINDOW_WIDTH = 1280;
//
//float vertex[] =
//{
//	-0.5f,	0.5f,	0.0f,	0.0f,	0.0f,			//����
//	0.5f,	0.5f,	0.0f,	1.0f,	0.0f,			//����
//	-0.5f,	-0.5f,	0.0f,	0.0f,	1.0f,			//����
//	0.5f,	-0.5f,	0.0f,	1.0f,	1.0f,			//����
//};
//
//int indices[] =
//{
//	0,1,3,
//	0,2,3
//};
//
//int main()
//{
//	std::cerr << "��  ��  ��  ��" << std::endl;
//	Sleep(50);
//	//��ʼ��glfw��glad
//	GLFWwindow* window_ID;
//	GLinit(&window_ID, "Quin33");
//
//	unsigned VAO, VBO, EBO, TEXTURE;
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	//������������
//	glEnableVertexAttribArray(0);													//����ɫ�������е�Locationֵ�����
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(2);													//����ɫ�������е�Locationֵ�����
//
//	glGenBuffers(1, &EBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
///*
//OpenGLҪ�����е�������4�ֽڶ���ģ�������Ĵ�С��Զ��4�ֽڵı���
//ͨ���Ⲣ�������ʲô���⣬��Ϊ�󲿷�����Ŀ�ȶ�Ϊ4�ı�����/��ÿ����ʹ��4���ֽ�
//�������ͼƬ��jpg���ҿ�߲���4�ı��������Գ���������
//ͨ���������ѹ���������Ϊ1����������ȷ�������ж�������
//*/
//	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//	//���������
//	glGenTextures(1, &TEXTURE);														//����(������������������ID����/Ԫ�ص�ַ)
//	glBindTexture(GL_TEXTURE_2D, TEXTURE);
//	//�����������Ż���
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
//	/*
//	GL_NEAREST:��������
//			   ָ����������������ĸ����أ������ĸ�����
//			   ����OpenGLĬ�ϵĹ��˷�ʽ���ٶ���죬����Ч�����
//	GL_LINEAR:��˫�����Թ���
//			  ָ������������λ�ø����ļ�������ֵ����ĳ�ֲ�ֵ����֮��Ľ��
//			  ����Ӧ����㷺��һ�ַ�ʽ��Ч��һ�㣬�ٶȽϿ졣
//	*/
//
//	// ���ز���������
//	int width, height, nrChannels;
//	unsigned char* data = stbi_load("375px-Mr._Quin.jpg", &width, &height, &nrChannels, 0);
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, nrChannels == 3 ? GL_RGB :  GL_RGBA, width, height, 0, nrChannels == 3 ? GL_RGB : GL_RGBA, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "Failed to load texture" << std::endl;
//	}
//	stbi_image_free(data);					//�ͷ�ͼ����ڴ�
//
//	SHADER s("Shader.vs", "Shader.fs");
//	glm::mat4 trans;
//	trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));
//	trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
//	s.setMat4("transform", glm::value_ptr(trans));
//
//	framebuffer_size_callback(window_ID, WINDOW_WIDTH, WINDOW_HEIGHT);
//	while (!glfwWindowShouldClose(window_ID)) {
//		processInput(window_ID);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);			//����������ɫ
//														//����1������2������3
//														//����4��͸����
//		glClear(GL_COLOR_BUFFER_BIT);					//��������
//
//		//...
//		trans = glm::mat4();
//		trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));
//		trans = glm::rotate(trans, /*glm::radians(0.0f)*/(float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
//		s.setMat4("transform", glm::value_ptr(trans));
//		s.useShaderProg();
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//		glfwSwapBuffers(window_ID);						//����ʾ������������潻��( ��ʾ���������е����� )��˫���湦�ܣ�����ǰ�����ݻ���ʹ����ˢ��ͬ��
//		glfwPollEvents();								//����Ƿ����¼�����( �����������ͼ��������¼�)
//	}
//	glfwTerminate();									//��ֹ��ͼ���ڽ���
//	return 0;
//}
//
//void GLinit(GLFWwindow** window_ID, std::string windowsName = std::string())
//{
//	//��ʼ��glfw
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	*window_ID = glfwCreateWindow(WINDOW_WIDTH,WINDOW_HEIGHT , windowsName.c_str(), NULL, NULL);
//	while (*window_ID == NULL)
//	{
//		exit(-1);
//	}
//	glfwMakeContextCurrent(*window_ID);										//
//	glfwSetFramebufferSizeCallback(*window_ID, framebuffer_size_callback);	//
//
//	//��ʼ��glad
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		exit(-1);
//	}
//}
//
//
//SHADER::SHADER(std::string vertexPath_in, std::string fragmentPath_in)
//{
//	//1
//	//���ļ��ж�ȡ������ɫ�����룬�����ַ����������ַ�����
//	std::string vertexCode_str;
//	std::ifstream vertexCode_fstream;
//	std::strstream vertexCode_strstream;
//
//	try
//	{
//		vertexCode_fstream.open(vertexPath_in);
//		vertexCode_strstream << vertexCode_fstream.rdbuf() << std::ends;
//		vertexCode_str = vertexCode_strstream.str();
//		vertexCode_fstream.close();
//	}
//	catch (const std::exception&)
//	{
//		std::cerr << vertexPath_in << "error!" << std::endl;;
//	}
//
//	//���ļ��ж�ȡƬԪ��ɫ�����룬�����ַ����������ַ�����
//	std::string fragmentCode_str;
//	std::ifstream fragmentCode_fstream;
//	std::strstream fragmentCode_strstream;
//
//	try
//	{
//		fragmentCode_fstream.open(fragmentPath_in);
//		fragmentCode_strstream << fragmentCode_fstream.rdbuf() << std::ends;
//		fragmentCode_str = fragmentCode_strstream.str();
//		fragmentCode_fstream.close();
//	}
//	catch (const std::exception&)
//	{
//		std::cerr << fragmentPath_in << "error!" << std::endl;;
//	}
//
//	//2
//	int success;
//	char infolog[512];
//	//���붥����ɫ��
//	const char* vertexCode_c_str = vertexCode_str.c_str();
//	unsigned vertex_ID = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertex_ID, 1, &vertexCode_c_str, NULL);
//	glCompileShader(vertex_ID);
//	glGetShaderiv(vertex_ID, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(vertex_ID, sizeof(infolog), NULL, infolog);
//		std::cerr << " " << infolog << std::endl;
//	}
//	//����ƬԪ��ɫ��
//	const char* fragmentCode_c_str = fragmentCode_str.c_str();
//	unsigned fragment_ID = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragment_ID, 1, &fragmentCode_c_str, NULL);
//	glCompileShader(fragment_ID);
//	glGetShaderiv(fragment_ID, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(fragment_ID, sizeof(infolog), NULL, infolog);
//		std::cerr << " " << infolog << std::endl;
//	}
//	//������ɫ������
//	progID = glCreateProgram();
//	glAttachShader(progID, vertex_ID);
//	glAttachShader(progID, fragment_ID);
//	glLinkProgram(progID);
//	glGetProgramiv(progID, GL_LINK_STATUS, &success);			//�����ɫ�������Ƿ����ӳɹ�
//	if (!success)
//	{
//		glGetProgramInfoLog(progID, 512, NULL, infolog);
//		std::cerr << " " << infolog << std::endl;
//	}
//	//ɾ����ɫ������
//	glDeleteShader(vertex_ID);
//	glDeleteShader(fragment_ID);
//}
//
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}