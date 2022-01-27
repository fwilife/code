#include"gl_class.h"
using namespace std;
CVAO::CVAO() {
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
}
CVAO::~CVAO() {
    glDeleteVertexArrays(1, &VAO);
}
unsigned int CVAO::get_VAO() {
    return VAO;
}
CVBO::CVBO(std::size_t size, float* vertices) {
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}
unsigned int CVBO::get_VBO() {
    return VBO;
}
CVBO::~CVBO() {
    glDeleteBuffers(1, &VBO);
}
CEBO::CEBO(std::size_t size,float*vertices) {
	glGenBuffers(1, &EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,size,&EBO,GL_STATIC_DRAW);
}
CEBO::~CEBO() {
    glDeleteBuffers(1, &EBO);
}
window::window(int width,int height,const char*winName) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    m_window = glfwCreateWindow(width, height, winName, NULL, NULL);
    if (m_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(m_window);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
}
GLFWwindow* window::getWindow() {
    return m_window;
}

