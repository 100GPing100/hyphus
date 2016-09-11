//
// Created by Super on 26/07/2016.
//

#ifndef HYPHUS_COLOR_H
#define HYPHUS_COLOR_H


// std
#include <memory>

// ...
#include "utils.h"


namespace hyphus {
    struct Color {
        float r;
        float g;
        float b;
        float a;

        void clamp() noexcept {
            r = math::clamp(r, 0.0f, 1.0f);
            g = math::clamp(g, 0.0f, 1.0f);
            b = math::clamp(b, 0.0f, 1.0f);
            a = math::clamp(a, 0.0f, 1.0f);
        }

        Color() = delete; // no default
        Color(Color &&) = delete; // no move
        Color & operator=(Color &&) = delete; // no move assignment

        constexpr Color(const Color & o) noexcept
            : r(o.r)
            , g(o.g)
            , b(o.b)
            , a(o.a) { }

        constexpr Color(float r, float g, float b, float a = 1.0f) noexcept
            : r{r}
            , g{g}
            , b{b}
            , a{a} { }

        Color & operator=(const Color & o) noexcept {
            r = o.r;
            g = o.g;
            b = o.b;
            a = o.a;

            return *this;
        }
    };

    namespace colors
    {
        constexpr const Color Black       = { 0.0f, 0.0f, 0.0f, 1.0f };
        constexpr const Color White       = { 1.0f, 1.0f, 1.0f, 1.0f };

        constexpr const Color Red         = { 1.0f, 0.0f, 0.0f, 1.0f };
        constexpr const Color Green       = { 0.0f, 1.0f, 0.0f, 1.0f };
        constexpr const Color Blue        = { 0.0f, 0.0f, 1.0f, 1.0f };
    }
}


#endif //HYPHUS_COLOR_H
