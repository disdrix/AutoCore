// =============================================================================
// NestedHash0x10_FindIterator_Inferred  (Ghidra: FUN_0046c1b0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0046c1b0
// Address:   0x0046c1b0 – 0x0046c223  (116 B / 0x74; autoassault.exe base 0x400000)
// System:    NestedHash bag (sentinel node 0x10) — find by u32 key
// Generated: 2026-07-29 W36-B OWN-ONLY dual (decompile + read_memory)
// Exactness: Byte-sealed CF. Register formals ESI=map, ECX=key*, EAX=out_it*.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Find node by u32 key in NestedHash0x10; write iterator to *out_it.
 *
 * ABI (byte-sealed):
 *   ESI     = NestedHash0x10*   (register formal)
 *   ECX     = uint32_t* key     (*key is hash + compare dword)
 *   EAX     = void** out_it
 *   bare RET
 *
 * Map:  +0x08 end sentinel, +0x14 bucket table, +0x20 mask, +0x24 bucket_count
 * Node: +0x00 next*, +0x08 key dword  (size 0x10; value at +0x0c unused here)
 *
 * Hash: identity — idx = (*key) & mask  (NO string-hash leaf).
 * Contrast: HashMap_FindIterator_Inferred (0x0044e8c0) uses FUN_0043b870 + EDI/EBX/ret4.
 *
 * Callers: sto factory, operator[] shell 0046bf40, GfxMesh 0098fef0, ~13 total.
 *
 * Note: Ghidra shows unaff_ESI / in_EAX; those are live formals, not junk.
 */

#include <stdint.h>

void NestedHash0x10_FindIterator_Inferred(
    void *map /* machine: ESI */,
    uint32_t *key /* machine: ECX */,
    void **out_it /* machine: EAX */)
{
  uint32_t mask = *(uint32_t *)((char *)map + 0x20);
  uint32_t keyv = *key;
  uint32_t idx = keyv & mask;

  if (*(uint32_t *)((char *)map + 0x24) <= idx) {
    idx = idx + (uint32_t)(-1 - (mask >> 1));
  }

  {
    int *bucket = (int *)(*(int *)((char *)map + 0x14) + (int)idx * 4);
    int *node = (int *)bucket[0];
    int *end = (int *)bucket[1];

    if (node != end) {
      do {
        uint32_t nkey = (uint32_t)node[2]; /* node + 8 */

        if (keyv <= nkey) {
          if (nkey <= keyv) {
            *out_it = node;
            return;
          }
          *out_it = *(void **)((char *)map + 8);
          return;
        }
        node = (int *)node[0];
      } while (node != end);
    }
  }

  *out_it = *(void **)((char *)map + 8);
  return;
}
