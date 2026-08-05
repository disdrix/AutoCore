// Twin of D3DPresentParams_Log_Inferred (aa_0075e710).
// See: docs/reconstruction/reconstructed-exact/D3DPresentParams_Log_Inferred.cpp

#include <cstdint>

extern "C" void FUN_0076c130(const char* fmt, ...);

// ESI = 14-dword present params; bare RET; void. Sealed W38-X.
void FUN_0075e710(void)
{
  uint32_t* p;
  __asm { mov p, esi }

  FUN_0076c130("\t BackBuffer [%ux%u], format=0x%08X, #%u\n", p[0], p[1], p[2], p[3]);
  FUN_0076c130("\t MultiSampleType = %d, Quality = %u\n", p[4], p[5]);

  const char* swap_name;
  if (p[6] == 2) {
    swap_name = "FLIP";
  } else {
    swap_name = "COPY";
    if (p[6] != 3) {
      swap_name = "DISCARD";
    }
  }
  FUN_0076c130("\t SwapEffect = %s\n", swap_name);
  FUN_0076c130("\t hDeviceWindow = 0x%08X\n", p[7]);
  FUN_0076c130("\t Fullscreen = %d\n", p[8] == 0);
  FUN_0076c130("\t EnableAutoDepthStencil = %d\n", p[9]);
  FUN_0076c130("\t AutoDepthStencilFormat = %d\n", p[10]);
  FUN_0076c130("\t Flags = 0x%08X\n", p[11]);
  FUN_0076c130("\t FullScreen_RefreshRateInHz = %u\n", p[12]);
  FUN_0076c130("\t PresentationInterval = 0x%X\n", p[13]);
}
