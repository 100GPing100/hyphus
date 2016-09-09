//
// Created by 100GPing100 on 03/09/2016.
//
#include "Window.h"

// std
#include <stdexcept>


namespace hyphus {
    Window::Window(SDL_Window * handle) {
        if (handle == nullptr) {
            throw std::invalid_argument("'handle' cannot be 'nullptr'. Can't create window from null handle.");
        }

        _handle = handle;
    }

    Window::Window(const std::string & title, const int x, const int y, const int width, const int height,
                   const WindowFlags flags) {
        _handle = SDL_CreateWindow(title.c_str(), x, y, width, height, static_cast<Uint32>(flags));

        if (_handle == nullptr) {
            throw std::runtime_error(SDL_GetError());
        }
    }

    Window::Window(const std::string & title, const int width, const int height, const WindowFlags flags)
            : Window(title, PositionCentered, PositionCentered, width, height, flags) {
    }

    Window::~Window() {
        SDL_ClearError();
        SDL_DestroyWindow(_handle); // error if _handle == nullptr

        // _handle is never nullptr, thus we don't check
        // for errors on the call to SDL_DestroyWindow
    }
}
