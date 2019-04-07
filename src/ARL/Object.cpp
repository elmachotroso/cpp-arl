#include "Object.hpp"
#include "macros.hpp"

ARL::Object::Object()
    : Object(nullptr)
{
}

ARL::Object::Object(Object *parentToAttach)
    : _parent(parentToAttach)
    , _siblings(nullptr)
    , _siblingsCount(0)
{
}

ARL::Object::Object(const Object & copy)
{
    _parent = copy._parent;
    _siblingsCount = copy._siblingsCount;
    _siblings = new Object*[_siblingsCount];
    for(int i = 0; i < _siblingsCount; ++i)
    {
        _siblings[i] = new Object(copy._siblings[i]);
    }
}

ARL::Object::~Object()
{
    if(_siblings != nullptr)
    {
        for(int i = 0; i < _siblingsCount; ++i)
        {
            if(_siblings[i] != nullptr)
            {
                SAFEDELETE(_siblings[i]);
            }
        }

        SAFEDELETE_ARRAY(_siblings);
    }
}