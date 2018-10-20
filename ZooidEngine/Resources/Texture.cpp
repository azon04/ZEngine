#include "Texture.h"

#include "External/Image/stb_image.h"
#include "Utils/Array.h"

namespace ZE
{
	IMPLEMENT_CLASS_0(Texture)

	Handle Texture::loadTexture(const char* filePath)
	{
		Handle textureHandle(sizeof(Texture));
		int width, height, channel;
		UChar* image = stbi_load(filePath, &width, &height, &channel, 0);

		if (image)
		{
			Texture* texture = new(textureHandle) Texture();
			
			texture->loadFromBuffer(image, width, height, channel);
		}
		else
		{
			ZEINFO("Unable to open texture file : %s ", filePath);
		}

		return textureHandle;
	}

	void Texture::loadFromBuffer(void* buffer, UInt32 _width, UInt32 _height, UInt32 _channel)
	{
		m_image = (UChar*)buffer;
		m_width = _width;
		m_height = _height;
		m_channel = _channel;

		switch (m_channel)
		{
		case 1:
			m_format = TEX_RED;
			break;
		case 2:
			m_format = TEX_RED_GREEN;
			break;
		case 3:
			m_format = TEX_RGB;
			break;
		case 4:
			m_format = TEX_RGBA;
			break;
		}
	}

	void Texture::createEmpty(UInt32 _width, UInt32 _height, ETextureFormat _format)
	{
		m_width = _width;
		m_height = _height;
		m_format = _format;
		m_image = nullptr;
	}

	void Texture::release()
	{
		// #TODO texture raw data is not part of Memory management since it's loaded using stbi, convert it later.
		if (m_image)
		{
			free(m_image);
			m_image = nullptr;
		}
	}

}

