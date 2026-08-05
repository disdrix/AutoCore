// =============================================================================
// FUN_004651d0  (scaffold alias → Mem_FillDwordN_ReturnEnd)
// -----------------------------------------------------------------------------
// Stable ID: aa_004651d0
// Address:   0x004651d0  (autoassault.exe, image base 0x400000)
// Canonical: Mem_FillDwordN_ReturnEnd
// System:    stl-helpers / POD fill
// Generated: 2026-07-29 W22-T dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Custom-ABI dword fill-N returning write end. See Mem_FillDwordN_ReturnEnd.cpp.
//
// Raw decompiler shape (registers as Ghidra saw them):

#include <stdint.h>

// Decompiler-shaped surface (ESI/EDI unaffiliated; EDX = param_2):
uint32_t *FUN_004651d0(/* fastcall unused */ uint32_t /*param_1*/,
                       uint32_t *param_2 /* EDX = &fill */,
                       /* unaff_ESI */ int count,
                       /* unaff_EDI */ uint32_t *dest)
{
  uint32_t *puVar1 = dest;
  for (int iVar2 = count; iVar2 != 0; iVar2 = iVar2 - 1) {
    *puVar1 = *param_2;
    puVar1 = puVar1 + 1;
  }
  return dest + count;
}
