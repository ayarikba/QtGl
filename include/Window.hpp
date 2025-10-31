#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <string>
#define GLFW_INCLUDE_NONE



class Window
{
    public:
    Window(const int width = 640, const int height = 480, const std::string& title = "Hello world");
    ~Window();


    public:
    double GetTime();

    private:
    GLFWwindow* window;



    private:
    bool Render();
    bool RenderTriangle();

};











#endif