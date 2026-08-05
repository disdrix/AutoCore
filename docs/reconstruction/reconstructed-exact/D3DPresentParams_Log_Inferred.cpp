// =============================================================================
// D3DPresentParams_Log_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0075e710
// Address:   0x0075e710  (autoassault.exe, image base 0x400000)
// System:    client / gfxDevice D3D9 present params
// Wave:      W38-X OWN-ONLY dual (2026-08-04)
// Exactness: Behavior-preserving rewrite of decompiler + sealed machine bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Log a 14-dword (0x38) D3DPRESENT_PARAMETERS-shaped block via FUN_0076c130.
//   ESI points at the block. Used from GfxDevice_Reset (device+0x2B8) and
//   device-create path FUN_00735c90.
//
// ABI:
//   ESI = const D3DPRESENT_PARAMETERS* (layout-compatible 14 dwords)
//   Bare RET after stack cleanup of printf args (ADD ESP,0x40; C3); void
//
// REJECT: incomplete alias Gfx_SwapEffect; scaffold Named_CalleeOf_Named_gfxDevice
// =============================================================================

#include <cstdint>

// printf-style logger (not vog_LogMessage).
extern "C" void FUN_0076c130(const char* fmt, ...);

// Layout-compatible with D3DPRESENT_PARAMETERS (D3D9, 0x38 bytes).
struct D3DPresentParams14 {
  uint32_t back_buffer_width;            // [0]
  uint32_t back_buffer_height;           // [1]
  uint32_t back_buffer_format;           // [2]
  uint32_t back_buffer_count;            // [3]
  uint32_t multi_sample_type;            // [4]
  uint32_t multi_sample_quality;         // [5]
  uint32_t swap_effect;                  // [6] 2=FLIP, 3=COPY, else DISCARD
  uint32_t h_device_window;              // [7]
  uint32_t windowed;                     // [8] Fullscreen log = (windowed==0)
  uint32_t enable_auto_depth_stencil;    // [9]
  uint32_t auto_depth_stencil_format;    // [10]
  uint32_t flags;                        // [11]
  uint32_t full_screen_refresh_rate_hz;  // [12]
  uint32_t presentation_interval;        // [13]
};

static_assert(sizeof(D3DPresentParams14) == 0x38, "14 dwords");

void D3DPresentParams_Log_Inferred(/* ESI */ const D3DPresentParams14* p)
{
  FUN_0076c130("\t BackBuffer [%ux%u], format=0x%08X, #%u\n",
               p->back_buffer_width,
               p->back_buffer_height,
               p->back_buffer_format,
               p->back_buffer_count);
  FUN_0076c130("\t MultiSampleType = %d, Quality = %u\n",
               p->multi_sample_type,
               p->multi_sample_quality);

  const char* swap_name;
  if (p->swap_effect == 2) {
    swap_name = "FLIP";
  } else {
    swap_name = "COPY";
    if (p->swap_effect != 3) {
      swap_name = "DISCARD";
    }
  }
  FUN_0076c130("\t SwapEffect = %s\n", swap_name);
  FUN_0076c130("\t hDeviceWindow = 0x%08X\n", p->h_device_window);
  FUN_0076c130("\t Fullscreen = %d\n", p->windowed == 0);
  FUN_0076c130("\t EnableAutoDepthStencil = %d\n", p->enable_auto_depth_stencil);
  FUN_0076c130("\t AutoDepthStencilFormat = %d\n", p->auto_depth_stencil_format);
  FUN_0076c130("\t Flags = 0x%08X\n", p->flags);
  FUN_0076c130("\t FullScreen_RefreshRateInHz = %u\n", p->full_screen_refresh_rate_hz);
  FUN_0076c130("\t PresentationInterval = 0x%X\n", p->presentation_interval);
}

// Ghidra twin alias
void FUN_0075e710(void)
{
  const D3DPresentParams14* p;
  __asm { mov p, esi }
  D3DPresentParams_Log_Inferred(p);
}
