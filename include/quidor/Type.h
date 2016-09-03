//
// Created by Super on 05/08/2016.
//

#ifndef QUIDOR_TYPE_H
#define QUIDOR_TYPE_H


// std
#include <string>
#include <vector>


namespace quidor {
    class Type {
    public:
        const char * getName() const {
            return name;
        }

        const Type * getParent() const {
            return parent;
        }

        bool isChildOf(const Type * type) const {
            // parent == type : comparing pointers, each quidor::Object
            // has it's own unique type, owned by ..::classType()
            return type != nullptr && (parent == type || parent->isChildOf(type));
        }

        template<class T>
        bool isChildOf() const {
            return isChildOf(T::classType());
        }

        template<const Type * type>
        bool isChildOf() const {
            return isChildOf(type);
        }

        bool isParentOf(const Type * type) const {
            /* Avoid costly downward iteration:
             *
             *  for (auto it : children) {
             *      // it == type : check isChildOf<T>
             *      if (it == T::classType() || it->isParentOf<T>()) {
             *          return true;
             *      }
             *  }
             *
             * return false;
             */
            return type->isChildOf(this);
        }

        template<class T>
        bool isParentOf() const {
            return isParentOf(T::classType());
        }

        template<const Type * type>
        bool isParentOf() const {
            return isParentOf(type);
        }

        template<bool strict = false>
        bool isA(const Type * type) {
            return this == type || (!strict && isChildOf(type));
        }

        template<class T, bool strict = false>
        bool isA() const {
            return isA<strict>(T::classType());
        }

        template<const Type * type, bool strict = false>
        bool isA() const {
            return isA<strict>(type);
        }

        Type() = delete;
        ~Type() = default;

        constexpr Type(const char * name, const Type * parent)
            : name(name)
            , parent(parent)
        { }

    private:
        const char * name;
        const Type * parent;
    };
}


#endif //QUIDOR_TYPE_H
