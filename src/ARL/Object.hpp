/// Object
/// me@andreivictor.net
/// Generic Object implementation as a base of GameObjects, Components, etc.

#ifndef ARL_OBJECT_HPP
#define ARL_OBJECT_HPP

#include "redirections.hpp"

namespace ARL
{
    class Object
    {
        public:
        Object();
		Object(Object *parentToAttach, string const & name);
        Object(Object *parentToAttach);
        Object(const Object & copy);
        ~Object();

		inline Object & SetName(string const & name);
		inline string GetName() const;
		inline uint32_t GetChildrenCount() const;
		void AddChild(Object * childObject);
		void RemoveChild(Object * childObject);
		Object & GetChild(int index);

        protected:
        Object * _parent;
        vector<Object *> _children;
		string _name;
    };

	inline Object & Object::SetName(string const & name)
	{
		_name = name;
		return *this;
	}

	inline string Object::GetName() const
	{
		return _name;
	}

	inline uint32_t Object::GetChildrenCount() const
	{
		return _children.size();
	}
}

#endif //ARL_OBJECT_HPP