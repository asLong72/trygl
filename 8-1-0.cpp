//#include "glad/glad.h"
//#include "GLFW/glfw3.h"
//#include "iostream"
//#include "fstream"
//#include "strstream"
//#define STB_IMAGE_IMPLEMENTATION
////预处理器会修改头文件，让其只包含相关的函数定义源码
////等于是将这个头文件变为一个 .cpp 文件了
////现在只需要在你的程序中包含stb_image.h并编译就可以了
//#include "stb-master/stb_image.h"
//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//#include "glm/gtc/type_ptr.hpp"
//
//class SHADER
//{
//public:
//	SHADER(std::string, std::string);
//	inline void useShaderProg() { glUseProgram(progID); };
//	template<typename in_type>
//	inline void set(std::string name, in_type value) { glUniform1f(glGetUniformLocation(progID, name.c_str()), (float)value); };
//	inline void setMat4(std::string name, float value[]) { glUniformMatrix4fv(glGetUniformLocation(progID, name.c_str()), 1, GL_FALSE, value); };
//	inline unsigned getProgID() { return progID; };
//
//private:
//	unsigned progID;
//};
//
//void processInput(GLFWwindow*);
//void framebuffer_size_callback(GLFWwindow*, int, int);
//
//// 设置
//const unsigned int SCR_WIDTH = 1280;
//const unsigned int SCR_HEIGHT = 720;
//
//float factor = 0.2f;
////
////float vertices[] = {
////	//位置					// 颜色					//纹理坐标
////	0.5f,	0.5f,	0.0f,	1.0f,	0.0f,	0.0f,	1.0f,	1.0f,	//右上角
////	0.5f,	-0.5f,	0.0f,	0.0f,	1.0f,	0.0f,	1.0f,	0.0f,	//右下角
////	-0.5f,	-0.5f,	0.0f,	0.0f,	0.0f,	1.0f,	0.0f,	0.0f,	//左下角
////	-0.5f,	0.5f,	0.0f,	1.0f,	1.0f,	0.0f,	0.0f,	1.0f	//左上角
////
////};
////
////unsigned int indices[] = {
////	0, 1, 3,		//第一个三角形
////	1, 2, 3			//第二个三角形
////};
//
//float vertices[] = {
//	-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
//	0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
//	0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
//	0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
//	-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
//
//	-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
//	0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
//	0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
//	0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
//	-0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
//	-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
//
//	-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//	-0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//	-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
//	-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//
//	0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//	0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
//	0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//	0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//	0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
//	0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//
//	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//	0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
//	0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
//	0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
//	-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
//	-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//
//	-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
//	0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
//	0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//	0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//	-0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
//	-0.5f, 0.5f, -0.5f, 0.0f, 1.0f
//};
//
//int main() {
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//	if (window == NULL) {
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	//获取最大属性数量
//	int nrAttributes;
//	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
//	std::cout << "最大支持的属性数量为：" << nrAttributes << std::endl;
//
//	glEnable(GL_DEPTH_TEST);
//
//	//！创建我们的着色器
//	SHADER shader("Shader3D.vs", "Shader-8.fs");
//
//	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//	//第一个环境
//	unsigned int VBO, VAO;
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//	//unsigned int EBO;
//	//glGenBuffers(1, &EBO);
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	//纹理1
//	unsigned int texture;
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture);
//	//设置纹理包装和过滤的方式
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	int width, height, nrChannels;
//	stbi_set_flip_vertically_on_load(true);
//	unsigned char* data = stbi_load(/*"zhou_yu.bmp"*/"grass_top.png", &width, &height, &nrChannels, 0);
//	if (data) {
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//		std::cout << "无法加载问题，请检查代码或资源是否有误。" << std::endl;
//	stbi_image_free(data);
//
//	//变换
//	//glm::mat4 trans;
//	//trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));
//	//trans = glm::rotate(trans, /*glm::radians(90.0f)*/(float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
//
//	glm::mat4 view;
//	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -4.0f));
//
//	glm::mat4 projection;
//	projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//
//
//	while (!glfwWindowShouldClose(window)) {
//		processInput(window);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture);
//
//		shader.useShaderProg();
//
//		glm::mat4 model;
//		model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
//
//
//		shader.setMat4("model", glm::value_ptr(model));
//		shader.setMat4("view", glm::value_ptr(view));
//		shader.setMat4("projection", glm::value_ptr(projection));
//
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glBindVertexArray(0);
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glfwTerminate();
//	return 0;
//}
//
//SHADER::SHADER(std::string vertexPath_in, std::string fragmentPath_in)
//{
//	//1
//	//从文件中读取顶点着色器代码，并经字符串流存入字符串中
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
//	//从文件中读取片元着色器代码，并经字符串流存入字符串中
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
//	//编译顶点着色器
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
//	//编译片元着色器
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
//	//链接着色器程序
//	progID = glCreateProgram();
//	glAttachShader(progID, vertex_ID);
//	glAttachShader(progID, fragment_ID);
//	glLinkProgram(progID);
//	glGetProgramiv(progID, GL_LINK_STATUS, &success);			//检查着色器程序是否链接成功
//	if (!success)
//	{
//		glGetProgramInfoLog(progID, 512, NULL, infolog);
//		std::cerr << " " << infolog << std::endl;
//	}
//	//删除着色器程序
//	glDeleteShader(vertex_ID);
//	glDeleteShader(fragment_ID);
//}
//
//void processInput(GLFWwindow* window) {
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//
//	//if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
//	//	factor += 0.01f;
//	//	if (factor > 1.0f)
//	//		factor = 1.0f;
//	//}
//
//	//if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
//	//	factor -= 0.01f;
//	//	if (factor < 0.0f)
//	//		factor = 0.0f;
//	//}
//
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//	glViewport(0, 0, width, height);
//}
