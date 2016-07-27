//
// Created by Super on 25/07/2016.
//

#ifndef HYPHUS_GRAPHICS_H
#define HYPHUS_GRAPHICS_H


// std
#include <memory>

// hyphus
#include "Color.h"

// misc.
#include <SDL2/SDL.h>


namespace hyphus {
    class Graphics {
    public:
        void setClearColor(const Color& color);

        void clear();

        Graphics() = default;
        Graphics(const Graphics&) = delete;
        Graphics& operator=(const Graphics&&) = delete;

    private:
        SDL_Window *window;
        SDL_GLContext context;
    };
}


#endif //HYPHUS_GRAPHICS_H
