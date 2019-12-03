
#include "window.h"

Window_t* windowCreate(const char *title, int width, int height)
{
    // printf("creating window\n");
    Window_t* window = malloc(sizeof(Window_t));
    // printf("window created\n");
    window->m_Title = title;
    // printf("set title\n");
    window->m_Width = width;
    // printf("set width\n");
    window->m_Height = height;
    // printf("set height\n");
    window->m_Window = NULL;

    if (!init(window))
    {
        free(window);
        glfwTerminate();
    }

    return window;
}


void windowDestroy(Window_t* window){
    free(window);
    glfwTerminate();
}


bool init(Window_t* window)
{
    if (!glfwInit())
    {
        printf("Fail to initialize GLFW!\n");
        return false;
    }

    window->m_Window = glfwCreateWindow(window->m_Width, window->m_Height, window->m_Title, NULL, NULL);
    if (!window->m_Window)
    {
        printf("Failed to create GLFW window!\n");
        return false;
    }

    glfwMakeContextCurrent(window->m_Window);
    glfwSetWindowSizeCallback(window->m_Window, windowResize);


    // Warning: Make sure we check glewInit after we create the context, or else it won't work
    glewExperimental = GL_TRUE; // Need this so it will not seg fault 11 on MACOS
    if (glewInit() != GLEW_OK)
    {
        printf("Could not initialize GLEW!\n");
        return false;
    }

    printf("OpenGL %s\n", glGetString(GL_VERSION));
    return true;
}

const void clear()
{
    // printf("clear everything\n");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

const bool closed(Window_t* window)
{
    // printf("closed work\n");
    return glfwWindowShouldClose(window->m_Window);
    // printf("closed execute\n");
}

void update(Window_t* window)
{
    // printf("update working\n");
    glfwPollEvents();
    glfwSwapBuffers(window->m_Window);
}

void windowResize(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int getWidth(Window_t* window) 
{ 
    return window->m_Width; 
}

int getHeight(Window_t* window) 
{ 
    return window->m_Height; 
}