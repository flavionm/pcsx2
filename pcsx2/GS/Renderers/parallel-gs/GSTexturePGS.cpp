#include "GS/Renderers/Common/GSDevice.h"
#include "GS/Renderers/Common/GSRenderer.h"
#include "GSDevicePGS.h"
#include <memory>
#include "GS/GS.h"
#include "GSTexturePGS.h"
#include "GSRendererPGS.h"
#include "GS/GSState.h"
#include "GS.h"
#include "GS/GSVector.h"
#include "math.hpp"
#include "muglm/muglm_impl.hpp"
#include "shaders/slangmosh.hpp"
#include "PerformanceMetrics.h"
#include "VMManager.h"

using namespace Vulkan;
using namespace ParallelGS;
using namespace Granite;

GSTexturePGS* GSDevicePGS::CreateTexture(int w, int h, int mipmap_levels, GSTexture::Format format, bool prefer_reuse) {
	GSRendererPGS* renderer = (GSRendererPGS*)g_gs_renderer.get();
	renderer->create_surface(renderer->wsi.get_device().get_instance(), renderer->wsi.get_device().get_physical_device());
}

GSTexture* GSDevicePGS::CreateSurface(GSTexture::Type type, int width, int height, int levels, GSTexture::Format format)
{
	Console.Warning("paraLLEl-GS CreateSurface method called, stub implementation");
	return nullptr;
}
void GSDevicePGS::DoMerge(GSTexture* sTex[3], GSVector4* sRect, GSTexture* dTex, GSVector4* dRect, const GSRegPMODE& PMODE, const GSRegEXTBUF& EXTBUF, u32 c, const bool linear)
{
	Console.Warning("paraLLEl-GS DoMerge method called, stub implementation");
};

void GSDevicePGS::DoInterlace(GSTexture* sTex, const GSVector4& sRect, GSTexture* dTex, const GSVector4& dRect, ShaderInterlace shader, bool linear, const InterlaceConstantBuffer& cb)
{
	Console.Warning("paraLLEl-GS DoInterlace method called, stub implementation");
}

void GSDevicePGS::DoFXAA(GSTexture* sTex, GSTexture* dTex)
{
	Console.Warning("paraLLEl-GS DoFXAA method called, stub implementation");
}

void GSDevicePGS::DoShadeBoost(GSTexture* sTex, GSTexture* dTex, const float params[4])
{
	Console.Warning("paraLLEl-GS DoShadeBoost method called, stub implementation");
}

/// Applies CAS and writes to the destination texture, which should be a RWTexture.
bool GSDevicePGS::DoCAS(GSTexture* sTex, GSTexture* dTex, bool sharpen_only, const std::array<u32, NUM_CAS_CONSTANTS>& constants)
{
	Console.Warning("paraLLEl-GS DoCAS method called, stub implementation");
	return false;
}

// Entry point to the renderer-specific StretchRect code.
void GSDevicePGS::DoStretchRect(GSTexture* sTex, const GSVector4& sRect, GSTexture* dTex, const GSVector4& dRect,
	GSHWDrawConfig::ColorMaskSelector cms, ShaderConvert shader, bool linear)
{
	Console.Warning("paraLLEl-GS DoStretchRect method called, stub implementation");
}

RenderAPI GSDevicePGS::GetRenderAPI() const
{
	return RenderAPI::Granite;
}

/// Returns true if we have a window we're rendering into.
bool GSDevicePGS::HasSurface() const
{
	Console.Warning("paraLLEl-GS HasSurface method called, stub implementation");
	return true;
}

/// Destroys the surface we're currently drawing to.
void GSDevicePGS::DestroySurface()
{
	Console.Warning("paraLLEl-GS DestroySurface method called, stub implementation");
}

/// Switches to a new window/surface.
bool GSDevicePGS::UpdateWindow()
{
	// Console.Warning("paraLLEl-GS UpdateWindow method called, stub implementation");
	return ((GSRendererPGS*)g_gs_renderer.get())->UpdateWindow();
}

/// Call when the window size changes externally to recreate any resources.
void GSDevicePGS::ResizeWindow(u32 new_window_width, u32 new_window_height, float new_window_scale)
{
	// Console.Warning("paraLLEl-GS ResizeWindow method called, stub implementation");
	((GSRendererPGS*)g_gs_renderer.get())->ResizeWindow(new_window_width, new_window_height, new_window_scale);
}

/// Returns true if exclusive fullscreen is supported.
bool GSDevicePGS::SupportsExclusiveFullscreen() const
{
	// Console.Warning("paraLLEl-GS SupportsExclusiveFullscreen method called, stub implementation");
	return false;
}

