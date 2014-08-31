#pragma once

#include "RendererState.h"
#include "Shader.h"
#include "../Utils/InputBuffer.h"
#include "Memory/RefPtr.h"
#include "EDXPrerequisites.h"

namespace EDX
{
	namespace RasterRenderer
	{
		class Renderer
		{
		private:
			RendererState mGlobalRenderStates;
			RefPtr<class FrameBuffer> mpFrameBuffer;
			RefPtr<class VertexShader> mpVertexShader;
			RefPtr<class PixelShader> mpPixelShader;
			RefPtr<class Scene> mpScene;

			vector<ProjectedVertex> mProjectedVertexBuf;
			IndexBuffer mIndexBuf;

		public:
			void Initialize(uint iScreenWidth, uint iScreenHeight);
			void SetRenderState(const class Matrix& mModelView, const Matrix& mProj, const Matrix& mToRaster);
			void RenderMesh(const class Mesh& mesh);

			const float* GetBackBuffer() const;

		private:
			void VertexProcessing(const IVertexBuffer* pVertexBuf);
			void Clipping(IndexBuffer* pSrcIdxBuf);
			void FragmentProcessing();
		};

	}
}