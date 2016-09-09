//
// Created by 100GPing100 on 04/09/2016.
//

#ifndef HYPHUS_OPENGLWINDOW_H
#define HYPHUS_OPENGLWINDOW_H


// std
#include <memory>

// ...
#include "Window.h"
#include "OpenGLContext.h"


namespace hyphus {
    class OpenGLWindow : public Window {
    public:
        std::weak_ptr<OpenGLContext> context() const;

        OpenGLWindow() = delete; // default
        OpenGLWindow(const OpenGLWindow &) = delete; // no copy
        OpenGLWindow & operator=(const OpenGLWindow &&) = delete; // no move

        OpenGLWindow(const std::string & title, const int x, const int y, const int width, const int height, const WindowFlags flags = WindowFlags::None);
        OpenGLWindow(const std::string & title, const int width, const int height, const WindowFlags flags = WindowFlags::None);
        virtual ~OpenGLWindow() { }

    private:
        std::shared_ptr<OpenGLContext> _context;
    };
}


#endif //HYPHUS_OPENGLWINDOW_H
