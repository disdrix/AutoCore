// =============================================================================
// FUN_00404130  (alias of UiToast_UninitializedFillN_0x98)
// -----------------------------------------------------------------------------
// Stable ID: aa_00404130
// Address:   0x00404130  (autoassault.exe, image base 0x400000)
// System:    missions-progression / UI toast vector helpers
// Generated: 2026-07-29 W20-G dual seal (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Dual A/B: accept — see UiToast_UninitializedFillN_0x98.cpp for named clean.
// =============================================================================

#include <stdint.h>

extern void FUN_00404670(void *dst, int count, const void *src);

/* Ghidra thiscall formals: ECX=param_1 (unused for result), stack dst/count/src.
   Body: ConstructN(dst,count,src) [+ phantom ECX/src pushes cleaned by caller of
   ConstructN via add esp,0x14]; return dst + count*0x98; ret 0x0C. */

void *FUN_00404130(void * /*ecx_unused*/, void *param_2, int param_3, void *param_4)
{
  FUN_00404670(param_2, param_3, param_4);
  return (uint8_t *)param_2 + (size_t)param_3 * 0x98u;
}
