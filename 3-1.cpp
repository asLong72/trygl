/////*Ԫ�ػ������*/
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
////��������
//float rectVertices[] =
//{
//0.5f, 0.5f, 0.0f,   //���Ͻ�
//0.5f, -0.5f, 0.0f,  //���½�
//-0.5f, -0.5f, 0.0f, //���½�
//-0.5f, 0.5f, 0.0f   //���Ͻ�
//};
////��������
//unsigned indices[] =
//{
//0, 1, 3,    //��һ��������
//1, 2, 3 //�ڶ���������
//};
//
//
//int main()
//{
//	//��ʼ��glfw
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
//	//��ʼ��glad
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	//��ʼ��������ɫ��
//	unsigned vertexShader_ID = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader_ID, 1, &vertexShader_Source, NULL);		//������ɫ������͵�ַ
//	glCompileShader(vertexShader_ID);
//	//��ʼ��ƬԪ��ɫ��
//	unsigned fragmentShader_ID = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader_ID, 1, &fragmentShader_Source, NULL);	//������ɫ������͵�ַ
//	glCompileShader(fragmentShader_ID);
//	//��ʼ����ɫ������
//	unsigned Shader_programe_ID = glCreateProgram();
//	glAttachShader(Shader_programe_ID, vertexShader_ID);				//glAttachShader(��ɫ������ID,��ɫ��ID)
//	glAttachShader(Shader_programe_ID, fragmentShader_ID);
//	glLinkProgram(Shader_programe_ID);
//
//	//�ͷ���ɫ����ַ
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
//	//���������ݴ���VBO
//	glBufferData(GL_ARRAY_BUFFER, sizeof(rectVertices), rectVertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glGenBuffers(1, &EBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);				//��EBO
//															//ע����VBO���֣�
//															//��VBO�õĲ�����GL_ARRAY_BUFFER����EBO��Ҫ����GL_ELEMENT_ARRAY_BUFFER��������ʾ��
//															//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	//ͬ����EBO����ʹ��glBufferData
//	//�������Ƶ�ʱ����Ҫָ����EBO�����ԣ�Ҫ��GL_ELEMENT_ARRAY_BUFFER��������������
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
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);			//����������ɫ
//														//����1������2������3
//														//����4:��͸����
//		glClear(GL_COLOR_BUFFER_BIT);					//��������
//
//		do
//		{
//			a = getchar();
//		} while (a == '\n');
//
//		if (a == ' ')
//		{
//			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);				//���߿�ģʽ(Wireframe Mode)����ͼ��
//																	//��һ������"GL_FRONT_AND_BACK"��ʾ���Ǵ��㽫��Ӧ�õ����е������ε�����ͱ���
//																	//�ڶ�������"GL_LINE"������������������
//		}
//		else
//		{
//			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);				//���û�Ĭ��ģʽ
//		}
//
//		glUseProgram(Shader_programe_ID);							//
//
//		//����
//
//		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//		glBindVertexArray(VAO);
//		//������VBOʹ��glDrawArrays����������EBO��Ҫʹ��glDrawElements����
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//
//		glfwSwapBuffers(window_ID);						//����ʾ������������潻��( ��ʾ���������е����� )��˫���湦�ܣ�����ǰ�����ݻ���ʹ����ˢ��ͬ��
//		glfwPollEvents();								//����Ƿ����¼�����( �����������ͼ��������¼�)
//	}
//
//	glfwTerminate();									//��ֹ��ͼ���ڽ���
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