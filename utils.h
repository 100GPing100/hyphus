//
// Created by Super on 26/07/2016.
//

#ifndef HYPHUS_UTILS_H
#define HYPHUS_UTILS_H


// std
#include <functional>
#include <cassert>
#include <exception>
#include <type_traits>


namespace hyphus {
    namespace utils {
        template<typename Base, typename Derived>
        struct is_strict_base_of
                : public std::conditional_t
                        <!std::is_same<Base, Derived>() &&
                         std::is_base_of<Base, Derived>(), std::true_type, std::false_type> {
        };
    }

    namespace math {
        /**
         * C++17 - Using possible implementation from cppreference.com
         *
         * Source: http://en.cppreference.com/w/cpp/algorithm/clamp
         */
        template<class T, class Compare>
        constexpr const T & clamp(const T & v, const T & lo, const T & hi, Compare comp) {
            return assert(!comp(hi, lo)),
                    comp(v, lo) ? lo : comp(hi, v) ? hi : v;
        }

        template<class T>
        constexpr const T & clamp(const T & v, const T & lo, const T & hi) {
            return clamp(v, lo, hi, std::less<>());
        }
    }

    namespace except {
        struct bad_class_exception
                : public std::logic_error {
            bad_class_exception(const char * what) noexcept
                    : std::logic_error(what) { }

            bad_class_exception(const std::string & what) noexcept
                    : std::logic_error(what) { }
        };
    }
}


#endif //HYPHUS_UTILS_H
