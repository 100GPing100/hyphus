//
// Created by Super on 26/07/2016.
//

#ifndef HYPHUS_STDPP_H
#define HYPHUS_STDPP_H


// std
#include <functional>
#include <cassert>

namespace stdpp {
    /**
     * C++17 - Using possible implementation from cppreference.com
     *
     * Source: http://en.cppreference.com/w/cpp/algorithm/clamp
     */
    template<class T, class Compare>
    constexpr const T &clamp(const T &v, const T &lo, const T &hi, Compare comp) {
        return assert(!comp(hi, lo)),
                comp(v, lo) ? lo : comp(hi, v) ? hi : v;
    }

    template<class T>
    constexpr const T &clamp(const T &v, const T &lo, const T &hi) {
        return clamp(v, lo, hi, std::less<T>()); // they missed a T on std::less<>
    }


}


#endif //HYPHUS_STDPP_H
