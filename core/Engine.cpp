//
// Created by Super on 25/07/2016.
//

#include "Engine.h"
#include <cstring>


namespace hyphus  {
    void Engine::mainLoop() {
        SDL_Event event;
        while (quitting == false) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    quitting = true;
                } else if (event.type == SDL_KEYDOWN) {
                    if (event.key.keysym.scancode == SDL_SCANCODE_R) {
                        graphics->setClearColor(colors::Red);
                    } else if (event.key.keysym.scancode == SDL_SCANCODE_G) {
                        graphics->setClearColor(colors::Green);
                    } else if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                        graphics->setClearColor(colors::Blue);
                    }
                }
            }

            graphics->clear();
            graphics->flush();
        }
    }

    Engine::Engine() {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
            std::string err = "Failed to initialise SDL: ";
            err += SDL_GetError();

            SDL_Log(err.c_str());
            throw std::runtime_error(err.c_str());
        }

        graphics.reset(new Graphics("hyphus_window"));

        SDL_AddEventWatch(Engine::watch , this);
    }

    Engine::~Engine() {
        graphics.reset(); // explicit delete

        SDL_DelEventWatch(Engine::watch, nullptr);
        SDL_Quit();
    }

    int Engine::watch(void * userdata, SDL_Event *event) {
        Engine * engine = static_cast<Engine *>(userdata); // non-owning

        if (event->type == SDL_APP_WILLENTERBACKGROUND) {
            engine->quitting = true;
        }

        return 1;
    }
}