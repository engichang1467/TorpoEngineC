#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

typedef struct window
{
    const char *title;
    int width, height;
    GLFWwindow *windowGL;
    bool closed;
} Window;

Window* windowCreate(const char *title, int width, int height);
void windowDestroy(Window* window);

bool init(Window* window);
const void clear();
const bool closed(Window* window); 
void update(Window* window);

int getWidth(Window* window);
int getHeight(Window* window);
void windowResize(GLFWwindow *window, int width, int height);