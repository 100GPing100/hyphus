//
//Hyphus
//
// Created by zeluisping on 25/07/2016
//

#include "core/Engine.h"
#include <iostream>
#include "core/Component.h"
#include "core/Entity.h"


class HealthComponent : public hyphus::Component {
    ObjectMeta(::HealthComponent, hyphus::Component);

public:
    int getHealth() const {
        return health;
    }

    void takeDamage(int amount) {
        health = std::max(0, health - amount);
    }

private:
    int health;
};

#include "quidor/experimental/Object.h"

class ChildObject : public quidor::experimental::Object {
    //QuidorObjectMeta(::ChildObject);
};

#ifdef __cplusplus
extern "C"
#endif
int main(int argc, char ** argv) {
    using namespace quidor::experimental;
    //std::vector<std::string> args { argv, argv + argc };

    auto t = Object::classType();
    auto o = Type<Object>();

    auto u = quidor::Object::class_type;

    std::cout << "sizeof(Type<Object>) = " << sizeof(u) << "\n";
    std::cout << "sizeof(Type<Object>) = " << sizeof(o) << " [experimental]\n";

    if (t == o) {
        std::cout << "true\n";
    }

    try {
        auto engine = std::make_unique<hyphus::Engine>();

        engine->mainLoop();
    } catch (std::exception e) {
        printf("error: %s", e.what());
        getchar();
    } catch (...) {
        printf("error: unknown");
        getchar();
    }
}