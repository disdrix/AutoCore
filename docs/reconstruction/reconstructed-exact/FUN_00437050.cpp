// =============================================================================
// FUN_00437050 / stoChunkReader_ReadU32
// -----------------------------------------------------------------------------
// Stable ID: aa_00437050
// Address:   0x00437050–0x00437095  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W18-N)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Prefer: reconstructed-exact/stoChunkReader_ReadU32.cpp
// =============================================================================

/*
 * Behavioral notes:
 * - Decompiler form: in_EAX = full reader*; param_1 = out dword*.
 * - Body bytes: mov esi,eax; add esi,0x14 → window; RET 4.
 * - Sole callee: FUN_00435df0 (ensure/refill).
 */

#include <cstdint>

// External (not owned)
extern "C" int32_t FUN_00435df0(int32_t absPos); // thiscall ECX=window in retail

// Decompiler-faithful plate (in_EAX = reader)
uint32_t FUN_00437050(uint32_t* param_1)
{
  int in_EAX; // reader* in EAX on entry (not a stack/ECX param)
  int iVar1;

  if (*(int*)(in_EAX + 0x20) < *(int*)(in_EAX + 0x18) + 4) {
    iVar1 = FUN_00435df0(*(int*)(in_EAX + 0x1c) + *(int*)(in_EAX + 0x18));
    // retail: ECX = in_EAX+0x14 before call
    if ((iVar1 < 0) || (*(int*)(in_EAX + 0x20) < 4)) {
      return 0xffffffff;
    }
  }
  *param_1 = *(uint32_t*)(*(int*)(in_EAX + 0x18) + in_EAX + 0x2c);
  *(int*)(in_EAX + 0x18) = *(int*)(in_EAX + 0x18) + 4;
  return 0;
}
