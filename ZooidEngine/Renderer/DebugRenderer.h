#ifndef __ZE_DEBUG_RENDERER_H__
#define __ZE_DEBUG_RENDERER_H__

#include "GameObjectModel/Component.h"
#include "Utils/Array.h"
#include "Math/Vector3.h"
#include "Math/Matrix4x4.h"

#define MAX_LINE 2048

namespace ZE
{
	class GameContext;
	class BufferData;
	class IGPUBufferData;
	class IGPUBufferArray;

	struct DebugPointStruct
	{
		Vector3 Point;
		Vector3 Color;
	};

	class DebugRenderer : public Component
	{

		DEFINE_CLASS(DebugRenderer)

	public:

		DebugRenderer(GameContext* gameContext) 
			: Component(gameContext)
		{}

		virtual ~DebugRenderer() {}

		static void Init(GameContext* gameContext);
		static void Destroy();
		static DebugRenderer* GetInstance() { return s_instance; }

		// Draw Matrix Basis (Static call)
		static void DrawMatrixBasis(Matrix4x4& mats);
		
		// Draw Line in 3D world (Static call)
		static void DrawLine(const Vector3& p1, const Vector3& p2, const Vector3& color);

		virtual void setupComponent() override;

		// Handle Gather render event
		void handleGatherRender(Event* _event);

	protected:
		// Draw Matrix Basis
		void drawMatrixBasis(Matrix4x4& mats);
		
		// Draw Line in 3D world
		void drawLine(const Vector3& p1, const Vector3& p2, const Vector3& color);
	
	private:
		static DebugRenderer* s_instance;
		BufferData* m_lineBufferData;
		IGPUBufferData* m_lineGPUBufferData;
		IGPUBufferArray* m_lineBufferArray;
		DebugPointStruct m_lineBuffers[MAX_LINE * 2];
		Int32 m_currentIndex;
	};
}
#endif