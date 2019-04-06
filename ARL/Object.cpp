#include "Object.hpp"
#include "macros.hpp"

ARL::Object::Object()
    : Object(nullptr)
{
}

ARL::Object::Object(Object *parentToAttach)
    : parent(parentToAttach)
    , siblings(nullptr)
    , siblingsCount(0)
{
}

ARL::Object::Object(const Object & copy)
{
    parent = copy.parent;
    siblingsCount = copy.siblingsCount;
    siblings = new Object*[siblingsCount];
    for(int i = 0; i < siblingsCount; ++i)
    {
        siblings[i] = new Object(copy.siblings[i]);
    }
}

ARL::Object::~Object()
{
    if(siblings != nullptr)
    {
        for(int i = 0; i < siblingsCount; ++i)
        {
            if(siblings[i] != nullptr)
            {
                SAFEDELETE(siblings[i]);
            }
        }

        SAFEDELETE_ARRAY(siblings);
    }
}