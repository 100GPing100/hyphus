//
// Created by Super on 25/07/2016.
//

#include "Graphics.h"

#include <GL/glew.h>


namespace hyphus {
    void Graphics::setClearColor(const Color& color) {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void Graphics::clear() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Graphics::flush() {
        SDL_GL_SwapWindow(window);
        glCreateProgram();
    }

    Graphics::Graphics(std::string title, int width, int height) {
        window = SDL_CreateWindow(
                title.c_str(),          // title
                SDL_WINDOWPOS_CENTERED, // pos_x
                SDL_WINDOWPOS_CENTERED, // pos_x
                width,                  // width
                height,                 // height
                SDL_WINDOW_OPENGL       // flags
        );

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        context = SDL_GL_CreateContext(window);
        SDL_GL_MakeCurrent(window, context);


        // load opengl after context creation
        glewExperimental = true; // temporary fix
        GLenum err = glewInit();
        if (err != GLEW_OK) {
            throw std::runtime_error("Failed to initialise glew.");
        }
    }

    Graphics::~Graphics() {
        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);
    }
}