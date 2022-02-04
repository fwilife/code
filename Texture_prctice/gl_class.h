#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h> 
#include<iostream>
#include<fstream>
#include<sstream>
class CVAO {
public:
	CVAO();
	~CVAO();
	unsigned int get_VAO();
private:
	unsigned int VAO;
};
class CVBO {
public:
	CVBO(std::size_t size,float*vertices);
	unsigned int get_VBO();
	~CVBO();
private:
	unsigned int VBO;
};
class CEBO {
public:
	CEBO(std::size_t,float*);
	~CEBO();
private:
	unsigned int EBO;
};
class window {
public:
	window(int width,int height,const char*);
	GLFWwindow* getWindow();
private:
	GLFWwindow* m_window;

};
class Shader {
public:
	unsigned int ID;
	Shader(const char* vertexPath, const char* fragmentPath);
	void use();
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
private:
	void checkCompileErrors(unsigned int shader, std::string type);
};
