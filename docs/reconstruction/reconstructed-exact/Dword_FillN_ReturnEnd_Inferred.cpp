// =============================================================================
// Dword_FillN_ReturnEnd_Inferred  (Ghidra FUN_004e2f70)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e2f70
// Address:   0x004e2f70  (autoassault.exe, image base 0x400000)
// System:    util / container (generic dword fill-n)
// Generated: 2026-07-29 dual A/B W16-B — live decompile + read_memory
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: body 0x2C bytes sealed statically; image diff deferred.
// =============================================================================
//
// PURPOSE:
//   Fill `count` consecutive dwords at `dst` with the single value `*pValue`.
//   Return end pointer (dst advanced by count elements / count*4 bytes).
//
// NOT:
//   - memcpy / copy-n (pValue is never advanced)
//   - domain / product logic (shared insert/grow fill helper)
//
// ABI: free function, three stack args, ret 0x0C. ECX unused.
// CALLEES: none (leaf).
// =============================================================================

#include <stdint.h>

uint32_t * Dword_FillN_ReturnEnd_Inferred(uint32_t *dst, int count, uint32_t *pValue)
{
  uint32_t *p;
  int n;

  p = dst;
  for (n = count; n != 0; n = n + -1) {
    *p = *pValue;
    p = p + 1;
  }
  return dst + count;
}
