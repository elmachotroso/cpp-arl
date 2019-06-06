#include "Object.hpp"
#include "macros.hpp"

#include <algorithm>

using namespace ARL;

Object::Object()
    : Object(nullptr)
{
}

Object::Object(Object *parentToAttach)
    : Object(parentToAttach, string(""))
{
}

Object::Object(Object *parentToAttach, string const & name)
	: _parent(parentToAttach)
	, _children(vector< Object *>(8))
	, _name(name)
{

}

Object::Object(const Object & copy)
{
    _parent = copy._parent;
	_children = copy._children;
	_name = copy._name;
}

Object::~Object()
{
	/*std::transform(_children.begin(), _children.end(), _children.begin(), [](Object * child) -> Object * {
		if (child != nullptr)
		{
			SAFEDELETE(child);
		}
		return child;
	});*/
    for(uint32_t i = 0; i < _children.size(); ++i)
    {		
        if(_children[i] != nullptr)
        {
            SAFEDELETE(_children[i]);
        }
    }
	_children.clear();
}

void Object::AddChild(Object * childObject)
{
	if (childObject == nullptr)
	{
		return;
	}
	_children.push_back(childObject);
}

void Object::RemoveChild(Object * childObject)
{
	if (childObject == nullptr)
	{
		return;
	}
	auto foundChild = std::find(_children.begin(), _children.end(), childObject);
	if (foundChild != _children.end())
	{
		_children.erase(foundChild);
	}
}

Object & Object::GetChild(int index)
{
	Object * child = nullptr;
	return *child;
}

#ifdef DEBUG_VERBOSE
string Object::ToString() const
{
	string builder;
	builder += "";
	return builder;
}
#endif //DEBUG_VERBOSE