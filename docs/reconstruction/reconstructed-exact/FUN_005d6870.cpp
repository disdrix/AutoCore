// =============================================================================
// FUN_005d6870 / Math_Float3_IsFiniteIEEE_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005d6870
// Address:   0x005d6870  (autoassault.exe, image base 0x400000)
// Body:      0x005d6870–0x005d68ab (60 B); RET 0x4 ×2; pad CC → sibling 0x005d68b0
// System:    math / IEEE-754 finite gate (3× float32)
// Generated: 2026-07-29 W27-J live decompile + read_memory seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Sibling:   Math_Float4_IsFiniteIEEE_Inferred @ 0x005d68b0 (bound 4)
// =============================================================================

// PURPOSE:
//   Write *outOk = 1 iff none of three consecutive float32 words has IEEE
//   exponent bits all-ones (Inf/NaN class via mask 0x7f800000). Else *outOk = 0.
//   Does not test unit length, magnitude, or denormal special-cases.

// ABI:
//   __thiscall: ECX = float[3]* (or any 12-byte float triplet base)
//   stack:      uint8_t *outOk
//   return:     void (EAX residual often left as outOk pointer — callers may read *EAX)

// READABILITY:
//   - Leaf; two return sites
//   - Loop bound hard-coded to 3 (not 4)

#include <stdint.h>

void __thiscall FUN_005d6870(float *param_1 /* this / ECX */, uint8_t *param_2 /* outOk */)
{
  int iVar1;

  iVar1 = 0;
  do {
    if ((*(uint32_t *)((char *)param_1 + iVar1 * 4) & 0x7f800000u) == 0x7f800000u) {
      *param_2 = 0;
      return;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  *param_2 = 1;
  return;
}
