#include "Material.h"
#include "Utils/String.h"

#include <stdio.h>

namespace ZE
{
	IMPLEMENT_CLASS_0(Material);

	void Material::Bind(ShaderAction& shaderAction)
	{
		int iDiffuse = 0;
		int iSpecular = 0;
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
			default:
				break;
			}
			shaderAction.setShaderTextureVar(varName.c_str(), matTexture.texture, i);
		}

		shaderAction.setShaderFloatVar("material.diffuseMapBound", iDiffuse > 0 ? 1.0f : 0.0f);
		shaderAction.setShaderFloatVar("material.specularMapBound", iSpecular > 0 ? 1.0f : 0.0f);

		shaderAction.setShaderFloatVar("material.shininess", m_shininess);
		shaderAction.setShaderVec3Var("material.Ka", m_Ka);
		shaderAction.setShaderVec3Var("material.Kd", m_Kd);
		shaderAction.setShaderVec3Var("material.Ks", m_Ks);
	}

}