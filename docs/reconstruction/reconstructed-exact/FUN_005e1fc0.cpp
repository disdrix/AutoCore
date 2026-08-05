// =============================================================================
// FUN_005e1fc0  (twin of Object_FwriteColorFields_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005e1fc0
// Address:   0x005e1fc0  (autoassault.exe, image base 0x400000)
// Body:      0x005e1fc0–0x005e203c (124 B)
// System:    object stream serialize (color extension)
// Generated: 2026-07-29 W29-J OWN dual (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI fix.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <stdint.h>
#include <stdio.h>

extern void thunk_FUN_005a61d0(void *self /*ecx*/, FILE *stream);
extern void FUN_00973820(uint8_t *dest /*ecx*/, const float *src);

// Image ABI: __thiscall; stack FILE*; ret 4.
// Decompiler marks pack locals as FILE* — rejected; they are packed u8×4.
void FUN_005e1fc0(void *self /*ecx*/, FILE *stream)
{
  uint8_t packedA[4];
  uint8_t packedB[4];

  thunk_FUN_005a61d0(self, stream);
  fwrite((char *)self + 0x170, 4, 1, stream);
  FUN_00973820(packedA, (const float *)((char *)self + 0x174));
  FUN_00973820(packedB, (const float *)((char *)self + 0x184));
  fwrite(packedA, 4, 1, stream);
  fwrite(packedB, 4, 1, stream);
}
