//
// Created by Super on 25/07/2016.
//

#include "Engine.h"

// std
#include <cstring>

static hyphus::Graphics * g = nullptr;
int set_background(lua_State * l) {
    const std::string color = lua_tostring(l, -1);
    lua_pop(l, 1);

    if (color == "red") {
        g->setClearColor(hyphus::colors::Red);
    } else if (color == "green") {
        g->setClearColor(hyphus::colors::Green);
    } else if (color == "blue") {
        g->setClearColor(hyphus::colors::Blue);
    } else {
        g->setClearColor(hyphus::colors::Black);
    }

    return 0;
}


namespace hyphus  {
    void Engine::mainLoop() {
        SDL_Event event;
        while (_quitting == false) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    _quitting = true;
                } else if (event.type == SDL_KEYDOWN) {
                    if (event.key.keysym.scancode == SDL_SCANCODE_R) {
                        _lua->call("on_key", "r");
                        //_graphics->setClearColor(colors::Red);
                    } else if (event.key.keysym.scancode == SDL_SCANCODE_G) {
                        _lua->call("on_key", "g");
                        //_graphics->setClearColor(colors::Green);
                    } else if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                        _lua->call("on_key", "b");
                        //_graphics->setClearColor(colors::Blue);
                    }
                }
            }

            _graphics->clear();
            _graphics->flush();
        }
    }

    Engine::Engine() {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
            std::string err = "Failed to initialise SDL: ";
            err += SDL_GetError();

            SDL_Log(err.c_str());
            throw std::runtime_error(err.c_str());
        }

        _window.reset(new OpenGLWindow("hyphus_window", 800, 600));
        _graphics.reset(new Graphics(_window->context()));
        _lua.reset(new LuaState());

        g = _graphics.get();
        _lua->load("test.lua");
        _lua->reg(set_background, "set_background");

        SDL_AddEventWatch(Engine::_watch, this);
    }

    Engine::~Engine() {
        _graphics.reset(); // explicit delete
        _window.reset(); // explicit delete

        SDL_DelEventWatch(Engine::_watch, nullptr);
        SDL_Quit();
    }

    int Engine::_watch(void * userdata, SDL_Event * event) {
        Engine * engine = static_cast<Engine *>(userdata); // non-owning

        if (event->type == SDL_APP_WILLENTERBACKGROUND) {
            engine->_quitting = true;
        }

        return 1;
    }
}