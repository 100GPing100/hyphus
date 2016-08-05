//
// Created by Super on 30/07/2016.
//

#ifndef HYPHUS_COMPONENT_H
#define HYPHUS_COMPONENT_H


// quidor
#include <quidor/Object.h>

namespace hyphus {
    class Component : public quidor::Object {
        ObjectMeta(hyphus::Component, quidor::Object);
    };
}


#endif //HYPHUS_COMPONENT_H
