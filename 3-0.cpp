////#include <glad/glad.h>
////#include <GLFW/glfw3.h>
////#include <iostream>
////
////void framebuffer_size_callback(GLFWwindow* window, int width, int height);
////void processInput(GLFWwindow* window);
////
////// settings
////const unsigned int SCR_WIDTH = 800;
////const unsigned int SCR_HEIGHT = 600;
////
////const char* vertexShaderSource = "#version 330 core\n"
////"layout (location = 0) in vec3 aPos;\n"
////"void main()\n"
////"{\n"
////"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
////"}\0";
////const char* fragmentShaderSource = "#version 330 core\n"
////"out vec4 FragColor;\n"
////"void main()\n"
////"{\n"
////"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
////"}\n\0";
////
////int main()
////{
////    // glfw: initialize and configure
////    // ------------------------------
////    glfwInit();
////    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
////    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
////    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
////
////#ifdef __APPLE__
////    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
////#endif
////
////    // glfw window creation
////    // --------------------
////    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
////    if (window == NULL)
////    {
////        std::cout << "Failed to create GLFW window" << std::endl;
////        glfwTerminate();
////        return -1;
////    }
////    glfwMakeContextCurrent(window);
////    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
////
////    // glad: load all OpenGL function pointers
////    // ---------------------------------------
////    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
////    {
////        std::cout << "Failed to initialize GLAD" << std::endl;
////        return -1;
////    }
////
////
////    // build and compile our shader program
////    // ------------------------------------
////    // vertex shader
////    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
////    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
////    glCompileShader(vertexShader);
////    // check for shader compile errors
////    int success;
////    char infoLog[512];
////    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
////    if (!success)
////    {
////        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
////        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
////    }
////    // fragment shader
////    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
////    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
////    glCompileShader(fragmentShader);
////    // check for shader compile errors
////    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
////    if (!success)
////    {
////        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
////        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
////    }
////    // link shaders
////    int shaderProgram = glCreateProgram();
////    glAttachShader(shaderProgram, vertexShader);
////    glAttachShader(shaderProgram, fragmentShader);
////    glLinkProgram(shaderProgram);
////    // check for linking errors
////    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
////    if (!success) {
////        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
////        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
////    }
////    glDeleteShader(vertexShader);
////    glDeleteShader(fragmentShader);
////
////    // set up vertex data (and buffer(s)) and configure vertex attributes
////    // ------------------------------------------------------------------
////    float vertices[] = {
////         0.5f,  0.5f, 0.0f,  // top right
////         0.5f, -0.5f, 0.0f,  // bottom right
////        -0.5f, -0.5f, 0.0f,  // bottom left
////        -0.5f,  0.5f, 0.0f   // top left 
////    };
////    unsigned int indices[] = {  // note that we start from 0!
////        0, 1, 3,  // first Triangle
////        1, 2, 3   // second Triangle
////    };
////    unsigned int VBO, VAO, EBO;
////    glGenVertexArrays(1, &VAO);
////    glGenBuffers(1, &VBO);
////    glGenBuffers(1, &EBO);
////    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
////    glBindVertexArray(VAO);
////
////    glBindBuffer(GL_ARRAY_BUFFER, VBO);
////    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
////
////    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
////    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
////
////    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
////    glEnableVertexAttribArray(0);
////
////    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
////    glBindBuffer(GL_ARRAY_BUFFER, 0);
////
////    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
////    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
////
////    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
////    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
////    glBindVertexArray(0);
////
////
////    // uncomment this call to draw in wireframe polygons.
////    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
////
////    // render loop
////    // -----------
////    while (!glfwWindowShouldClose(window))
////    {
////        // input
////        // -----
////        processInput(window);
////
////        // render
////        // ------
////        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
////        glClear(GL_COLOR_BUFFER_BIT);
////
////        // draw our first triangle
////        glUseProgram(shaderProgram);
////        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
////        //glDrawArrays(GL_TRIANGLES, 0, 6);
////        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
////        // glBindVertexArray(0); // no need to unbind it every time 
////
////        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
////        // -------------------------------------------------------------------------------
////        glfwSwapBuffers(window);
////        glfwPollEvents();
////    }
////
////    // optional: de-allocate all resources once they've outlived their purpose:
////    // ------------------------------------------------------------------------
////    glDeleteVertexArrays(1, &VAO);
////    glDeleteBuffers(1, &VBO);
////    glDeleteBuffers(1, &EBO);
////
////    // glfw: terminate, clearing all previously allocated GLFW resources.
////    // ------------------------------------------------------------------
////    glfwTerminate();
////    return 0;
////}
////
////// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
////// ---------------------------------------------------------------------------------------------------------
////void processInput(GLFWwindow* window)
////{
////    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
////        glfwSetWindowShouldClose(window, true);
////}
////
////// glfw: whenever the window size changed (by OS or user resize) this callback function executes
////// ---------------------------------------------------------------------------------------------
////void framebuffer_size_callback(GLFWwindow* window, int width, int height)
////{
////    // make sure the viewport matches the new window dimensions; note that width and 
////    // height will be significantly larger than specified on retina displays.
////    glViewport(0, 0, width, height);
////}
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//#include <iostream>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
//// 设置
//const unsigned int SCR_WIDTH = 1280;
//const unsigned int SCR_HEIGHT = 720;
//
////顶点着色代码
//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\0";	//千万别忘记这个\0
//
////片元着色器代码
//const char* fragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}\0";	//千万别忘记这个\0
//
//float vertices[] = {
//	-0.5f, -0.5f, 0.0f,		//左
//	0.5f, -0.5f, 0.0f,		//右
//	0.0f, 0.5f, 0.0f,		//上
//	1.0f, 0.0f, 0.0f,
//	0.75f, 0.5f, 0.0f,
//	0.5f, 0.0f, 0.0f
//};
//
//float rectVertices[] = {
//	0.5f, 0.5f, 0.0f,		//右上角
//	0.5f, -0.5f, 0.0f,		//右下角
//	-0.5f, -0.5f, 0.0f,		//左下角
//	-0.5f, 0.5f, 0.0f		//左上角
//};
//
//unsigned int indices[] = {
//	0, 1, 3,		//第一个三角形
//	1, 2, 3			//第二个三角形
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
//	//！创建、编译我们的着色器程序
//	//顶点着色器
//	int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//
//	//片元着色器
//	int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShader);
//
//	//链接着色器
//	int shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//
//	//别忘了释放着色器
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	unsigned int VBO, VAO;
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
//	unsigned int EBO;
//	glGenBuffers(1, &EBO);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	while (!glfwWindowShouldClose(window)) {
//		processInput(window);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glUseProgram(shaderProgram);
//
//		/*
//		* 这里是一个习惯，上面的操作把属性都保存到了VAO中，这里只需要绑定就可以
//		* 如果要显示的东西不同，也只需要在这里绑定不同的东西就可以显示
//		*/
//		glBindVertexArray(VAO);
//		//glDrawArrays(GL_TRIANGLES, 0, 6);	//修改绘制的顶点数量
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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
//void processInput(GLFWwindow* window) {
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//	glViewport(0, 0, width, height);
//}
