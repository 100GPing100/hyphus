//
// Created by Super on 14/08/2016.
//

#ifndef QUIDOR_EXPERIMENTAL_OBJECT_H
#define QUIDOR_EXPERIMENTAL_OBJECT_H


// quidor
#include "Type.h"


#define QuidorObjectMeta(class) \
    public: \
        static constexpr const char * className() { \
            return #class; \
        } \
        \
        static const quidor::experimental::Type<class> classType() { \
            return quidor::experimental::Type<class>(); \
        } \
        \
        virtual const quidor::experimental::Type<class> getClassType() const { \
            return class::classType(); \
        } \
    private:
//\ObjectMeta(class)


namespace quidor {
    namespace experimental {

        class Object {
        public:
            static constexpr const char * className() {
                return "quidor::experimental::Object";
            }

            static const Type<Object> classType() {
                return Type<Object>();
            }

            virtual const Type<Object> getClassType() const {
                return Object::classType();
            }

            Object() = default;
            virtual ~Object() = default;

        private:
        };

    }
}

#endif //QUIDOR_EXPERIMENTAL_OBJECT_H
