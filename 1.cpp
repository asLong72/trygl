//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
////using namespace std;
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int heigh)
//{
//	glViewport(0, 0, width, heigh);//�ı��Ӵ���С
//}
//
//void processInput(GLFWwindow* window)
//{
//
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)//���esc�Ƿ���
//	{
//		glfwSetWindowShouldClose(window, true);//���ô��ڸ���
//	}
//}
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
//	glfwMakeContextCurrent(window); //�����ڵ������Ļ�������Ϊ��ǰ���̵߳������Ļ���
//	//!��ʼ��glad
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//!ע�ᴰ�ڻص�����
//
//	//!��Ⱦѭ��
//	while (!glfwWindowShouldClose(window)) //����Ƿ�رմ���
//	{
//		processInput(window);//���������¼�
//
//		//!��Ⱦ
//		glClearColor(1.0f, 1.0f, 0.0f, 1.0f);//����������ɫ(��ɫ)
//
//		glClear(GL_COLOR_BUFFER_BIT);//����
//
//		glfwSwapBuffers(window);//����ʾ������������潻��( ��ʾ���������е�����)
//
//
//		glfwPollEvents();//����Ƿ����¼�����( �����������ͼ��������¼�)
//
//	}
//	glfwTerminate();	//��ֹ����
//
//	return 0;
//}