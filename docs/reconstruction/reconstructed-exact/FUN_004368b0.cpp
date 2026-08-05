// =============================================================================
// FUN_004368b0 / stoChunkStreamWindow_ReadHeader16
// -----------------------------------------------------------------------------
// Stable ID: aa_004368b0
// Address:   0x004368b0–0x004368f9  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W17-R)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Prefer: reconstructed-exact/stoChunkStreamWindow_ReadHeader16.cpp
// =============================================================================

/*
 * Behavioral notes:
 * - ESI = stream window*; EDI = u32 out[4].
 * - Ensure path: FUN_00435df0 when available < cursor+0x10.
 * - Copy 16 bytes (4 dwords); cursor += 0x10; return 0 / -1.
 */

#include <cstdint>

extern "C" int32_t __thiscall FUN_00435df0(void* window, int32_t absPos);

// Decompiler-faithful control flow (register ABI documented in named clean plate)
uint32_t FUN_004368b0(void /* ESI=window, EDI=out */)
{
  // Mirrors raw:
  // if (*(int*)(esi+0xc) < *(int*)(esi+4)+0x10) {
  //   iVar2 = FUN_00435df0(*(int*)(esi+8)+*(int*)(esi+4)); // ECX=esi
  //   if (iVar2 < 0 || *(int*)(esi+0xc) < 0x10) return 0xffffffff;
  // }
  // puVar1 = (u32*)(esi + 0x18 + *(int*)(esi+4));
  // *edi = *puVar1; edi[1]=puVar1[1]; edi[2]=puVar1[2]; edi[3]=puVar1[3];
  // *(int*)(esi+4) += 0x10;
  // return 0;

  // See stoChunkStreamWindow_ReadHeader16.cpp for typed reconstruction.
  return 0; // not linked; documentation unit
}
