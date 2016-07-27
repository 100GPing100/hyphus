//
// Created by Super on 25/07/2016.
//

#include "Graphics.h"
#include <GL/gl.h>


namespace hyphus {
    void Graphics::setClearColor(const Color& color) {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void Graphics::clear() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}