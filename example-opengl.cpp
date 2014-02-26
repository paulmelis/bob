/// uselibrary GL
/// usepackage sdl
#include <GL/gl.h>
#include <SDL.h>

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    const SDL_VideoInfo *vidinfo = SDL_GetVideoInfo();
    printf("Screen resolution: %d x %d\n", vidinfo->current_w, vidinfo->current_h);    
        
    int flags = SDL_OPENGL | SDL_DOUBLEBUF | SDL_HWSURFACE;
    SDL_Surface *surface;
    
    surface = SDL_SetVideoMode(800, 600, 0, flags);        
    if (surface == NULL)
    {
        fprintf(stderr, "Unable to create OpenGL screen: %s\n", SDL_GetError());
        SDL_Quit();
        exit(-1);
    }    
    
    printf("Vendor: %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Version: %s\n", glGetString(GL_VERSION));
    printf("GLSL version: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
    printf("Extensions: %s\n", glGetString(GL_EXTENSIONS));

    SDL_Quit();
    
    return 0;
}