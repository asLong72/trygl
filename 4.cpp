//#include <iostream>
//#include <fstream>
//#include <strstream>
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
///*
//
//*/
//class SHADER
//{
//public:
//	SHADER(std::string, std::string);
//	inline void useShaderProg() { glUseProgram(progID); };
//	template<typename in_type>
//	inline void set(std::string name, in_type value) { glUniform1f(glGetUniformLocation(progID, name.c_str()), (float)value); };
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
//const int WINDOW_HEIGHT = 1280;
//const int WINDOW_WIDTH = 720;
//float rectVertices[] = {
//	0.5f, 0.5f, 0.0f,		//右上角
//	0.5f, -0.5f, 0.0f,		//右下角
//	-0.5f, -0.5f, 0.0f,		//左下角
//	-0.5f, 0.5f, 0.0f		//左上角
//};
//
//unsigned int indices[] = {
//	0, 1, 3,				//第一个三角形
//	1, 2, 3					//第二个三角形
//};
//
//int main()
//{
//	GLFWwindow* window_ID;
//	GLinit(&window_ID, "test");
//
//	SHADER atry("Shader4.vs", "Shader.fs");
//
//	unsigned VAO, VBO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, /*sizeof(vertices)*/sizeof(rectVertices), /*vertices*/rectVertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glGenBuffers(1, &EBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//
//	framebuffer_size_callback(window_ID, 1280, 720);
//	while (!glfwWindowShouldClose(window_ID)) {
//		processInput(window_ID);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);			//设置清屏颜色
//														//参数1，参数2，参数3
//														//参数4不透明度
//		glClear(GL_COLOR_BUFFER_BIT);					//清屏函数
//
//		//...
//		atry.useShaderProg();
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//		glfwSwapBuffers(window_ID);						//将显示缓存和离屏缓存交换( 显示离屏缓存中的内容 )；双缓存功能：交换前后两份缓存使画面刷新同步
//		glfwPollEvents();								//检查是否有事件触发( 例如鼠标输入和键盘输入事件)
//	}
//	glfwTerminate();									//终止绘图窗口进程
//	return 0;
//}
//
//void GLinit(GLFWwindow** window_ID, std::string windowsName=std::string())
//{
//	//初始化glfw
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	*window_ID = glfwCreateWindow(WINDOW_HEIGHT, WINDOW_WIDTH, windowsName.c_str(), NULL, NULL);
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