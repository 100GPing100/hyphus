#include <SDL2/SDL.h>
#include <GL/gl.h>

#include "core/Engine.h"

#ifdef __cplusplus
extern "C"
#endif
int main(int argc, char ** argv) {
    std::shared_ptr<hyphus::Engine> engine = hyphus::Engine::instance();

    engine->init();
    engine->mainLoop();
    engine->free();

    return 0;
}