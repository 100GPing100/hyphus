//
// Created by 100GPing100 on 04/09/2016.
//

#ifndef HYPHUS_CONTEXT_H
#define HYPHUS_CONTEXT_H


// sdl2
#include <SDL2/SDL.h>
#include <include/SDL2/SDL_video.h>

// glew
#include <GL/glew.h>


namespace hyphus {
    class OpenGLContext {
    public:
        static void make_none_current() {
            /** from wglMakeCurrent (msdn):
             * If hglrc is NULL, the function makes the calling thread's current rendering
             * context no longer current, and releases the device context that is used by
             * the rendering context. In this case, hdc is ignored.
             */
            SDL_GL_MakeCurrent(nullptr, nullptr);
        }

        const SDL_GLContext * handle() {
            return &_handle;
        }

        void make_current() const {
            SDL_GL_MakeCurrent(_window, _handle);
        }

        void swap_window() const {
            SDL_GL_SwapWindow(_window);
        }

        OpenGLContext(SDL_Window * window, int major, int minor)
                : _window(window) {
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

            _handle = SDL_GL_CreateContext(window);
            if (_handle == nullptr) {
                throw std::runtime_error(std::string("sdl error: ") + SDL_GetError());
            }

            SDL_GL_MakeCurrent(window, _handle);

            glewExperimental = true; // temporary fix
            GLenum err = glewInit();
            if (err != GLEW_OK) {
                throw std::runtime_error(std::string("glew error: ") + reinterpret_cast<const char *>(glewGetErrorString(err)));
            }
        }

        ~OpenGLContext() {
            SDL_GL_DeleteContext(_handle);
        }

        OpenGLContext(const OpenGLContext &) = delete;
        OpenGLContext & operator=(const OpenGLContext &) = delete;


    private:
        SDL_Window * _window;
        SDL_GLContext _handle;
    };
}


#endif //HYPHUS_CONTEXT_H
