#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

const GLuint DEFAULT_WINDOW_WIDTH = 800, DEFAULT_WINDOW_HEIGHT = 800;
const char *WINDOW_TITLE = "OpenGL Application";

void framebuffer_size_callback(GLFWwindow *, int new_screen_width, int new_screen_height)
{
    glViewport(0, 0, new_screen_width, new_screen_height);
}

int main()
{
    GLFWwindow *window;

    if (!glfwInit())
        return 1;

    window = glfwCreateWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return 1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK)
        return 1;

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    std::cout << "Loop Started" << std::endl;
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Test (legacy OpenGL functions)
        glBegin(GL_TRIANGLES);
        glColor3f(0.1, 0.2, 0.3);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();
        glFlush();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
