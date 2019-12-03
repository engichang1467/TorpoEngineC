#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

typedef struct window
{
    const char *m_Title;
    int m_Width, m_Height;
    GLFWwindow *m_Window;
    bool m_Closed;
} Window_t;

Window_t* windowCreate(const char *title, int width, int height);
void windowDestroy(Window_t* window);

bool init(Window_t* window);
const void clear();
const bool closed(Window_t* window); 
void update(Window_t* window);

int getWidth(Window_t* window);
int getHeight(Window_t* window);
void windowResize(GLFWwindow *window, int width, int height);