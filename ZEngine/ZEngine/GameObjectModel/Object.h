#ifndef __ZE_OBJECT_H__
#define __ZE_OBJECT_H__

// Outer engine includes
#include <vector>

#include "../Utils/PrimitiveTypes.h"

#include "ObjDecl.h"
#include "RTTI.h"

namespace ZE {
	class Object {
	public:
		Object() {}
		virtual ~Object() {}

		virtual int getClassID() = 0;
		virtual const char* getClassName() = 0;

		static std::vector<Int32>& ClassMap();

		static void RegisterClass() {};

	};

	
};

#endif
