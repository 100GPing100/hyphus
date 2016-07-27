//
// Created by Super on 25/07/2016.
//

#include "Engine.h"
#include <GL/gl.h>

namespace hyphus
{
    std::shared_ptr<Engine> Engine::instance() {
        static std::shared_ptr<Engine> engine = std::make_shared<Engine>();
        return engine;
    }

    void Engine::mainLoop() {
        SDL_Event event;
        while (quitting == false) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    quitting = true;
                }
            }

            render();
        }
    }

    bool Engine::init() {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
            SDL_Log("Failed to initialise SDL: %s", SDL_GetError());
            return false;
        }

        window = SDL_CreateWindow(
                "Title",                // title
                SDL_WINDOWPOS_CENTERED, // pos_x
                SDL_WINDOWPOS_CENTERED, // pos_x
                512,                    // width
                512,                    // height
                SDL_WINDOW_OPENGL       // flags
        );

        gl_context = SDL_GL_CreateContext(window);
        SDL_AddEventWatch(Engine::watch , nullptr);
    }

    bool Engine::free() {
        SDL_DelEventWatch(Engine::watch, nullptr);
        SDL_GL_DeleteContext(gl_context);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    Engine::Engine() { }

    int Engine::watch(void *userdata, SDL_Event *event) {
        if (event->type == SDL_APP_WILLENTERBACKGROUND) {
            Engine::instance()->quitting = true;
        }

        return 1;
    }

    void Engine::render() {
        SDL_GL_MakeCurrent(window, gl_context);

        glClearColor(0.3f, 0.4f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window);
    }
}