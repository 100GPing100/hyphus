//
// Created by Super on 25/07/2016.
//

#ifndef HYPHUS_ENGINE_H
#define HYPHUS_ENGINE_H


// std
#include <memory>

// hyphus
#include "Graphics.h"

// misc.
#include <SDL2/SDL.h>

namespace hyphus  {
    class Engine {
    public:
        static std::shared_ptr<Engine> instance();

        void mainLoop();

        bool init();
        bool free();

        Engine();

    private:
        static int watch(void * userdata, SDL_Event * event);

        GraphicsPtr graphics;
        bool quitting;
    };


    typedef std::shared_ptr<Engine> EnginePtr;
}


#endif //HYPHUS_ENGINE_H
