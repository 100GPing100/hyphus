//
// Created by Super on 25/07/2016.
//

#ifndef HYPHUS_GRAPHICS_H
#define HYPHUS_GRAPHICS_H


// std
#include <memory>

// hyphus
#include "Color.h"
#include "OpenGLContext.h"

// misc.
#include <SDL2/SDL.h>


namespace hyphus {
    class Graphics {
    public:
        void setClearColor(const Color& color);

        void clear();
        void flush();

        Graphics() = delete; // no default
        Graphics(const Graphics &) = delete; // no copy
        Graphics & operator=(const Graphics &&) = delete; // no move

        Graphics(const OpenGLContext * context);
        virtual ~Graphics();

    private:
        const OpenGLContext * _context;
    };
}


#endif //HYPHUS_GRAPHICS_H
