// =============================================================================
// FUN_0046bf90  (twin of NestedHash0x10_Insert_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0046bf90
// Address:   0x0046bf90–0x0046c1ae  (autoassault.exe, image base 0x400000)
// System:    NestedHash bag (sentinel node 0x10) — insert
// Generated: dual A/B seal 2026-07-29 (W36-B)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// Canonical clean: NestedHash0x10_Insert_Inferred.cpp

#include <stdint.h>

extern void FUN_0044a380(void *sentinel);
extern void *FUN_0046c2a0(void *next, void *prev);
extern void FUN_0046c230(uint32_t count /*ECX*/, void *list_host /*EDX*/);

/*
 * Retail: EDI=map*, stack out_pair*, stack kv*; RET 8.
 * Ghidra name retained as twin entry; prefer named clean for ports.
 *
 * Full rehash/relink body: see NestedHash0x10_Insert_Inferred.cpp + raw decompile.
 * This twin preserves the sealed ABI surface and hit/miss exits.
 */
void FUN_0046bf90(int *out_pair /*stack*/, uint32_t *kv /*stack*/)
{
  void *map; /* EDI formal — live, not junk */
  uint32_t list_size = *(uint32_t *)((char *)map + 0x0c);
  uint32_t maxidx = *(uint32_t *)((char *)map + 0x24);

  if (maxidx <= (list_size >> 2)) {
    /* rehash / redistribute — full body in named clean + raw */
    (void)FUN_0044a380;
  }

  {
    uint32_t key = *kv;
    uint32_t mask = *(uint32_t *)((char *)map + 0x20);
    uint32_t idx = key & mask;
    if (*(uint32_t *)((char *)map + 0x24) <= idx) {
      idx = idx + (uint32_t)(-1 - (mask >> 1));
    }

    void **tbl = *(void ***)((char *)map + 0x14);
    void *hint = tbl[idx + 1];
    void *bucket_start = tbl[idx];

    if (hint != bucket_start) {
      do {
        hint = *(void **)((char *)hint + 4);
        uint32_t nkey = *(uint32_t *)((char *)hint + 8);
        if (nkey <= key) {
          if (key <= nkey) {
            out_pair[0] = (int)hint;
            *(uint8_t *)(out_pair + 1) = 0;
            return; /* RET 8 */
          }
          hint = *(void **)hint;
          break;
        }
      } while (hint != bucket_start);
    }

    {
      void *new_node = FUN_0046c2a0(hint, *(void **)((char *)hint + 4));
      FUN_0046c230(1u, (char *)map + 4);
      *(void **)((char *)hint + 4) = new_node;
      **(void ***)((char *)new_node + 4) = new_node;
      /* bucket start repair loop — named clean */
      out_pair[0] = (int)*(void **)((char *)hint + 4);
      *(uint8_t *)(out_pair + 1) = 1;
      return; /* RET 8 */
    }
  }
}
