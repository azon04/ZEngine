#include "PhysXZooid.h"

#include "Memory/Handle.h"
#include "PhysX.h"

namespace ZE
{

	void PhysXZooid::Init()
	{
		Handle physicsHandle("PhysX Physics", sizeof(PhysXEngine));
		m_physics = new(physicsHandle) PhysXEngine();
		m_physics->Setup();
	}

	void PhysXZooid::Destroy()
	{
		m_physics->Destroy();
		m_physics = nullptr;
	}

}