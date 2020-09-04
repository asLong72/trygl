/////*元素缓存对象*/
//
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//
//void processInput(GLFWwindow* window);
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//
//const char* vertexShader_Source = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\0";
//const char* fragmentShader_Source = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}\n\0";
//const int WINDOW_HEIGHT = 1280;
//const int WINDOW_WIDTH = 720;
//
////顶点数组
//float rectVertices[] =
//{
//0.5f, 0.5f, 0.0f,   //右上角
//0.5f, -0.5f, 0.0f,  //右下角
//-0.5f, -0.5f, 0.0f, //左下角
//-0.5f, 0.5f, 0.0f   //左上角
//};
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
//	//初始化glfw
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	GLFWwindow* window_ID = glfwCreateWindow(WINDOW_HEIGHT, WINDOW_WIDTH, " ", NULL, NULL);
//	while (window_ID == NULL)
//	{
//		;
//		return -1;
//	}
//	glfwMakeContextCurrent(window_ID);
//	glfwSetFramebufferSizeCallback(window_ID, framebuffer_size_callback);
//	//初始化glad
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	//初始化顶点着色器
//	unsigned vertexShader_ID = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader_ID, 1, &vertexShader_Source, NULL);		//赋予着色器代码和地址
//	glCompileShader(vertexShader_ID);
//	//初始化片元着色器
//	unsigned fragmentShader_ID = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader_ID, 1, &fragmentShader_Source, NULL);	//赋予着色器代码和地址
//	glCompileShader(fragmentShader_ID);
//	//初始化着色器程序
//	unsigned Shader_programe_ID = glCreateProgram();
//	glAttachShader(Shader_programe_ID, vertexShader_ID);				//glAttachShader(着色器程序ID,着色器ID)
//	glAttachShader(Shader_programe_ID, fragmentShader_ID);
//	glLinkProgram(Shader_programe_ID);
//
//	//释放着色器地址
//	glDeleteShader(vertexShader_ID);
//	glDeleteShader(fragmentShader_ID);
//
//	unsigned VBO, VAO, EBO;
//
//	glGenVertexArrays(1, &VAO);											//
//	glBindVertexArray(VAO);
//
//	glGenBuffers(1, &VBO);												//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	//将顶点数据传到VBO
//	glBufferData(GL_ARRAY_BUFFER, sizeof(rectVertices), rectVertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glGenBuffers(1, &EBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);				//绑定EBO
//															//注意与VBO区分：
//															//绑定VBO用的参数是GL_ARRAY_BUFFER，绑定EBO需要的是GL_ELEMENT_ARRAY_BUFFER，如下所示：
//															//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	//同样，EBO还是使用glBufferData
//	//不过复制的时候需要指明是EBO，所以，要用GL_ELEMENT_ARRAY_BUFFER参数，像这样：
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//
//
//	//framebuffer_size_callback(window_ID, 1280, 720);
//	char a = '\n';
//	while (!glfwWindowShouldClose(window_ID))
//	{
//		processInput(window_ID);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);			//设置清屏颜色
//														//参数1，参数2，参数3
//														//参数4:不透明度
//		glClear(GL_COLOR_BUFFER_BIT);					//清屏函数
//
//		do
//		{
//			a = getchar();
//		} while (a == '\n');
//
//		if (a == ' ')
//		{
//			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);				//以线框模式(Wireframe Mode)绘制图形
//																	//第一个参数"GL_FRONT_AND_BACK"表示我们打算将其应用到所有的三角形的正面和背面
//																	//第二个参数"GL_LINE"告诉我们用线来绘制
//		}
//		else
//		{
//			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);				//设置回默认模式
//		}
//
//		glUseProgram(Shader_programe_ID);							//
//
//		//绘制
//
//		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//		glBindVertexArray(VAO);
//		//（绘制VBO使用glDrawArrays函数，绘制EBO就要使用glDrawElements函数
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//
//		glfwSwapBuffers(window_ID);						//将显示缓存和离屏缓存交换( 显示离屏缓存中的内容 )；双缓存功能：交换前后两份缓存使画面刷新同步
//		glfwPollEvents();								//检查是否有事件触发( 例如鼠标输入和键盘输入事件)
//	}
//
//	glfwTerminate();									//终止绘图窗口进程
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