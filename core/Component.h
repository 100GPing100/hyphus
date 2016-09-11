//
// Created by Super on 30/07/2016.
//

#ifndef HYPHUS_COMPONENT_H
#define HYPHUS_COMPONENT_H


namespace hyphus {
    class Entity;

    class Component {
        friend hyphus::Entity;

    public:
        virtual void update(double deltatime) { }

        Entity * owner() const {
            return _owner;
        }

    private:
        Entity * _owner;
    };
}


#endif //HYPHUS_COMPONENT_H
