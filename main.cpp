//
//Hyphus
//
// Created by zeluisping on 25/07/2016
//

#include "core/Engine.h"


#ifdef __cplusplus
extern "C"
#endif
int main(int argc, char ** argv) {
    try {
        std::unique_ptr<hyphus::Engine> engine(new hyphus::Engine());


        engine->mainLoop();
    } catch (std::exception e) {
        // @todo: handle gracefully
    } catch (...) {
        // non-standard exceptions
        // @todo: handle
    }
}