//
// Created by Super on 30/07/2016.
//

#ifndef HYPHUS_ENTITY_H
#define HYPHUS_ENTITY_H


// std
#include <vector>
#include <algorithm>


// std
#include <memory>

// hyphus
#include <core/Component.h>

// quidor
#include <quidor/Object.h>

namespace hyphus {
    class Entity final : public quidor::Object {
        ObjectMeta(hyphus::Entity, quidor::Object);

        using ComponentUPtr = std::unique_ptr<Component>;
        using ComponentVector = std::vector<ComponentUPtr>;

    public:
        template<class T, typename ... TArgs>
        void addComponent(TArgs && ... args) {
            components.push_back(std::make_unique<T>(args...));
        }

        template<class T = Component, bool strict = false>
        std::vector<T *> getComponents() const {
            std::vector<T *> result; // non-owning

            std::for_each(components.begin(), components.end(), [&] (ComponentUPtr c) {
                if (c->getClassType()->isA<T, strict>() == true) {
                    result.push_back(reinterpret_cast<T *>(c.get()));
                }
            });

            return result;
        }

        template<class T, bool strict = false>
        bool hasComponent() const {
            return std::find_if(components.begin(), components.end(), [] (const ComponentUPtr & c) -> bool {
                return c->getClassType()->isA<T, strict>();
            }) != components.end();
        }

        Entity() = default;
        Entity(const Entity &) = delete;
        ~Entity() = default;

    private:
        ComponentVector components;
    };
}


#endif //HYPHUS_ENTITY_H
