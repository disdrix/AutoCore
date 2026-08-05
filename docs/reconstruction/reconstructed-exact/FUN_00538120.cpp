// =============================================================================
// CNDHash_ReleaseNodesToFreelist_Owning_009cefd4
// -----------------------------------------------------------------------------
// Stable ID: aa_00538120
// Address:   0x00538120  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00538120
// System:    container / CNDHash (object family 009cfa64; node vtbl 009cefd4)
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W17-K)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes (dual A/B sealed 2026-07-29):
 * - Owning reclaim of all live bucket chains onto freelist hash+0x20.
 * - Per node: stamp PTR_FUN_009cefd4, operator_delete(value at +8) if set,
 *   clear value, push node on freelist (overwrite *node with old freelist head).
 * - Loop i = 0 .. *(hash+8) inclusive; clear each bucket head (*bucket+4).
 * - Sole caller: CNDHash_FreeBuckets_Owning_009cfa64 (FUN_00539090) — count=0 then
 *   this reclaim then free sentinel slab + table.
 * - Node layout matches CNDHash_Insert 0x0053c560 (vtbl 009cefd4, value +8, next +0xc).
 * - Ghidra WARNING "does not return" on operator_delete is a false positive.
 *
 * Readability pass:
 * - Control flow and call order preserved from authoritative raw.
 * - Types refined from family duals; product English still Inferred.
 */

#include <stdint.h>

/* Forward decls — retail symbols unresolved in this translation unit. */
struct CNDHash;
struct CNDHashNode_009cefd4;
extern void *PTR_FUN_009cefd4;
void operator_delete(void *p);

void __fastcall CNDHash_ReleaseNodesToFreelist_Owning_009cefd4(CNDHash *hash)
{
  uint32_t i;
  uint32_t *node;
  uint32_t *next;
  uint32_t *table;
  uint32_t *bucket;

  i = 0;
  do {
    table = *(uint32_t **)((char *)hash + 0x10);
    bucket = (uint32_t *)table[i];
    node = (uint32_t *)bucket[1]; /* head at bucket+4 */
    while (node != 0) {
      next = (uint32_t *)node[3]; /* +0x0c */
      *node = (uint32_t)&PTR_FUN_009cefd4;
      if ((void *)node[2] != 0) { /* value +0x08 */
        operator_delete((void *)node[2]);
      }
      node[2] = 0;
      *node = *(uint32_t *)((char *)hash + 0x20);
      *(uint32_t **)((char *)hash + 0x20) = node;
      node = next;
    }
    table = *(uint32_t **)((char *)hash + 0x10);
    bucket = (uint32_t *)table[i];
    i = i + 1;
    bucket[1] = 0;
  } while (i <= *(uint32_t *)((char *)hash + 8));
  return;
}

/* Ghidra name retained for xref continuity. */
void __fastcall FUN_00538120(int param_1)
{
  CNDHash_ReleaseNodesToFreelist_Owning_009cefd4((CNDHash *)param_1);
}