/// Returns false if the window was completely occluded. If frame_skip is set, the frame won't be
/// displayed, but the GPU command queue will still be flushed.
GSDevice::PresentResult GSDevicePGS::BeginPresent(bool frame_skip)
{
	Console.Warning("paraLLEl-GS BeginPresent method called, stub implementation");
	return PresentResult::DeviceLost;
}

/// Presents the frame to the display.
void GSDevicePGS::EndPresent()
{
	Console.Warning("paraLLEl-GS EndPresent method called, stub implementation");
}

/// Changes vsync mode for this display.
void GSDevicePGS::SetVSyncMode(GSVSyncMode mode, bool allow_present_throttle)
{
	// Console.Warning("paraLLEl-GS SetVSyncMode method called, stub implementation");
	((GSRendererPGS*)g_gs_renderer.get())->SetVSyncMode(mode, allow_present_throttle);
}

/// Returns a string of information about the graphics driver being used.
std::string GSDevicePGS::GetDriverInfo() const
{
	// Console.Warning("paraLLEl-GS GetDriverInfo method called, stub implementation");
	return "paraLLEl-GS";
}

/// Enables/disables GPU frame timing.
bool GSDevicePGS::SetGPUTimingEnabled(bool enabled)
{
	Console.Warning("paraLLEl-GS SetGPUTimingEnabled method called, stub implementation");
	return false;
}

/// Returns the amount of GPU time utilized since the last time this method was called.
float GSDevicePGS::GetAndResetAccumulatedGPUTime()
{
	Console.Warning("paraLLEl-GS GetAndResetAccumulatedGPUTime method called, stub implementation");
	return 0;
}

void GSDevicePGS::PushDebugGroup(const char* fmt, ...)
{
	Console.Warning("paraLLEl-GS PushDebugGroup method called, stub implementation");
}

void GSDevicePGS::PopDebugGroup()
{
	Console.Warning("paraLLEl-GS PopDebugGroup method called, stub implementation");
}

void GSDevicePGS::InsertDebugMessage(GSDevice::DebugMessageCategory category, const char* fmt, ...)
{
	Console.Warning("paraLLEl-GS InsertDebugMessage method called, stub implementation");
}

std::unique_ptr<GSDownloadTexture> GSDevicePGS::CreateDownloadTexture(u32 width, u32 height, GSTexture::Format format)
{
	Console.Warning("paraLLEl-GS CreateDownloadTexture method called, stub implementation");
	return nullptr;
}

void GSDevicePGS::CopyRect(GSTexture* sTex, GSTexture* dTex, const GSVector4i& r, u32 destX, u32 destY)
{
	Console.Warning("paraLLEl-GS CopyRect method called, stub implementation");
}

/// Performs a screen blit for display. If dTex is null, it assumes you are writing to the system framebuffer/swap chain.
void GSDevicePGS::PresentRect(GSTexture* sTex, const GSVector4& sRect, GSTexture* dTex, const GSVector4& dRect, PresentShader shader, float shaderTime, bool linear)
{
	Console.Warning("paraLLEl-GS PresentRect method called, stub implementation");
}

/// Updates a GPU CLUT texture from a source texture.
void GSDevicePGS::UpdateCLUTTexture(GSTexture* sTex, float sScale, u32 offsetX, u32 offsetY, GSTexture* dTex, u32 dOffset, u32 dSize)
{
	Console.Warning("paraLLEl-GS UpdateCLUTTexture method called, stub implementation");
}

/// Converts a colour format to an indexed format texture.
void GSDevicePGS::ConvertToIndexedTexture(GSTexture* sTex, float sScale, u32 offsetX, u32 offsetY, u32 SBW, u32 SPSM, GSTexture* dTex, u32 DBW, u32 DPSM)
{
	Console.Warning("paraLLEl-GS ConvertToIndexedTexture method called, stub implementation");
}

/// Uses box downsampling to resize a texture.
void GSDevicePGS::FilteredDownsampleTexture(GSTexture* sTex, GSTexture* dTex, u32 downsample_factor, const GSVector2i& clamp_min, const GSVector4& dRect)
{
	Console.Warning("paraLLEl-GS FilteredDownsampleTexture method called, stub implementation");
}

void GSDevicePGS::RenderHW(GSHWDrawConfig& config)
{
	Console.Warning("paraLLEl-GS RenderHW method called, stub implementation");
}

void GSDevicePGS::ClearSamplerCache()
{
	Console.Warning("paraLLEl-GS ClearSamplerCache method called, stub implementation");
}
