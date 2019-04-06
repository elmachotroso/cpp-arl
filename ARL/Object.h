#ifndef ARL_OBJECT_H
#define ARL_OBJECT_H

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
        Object * parent = nullptr;
        Object ** siblings = nullptr;
        int siblingsCount = 0;
    };
}

#endif