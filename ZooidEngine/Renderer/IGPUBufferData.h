#ifndef __Z_GPU_BUFFER__
#define __Z_GPU_BUFFER__

#include "Utils/PrimitiveTypes.h"
#include "Utils/Macros.h"

#include "Enums.h"

#define MAX_LAYOUT 16

namespace ZE 
{

	class BufferLayout;
	class BufferData;

	class IGPUBufferData 
	{
		friend class BufferManager;

	public:
		IGPUBufferData() 
		{
			m_isStatic = true;
		}

		IGPUBufferData(bool _isStaticBuffer)
			: IGPUBufferData()
		{
			m_isStatic = _isStaticBuffer;
		}

		virtual ~IGPUBufferData();

		// Load GPU Buffer Data from Buffer Data
		virtual void FromBufferData(BufferData* _bufferData);

		// Setup buffer layout
		void SetupLayout(BufferLayout* _layouts);

		// Bind GPU Buffer into render pipeline
		virtual void bind() = 0;

		// Unbind GPU buffer from render pipeline
		virtual void unbind() = 0;

		// Release GPU buffer data
		virtual void release() {};

		// Refresh data to GPU
		virtual void refresh() = 0;

		// Bind and refresh
		virtual void bindAndRefresh() = 0;

		// Write data to the buffer
		virtual void writeData(void* data, size_t size, size_t offset) = 0;

		// Set if the buffer is static
		void setStatic(bool _bStatic) { m_isStatic = _bStatic; }

		// Set the stride of the buffer
		void setStride(UInt32 stride) { m_stride = stride; }

		// Check if the buffer is a static buffer
		bool isStatic() const { return m_isStatic; }
		
		// Set Debug Name
		virtual void setDebugName(const char* debugName) = 0;

		// get data count
		FORCEINLINE Int32 getDataCount() const { return m_dataCount; }

		// Get GPU Binding Index
		FORCEINLINE Int32 getBindingIndex() const { return m_bindingIndex; }

		// Get buffer layout
		FORCEINLINE BufferLayout* getBufferLayout() const { return m_layout; }

		// Get current CPU Buffer Data
		FORCEINLINE BufferData* getBufferData() const { return m_BufferData; }

		// Get the stride of the buffer
		FORCEINLINE UInt32 getStride() const { return m_stride; }

	protected:
		EBufferType m_bufferType;
		BufferData* m_BufferData;

		bool m_isStatic;

		Int32 m_dataCount;
		Int32 m_bindingIndex;
		UInt32 m_stride;
		BufferLayout* m_layout;

	};
};
#endif // __Z_GPU_BUFFER__

