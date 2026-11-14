#include "framework/Object.h"
#include "framework/Core.h"

namespace ly
{
	Object::Object()
		: mIsPendingDestroy{false}
	{

	}

	Object::~Object()
	{
		LOG("object destroyed");
	}

	void Object::Destroy()
	{
		mIsPendingDestroy = true;
	}

	bool Object::IsPendingDestroy() const
	{
		return mIsPendingDestroy;
	}
}
