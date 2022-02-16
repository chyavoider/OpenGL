#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

using namespace std;

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto* Window = glfwCreateWindow(800, 600, "HelloWindow", nullptr, nullptr);

    if (!Window)
    {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(Window);
    glfwSetFramebufferSizeCallback(Window, [](GLFWwindow* Window, int Width, int Height) { glViewport(0, 0, Width, Height); });

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }

    while (!glfwWindowShouldClose(Window))
    {
        if (glfwGetKey(Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(Window, true);

        glClearColor(1.f, 0.3f, 0.5f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(Window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}