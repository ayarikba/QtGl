#include "Window.hpp"
static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods);
Window::Window(const int width, const int height, const std::string& title)
{

    glfwWindowHint(GLFW_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    glfwSwapInterval(1);


    glfwSetErrorCallback(error_callback);
    glfwSetKeyCallback(window, key_callback);
    if (!glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW");
    }


    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create window");
    }
    

    glfwMakeContextCurrent(window);


    Render(); 
}

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

bool Window::Render()
{
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents(); // instead of this glfwWaitEvents can be used to save cpu cycle for program that refreshes only with new input
    }
    glfwTerminate();
    return true ; 
}


bool Window::RenderTriangle()
{
    int width, height ;

    glfwGetFramebufferSize(window, &width, &height); // u can use glfwsetframbuffersizecallback and be notified when size changed
    glViewport(0 ,0, width , height);
    return true ;
}

double Window::GetTime()
{
    return glfwGetTime();
}
