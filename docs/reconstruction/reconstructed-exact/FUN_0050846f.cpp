// =============================================================================
// FUN_0050846f  (scaffold / Ghidra symbol mirror)
// -----------------------------------------------------------------------------
// Stable ID: aa_0050846f
// Address:   0x0050846f  (autoassault.exe, image base 0x400000)
// System:    heartbeat / CVOGHBBase
// Generated: 2026-07-29 W21-B dual seal
// Named plate: reconstructed-exact/CVOGHBBase_EndOrDestroy_SoftMarkEpilogue.cpp
// Exactness: Behavior-preserving rewrite of decompiler control flow + body bytes.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Soft-mark + SEH epilogue tail of CVOGHBBase_EndOrDestroy.
//   Body bytes (complete):
//     c6462001 895e18 8b4df4 5f5e 64890d00000000 5b 8be5 5d c20800
//   this+0x20=1; this+0x18=ebx; ExceptionList=[ebp-0xc]; ret 8.

#include <cstdint>

extern void *ExceptionList;

void FUN_0050846f(void)
{
  register uint32_t unaff_EBX;
  register int      unaff_EBP;
  register int      unaff_ESI;

  *(uint8_t *)(unaff_ESI + 0x20) = 1;
  *(uint32_t *)(unaff_ESI + 0x18) = unaff_EBX;
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  return;
}
