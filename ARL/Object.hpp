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
        Object * parent;
        Object ** siblings;
        int siblingsCount;
    };
}

#endif //ARL_OBJECT_HPP