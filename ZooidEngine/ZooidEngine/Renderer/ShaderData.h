#ifndef __ZE_SHADER_DATA_H__
#define __ZE_SHADER_DATA_H__

#include "Utils/PrimitiveTypes.h"
#include "Math/Matrix4x4.h"

#define MAX_NUMBER_OF_LIGHT 8

namespace ZE
{
	struct ShaderData
	{
		Float32 ViewMat[4][4];
		Float32 ProjectionMat[4][4];

		void setViewMat(Matrix4x4& _viewMat4);
		void setProjectionMat(Matrix4x4& _projectionMat4);
	};

	struct LightStruct
	{
		Int32 Type;

		// For flashlight
		Float32 CutOff;
		Float32 OuterCutOff;

		// use for attenuation
		Float32 Att_constant;
		Float32 Att_linear;
		Float32 Att_quadratic;

		// padding
		Float32 Padding[2];

		Float32 Position[4];
		Float32 Direction[4];

		Float32 Ambient[4];
		Float32 Diffuse[4];
		Float32 Specular[4];

		void setPosition(Vector3& _position);
		void setDirection(Vector3& _direction);
		void setAmbient(Vector3& _ambient);
		void setDiffuse(Vector3& _diffuse);
		void setSpecular(Vector3& _specular);

	};

	struct LightData
	{
		LightData() : NumLight(0) { }

		Float32 ViewPos[3];
		UInt32 NumLight;

		LightStruct lights[MAX_NUMBER_OF_LIGHT];

		void setViewPos(Vector3& _viewPos);
	};
}
#endif
