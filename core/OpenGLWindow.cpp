//
// Created by 100GPing100 on 04/09/2016.
//

#include "OpenGLWindow.h"


namespace hyphus {
    Graphics * OpenGLWindow::graphics() const {
        return _graphics.get();
    }

    OpenGLWindow::OpenGLWindow(const std::string & title, const int x, const int y, const int width, const int height,
                               WindowFlags flags)
            : Window(title, x, y, width, height, flags | WindowFlags::OpenGL) {
        _context = std::make_unique<OpenGLContext>(handle(), 3, 1);
        _graphics = std::make_unique<Graphics>(_context.get());
    }


    OpenGLWindow::OpenGLWindow(const std::string & title, const int width, const int height, WindowFlags flags)
            : OpenGLWindow(title, PositionCentered, PositionCentered, width, height, flags) { }
}
