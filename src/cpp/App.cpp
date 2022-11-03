#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <SOIL/SOIL.h>

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 800
#define WINDOW_TITLE "OpenGL Application"

void frame_buffer_size_callback(GLFWwindow *, int new_screen_width, int new_screen_height)
{
    glViewport(0, 0, new_screen_width, new_screen_height); // Tell OpenGL how to convert from coordinates to pixel values
    glMatrixMode(GL_PROJECTION);                           // Switch to setting the camera perspective
    glLoadIdentity();                                      // Reset the camera

    gluPerspective(45.0,                                                 // The camera angle
                   (double)new_screen_width / (double)new_screen_height, // The width-to-height ratio
                   1.0,                                                  // The near z clipping coordinate
                   200.0);                                               // The far z clipping coordinate
}

int main()
{
    // Setup the window
    GLFWwindow *window;

    if (!glfwInit())
        return 1;

    window = glfwCreateWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
    // window = glfwCreateWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, WINDOW_TITLE, glfwGetPrimaryMonitor(), NULL); // If full screen needed

    if (!window)
    {
        glfwTerminate();
        return 1;
    }

    glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK)
        return 1;
    // Done setting up the window

    // OpenGL hints
    glEnable(GL_DEPTH_TEST);

    std::cout << "Loop Started" << std::endl;
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);               // Background color
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear information from last draw
        glMatrixMode(GL_MODELVIEW);                         // Switch to the drawing perspective
        glLoadIdentity();                                   // Reset the drawing perspective

        glTranslated(0, 0, -2); // Take the camera back two steps

        glBegin(GL_TRIANGLES);
        glColor3f(0.1, 0.2, 0.3);
        glVertex3f(-0.5f, -0.5f, 0.0f);
        glVertex3f(0.0f, 0.5f, 0.0f);
        glVertex3f(0.5f, -0.5f, 0.0f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
