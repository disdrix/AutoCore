// =============================================================================
// NDAssetImage_ReleaseOwnedBuffers_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004321b0
// Address:   0x004321b0  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_004321b0
// System:    NDAssetImage / asset image buffer ownership
// Generated: 2026-07-29 W24-A OWN-ONLY dual seal
// Evidence:  decompile_function + read_memory + analyze_function_complete
// Exactness: Faithful control flow / offsets / call order. Not modernization.
// =============================================================================

#include <stdint.h>
#include <stdlib.h>

// Image object layout (partial — ownership slots sealed by this unit + TransferFields):
//   +0x04   owned heap buffer (primary)
//   +0x38   busy/lock gate (nonzero → refuse release)
//   +0x1a4  count of entries in +0x1b4 array
//   +0x1ac  owned heap buffer
//   +0x1b0  owned heap buffer
//   +0x1b4  owned heap array of object pointers (each has vtbl[0](1))

extern "C" {

// ABI: ESI = image*; no stack args; AL return; plain ret.
// Readable thiscall-shaped port (callers must still honor ESI convention in native):
uint32_t NDAssetImage_ReleaseOwnedBuffers_Inferred(void *imageObj_ESI)
{
  uint8_t *const obj = (uint8_t *)imageObj_ESI;
  int i;
  uint32_t *entry;

  if (*(int *)(obj + 0x38) != 0) {
    return 0;
  }

  if (*(void **)(obj + 0x1b4) != 0) {
    i = 0;
    if (*(int *)(obj + 0x1a4) > 0) {
      do {
        entry = *(uint32_t **)(*(int *)(obj + 0x1b4) + i * 4);
        if (entry != 0) {
          // (**(code **)*puVar1)(1)  — thiscall vtbl[0] with stack/reg arg 1
          (*(void (__thiscall **)(uint32_t *, int))(*entry))(entry, 1);
        }
        i = i + 1;
      } while (i < *(int *)(obj + 0x1a4));
    }
    free(*(void **)(obj + 0x1b4));
    *(void **)(obj + 0x1b4) = 0;
  }

  if (*(void **)(obj + 0x1ac) != 0) {
    free(*(void **)(obj + 0x1ac));
    *(void **)(obj + 0x1ac) = 0;
  }
  if (*(void **)(obj + 0x1b0) != 0) {
    free(*(void **)(obj + 0x1b0));
    *(void **)(obj + 0x1b0) = 0;
  }
  if (*(void **)(obj + 4) != 0) {
    free(*(void **)(obj + 4));
    *(void **)(obj + 4) = 0;
  }

  return 1;
}

// Ghidra symbol retained for xref continuity
uint32_t FUN_004321b0(void);

} // extern "C"
