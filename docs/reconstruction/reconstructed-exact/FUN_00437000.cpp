// =============================================================================
// FUN_00437000 / stoChunkReader_ReadU8
// -----------------------------------------------------------------------------
// Stable ID: aa_00437000
// Address:   0x00437000–0x00437048  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-08-04 (W38-D)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Prefer: reconstructed-exact/stoChunkReader_ReadU8.cpp
// =============================================================================

/*
 * Behavioral notes:
 * - Decompiler form: in_EAX = full reader*; unaff_EDI = out byte*; invents fastcall param_1.
 * - Body bytes: mov esi,eax; add esi,0x14 → window; EDI=out; bare RET.
 * - Sole callee: FUN_00435df0 (ensure/refill).
 * - Fail path writes *EDI from stack spill (entry-ECX high byte) — unreliable.
 */

#include <cstdint>

// External (not owned)
extern "C" int32_t FUN_00435df0(int32_t absPos); // thiscall ECX=window in retail

// Decompiler-faithful plate (in_EAX = reader, unaff_EDI = out)
uint32_t __fastcall FUN_00437000(uint32_t param_1)
{
  uint8_t uVar1;
  int in_EAX; // reader* in EAX on entry
  int iVar2;
  uint8_t* unaff_EDI; // out* in EDI on entry
  uint8_t local_1;

  if (*(int*)(in_EAX + 0x20) < *(int*)(in_EAX + 0x18) + 1) {
    iVar2 = FUN_00435df0(*(int*)(in_EAX + 0x1c) + *(int*)(in_EAX + 0x18));
    // retail: ECX = in_EAX+0x14 before call
    if ((iVar2 < 0) || (*(int*)(in_EAX + 0x20) < 1)) {
      local_1 = (uint8_t)((uint32_t)param_1 >> 0x18); // decompiler view of [esp+7] spill
      *unaff_EDI = local_1;
      return 0xffffffff;
    }
  }
  uVar1 = *(uint8_t*)(*(int*)(in_EAX + 0x18) + in_EAX + 0x2c);
  *(int*)(in_EAX + 0x18) = *(int*)(in_EAX + 0x18) + 1;
  *unaff_EDI = uVar1;
  return 0;
}
