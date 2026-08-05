// =============================================================================
// FUN_0046c1b0  (twin of NestedHash0x10_FindIterator_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0046c1b0
// Address:   0x0046c1b0–0x0046c223  (autoassault.exe, image base 0x400000)
// System:    NestedHash bag (sentinel node 0x10) — find-iterator
// Generated: dual A/B seal 2026-07-29 (W36-B)
// Exactness: Behavior-preserving rewrite. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// Canonical clean: NestedHash0x10_FindIterator_Inferred.cpp

#include <stdint.h>

// Retail: ESI=map, ECX=key*, EAX=out_it*; bare RET.
// Ghidra name retained as twin entry; prefer named clean for ports.
void FUN_0046c1b0(uint32_t *key /*ECX*/)
{
  uint32_t mask;
  uint32_t keyv;
  uint32_t idx;
  int *bucket;
  int *node;
  int *end;
  void **out_it; /* EAX formal */
  void *map;     /* ESI formal */

  /* Register formals sealed by bytes — not decompiler junk */
  /* map lives in ESI; out_it lives in EAX; key in ECX (param) */

  mask = *(uint32_t *)((char *)map + 0x20);
  keyv = *key;
  idx = keyv & mask;
  if (*(uint32_t *)((char *)map + 0x24) <= idx) {
    idx = idx + (uint32_t)(-1 - (mask >> 1));
  }

  bucket = (int *)(*(int *)((char *)map + 0x14) + (int)idx * 4);
  node = (int *)bucket[0];
  end = (int *)bucket[1];

  if (node != end) {
    do {
      uint32_t nkey = (uint32_t)node[2];
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

  *out_it = *(void **)((char *)map + 8);
  return;
}
