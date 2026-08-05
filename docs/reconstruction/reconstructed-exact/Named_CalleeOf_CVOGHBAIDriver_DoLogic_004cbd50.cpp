// =============================================================================
// Map_LowerBoundFindByIntKey_Isnil65  (Ghidra: FUN_004cbd50)
// -----------------------------------------------------------------------------
// Stable ID: aa_004cbd50
// Address:   0x004cbd50–0x004cbdb1  (98 B; autoassault.exe base 0x400000)
// System:    ordered map exact-find helper (AI profile / skill row maps)
// Sealed:    2026-07-29 W26-O (decompile + read_memory + analyze_function_complete)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Leaf MSVC-style ordered-tree **exact find** for a **signed dword** key.
//   Walk is lower_bound-shaped; post-gate (cand != end && key <= search) with
//   walk invariant key >= search yields equality. Miss writes end iterator.
//
// ABI:
//   __thiscall  ECX = map header (end/head at this+4)
//   stack:      Node **pOutIt, int *pKey
//   cleanup:    ret 8
//   return:     void (*pOutIt written)
//
// NODE (this unit):
//   +0x00 left, +0x08 right, +0x0C signed key dword, +0x65 isnil (0 = real)
//   root = (*(this+4))[1]   // head->parent
//
// CALLERS (5): FUN_004c9120, FUN_004c9430, CVOGHBAIDriver_DoLogic,
//   FUN_005d7ca0, FUN_005d7f70 (CVOGHBAICreatureBase_DoLogic)
//
// Siblings (different isnil/key layouts):
//   Map_LowerBoundFindByIntKey          0x0050f940  isnil+0x15
//   StdMap_LowerBoundByIntKey_INFERRED  0x004054f0  isnil+0x1d
//   Map_LowerBoundFindByCharKey         0x00402210  isnil+0x21
// =============================================================================

#include <stdint.h>

typedef struct MapNode_Isnil65 {
  struct MapNode_Isnil65 *left;    /* +0x00 */
  struct MapNode_Isnil65 *parent;  /* +0x04 */
  struct MapNode_Isnil65 *right;   /* +0x08 */
  int32_t key;                     /* +0x0C — compared as signed dword */
  /* ... value_type payload ... */
  /* isnil at +0x65 */
} MapNode_Isnil65;

typedef struct MapHeader_Isnil65 {
  /* +0x00 unused here */
  MapNode_Isnil65 *head;           /* +0x04 end / _Myhead */
} MapHeader_Isnil65;

/* Scaffold note: isnil accessed as *(char*)(node + 0x65). */
#define NODE_ISNIL65(n) (*(char *)((char *)(n) + 0x65))

void __thiscall Map_LowerBoundFindByIntKey_Isnil65(
    MapHeader_Isnil65 *this_map,
    MapNode_Isnil65 **p_out_it,
    int32_t *p_key)
{
  MapNode_Isnil65 *end_node;
  MapNode_Isnil65 *cand;
  MapNode_Isnil65 *cur;

  end_node = this_map->head; /* *(this+4) */
  cand = end_node;
  cur = end_node->parent;    /* end[1] */

  if (NODE_ISNIL65(cur) == 0) {
    do {
      if (cur->key < *p_key) {
        cur = cur->right;
      } else {
        cand = cur;
        cur = cur->left;
      }
    } while (NODE_ISNIL65(cur) == 0);
  }

  if ((cand != end_node) && (cand->key <= *p_key)) {
    *p_out_it = cand;
    return;
  }
  *p_out_it = end_node;
  return;
}

/* Ghidra twin name */
void __thiscall FUN_004cbd50(
    MapHeader_Isnil65 *param_1,
    MapNode_Isnil65 **param_2,
    int32_t *param_3)
{
  Map_LowerBoundFindByIntKey_Isnil65(param_1, param_2, param_3);
}
