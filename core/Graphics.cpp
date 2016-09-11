//
// Created by Super on 25/07/2016.
//

#include "Graphics.h"

#include <GL/glew.h>
#include "Engine.h"

namespace hyphus {
    void Graphics::setClearColor(const Color& color) {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void Graphics::clear() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Graphics::flush() {
        _context->swap_window();
    }

    Graphics::Graphics(const OpenGLContext * context)
            : _context(context) {
        context->make_current();
    }

    Graphics::~Graphics() {
    }
}