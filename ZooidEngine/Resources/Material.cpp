#include "Material.h"
#include "Utils/String.h"

#include "Renderer/IShader.h"
#include "Renderer/IGPUTexture.h"

#include <stdio.h>

namespace ZE
{
	IMPLEMENT_CLASS_0(Material);

	void Material::Bind(IShaderChain* shaderChain)
	{
		int iDiffuse = 0;
		int iSpecular = 0;
		int iNormal = 0;
		int iMask = 0;
		for (int i = 0; i < m_textures.length(); ++i)
		{
			MaterialTexture& matTexture = m_textures[i];
			String varName(1024);
			varName += "material.";
			switch (matTexture.type)
			{
			case TextureType::DIFFUSE:
				varName += "diffuseMap";
				iDiffuse++;
				break;
			case TextureType::SPECULAR:
				varName += "specularMap";
				iSpecular++;
				break;
			case TextureType::NORMAL:
				varName += "normalMap";
				iNormal++;
				break;
			case TextureType::MASK:
				varName += "maskMap";
				iMask++;
				break;
			default:
				break;
			}
			shaderChain->setTexture(varName.c_str(), matTexture.texture, i);
			matTexture.texture->bind();
		}

		shaderChain->setFloat("material.diffuseMapBound", iDiffuse > 0 ? 1.0f : 0.0f);
		shaderChain->setFloat("material.specularMapBound", iSpecular > 0 ? 1.0f : 0.0f);
		shaderChain->setFloat("material.normalMapBound", iNormal > 0 ? 1.0f : 0.0f);
		shaderChain->setInt("material.maskMapBound", iMask > 0);

		shaderChain->setFloat("material.shininess", m_shininess);
		shaderChain->setVec3("material.Ka", m_Ka);
		shaderChain->setVec3("material.Kd", m_Kd);
		shaderChain->setVec3("material.Ks", m_Ks);
	}

	ZE::IGPUTexture* Material::getTextureType(TextureType textureType) const
	{
		for (Int32 i = 0; i < m_textures.size(); i++)
		{
			if (m_textures[i].type == textureType) { return m_textures[i].texture; }
		}
		return nullptr;
	}

}