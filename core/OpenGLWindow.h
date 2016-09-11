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
#include "Graphics.h"


namespace hyphus {
    class OpenGLWindow : public Window {
    public:
        Graphics * graphics() const;


        OpenGLWindow() = delete; // default
        OpenGLWindow(const OpenGLWindow &) = delete; // no copy
        OpenGLWindow & operator=(const OpenGLWindow &&) = delete; // no move

        OpenGLWindow(const std::string & title, const int x, const int y, const int width, const int height, const WindowFlags flags = WindowFlags::None);
        OpenGLWindow(const std::string & title, const int width, const int height, const WindowFlags flags = WindowFlags::None);
        virtual ~OpenGLWindow() noexcept { }

    private:
        std::unique_ptr<Graphics> _graphics;
        std::unique_ptr<OpenGLContext> _context;
    };
}


#endif //HYPHUS_OPENGLWINDOW_H
