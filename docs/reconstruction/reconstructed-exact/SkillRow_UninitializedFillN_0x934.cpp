// =============================================================================
// SkillRow_UninitializedFillN_0x934
// -----------------------------------------------------------------------------
// Purpose:  Leaf uninitialized_fill_n for fixed-stride 0x934 skill-row elements.
//           Copies the EBX prototype into `count` consecutive slots starting at
//           EAX via rep movsd of 0x24d dwords per slot.
//
// Address:  0x004220c0  (autoassault.exe, image base 0x400000)
// Body:     0x004220c0–0x004220e3 (36 bytes)
// Stable:   aa_004220c0
// System:   skills-abilities / vector helpers
// Ghidra:   FUN_004220c0
//
// ABI:      Register-only — ECX=count, EAX=dst, EBX=src prototype; bare ret.
//           (Decompiler shows __fastcall count only; EAX/EBX are live inputs.)
// Callers:  SkillRowVec_EmplaceBack_Stride934_Inferred (0x0041aef0) count=1
//           FUN_0041c9a0 fill-N + end arithmetic
//           FUN_0041f740 vector grow/insert fill
//
// Exactness: CF mirrors raw + full body read_memory (36 B).
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W22-M seal).
// =============================================================================

#include <stdint.h>
#include <string.h>

enum {
  kSkillRowDwordCount = 0x24d,           /* 589 */
  kSkillRowStrideBytes = 0x934           /* 2356 == 0x24d * 4 */
};

/* Register ABI documented in parameters for readability.
   Actual machine: ECX=count, EAX=dst (updated), EBX=src. */

void SkillRow_UninitializedFillN_0x934(uint32_t count,
                                       uint32_t *dst,
                                       const uint32_t *src)
{
  if (count == 0)
    return;

  for (; count != 0; --count) {
    if (dst != 0) {
      /* rep movsd ecx=0x24d from ESI=src to EDI=dst */
      memcpy(dst, src, (size_t)kSkillRowStrideBytes);
    }
    dst += kSkillRowDwordCount; /* +0x934 bytes */
  }
}
