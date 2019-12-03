#include "src/graphics/window.h"

int main()
{
    Window_t* window = windowCreate("Torpo!", 960, 540);
    glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

//     printf("Working\n");
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
//     printf("working\n");

    while (!closed(window))
    {
        // printf("%d, %d\n", getWidth(window), getHeight(window));
        clear();
#if 1
        glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.5f,  0.5f);
        glVertex2f( 0.5f,  0.5f);
        glVertex2f( 0.5f, -0.5f);
        glEnd();
#else
        glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
        update(window);
    }
    return 0;
}