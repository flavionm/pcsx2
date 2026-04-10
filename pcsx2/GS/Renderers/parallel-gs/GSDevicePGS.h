#pragma once

#include "GS/Renderers/Common/GSDevice.h"
#include "GS/Renderers/Common/GSTexture.h"
#include "../Vulkan/VKLoaderPlatformDefines.h"
#include "GS/GSRegs.h"
#include "GS/GSVector.h"
#include "GS/Renderers/parallel-gs/GSRendererPGS.h"
#include "GS/Renderers/parallel-gs/GSTexturePGS.h"
#include "SaveState.h"
#include "GS/GSDump.h"
#include "GS/Renderers/Common/GSRenderer.h"
#include "Config.h"
#include "common/WindowInfo.h"
#include "gs_interface.hpp"
#include "device.hpp"
#include "context.hpp"
#include "wsi.hpp"

class GSDevicePGS final : public GSDevice
{
public:
	GSTexturePGS* CreateTexture(int w, int h, int mipmap_levels, GSTexture::Format format, bool prefer_reuse = false) override;

	GSTexture* CreateSurface(GSTexture::Type type, int width, int height, int levels, GSTexture::Format format) override;

	void DoMerge(GSTexture* sTex[3], GSVector4* sRect, GSTexture* dTex, GSVector4* dRect, const GSRegPMODE& PMODE, const GSRegEXTBUF& EXTBUF, u32 c, const bool linear) override;
	void DoInterlace(GSTexture* sTex, const GSVector4& sRect, GSTexture* dTex, const GSVector4& dRect, ShaderInterlace shader, bool linear, const InterlaceConstantBuffer& cb) override;
	void DoFXAA(GSTexture* sTex, GSTexture* dTex) override;
	void DoShadeBoost(GSTexture* sTex, GSTexture* dTex, const float params[4]) override;

	/// Applies CAS and writes to the destination texture, which should be a RWTexture.
	bool DoCAS(GSTexture* sTex, GSTexture* dTex, bool sharpen_only, const std::array<u32, NUM_CAS_CONSTANTS>& constants) override;

	// Entry point to the renderer-specific StretchRect code.
	void DoStretchRect(GSTexture* sTex, const GSVector4& sRect, GSTexture* dTex, const GSVector4& dRect,
		GSHWDrawConfig::ColorMaskSelector cms, ShaderConvert shader, bool linear) override;

	RenderAPI GetRenderAPI() const override;

	/// Returns true if we have a window we're rendering into.
	bool HasSurface() const override;

	/// Destroys the surface we're currently drawing to.
	void DestroySurface() override;

	/// Switches to a new window/surface.
	bool UpdateWindow() override;

	/// Call when the window size changes externally to recreate any resources.
	void ResizeWindow(u32 new_window_width, u32 new_window_height, float new_window_scale) override;

	/// Returns true if exclusive fullscreen is supported.
	bool SupportsExclusiveFullscreen() const override;

	/// Returns false if the window was completely occluded. If frame_skip is set, the frame won't be
	/// displayed, but the GPU command queue will still be flushed.
	PresentResult BeginPresent(bool frame_skip) override;

	/// Presents the frame to the display.
	void EndPresent() override;

	/// Changes vsync mode for this display.
	void SetVSyncMode(GSVSyncMode mode, bool allow_present_throttle) override;

	/// Returns a string of information about the graphics driver being used.
	std::string GetDriverInfo() const override;

	/// Enables/disables GPU frame timing.
	bool SetGPUTimingEnabled(bool enabled) override;

	/// Returns the amount of GPU time utilized since the last time this method was called.
	float GetAndResetAccumulatedGPUTime() override;

	void PushDebugGroup(const char* fmt, ...) override;
	void PopDebugGroup() override;
	void InsertDebugMessage(DebugMessageCategory category, const char* fmt, ...) override;

	std::unique_ptr<GSDownloadTexture> CreateDownloadTexture(u32 width, u32 height, GSTexture::Format format) override;

	void CopyRect(GSTexture* sTex, GSTexture* dTex, const GSVector4i& r, u32 destX, u32 destY) override;

	/// Performs a screen blit for display. If dTex is null, it assumes you are writing to the system framebuffer/swap chain.
	void PresentRect(GSTexture* sTex, const GSVector4& sRect, GSTexture* dTex, const GSVector4& dRect, PresentShader shader, float shaderTime, bool linear) override;

	/// Updates a GPU CLUT texture from a source texture.
	void UpdateCLUTTexture(GSTexture* sTex, float sScale, u32 offsetX, u32 offsetY, GSTexture* dTex, u32 dOffset, u32 dSize) override;

	/// Converts a colour format to an indexed format texture.
	void ConvertToIndexedTexture(GSTexture* sTex, float sScale, u32 offsetX, u32 offsetY, u32 SBW, u32 SPSM, GSTexture* dTex, u32 DBW, u32 DPSM) override;

	/// Uses box downsampling to resize a texture.
	void FilteredDownsampleTexture(GSTexture* sTex, GSTexture* dTex, u32 downsample_factor, const GSVector2i& clamp_min, const GSVector4& dRect) override;

	void RenderHW(GSHWDrawConfig& config) override;

	void ClearSamplerCache() override;
};
