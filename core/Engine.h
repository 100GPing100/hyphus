//
// Created by Super on 25/07/2016.
//

#ifndef HYPHUS_ENGINE_H
#define HYPHUS_ENGINE_H


// std
#include <memory>

// hyphus
#include "Graphics.h"


namespace hyphus  {
    class Engine {
    public:
        void mainLoop();

        Engine();
        virtual ~Engine();

    private:
        static int watch(void * userdata, SDL_Event * event);

        std::unique_ptr<Graphics> graphics;
        bool quitting;
    };
}


#endif //HYPHUS_ENGINE_H
