// =============================================================================
// HashMap_FindIterator_Inferred  (Ghidra: FUN_0044e8c0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0044e8c0
// Address:   0x0044e8c0 – 0x0044e945  (autoassault.exe, image base 0x400000)
// System:    hash map (ND resource cache + other name tables)
// Generated: 2026-07-29 W21-N OWN-ONLY dual (decompile + read_memory)
// Exactness: Byte-sealed CF. Register formals EDI=map, EBX=key sealed by bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Find node by key in custom hash map; write iterator to *out_it.
 *
 * ABI (byte-sealed):
 *   EDI     = HashMap*          (register formal — not on stack)
 *   EBX     = KeyObject*        (*key is char* for hash; *key dword compared)
 *   stack   = out_it**          (ret 4)
 *   returns out_it* in EAX
 *
 * Map:  +0x08 end sentinel, +0x14 bucket table, +0x20 mask, +0x24 bucket_count
 * Node: +0x00 next*, +0x08 key dword
 *
 * Hash: FUN_0043b870 (ELF-style string hash on *(char**)key).
 * Callers: NDResourceCache_LookupOrCreate and ~19 other sites.
 *
 * Note: Ghidra shows unaff_EDI/unaff_EBX; those are live formals, not junk.
 * This clean documents them as explicit parameters for readability while
 * preserving the machine algorithm.
 */

#include <stdint.h>

/* Hash leaf — not owned by this dual; EAX=key on entry in machine code. */
extern uint32_t FUN_0043b870(void *key_object /* machine: EAX */);

void **HashMap_FindIterator_Inferred(
    void *map /* machine: EDI */,
    uint32_t *key /* machine: EBX */,
    void **out_it /* machine: stack; ret 4 */)
{
  uint32_t mask = *(uint32_t *)((char *)map + 0x20);
  uint32_t idx = FUN_0043b870(key) & mask;

  if (*(uint32_t *)((char *)map + 0x24) <= idx) {
    idx = idx + (uint32_t)(-1 - (mask >> 1));
  }

  {
    int *bucket = (int *)(*(int *)((char *)map + 0x14) + (int)idx * 4);
    int *node = (int *)bucket[0];
    int *end = (int *)bucket[1];

    if (node != end) {
      do {
        uint32_t keyv = *key;
        uint32_t nkey = (uint32_t)node[2]; /* node + 8 */

        if (keyv <= nkey) {
          if (nkey <= keyv) {
            *out_it = node;
            return out_it;
          }
          *out_it = *(void **)((char *)map + 8);
          return out_it;
        }
        node = (int *)node[0];
      } while (node != end);
    }
  }

  *out_it = *(void **)((char *)map + 8);
  return out_it;
}
