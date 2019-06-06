#ifndef __ZE_FORWARD_RENDER_PASS_H__
#define __ZE_FORWARD_RENDER_PASS_H__

#include "RenderPass.h"

namespace ZE
{
	class ForwardRenderPass : public RenderPass
	{
	public:

		virtual void prepare(GameContext* _gameContext) override;
		virtual void release(GameContext* _gameContext) override;

		virtual void begin(GameContext* _gameContext) override;
		virtual void end(GameContext* _gameContext) override;

		virtual bool execute_CPU(GameContext* _gameContext) override;
		virtual bool execute_GPU(GameContext* _gameContext) override;

		static bool ExecutePass(GameContext* _gameContext);
	};
}
#endif