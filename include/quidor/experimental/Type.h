//
// Created by Super on 14/08/2016.
//

#ifndef QUIDOR_EXPERIMENTAL_TYPE_H
#define QUIDOR_EXPERIMENTAL_TYPE_H


// std
#include <type_traits>


namespace quidor {
    namespace experimental {

        template<class T> class Type {
        public:
            typedef T class_type;

        public:
            template<class O> // is<O>
            bool operator ==(const Type<O> &) const {
                return std::is_same<class_type, O>();
            }

            template<class O> // is_not<O>
            bool operator !=(const Type<O> & o) const {
                return !(*this == o);
            }

            template<class O> // is_child_of<O>
            bool operator <(const Type<O> &) const {
                return std::is_base_of<class_type, O>() && !std::is_same<class_type, O>();
            }

            template<class O> // is_parent_of<O>
            bool operator >(const Type<O> &) const {
                return std::is_base_of<O, class_type>() && !std::is_same<class_type, O>();
            }

            template<class O> // is_child_of_or<O>
            bool operator <=(const Type<O> &) const {
                return std::is_base_of<class_type, O>();
            }

            template<class O> // is_parent_of_or<O>
            bool operator >=(const Type<O> &) const {
                return std::is_base_of<O, class_type>();
            }

            Type() = default;
            ~Type() = default;
        };

    } /* \experimental */
} /* \quidor */


#endif //QUIDOR_EXPERIMENTAL_TYPE_H
