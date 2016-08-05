//
// Created by Super on 30/07/2016.
//

#ifndef HYPHUS_ENTITY_H
#define HYPHUS_ENTITY_H


// std
#include <vector>

// hyphus
#include <core/Component.h>

namespace hyphus {
    class Entity {
    public:
        /*
        template<class T = Component>
        std::vector<T &> get_components();

        template<class T = Component>
        std::vector<T &> find_components(void (& check)(T &));
        */
    private:
        std::vector<Component> components;
    };




}


#endif //HYPHUS_ENTITY_H
