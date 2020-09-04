//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//#include "glm/gtc/type_ptr.hpp"
//
//#include <iostream>
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb-master/stb_image.h"
//
//#include "Shader.h"
//#include "Camera.h"
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//void mouse_callback(GLFWwindow* window, double xPos, double yPos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//
//// 设置
//const unsigned int SCR_WIDTH = 1280;
//const unsigned int SCR_HEIGHT = 720;
//
//float factor = 0.2f;
//double fov = 45.0;
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
//glm::vec3 cubePositions[] = {
//	glm::vec3(0.0f, 0.0f, 0.0f),
//	glm::vec3(2.0f, 5.0f, -15.0f),
//	glm::vec3(-1.0f, -2.0f, -2.0f),
//	glm::vec3(-3.0f, -2.0f, -12.0f),
//	glm::vec3(2.0f, -0.0f, -3.0f),
//	glm::vec3(-1.0f, 3.0f, -7.0f),
//	glm::vec3(1.0f, -2.0f, -2.0f),
//	glm::vec3(1.0f, 2.0f, -2.0f),
//	glm::vec3(1.0f, 0.0f, -1.0f),
//	glm::vec3(-1.0f, 1.0f, -0.0f)
//};
//
//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 4.0f);
//glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//
//float deltaTime = 0.0f;  //两帧之间的间隔时间
//float lastFrame = 0.0f;  //上一帧绘制的时间
//
//float lastX = 400, lastY = 300;
//bool firstMouse = true;
//float yaw = 0.0f, pitch = 0.0f;
//
////！创造我们的摄像机
//Camera camera(glm::vec3(0.0f, 0.0f, 4.0f));
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
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//	glfwSetCursorPosCallback(window, mouse_callback);
//	glfwSetScrollCallback(window, scroll_callback);
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
//	Shader shader("Shader3D.vs", "Shader.fs");
//
//
//
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
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
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
//	////纹理2
//	//unsigned int texture2;
//	//glGenTextures(1, &texture2);
//	//glActiveTexture(GL_TEXTURE1);	//激活纹理1对象
//	//glBindTexture(GL_TEXTURE_2D, texture2);
//	////设置纹理环绕和过滤的方式
//	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	////加载图片
//	//stbi_set_flip_vertically_on_load(true);
//	//unsigned char* data2 = stbi_load("awesomeface.png", &width, &height, &nrChannels, 0);
//	//if (data2) {
//	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data2);
//	//	glGenerateMipmap(GL_TEXTURE_2D);
//	//}
//	//else
//	//	std::cout << "无法加载问题，请检查代码或资源是否有误。" << std::endl;
//	//stbi_image_free(data2);
//
//	//告诉OpenGL哪个采样器属于哪个纹理单元
//	//shader.useShaderProg();
//	//shader.setInt("texture1", 0);
//	//shader.setInt("texture2", 1);
//
//	//变换
//	//glm::mat4 trans;
//	//trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));
//	//trans = glm::rotate(trans, /*glm::radians(90.0f)*/(float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
//
//
//
//	while (!glfwWindowShouldClose(window)) {
//
//		processInput(window);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture);/*
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);*/
//
//		float currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		shader.useShaderProg();
//		glm::mat4 projection;
//		projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//
//		//float radius = 10.0f;
//		//float camX = sin(glfwGetTime()) * radius;
//		//float camZ = cos(glfwGetTime()) * radius;
//		glm::mat4 view;
//		//view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
//		view = camera.GetViewMatrix();//glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
//		shader.setMat4("view", glm::value_ptr(view));
//		shader.setMat4("projection", glm::value_ptr(projection));
//
//		glm::mat4 model;
//		glBindVertexArray(VAO);
//		int x = 0, y = 0, z = 0;
//		while (x < 10)
//		{
//			while (y < 10)
//			{
//				model = glm::translate(glm::mat4() , glm::vec3((float)x, (float)y, (float)z));
//				model = glm::rotate(model, glm::radians(0.0f), glm::vec3(1.0f, 0.3f, 0.5f));
//				shader.setMat4("model", glm::value_ptr(model));
//				glDrawArrays(GL_TRIANGLES, 0, 36);
//				y++;
//			}
//			y = 0;
//			x++;
//		}
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
//
//	//float cameraSpeed = 2.5f * deltaTime; //移动速度
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//		camera.ProcessKeyboard(FORWARD, deltaTime);
//	//cameraPos += cameraSpeed * cameraFront;
//
//	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//		camera.ProcessKeyboard(BACKWARD, deltaTime);
//	//cameraPos -= cameraSpeed * cameraFront;
//
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//		camera.ProcessKeyboard(LEFT, deltaTime);
//	//cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp) * cameraSpeed);
//
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//		camera.ProcessKeyboard(RIGHT, deltaTime);
//	//cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp) * cameraSpeed);
//
//}
//
//void mouse_callback(GLFWwindow* window, double xPos, double yPos) {
//	//static int x = 0;
//
//	//x++;
//	//if (x == 10) {
//	//	int y = 0;
//	//}
//	if (firstMouse) {
//		lastX = xPos;
//		lastY = yPos;
//		firstMouse = false;
//	}
//
//	float xoffset = lastX - xPos;	//别忘了，在窗口中，左边的坐标小于右边的坐标，而我们需要一个正的角度
//	float yoffset = lastY - yPos;	//同样，在窗口中，下面的坐标大于上面的坐标，而我们往上抬头的时候需要一个正的角度
//	lastX = xPos;
//	lastY = yPos;
//
//	camera.ProcessMouseMovement(xoffset, yoffset);
//
//	//float sensitivity = 0.05f;
//	//xoffset *= sensitivity;
//	//yoffset *= sensitivity;
//
//	//yaw += xoffset;
//	//pitch += yoffset;
//
//	//if (pitch > 89.0f)
//	//	pitch = 89.0f;
//	//if (pitch < -89.0f)
//	//	pitch = -89.0f;
//
//	//glm::vec3 front;
//	//front.x = -sin(glm::radians(yaw));
//	//front.y = sin(glm::radians(pitch));
//	//front.z = -cos(glm::radians(pitch)) * cos(glm::radians(yaw));
//	//cameraFront = glm::normalize(front);
//}
//
////鼠标滚轮消息回调
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
//	camera.ProcessMouseScroll(yoffset);
//	//if (fov >= 1.0 && fov <= 45.0)
//	//	fov -= yoffset;
//	//if (fov <= 1.0)
//	//	fov = 1.0;
//	//if (fov >= 45.0)
//	//	fov = 45.0;
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//	glViewport(0, 0, width, height);
//}
