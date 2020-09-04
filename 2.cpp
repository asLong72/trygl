//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//
//
//void processInput(GLFWwindow* window);
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//
//int main()
//{
//	//!初始化glfw窗口
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //指定OpenGL的主版本号
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //指定OpenGL的子版本号
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //使用OpenGL的核心模式(可编程渲染管道的模式)
//																   //告诉glfw使用的是核心模式，即只能使用opengl功能的一个子集，不需要3.3之后版本的兼容功能。
//
//	GLFWwindow* window = glfwCreateWindow(1280, 720, "Learn0penGL", NULL, NULL); //创建窗口
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate(); //如果出错， 则终止进程
//		return -1;
//	}
//
//	glfwMakeContextCurrent(window);											//将窗口的上下文环境设置为当前主线程的上下文环境
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);		//
//	//!初始化glad
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//
//	float tryanglepoints[] =												//屏幕中心点为原点，值为到原点屏幕边缘的比例？
//	{
//		-0.5f,-0.5f,0.0f,
//		0.5f,-0.5f,0.0f,
//		0.0f,0.5f,0.0f,
//	};
//
//
//	const char* vertexSHADER_SOURCE = "#version 330 core\n"
//		"layout (location = 0) in vec3 aPos;\n"
//		"void main()\n"
//		"{\n"
//		"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//		"}\0";	//千万别忘记这个\0
//	unsigned vertexSHADER_ID = glCreateShader(GL_VERTEX_SHADER);			//vertex三角形顶点
//	glShaderSource(vertexSHADER_ID, 1, &vertexSHADER_SOURCE, NULL);
//	glCompileShader(vertexSHADER_ID);
//
//
//	const char* fragmentSHADER_SOURCE = "#version 330 core\n"
//		"out vec4 FragColor;\n"
//		"void main()\n"
//		"{\n"
//		"	FragColor = vec4(1.0f, 0.5f, 0.2f, 0.2f);\n"
//		"}\0";	//千万别忘记这个\0
//	unsigned fragmentSHADER_ID = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentSHADER_ID, 1, &fragmentSHADER_SOURCE, NULL);
//	glCompileShader(fragmentSHADER_ID);
//
//	unsigned SHADER_PROGRAM_ID = glCreateProgram();
//	glAttachShader(SHADER_PROGRAM_ID,vertexSHADER_ID );						//glAttachShader(着色器程序ID,着色器ID)
//	glAttachShader(SHADER_PROGRAM_ID,fragmentSHADER_ID );
//	glLinkProgram(SHADER_PROGRAM_ID);
//
//
//	glDeleteShader(vertexSHADER_ID);
//	glDeleteShader(fragmentSHADER_ID);
//
//	unsigned VBO, VAO;
//
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//
//	glGenBuffers(1, &VBO);						//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);			//
//
//
//	//将顶点数据传到VBO
//	glBufferData(GL_ARRAY_BUFFER, sizeof(tryanglepoints), tryanglepoints, GL_STATIC_DRAW);
//	//参数1：我们的顶点数据需要拷贝到的地方。（之前我们绑定的VBO）
//	//参数2：数组的大小
//	//参数3：数组的地址
//	//参数4：指定显卡要采用什么方式来管理我们的数据，GL_STATIC_DRAW表示这些数据不会经常改变。
//
//
//	//我们获取的顶点属性是由VBO决定的
//	//而glVertexAttribPointer操作的是当前绑定到GL_ARRAY_BUFFER上的VBO
//	//所以，我们当前操作的就是我们之前生成并绑定的那个VBO
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	//	参数1：指明我们想要配置的顶点属性。类似编号的东西，之前我们设置了location = 0，就是我们在这里用到的0.
//	//	参数2：顶点属性的大小。我们用到的顶点是一个vec3的结果，所以大小为3.
//	//	参数3：数据的类型。我们使用的是float类型
//	//	参数4：指明数据是否要被规范化。这里我们设置成FALSE，不用规范化，因为我们已经规范化好了。
//	//	参数5：表示属性的跨度。正如之前我们分析的，我们的跨度是12，就是3倍的float类型。
//	//	参数6：指明了数据的起始偏移量。这里转成了一个void * 指针类型比较奇怪，我们以后再聊
//	glEnableVertexAttribArray(0);					//用来让顶点属性生效的，参数0就是我们之前配置的那个顶点属性的位置
//
//	glDrawArrays(GL_TRIANGLES, 0, 3);
//
//
//	framebuffer_size_callback(window, 1280, 720);
//	while (!glfwWindowShouldClose(window)) {
//		processInput(window);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glUseProgram(SHADER_PROGRAM_ID);
//
//
//		//这里是一个习惯，上面的操作把属性都保存到了VAO中，这里只需要绑定就可以
//		//如果要显示的东西不同，也只需要在这里绑定不同的东西就可以显示
//
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glDeleteBuffers(1, &VBO);
//	glfwTerminate();
//	return 0;
//}
//
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