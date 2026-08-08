// =============================================================================
// DisciplineDefMap_ExactFindByIntKey_Inferred  (aka FUN_00538ab0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00538ab0
// Address:   0x00538ab0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Dual:      R13-037 OWN-ONLY 2026-08-05 (dual start 2686)
// Parent:    0x0052b040 DisciplineDefMap_TryCopyPayloadById_Inferred (R12-020)
// Exactness: Behavior-preserving rewrite of decompiler + asm-sealed CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: NOT claimed.
// =============================================================================
//
// PURPOSE:
//   MSVC-style ordered-map exact find for the process-global DisciplineDef tree.
//   Lower-bound walk then equality gate; writes hit node* or end sentinel through
//   out-iterator. Read-only leaf (no insert/erase/alloc).
//
// ABI (asm-sealed):
//   void* __thiscall DisciplineDefMap_ExactFindByIntKey_Inferred(
//       MapHeader *this,   // ECX — callers hardcode 0x00b045b0
//       Node **pOut,       // stack +4
//       int *pKey);        // stack +8
//   - RET 8 (C2 08 00) both exits
//   - *pOut = hit node or *(this+4); EAX returns pOut so callers MOV EAX,[EAX]
//
// LAYOUT:
//   head = *(this+4); root = head[1]; nil @ node+0x20d; key int @ +0x0C;
//   left *node; right node+8. End symbol often DAT_00b045b4.
//
// DISTINCT FROM:
//   SkillDefMap_ExactFindByIntKey 0x00418890 (nil +0x641, separate lower_bound)
//   Map_ExactFindByIntKey 0x0051c150 (nil +0x29, key +0x10)
//   Map_FindByIntKey 0x00538a40 (nil +0x49, key +0x10) — nearby VA, different geometry
// =============================================================================

#include <stdint.h>

struct DisciplineDefMapNode {
  DisciplineDefMapNode *left;    // +0x00
  DisciplineDefMapNode *parent;  // +0x04
  DisciplineDefMapNode *right;    // +0x08
  int key;                       // +0x0C
  // +0x10  payload (0x1FC DisciplineDef blob — caller-owned)
  // +0x20D isnil
};

struct DisciplineDefMapHeader {
  // +0x00 unused by this unit
  DisciplineDefMapNode *head; // +0x04 end / _Myhead
};

// Returns pOut (iterator address); *pOut holds node* or end.
extern "C" DisciplineDefMapNode **__thiscall DisciplineDefMap_ExactFindByIntKey_Inferred(
    DisciplineDefMapHeader *self,
    DisciplineDefMapNode **pOut,
    const int *pKey)
{
  DisciplineDefMapNode *head = self->head;
  DisciplineDefMapNode *cand = head;
  DisciplineDefMapNode *cur = head->parent; // root = head[1]

  if (*(const uint8_t *)((const uint8_t *)cur + 0x20d) == 0) {
    do {
      if (cur->key < *pKey) {
        cur = cur->right;
      } else {
        cand = cur;
        cur = cur->left;
      }
    } while (*(const uint8_t *)((const uint8_t *)cur + 0x20d) == 0);
  }

  if (cand != head && cand->key <= *pKey) {
    *pOut = cand; // exact hit (walk invariant + <= ⇒ equality)
  } else {
    *pOut = head; // miss
  }
  return pOut;
}

// Ghidra twin export name
extern "C" DisciplineDefMapNode **__thiscall FUN_00538ab0(
    DisciplineDefMapHeader *param_1,
    DisciplineDefMapNode **param_2,
    const int *param_3)
{
  return DisciplineDefMap_ExactFindByIntKey_Inferred(param_1, param_2, param_3);
}
