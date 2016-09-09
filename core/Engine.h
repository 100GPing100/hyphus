//
// Created by Super on 25/07/2016.
//

#ifndef HYPHUS_ENGINE_H
#define HYPHUS_ENGINE_H


// std
#include <memory>

// hyphus
#include "OpenGLWindow.h"
#include "Graphics.h"
#include "LuaState.h"


namespace hyphus  {
    class Engine {
    public:
        void mainLoop();

        Engine();
        virtual ~Engine();

    private:
        static int _watch(void * userdata, SDL_Event * event);

        std::unique_ptr<OpenGLWindow> _window;
        std::unique_ptr<Graphics> _graphics;
        std::unique_ptr<LuaState> _lua;
        bool _quitting;
    };
}


#endif //HYPHUS_ENGINE_H
