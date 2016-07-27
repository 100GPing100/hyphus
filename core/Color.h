//
// Created by Super on 26/07/2016.
//

#ifndef HYPHUS_COLOR_H
#define HYPHUS_COLOR_H


// std
#include <memory>


namespace hyphus {
    struct Color {
        float r;
        float g;
        float b;
        float a;

        void clamp();

        Color() = delete;
        Color(const Color&) = default;
        constexpr Color(float r, float g, float b, float a = 1.0f);

        Color& operator=(const Color&&) = default;
    };

}


#endif //HYPHUS_COLOR_H
