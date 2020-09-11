//#include "glad/glad.h"
//#include "glfw/glfw3.h"
//#include "iostream"
//#include "fstream"
//#include "strstream"
//#define stb_image_implementation
////预处理器会修改头文件，让其只包含相关的函数定义源码
////等于是将这个头文件变为一个 .cpp 文件了
////现在只需要在你的程序中包含stb_image.h并编译就可以了
//#include "stb-master/stb_image.h"
//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//#include "glm/gtc/type_ptr.hpp"
//#include "camera.h"
//#include "Shader.h"
//#include "math.h"
//
//
//class cubemodel :public Shader
//{
//public:
//	cubemodel();
//	cubemodel(std::string, std::string);
//	inline unsigned getvao() { return vao; };
//	inline unsigned getvbo() { return vbo; };
//	inline unsigned getebo() { return ebo; };
//	~cubemodel() {};
//
//protected:
//	unsigned vao;
//	unsigned vbo;
//	unsigned ebo;
//};
//void framebuffersize_callback(glfwwindow*, int, int);
//void key_callback(glfwwindow*, int, int, int, int);
////glfwsetmousebuttoncallback(window, mousebutton_callback);
//void mouseposition_callback(glfwwindow*, double, double);
//
//
//cubemodel test;
//camera c;
//int main()
//{
//	glfwinit();
//	glfwwindowhint(glfw_context_version_major, 3);
//	glfwwindowhint(glfw_context_version_minor, 3);
//	glfwwindowhint(glfw_opengl_profile, glfw_opengl_core_profile);
//	glfwwindow* window = glfwcreatewindow(1080, 720, "test", null, null);
//	while (window == null)
//	{
//		std::cout << "" << std::endl;
//		return -1;
//	}
//	glfwmakecontextcurrent(window);
//	if (!gladloadglloader((gladloadproc)glfwgetprocaddress)) {
//		std::cout << "failed to initialize glad" << std::endl;
//		exit(-1);
//	}
//	glfwsetframebuffersizecallback(window, framebuffersize_callback);
//	glfwsetkeycallback(window, key_callback);
//	//glfwsetmousebuttoncallback(window, mousebutton_callback);
//	glfwsetcursorposcallback(window, mouseposition_callback);
//	glfwsetinputmode(window, glfw_cursor, glfw_cursor_normal);
//	glclearcolor(0.2f, 0.3f, 0.3f, 1.0f);
//
//	unsigned textureid;
//	glgentextures(1, &textureid);
//	glbindtexture(gl_texture_2d, textureid);
//	gltexparameteri(gl_texture_2d, gl_texture_wrap_s, gl_repeat);
//	gltexparameteri(gl_texture_2d, gl_texture_wrap_t, gl_repeat);
//	gltexparameteri(gl_texture_2d, gl_texture_min_filter, gl_nearest_mipmap_nearest);
//	gltexparameteri(gl_texture_2d, gl_texture_mag_filter, gl_nearest_mipmap_nearest);
//	int width, height, nrchannels;
//	unsigned char* data;
//	data = stbi_load("375px-mr._quin.jpg", &width, &height, &nrchannels, 0);
//	if (data)
//	{
//		glteximage2d(gl_texture_2d, 0, nrchannels == 3 ? gl_rgb : gl_rgba, width, height, 0, nrchannels == 3 ? gl_rgb : gl_rgba, gl_unsigned_byte, data);
//		glgeneratemipmap(gl_texture_2d);
//	}
//	else
//	{
//		std::cout << "failed to load texture" << std::endl;
//	}
//	stbi_image_free(data);					//释放图像的内存
//
//	glbindvertexarray(0);
//	glbindbuffer(gl_array_buffer, 0);
//	glbindbuffer(gl_element_array_buffer, 0);
//	glbindtexture(gl_texture_2d, 0);
//
//	test = cubemodel("shader_try.vs", "shader.fs");
//	c = camera(glm::vec3(0.0f, 0.0f, 4.0f));
//	glm::mat4 model = glm::translate(glm::mat4(), glm::vec3(0, 0, -1)), view, projection;
//	projection = glm::perspective(/*glm::radians(45.0f)*/45.0f, (float)1080 / (float)720, 0.1f, 100.0f);
//
//	while (!glfwwindowshouldclose(window))
//	{
//		glclear(gl_color_buffer_bit | gl_depth_buffer_bit);
//
//
//
//		test.useshaderprog();
//		glbindvertexarray(test.getvao());
//		glbindbuffer(gl_array_buffer, test.getvbo());
//		glbindbuffer(gl_element_array_buffer, test.getebo());
//		glbindtexture(gl_texture_2d, textureid);
//		test.setmat4("model", glm::value_ptr(model));
//		view = c.getviewmatrix();
//		test.setmat4("view", glm::value_ptr(view));
//		test.setmat4("projection", glm::value_ptr(projection));
//
//		gldrawelements(gl_triangles, 36, gl_unsigned_int, 0);
//		glbindvertexarray(null);
//		glbindtexture(gl_texture_2d, null);
//
//		glfwswapbuffers(window);
//		glfwpollevents();
//	}
//	glfwterminate();
//	return 0;
//}
//
//cubemodel::cubemodel()
//{
//	progid = 0;
//	vao = 0;
//	vbo = 0;
//	ebo = 0;
//}
//cubemodel::cubemodel(std::string vertexshader_path, std::string fragmentshader_path)
//{
//	float vertices[] = {
//		//背面
//		1.0f,	0.0f,	0.0f,	0.0f,	0.0f,		//左下
//		0.0f,	0.0f,	0.0f,	1.0f,	0.0f,		//右下
//		0.0f,	1.0f,	0.0f,	1.0f,	1.0f,		//右上
//		1.0f,	1.0f,	0.0f,	0.0f,	1.0f,		//左上
//		//正面
//		0.0f,	0.0f,	1.0f,	0.0f,	0.0f,		//左下
//		1.0f,	0.0f,	1.0f,	1.0f,	0.0f,		//右下
//		1.0f,	1.0f,	1.0f,	1.0f,	1.0f,		//右上
//		0.0f,	1.0f,	1.0f,	0.0f,	1.0f,		//左上
//		//左面
//		0.0f,	0.0f,	0.0f,	0.0f,	0.0f,		//左下
//		0.0f,	0.0f,	1.0f,	1.0f,	0.0f,		//右下
//		0.0f,	1.0f,	1.0f,	1.0f,	1.0f,		//右上
//		0.0f,	1.0f,	0.0f,	0.0f,	1.0f,		//左上
//		//右面
//		1.0f,	0.0f,	1.0f,	0.0f,	0.0f,		//左下
//		1.0f,	0.0f,	0.0f,	1.0f,	0.0f,		//右下
//		1.0f,	1.0f,	0.0f,	1.0f,	1.0f,		//右上
//		1.0f,	1.0f,	1.0f,	0.0f,	1.0f,		//左上
//		//顶面
//		0.0f,	1.0f,	1.0f,	0.0f,	0.0f,		//左下
//		1.0f,	1.0f,	0.0f,	1.0f,	0.0f,		//右下
//		1.0f,	1.0f,	0.0f,	1.0f,	1.0f,		//右上
//		0.0f,	1.0f,	0.0f,	0.0f,	1.0f,		//左上
//		//底面
//		0.0f,	0.0f,	0.0f,	0.0f,	0.0f,		//左下
//		1.0f,	0.0f,	0.0f,	1.0f,	0.0f,		//右下
//		1.0f,	0.0f,	1.0f,	1.0f,	1.0f,		//右上
//		0.0f,	0.0f,	1.0f,	0.0f,	1.0f,		//左上
//	};
//	unsigned indicat[] =
//	{
//		//背面
//		0,	1,	3,		//左下
//		1,	2,	3,		//右上
//		//正面
//		0,	0,	0,		//左下
//		0,	0,	0,		//右上
//		//左面
//		0,	0,	0,		//左下
//		0,	0,	0,		//右上
//		//右面
//		0,	0,	0,		//左下
//		0,	0,	0,		//右上
//		//顶面
//		0,	0,	0,		//左下
//		0,	0,	0,		//右上
//		//底面
//		0,	0,	0,		//左下
//		0,	0,	0,		//右上
//	};
//	this->progid = shader(vertexshader_path, fragmentshader_path).getprogid();
//	glgenvertexarrays(1, &vao);
//	glbindvertexarray(vao);
//	glgenbuffers(1, &vbo);
//	glbindbuffer(gl_array_buffer, vbo);
//	glbufferdata(vbo, sizeof(vertices), vertices, gl_static_draw);
//	glgenbuffers(1, &ebo);
//	glbindbuffer(gl_element_array_buffer, ebo);
//	glbindbuffer(gl_element_array_buffer, vbo);
//	glbufferdata(ebo, sizeof(indicat), indicat, gl_static_draw);
//
//	glvertexattribpointer(0, 3, gl_float, gl_false, 5 * sizeof(float), (void*)0);
//	glenablevertexattribarray(0);
//	glvertexattribpointer(1, 2, gl_float, gl_false, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glenablevertexattribarray(1);
//	std::cout<< vao<<"|" << vbo << "|" << ebo << "|"<<std::endl;
//	glbindvertexarray(null);
//	gluseprogram(null);
//}
//
//void framebuffersize_callback(glfwwindow* window, int width, int height)
//{
//	glviewport(0, 0, width, height);
//}
//void key_callback(glfwwindow* window, int key, int scancode, int action, int mods)
//{
//	if (action == glfw_repeat || action == glfw_press)
//	{
//		switch (key)
//		{
//		case glfw_key_w:
//
//			break;
//		case glfw_key_s:
//
//			break;
//		case glfw_key_a:
//
//			break;
//		case glfw_key_d:
//
//			break;
//		case glfw_key_space:
//
//			break;
//		case glfw_key_left_shift:
//
//			break;
//		default:
//			break;
//		}
//
//	}
//
//}
////glfwsetmousebuttoncallback(window, mousebutton_callback);
//void mouseposition_callback(glfwwindow* window, double xpos, double ypos)
//{
//
//
//}