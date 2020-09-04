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
//	//!��ʼ��glfw����
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //ָ��OpenGL�����汾��
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //ָ��OpenGL���Ӱ汾��
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //ʹ��OpenGL�ĺ���ģʽ(�ɱ����Ⱦ�ܵ���ģʽ)
//																   //����glfwʹ�õ��Ǻ���ģʽ����ֻ��ʹ��opengl���ܵ�һ���Ӽ�������Ҫ3.3֮��汾�ļ��ݹ��ܡ�
//
//	GLFWwindow* window = glfwCreateWindow(1280, 720, "Learn0penGL", NULL, NULL); //��������
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate(); //������� ����ֹ����
//		return -1;
//	}
//
//	glfwMakeContextCurrent(window);											//�����ڵ������Ļ�������Ϊ��ǰ���̵߳������Ļ���
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);		//
//	//!��ʼ��glad
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//
//	float tryanglepoints[] =												//��Ļ���ĵ�Ϊԭ�㣬ֵΪ��ԭ����Ļ��Ե�ı�����
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
//		"}\0";	//ǧ����������\0
//	unsigned vertexSHADER_ID = glCreateShader(GL_VERTEX_SHADER);			//vertex�����ζ���
//	glShaderSource(vertexSHADER_ID, 1, &vertexSHADER_SOURCE, NULL);
//	glCompileShader(vertexSHADER_ID);
//
//
//	const char* fragmentSHADER_SOURCE = "#version 330 core\n"
//		"out vec4 FragColor;\n"
//		"void main()\n"
//		"{\n"
//		"	FragColor = vec4(1.0f, 0.5f, 0.2f, 0.2f);\n"
//		"}\0";	//ǧ����������\0
//	unsigned fragmentSHADER_ID = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentSHADER_ID, 1, &fragmentSHADER_SOURCE, NULL);
//	glCompileShader(fragmentSHADER_ID);
//
//	unsigned SHADER_PROGRAM_ID = glCreateProgram();
//	glAttachShader(SHADER_PROGRAM_ID,vertexSHADER_ID );						//glAttachShader(��ɫ������ID,��ɫ��ID)
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
//	//���������ݴ���VBO
//	glBufferData(GL_ARRAY_BUFFER, sizeof(tryanglepoints), tryanglepoints, GL_STATIC_DRAW);
//	//����1�����ǵĶ���������Ҫ�������ĵط�����֮ǰ���ǰ󶨵�VBO��
//	//����2������Ĵ�С
//	//����3������ĵ�ַ
//	//����4��ָ���Կ�Ҫ����ʲô��ʽ���������ǵ����ݣ�GL_STATIC_DRAW��ʾ��Щ���ݲ��ᾭ���ı䡣
//
//
//	//���ǻ�ȡ�Ķ�����������VBO������
//	//��glVertexAttribPointer�������ǵ�ǰ�󶨵�GL_ARRAY_BUFFER�ϵ�VBO
//	//���ԣ����ǵ�ǰ�����ľ�������֮ǰ���ɲ��󶨵��Ǹ�VBO
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	//	����1��ָ��������Ҫ���õĶ������ԡ����Ʊ�ŵĶ�����֮ǰ����������location = 0�����������������õ���0.
//	//	����2���������ԵĴ�С�������õ��Ķ�����һ��vec3�Ľ�������Դ�СΪ3.
//	//	����3�����ݵ����͡�����ʹ�õ���float����
//	//	����4��ָ�������Ƿ�Ҫ���淶���������������ó�FALSE�����ù淶������Ϊ�����Ѿ��淶�����ˡ�
//	//	����5����ʾ���ԵĿ�ȡ�����֮ǰ���Ƿ����ģ����ǵĿ����12������3����float���͡�
//	//	����6��ָ�������ݵ���ʼƫ����������ת����һ��void * ָ�����ͱȽ���֣������Ժ�����
//	glEnableVertexAttribArray(0);					//�����ö���������Ч�ģ�����0��������֮ǰ���õ��Ǹ��������Ե�λ��
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
//		//������һ��ϰ�ߣ�����Ĳ��������Զ����浽��VAO�У�����ֻ��Ҫ�󶨾Ϳ���
//		//���Ҫ��ʾ�Ķ�����ͬ��Ҳֻ��Ҫ������󶨲�ͬ�Ķ����Ϳ�����ʾ
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