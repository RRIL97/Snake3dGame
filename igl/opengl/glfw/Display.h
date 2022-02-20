#pragma once
#include <string>
#include <GLFW/glfw3.h>
#include <vector>

#include <learnopengl/camera.h>

//#include "igl/opengl/glfw/renderer.h"
#define EXIT_FAILURE 1
struct GLFWwindow;

class Display
{
public:
	Display(int windowWidth, int windowHeight, const std::string& title);
	
	bool launch_rendering(bool loop);
	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void SwapBuffers();
	void PollEvents();

	unsigned int loadCubemap(std::vector<std::string> faces);
	void SetRenderer(void* userPointer);
	void* GetScene();
	void AddKeyCallBack(void(*func)(GLFWwindow*, int, int, int, int));
	void AddMouseCallBacks(void (*mousebuttonfun)(GLFWwindow*, int, int, int), void(*scrollfun)(GLFWwindow*, double, double), void (*cursorposfun)(GLFWwindow*, double, double));
	void AddResizeCallBack(void (*windowsizefun)(GLFWwindow*, int, int));

	Camera * getCamera();
	~Display();
//private:
	GLFWwindow* window;  
	//Renderer* renderer;
	//int highdpi;  //relation between width and height?

};

