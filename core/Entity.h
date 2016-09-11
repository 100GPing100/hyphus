//
// Created by Super on 30/07/2016.
//

#ifndef HYPHUS_ENTITY_H
#define HYPHUS_ENTITY_H


// std
#include <type_traits>
#include <exception>
#include <functional>
#include <vector>
#include <memory>

// hyphus
#include "Component.h"

// ...
#include "utils.h"


namespace hyphus {
    class Entity final {
        struct empty_t { };

    public:
        template<class T, typename ... Args>
        T * add(Args ... args) noexcept(std::is_nothrow_constructible<T, Args ...>()) {
            static_assert(utils::is_strict_base_of<Component, T>(), "'T' must be a child of, and not same as, 'hyphus::Component'");
            static_assert(std::is_constructible<T, Args ...>(), "Cannot construct object with given arguments");

            T * component = new T(std::forward<Args>(args) ...);

            component->_owner = this;

            _components.push_back(static_cast<Component *>(component));

            return component;
        }

        template<class T>
        T * first_of() const noexcept {
            static_assert(utils::is_strict_base_of<Component, T>(), "'T' must be a child of, and not same as, 'hyphus::Component'");

            for (Component * c : _components) {
                T * dc = dynamic_cast<T *>(c);

                if (dc != nullptr) {
                    return dc;
                }
            }

            return nullptr;
        }

        template<class T>
        std::vector<T *> all_of() const noexcept {
            static_assert(utils::is_strict_base_of<Component, T>(), "'T' must be a child of, and not same as, 'hyphus::Component'");

            std::vector<T *> all { };
            for (Component * c : _components) {
                T * dc = dynamic_cast<T *>(c);

                if (dc != nullptr) {
                    all.push_back(dc);
                }
            }

            return std::move(all);
        }

        const std::vector<Component *> & all() const noexcept {
            return _components;
        }

        bool operator ==(const Entity & e) {
            return _id == e._id;
        }

        Entity() noexcept
            : _components{}
            , _id(new empty_t()) { }

        ~Entity() noexcept {
            delete _id;

            for (Component * c : _components) {
                delete c;
            }
        }

        Entity(Entity && o) = delete; // no move
        Entity(const Entity &) = delete; // no copy
        Entity & operator=(const Entity &) = delete; // no copy assign
        Entity & operator=(const Entity &&) = delete; // no move assign

    private:
        std::vector<Component *> _components;
        empty_t * _id;
    };
}


#endif //HYPHUS_ENTITY_H
