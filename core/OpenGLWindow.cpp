//
// Created by 100GPing100 on 04/09/2016.
//

#include "OpenGLWindow.h"


namespace hyphus {
    std::weak_ptr<OpenGLContext> OpenGLWindow::context() const {
        return _context;
    }

    OpenGLWindow::OpenGLWindow(const std::string & title, const int x, const int y, const int width, const int height,
                               WindowFlags flags)
            : Window(title, x, y, width, height, flags | WindowFlags::OpenGL)
            , _context(std::make_shared<OpenGLContext>(handle(), 3, 1)) { }


    OpenGLWindow::OpenGLWindow(const std::string & title, const int width, const int height, WindowFlags flags)
            : OpenGLWindow(title, PositionCentered, PositionCentered, width, height, flags) { }
}
