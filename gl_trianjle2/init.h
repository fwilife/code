#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
using namespace std;
const unsigned int SCR_WIDTH = 1000;
const unsigned int SCR_HEIGHT = 1000;
void CreateVAO(unsigned int& VAO, unsigned int& VBO, float* vertices);
GLFWwindow* initAndCreateWindow();


