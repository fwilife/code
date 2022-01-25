#include"glClass.h"
using namespace std;
CVAO::CVAO(unsigned int VBO):VAO(1) {
    glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
}
CVAO::~CVAO() {
	glDeleteVertexArrays(1, &VAO);
}
CVBO::CVBO():VBO(1) {
	glGenBuffers(1, &VBO);
}
CVBO::~CVBO() {
	glDeleteBuffers(1, &VBO);
}
void CVBO::bind(float*vertices,size_t size) {
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}
CEBO::CEBO(unsigned int* indices, size_t size) : EBO(1) {
	cout << size << endl;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}
CEBO::~CEBO() {
	glDeleteBuffers(1, &EBO);
}
CWindows::CWindows(int mSCR_WIDTH, int mSCR_HEIGHT, const char* mWinName) : SCR_WIDTH(mSCR_WIDTH), SCR_HEIGHT(mSCR_HEIGHT), winName(mWinName) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, winName, NULL, NULL);
	glfwMakeContextCurrent(window);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}

}