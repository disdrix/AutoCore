// =============================================================================
// FUN_00966630  (twin of Gfx_DeviceStateCache_Clear_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00966630
// Address:   0x00966630  (autoassault.exe, image base 0x400000)
// Wave:      W38-Y OWN-ONLY dual
// Note:      Ghidra symbol twin; prefer Gfx_DeviceStateCache_Clear_Inferred.cpp
//            Decompiler phantom ECX (param_1) is unused — EDX host only.
// =============================================================================

#include <cstdint>

extern uint32_t DAT_00d0e128[16];
extern uint32_t DAT_00d0e0e8[16];
extern uint32_t DAT_00d1a568;
extern uint32_t DAT_00d1a564;
extern uint32_t DAT_00d1a558;
extern uint32_t DAT_00d1a55c;

void FUN_00966630(uint32_t * /*edx*/ host)
{
  uint32_t *puVar2;
  int iVar1;

  puVar2 = &DAT_00d0e128[0];
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_00d0e0e8[0];
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  DAT_00d1a568 = 0;
  DAT_00d1a564 = 0;
  DAT_00d1a558 = 0;
  DAT_00d1a55c = 0;
  host[0] = 0;
  host[1] = 0;
  host[2] = 0;
  host[0xf] = 0;
}
