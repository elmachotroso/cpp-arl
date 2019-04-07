#ifndef ARL_OBJECT_HPP
#define ARL_OBJECT_HPP

namespace ARL
{
    class Object
    {
        public:
        Object();
        Object(Object *parentToAttach);
        Object(const Object & copy);
        ~Object();

        protected:
        Object * _parent;
        Object ** _siblings;
        int _siblingsCount;
    };
}

#endif //ARL_OBJECT_HPP