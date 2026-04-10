#pragma once

#include "GS/Renderers/Common/GSTexture.h"
#include "vulkan/vulkan_core.h"

class GSTexturePGS final : public GSTexture {
	void* GetNativeHandle() const override;

	bool Update(const GSVector4i& r, const void* data, int pitch, int layer = 0) override;
	bool Map(GSMap& m, const GSVector4i* r = nullptr, int layer = 0) override;
	void Unmap() override;
	void GenerateMipmap() override;

#ifdef PCSX2_DEVBUILD
	void SetDebugName(std::string_view name) override;
#endif
};

// class GSDownloadTexturePGS final : public GSDownloadTexture {};
