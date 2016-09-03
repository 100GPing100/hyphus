//
// Created by Super on 26/07/2016.
//

#include "Color.h"
#include <stdpp.h>


namespace hyphus {
    void Color::clamp() {
        r = stdpp::clamp(r, 0.0f, 1.0f);
        g = stdpp::clamp(g, 0.0f, 1.0f);
        b = stdpp::clamp(b, 0.0f, 1.0f);
        a = stdpp::clamp(a, 0.0f, 1.0f);
    }
}