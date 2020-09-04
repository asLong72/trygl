//#include "glad/glad.h"
//#include "GLFW/glfw3.h"
//#include "iostream"
//#include "fstream"
//#include "strstream"
//#include "glm/glm.hpp"
//#define STB_IMAGE_IMPLEMENTATION
////预处理器会修改头文件，让其只包含相关的函数定义源码
////等于是将这个头文件变为一个 .cpp 文件了
////现在只需要在你的程序中包含stb_image.h并编译就可以了
//#include "stb-master/stb_image.h"
//
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
//
////关联贴图之后的顶点数组数据
////因此顶点坐标偏移量不再是3个元素（上一个顶点的xyz）了，还会包括上一个顶点的其他信息
//float vertices[] = {
//	//位置                  // 颜色                 //纹理坐标（相对）
//	0.5f,   0.5f,   0.0f,   1.0f,   0.0f,   0.0f,   1.0f,   0.0f,   //右上角
//	0.5f,   -0.5f,  0.0f,   0.0f,   1.0f,   0.0f,   1.0f,   1.0f,   //右下角
//	-0.5f,  -0.5f,  0.0f,   0.0f,   0.0f,   1.0f,   0.0f,   1.0f,   //左下角
//	-0.5f,  0.5f,   0.0f,   1.0f,   1.0f,   0.0f,   0.0f,   0.0f    //左上角
//
//};
//
//int indices[] =
//{
//	0,1,3,
//	1,2,3
//};
//
//int main()
//{
//	//初始化glfw和glad
//	GLFWwindow* window_ID;
//	GLinit(&window_ID, "test");
//
//	SHADER s("Shader.vs", "Shader.fs");
//
//	unsigned VAO, VBO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//	glGenBuffers(1, &EBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	/*
//		OpenGL要求所有的纹理都是4字节对齐的，即纹理的大小永远是4字节的倍数
//		通常这并不会出现什么问题，因为大部分纹理的宽度都为4的倍数并/或每像素使用4个字节
//		但是这个图片是jpg并且宽高不是4的倍数，所以出现了问题
//		通过将纹理解压对齐参数设为1，这样才能确保不会有对齐问题
//	*/
//	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//
//	//纹理缓存对象
//	unsigned int texture;
//	glGenTextures(1, &texture);										//函数(输入纹理数量，纹理ID数组/元素地址)
//	glBindTexture(GL_TEXTURE_2D, texture);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	// 加载并生成纹理
//	int width, height, nrChannels;
//	unsigned char* data = stbi_load("375px-Mr._Quin.jpg", &width, &height, &nrChannels, 0);
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "Failed to load texture" << std::endl;
//	}
//	stbi_image_free(data);					//释放图像的内存
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
//		s.useShaderProg();
//		glBindTexture(GL_TEXTURE_2D, texture);
//		glBindVertexArray(VAO);
//		//glm::mat4 transform = glm::mat4();
//		//transform=glm::transform
//		//s.set("transform", glm::value_ptr(transform));
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//		glfwSwapBuffers(window_ID);						//将显示缓存和离屏缓存交换( 显示离屏缓存中的内容 )；双缓存功能：交换前后两份缓存使画面刷新同步
//		glfwPollEvents();								//检查是否有事件触发( 例如鼠标输入和键盘输入事件)
//	}
//	glfwTerminate();									//终止绘图窗口进程
//	return 0;
//}
//
//
//void texfun1()
//{
//	//设置纹理环绕方式(可选用参数如下)
//	//GL_REPEAT：			默认方案，重复纹理图片。
//	//GL_MIRRORED_REPEAT：	类似于默认方案，不过每次重复的时候进行镜像重复(关于对称轴镜像)
//	//GL_CLAMP_TP_EDGE：	将坐标限制在0到1之间。超出的坐标会重复绘制边缘的像素，变成一种扩展边缘的图案（通常很难看）
//	//GL_CLAMP_TO_BORDER：	超出的坐标将会被绘制成用户指定的边界颜色
//	//						想要指定边界颜色，就需要使用glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor)
//	//						参数1	贴图类型
//	//						参数2	相关操作
//	//						参数3	颜色参数数组名
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);    //横坐标
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);    //纵坐标
//
//}
//
//void texfun2()
//{
//	//参数2	
//	//GL_NEAREST	最近点过滤		 指的是纹理坐标最靠近哪个纹素，就用哪个纹素。这是OpenGL默认的过滤方式，速度最快，但是效果最差
//	//GL_LINEAR		(双)线性过滤	 指的是纹理坐标位置附近的几个纹素值进行某种插值计算之后的结果。这是应用最广泛的一种方式，效果一般，速度较快
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);  //缩小时的过滤方式
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	//放大时的过滤方式（GL_TEXTURE_MAG_FILTER）
//}
//
//void Mipmaps()
//{
//	//多级渐进纹理
//	//参数		  
//	glGenerateMipmap(GL_TEXTURE_2D);
//	/*
//		使用不同分辨率贴图时的顶点着色优先方案（如下可选参数）
//		GL_NEAREST_MIPMAP_NEAREST	采用最近的mipmap图，在纹理采样的时候使用最近点过滤采样
//		GL_LINEAR_MIPMAP_NEAREST	采用最近的mipmap图，纹理采样的时候使用线性过滤采样
//		GL_NEAREST_MIPMAP_LINEAR	采用两张mipmap图的线性插值纹理图，纹理采样的时候采用最近点过滤采样
//		GL_LINEAR_MIPMAP_LINEAR		采用两张mipmap图的线性插值纹理图，纹理采样的时候采用线性过滤采样
//	*/
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);	 //都是线性过滤
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);				 //放大时（GL_TEXTURE_MAG_FILTER）
//}
//
//void stb_funs()
//{
//	//加载图片，并且将图片格式信息保存起来（长，宽，颜色通道数量,）
//	int width, height, nrChannels;
//	unsigned char* data = stbi_load("375px-Mr._Quin.jpg", &width, &height, &nrChannels, 0);
//
//
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
//
//void GLinit(GLFWwindow** window_ID, std::string windowsName = std::string())
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
