#ifndef __ZE_GL_ENUMS_H__
#define  __ZE_GL_ENUMS_H__

#include "Renderer/Enums.h"
#include "Utils/PrimitiveTypes.h"
#include "Utils/Macros.h"

#include <GL/glew.h>

namespace ZE
{
	FORCEINLINE GLenum getGLAttachmentType(EFrameBuferAttachmentType attachType, UInt32 index = 0)
	{
		switch (attachType)
		{
		case ZE::COLOR_ATTACHMENT:
			return GL_COLOR_ATTACHMENT0 + index;
			break;
		case ZE::DEPTH_ATTACHMENT:
			return GL_DEPTH_ATTACHMENT;
			break;
		case ZE::STENCIL_ATTACHMENT:
			return GL_STENCIL_ATTACHMENT;
			break;
		case ZE::DEPTH_STENCIL_ATTACHMENT:
			return GL_DEPTH_STENCIL;
			break;
		default:
			return GL_NONE;
		}
	}

	FORCEINLINE GLenum getGLStorageFormat(ERenderBufferFormat engineFormat)
	{
		switch (engineFormat)
		{
		case ZE::COLOR_RGB:
			return GL_RGB32F;
		case ZE::COLOR_RGB_ALPHA:
			return GL_RGBA32F;
		case ZE::COLOR_sRGB:
			return GL_SRGB8;
		case ZE::COLOR_sRGB_ALPHA:
			return GL_SRGB8_ALPHA8;
		case ZE::DEPTH_ONLY:
			return GL_DEPTH_COMPONENT32F;
		case ZE::DEPTH_STENCIL:
			return GL_DEPTH24_STENCIL8;
		case ZE::STENCIL_ONLY:
			return GL_STENCIL_INDEX8;
		default:
			return GL_NONE;
		}
	}

	FORCEINLINE GLenum getGLDataType(EDataType dataType)
	{
		switch (dataType)
		{
		case ZE::FLOAT:
			return GL_FLOAT;
		case ZE::INTEGER:
			return GL_INT;
		case ZE::UNSIGNED_INTEGER:
			return GL_UNSIGNED_INT;
		case ZE::BYTE:
			return GL_BYTE;
		case ZE::UNSIGNED_BYTE:
			return GL_UNSIGNED_BYTE;
		default:
			return GL_NONE;
		}
	}

	FORCEINLINE GLint getTextureWrap(ETextureWrap wrap)
	{
		switch (wrap)
		{
		case REPEAT:
			return GL_REPEAT;
		case MIRRORED_REPEAT:
			return GL_MIRRORED_REPEAT;
		case CLAMP_TO_EDGE:
			return GL_CLAMP_TO_EDGE;
		case CLAMP_TO_BORDER:
			return GL_CLAMP_TO_BORDER;
		default:
			return 0;
		}
	}

	FORCEINLINE GLint getTextureFilter(ETextureFilter filter)
	{
		switch (filter)
		{
		case NEAREST:
			return GL_NEAREST;
		case NEAREST_MIPMAP_NEAREST:
			return GL_NEAREST_MIPMAP_NEAREST;
		case LINEAR_MIPMAP_NEAREST:
			return GL_LINEAR_MIPMAP_NEAREST;
		case NEAREST_MIPMAP_LINEAR:
			return GL_NEAREST_MIPMAP_LINEAR;
		case LINEAR:
			return GL_LINEAR;
		case LINEAR_MIPMAP_LINEAR:
			return GL_LINEAR_MIPMAP_LINEAR;
		default:
			return 0;
		}
	}

	FORCEINLINE GLenum getGLTextureFormat(ETextureFormat format) 
	{
		switch (format)
		{
		case ZE::TEX_RED:
			return GL_RED;
		case ZE::TEX_RED_GREEN:
			return GL_RG;
		case ZE::TEX_RGB:
			return GL_RGB;
		case ZE::TEX_RGBA:
			return GL_RGBA;
		case ZE::TEX_DEPTH:
			return GL_DEPTH_COMPONENT;
		case ZE::TEXT_DEPTH_STENCIL:
			return GL_DEPTH_STENCIL;
		case ZE::TEX_NONE:
		default:
			return GL_NONE;
		}
	}
}
#endif