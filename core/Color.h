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
        constexpr Color(float r, float g, float b, float a = 1.0f)
            : r{r}
            , g{g}
            , b{b}
            , a{a}
        { }

        Color& operator=(Color&&) = default;
    };

    namespace colors
    {
        const Color Black       = Color(0.0f, 0.0f, 0.0f, 1.0f);
        const Color White       = Color(1.0f, 1.0f, 1.0f, 1.0f);

        const Color Red         = Color(1.0f, 0.0f, 0.0f, 1.0f);
        const Color Green       = Color(0.0f, 1.0f, 0.0f, 1.0f);
        const Color Blue        = Color(0.0f, 0.0f, 1.0f, 1.0f);
    }
}


#endif //HYPHUS_COLOR_H
