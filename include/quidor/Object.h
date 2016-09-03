//
// Created by Super on 05/08/2016.
//

#ifndef QUIDOR_OBJECT_H
#define QUIDOR_OBJECT_H


// quidor
#include "Type.h"


#define ObjectMeta(class, parent) \
    public: \
        static constexpr const quidor::Type class_type = quidor::Type(#class, &parent::class_type); \
        \
        virtual const quidor::Type * getClassType() const { \
            return &class::class_type; \
        } \
    private:
//ObjectMeta(class, parent)

namespace quidor {
    class Object {
    public:
        static constexpr const quidor::Type class_type = quidor::Type("quidor::Object", nullptr);

        virtual const Type * getClassType() const {
            return &class_type;
        }

        virtual std::string toString() const {
            return this->getClassType()->getName();
        }

        Object() = default;
        virtual ~Object() = default;
    };
}


#endif //QUIDOR_OBJECT_H
