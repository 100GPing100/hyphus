//
// Created by 100GPing100 on 03/09/2016.
//

#ifndef HYPHUS_WINDOW_H
#define HYPHUS_WINDOW_H


// std
#include <string>
#include <stdexcept>

// sdl2
#include <SDL2/SDL.h>


namespace hyphus {
    enum class WindowFlags : uint32_t {
        None = 0,
        Fullscreen = SDL_WINDOW_FULLSCREEN,
        FullscreenDesktop = SDL_WINDOW_FULLSCREEN_DESKTOP,
        OpenGL = SDL_WINDOW_OPENGL,
        Shown = SDL_WINDOW_SHOWN,
        Hidden = SDL_WINDOW_HIDDEN,
        Borderless = SDL_WINDOW_BORDERLESS,
        Resizable = SDL_WINDOW_RESIZABLE,
        Minimized = SDL_WINDOW_MINIMIZED,
        Maximized = SDL_WINDOW_MAXIMIZED,
        InputGrabbed = SDL_WINDOW_INPUT_GRABBED,
        InputFocus = SDL_WINDOW_INPUT_FOCUS,
        MouseFocus = SDL_WINDOW_MOUSE_FOCUS,
        Foreign = SDL_WINDOW_FOREIGN,
        AllowHighDPI = SDL_WINDOW_ALLOW_HIGHDPI,
        MouseCapture = SDL_WINDOW_MOUSE_CAPTURE,
    };

    class Window {
    public:
        static constexpr const uint32_t PositionCentered = SDL_WINDOWPOS_CENTERED;
        static constexpr const uint32_t PositionUndefined = SDL_WINDOWPOS_UNDEFINED;

    public:
        SDL_Window * handle() const {
            return _handle;
        }

        WindowFlags getFlags() const {
            return static_cast<WindowFlags>(SDL_GetWindowFlags(_handle));
        }

        Window() = delete; // no default
        Window(const Window &) = delete; // no copy
        Window & operator=(const Window &&) = delete; // no move

        Window(SDL_Window * handle);
        Window(const std::string & title, const int x, const int y, const int width, const int height, const WindowFlags flags);
        Window(const std::string & title, const int width, const int height, const WindowFlags flags);

        virtual ~Window();

    private:
        SDL_Window * _handle;
    };
}

inline hyphus::WindowFlags operator |(const hyphus::WindowFlags & a, const hyphus::WindowFlags & b) {
    return static_cast<hyphus::WindowFlags>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b));
}

inline hyphus::WindowFlags operator &(const hyphus::WindowFlags & a, const hyphus::WindowFlags & b) {
    return static_cast<hyphus::WindowFlags>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b));
}

inline bool operator %(const hyphus::WindowFlags & a, const hyphus::WindowFlags & b) {
    return (a & b) == b;
}

#endif //HYPHUS_WINDOW_H
