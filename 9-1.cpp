//#include "glad/glad.h"
//#include "GLFW/glfw3.h"
//#include "iostream"
//#include "fstream"
//#include "strstream"
//#define STB_IMAGE_IMPLEMENTATION
///*
//预处理器会修改头文件，让其只包含相关的函数定义源码
//等于是将这个头文件变为一个 .cpp 文件了
//现在只需要在你的程序中包含stb_image.h并编译就可以了
//*/
//#include "stb-master/stb_image.h"
//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//#include "glm/gtc/type_ptr.hpp"
//
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
//void GLinit(GLFWwindow**, std::string);
//
//const int WINDOW_HEIGHT = 720;
//const int WINDOW_WIDTH = 1280;
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
////索引数组
//unsigned indices[] =
//{
//0, 1, 3,    //第一个三角形
//1, 2, 3 //第二个三角形
//};
//
//
//int main()
//{
//	//初始化glfw和glad
//	GLFWwindow* window_ID;
//	GLinit(&window_ID, "GrassCube");
//
//	SHADER s("Shader3D.vs", "Shader.fs");
//
//	unsigned VAO, VBO, EBO, TEXTURE;
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//	/*
//	glGenBuffers(1, &EBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//	*/
//
//	glGenTextures(1, &TEXTURE);
//	glBindTexture(GL_TEXTURE_2D, TEXTURE);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//
//	int width, height, nrChannels;
//	unsigned char* data = stbi_load("grass_top.png", &width, &height, &nrChannels, 0);
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, nrChannels == 3 ? GL_RGB : GL_RGBA, width, height, 0, nrChannels == 3 ? GL_RGB : GL_RGBA, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "Failed to load texture" << std::endl;
//	}
//	stbi_image_free(data);					//释放图像的内存
//	glActiveTexture(GL_TEXTURE0);
//
//
//	//机位设置
//	//相机位置的位置向量
//	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 4.0f);
//
//	//光线方向向量，相机朝向的反方向向量（即射入相机的光线向量）
//	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
//	glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
//
//	//相机右轴（right），表示坐标系统中的x轴正方向（用相机位置向量叉乘上向量(Up Vector，即世界空间Y轴)可得）
//	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
//	glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
//
//	//相机上轴（up），表示与相机的XZ对应的y轴正方向的向量（用相机Z轴向量叉乘相机X轴向量可得）
//	glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);
//
//
//	//观察矩阵
//	glm::mat4 view;
//	//调用glm已经帮我们封装好了的lookAt函数，直接获取到观察变换矩阵
//	//例如：
//	view = glm::lookAt(glm::vec3(0.0f, 0.0f, 4.0f),
//		glm::vec3(0.0f, 0.0f, 0.0f),
//		glm::vec3(0.0f, 1.0f, 0.0f));
//	//参数1：一个摄像机位置
//	//参数2：一个目标位置
//	//参数3：一个表示世界空间中的上向量的向量（我们计算右向量使用的那个上向量）
//
//	//模型变换矩阵
//	glm::mat4 model;
//
//	//投影变换矩阵/透视矩阵
//	//glm更新后，透视矩阵传递一个角度就行了不用弧度
//	glm::mat4 projection;
//	projection = glm::perspective(/*glm::radians(45.0f)*/45.0f, (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 100.0f);
//
//
//	//让相机在世界空间XOZ面上半径为10圆上旋转
//	float radius = 10.0f;
//	float camX = sin(glfwGetTime()) * radius;
//	float camZ = cos(glfwGetTime()) * radius;
//
//	framebuffer_size_callback(window_ID, 1280, 720);
//	while (!glfwWindowShouldClose(window_ID)) {
//		processInput(window_ID);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);			//设置清屏颜色
//														//参数1，参数2，参数3
//														//参数4不透明度
//		//绘制前，必须调用清除函数（清屏）
//		//清除颜色缓存
//		//glClear(GL_COLOR_BUFFER_BIT);		
//		//清除深度缓存
//		//glClear( GL_DEPTH_BUFFER_BIT);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		//...
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, TEXTURE);
//		s.useShaderProg();
//
//
//		//
//		camX = sin(glfwGetTime()) * radius;
//		camZ = cos(glfwGetTime()) * radius;
//		view = glm::lookAt(glm::vec3(camX, 0.0f, camZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//		model = glm::rotate(glm::mat4(), /*(float)glfwGetTime()*  */glm::radians(0.0f), glm::vec3(0.5f, 1.0f, 0.0f));
//		s.setMat4("model", glm::value_ptr(model));
//		s.setMat4("view", glm::value_ptr(view));
//		s.setMat4("projection", glm::value_ptr(projection));
//
//
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		glfwSwapBuffers(window_ID);						//将显示缓存和离屏缓存交换( 显示离屏缓存中的内容 )；双缓存功能：交换前后两份缓存使画面刷新同步
//		glfwPollEvents();								//检查是否有事件触发( 例如鼠标输入和键盘输入事件)
//	}
//	glfwTerminate();									//终止绘图窗口进程
//	return 0;
//}
//
//void GLinit(GLFWwindow** window_ID, std::string windowsName = std::string())
//{
//	//初始化glfw
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	*window_ID = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, windowsName.c_str(), NULL, NULL);
//	while (*window_ID == NULL)
//	{
//		exit(-1);
//	}
//	glfwMakeContextCurrent(*window_ID);										//
//	glfwSetFramebufferSizeCallback(*window_ID, framebuffer_size_callback);	//
//
//	//初始化glad
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		exit(-1);
//	}
//	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//	glEnable(GL_DEPTH_TEST);
//}
//
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