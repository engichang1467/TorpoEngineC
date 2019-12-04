
#include "window.h"

Window* windowCreate(const char *title, int width, int height)
{
    // printf("creating window\n");
    Window* window = malloc(sizeof(Window));
    // printf("window created\n");
    window->title = title;
    // printf("set title\n");
    window->width = width;
    // printf("set width\n");
    window->height = height;
    // printf("set height\n");
    window->windowGL = NULL;

    if (!init(window))
    {
        free(window);
        glfwTerminate();
    }

    return window;
}


void windowDestroy(Window* window){
    free(window);
    glfwTerminate();
}


bool init(Window* window)
{
    if (!glfwInit())
    {
        printf("Fail to initialize GLFW!\n");
        return false;
    }

    window->windowGL = glfwCreateWindow(window->width, window->height, window->title, NULL, NULL);
    if (!window->windowGL)
    {
        printf("Failed to create GLFW window!\n");
        return false;
    }

    glfwMakeContextCurrent(window->windowGL);
    glfwSetWindowSizeCallback(window->windowGL, windowResize);


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

const bool closed(Window* window)
{
    // printf("closed work\n");
    return glfwWindowShouldClose(window->windowGL);
    // printf("closed execute\n");
}

void update(Window* window)
{
    // printf("update working\n");
    glfwPollEvents();
    glfwSwapBuffers(window->windowGL);
}

void windowResize(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int getWidth(Window* window) 
{ 
    return window->width; 
}

int getHeight(Window* window) 
{ 
    return window->height; 
}