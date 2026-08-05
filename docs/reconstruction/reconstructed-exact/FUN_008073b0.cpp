// =============================================================================
// FUN_008073b0  (scaffold alias — prefer Client_SendGlobalPacket.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_008073b0
// Address:   0x008073b0  (autoassault.exe, image base 0x400000)
// System:    network-global
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W18-B)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical clean: reconstructed-exact/Client_SendGlobalPacket.cpp
// =============================================================================

#include <cstdint>

uint32_t FUN_008073b0(short param_1, uint32_t param_2)
{
  char cVar1;
  int unaff_ESI; // client* live-in ESI

  if (*(int *)(unaff_ESI + 0xc7c) != 0) {
    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0xc7c) + 8))();
    if (cVar1 != '\0') {
      (**(code **)(**(int **)(unaff_ESI + 0xc7c) + 0x18))(
          0xffffffff, param_2, (int)param_1, 0);
      return 0;
    }
  }
  return 0x80004005;
}
