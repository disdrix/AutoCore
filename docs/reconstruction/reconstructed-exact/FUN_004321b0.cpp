// =============================================================================
// FUN_004321b0  /  NDAssetImage_ReleaseOwnedBuffers_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004321b0
// Address:   0x004321b0 – 0x00432254  (autoassault.exe, image base 0x400000)
// System:    NDAssetImage / asset image buffer ownership
// Generated: 2026-07-29 W24-A dual seal (live Ghidra decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Release owned heap payloads on image object (ESI), gated on +0x38.
//   Walk +0x1b4[0..+0x1a4) with vtbl[0](1), free array, free +0x1ac/+0x1b0/+4.
//   Return 1 on success, 0 if busy.
//
// ABI: no stack formals; ESI = image*; AL bool; plain ret.
// free via IAT 0x009C6524 (cdecl).
// =============================================================================

#include <stdint.h>
#include <stdlib.h>

extern "C" {

// Live Ghidra decompile (authoritative CF). ESI = image object.
uint32_t FUN_004321b0(void)
{
  uint32_t *puVar1;
  int unaff_ESI;
  int iVar2;

  if (*(int *)(unaff_ESI + 0x38) != 0) {
    return 0;
  }
  if (*(int *)(unaff_ESI + 0x1b4) != 0) {
    iVar2 = 0;
    if (0 < *(int *)(unaff_ESI + 0x1a4)) {
      do {
        puVar1 = *(uint32_t **)(*(int *)(unaff_ESI + 0x1b4) + iVar2 * 4);
        if (puVar1 != (uint32_t *)0x0) {
          // (**(code **)*puVar1)(1)
          (*(void (**)(uint32_t *, int))(*puVar1))(puVar1, 1);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(unaff_ESI + 0x1a4));
    }
    free(*(void **)(unaff_ESI + 0x1b4));
    *(uint32_t *)(unaff_ESI + 0x1b4) = 0;
  }
  if (*(void **)(unaff_ESI + 0x1ac) != (void *)0x0) {
    free(*(void **)(unaff_ESI + 0x1ac));
    *(uint32_t *)(unaff_ESI + 0x1ac) = 0;
  }
  if (*(void **)(unaff_ESI + 0x1b0) != (void *)0x0) {
    free(*(void **)(unaff_ESI + 0x1b0));
    *(uint32_t *)(unaff_ESI + 0x1b0) = 0;
  }
  if (*(void **)(unaff_ESI + 4) != (void *)0x0) {
    free(*(void **)(unaff_ESI + 4));
    *(uint32_t *)(unaff_ESI + 4) = 0;
  }
  return 1;
}

} // extern "C"
