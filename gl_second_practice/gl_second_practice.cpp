#include"gl_class.h"
using namespace std;
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";
const char*fragmentShader2Source=  "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
    "}\n\0";
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
int main() {
    window win1(800, 600, "gl_window");
    glfwSetFramebufferSizeCallback(win1.getWindow(), framebuffer_size_callback);
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int FragmentShaderyellow = glCreateShader(GL_FRAGMENT_SHADER);
    unsigned int FragmentShaderorange = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glShaderSource(FragmentShaderorange, 1, &fragmentShader2Source, nullptr);
    glShaderSource(FragmentShaderyellow, 1, &fragmentShaderSource, nullptr);
    glCompileShader(vertexShader);
    glCompileShader(FragmentShaderyellow);
    glCompileShader(FragmentShaderorange);
    unsigned int ShaderProgramyellow = glCreateProgram();
    unsigned int ShaderProgramOrange = glCreateProgram();
    glAttachShader(ShaderProgramyellow, vertexShader);
    glAttachShader(ShaderProgramOrange, vertexShader);
    glAttachShader(ShaderProgramyellow, FragmentShaderyellow);
    glAttachShader(ShaderProgramOrange, FragmentShaderorange);
    glLinkProgram(ShaderProgramyellow);
    glLinkProgram(ShaderProgramOrange);
    float firstTriangle[] = {
    -0.9f, -0.5f, 0.0f,  // left 
    -0.0f, -0.5f, 0.0f,  // right
    -0.45f, 0.5f, 0.0f,  // top 
    };
    float secondTriangle[] = {
        0.0f, -0.5f, 0.0f,  // left
        0.9f, -0.5f, 0.0f,  // right
        0.45f, 0.5f, 0.0f   // top 
    };
    CVAO VA1;
    CVBO VB1(sizeof(firstTriangle), firstTriangle);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);	// Vertex attributes stay the same
    glEnableVertexAttribArray(0);
    CVAO VA2;
    CVBO VB2(sizeof(secondTriangle), secondTriangle);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); // because the vertex data is tightly packed we can also specify 0 as the vertex attribute's stride to let OpenGL figure it out
    glEnableVertexAttribArray(0);
    while (!glfwWindowShouldClose(win1.getWindow()))
    {
        // input
        // -----
        processInput(win1.getWindow());

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // now when we draw the triangle we first use the vertex and orange fragment shader from the first program
        glUseProgram(ShaderProgramOrange);
        // draw the first triangle using the data from our first VAO
        glBindVertexArray(VA1.get_VAO());
        glDrawArrays(GL_TRIANGLES, 0, 3);	// this call should output an orange triangle
        // then we draw the second triangle using the data from the second VAO
        // when we draw the second triangle we want to use a different shader program so we switch to the shader program with our yellow fragment shader.
        glUseProgram(ShaderProgramyellow);
        glBindVertexArray(VA2.get_VAO());
        glDrawArrays(GL_TRIANGLES, 0, 3);	// this call should output a yellow triangle

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(win1.getWindow());
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteProgram(ShaderProgramOrange);
    glDeleteProgram(ShaderProgramyellow);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}