#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
using namespace std;
class CVAO {
public:
	CVAO(unsigned int VBO);
	unsigned int VAO;
	~CVAO();
};
class CVBO {
public:
	CVBO();
	void bind(float*vertices,size_t size);
	unsigned int VBO;
	~CVBO();
};
class CEBO {
public:
	CEBO(unsigned int *indices,size_t size);
	unsigned int EBO;
	~CEBO();
};
class CWindows {
public:
	CWindows(int SCR_WIDTH, int SCR_HEIGHT, const char* winName);
	GLFWwindow* window;
	int SCR_WIDTH;
	int SCR_HEIGHT;
	const char* winName;
};