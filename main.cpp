//
//Hyphus
//
// Created by zeluisping on 25/07/2016
//


// std
#include <iostream>

// hyphus
#include "core/Engine.h"



extern "C" int main(int argc, char ** argv) {
    std::cout << std::boolalpha;

    try {
        hyphus::Engine engine { };

        engine.mainLoop();
    } catch (std::exception e) {
        printf("error: %s", e.what());
        getchar();
    } catch (...) {
        printf("error: unknown");
        getchar();
    }

    return 0;
}