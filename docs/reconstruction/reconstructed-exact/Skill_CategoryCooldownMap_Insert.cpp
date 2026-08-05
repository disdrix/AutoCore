// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, do×1, while×1.
//  - Notable callees: FUN_0051c1c0×2, FUN_005ae050.
//  - Return sites: 3 × RET 0x8.
//  - Residual 2026-07-29: insert-or-find (not assign); node 0x1c layout sealed via FUN_005ae220.

// =============================================================================
// Skill_CategoryCooldownMap_Insert
// -----------------------------------------------------------------------------
// Stable ID: aa_0051d2f0
// Address:   0x0051d2f0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 from raw capture; plate residual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - __thiscall map mutator; RET 0x8 (two stack args).
 * - Insert-or-find: equal key returns existing node, inserted=0, NO start/duration write.
 * - New key: FUN_0051c1c0 → FUN_005ae220 operator_new(0x1c) copies {key,start,duration}.
 * - Node: +0x0C key, +0x10 startTick, +0x14 durationMs, +0x18 color, +0x19 isnil.
 * - Map shell: +0x04 head, +0x08 size, size 0x0c.
 * - FUN_005ae050 = tree predecessor (not insert).
 * - Callers: Skill_InsertCategoryCooldown, CVOGHBOKToCastAgain_ctor only.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

/* Skill_CategoryCooldownMap_Insert / Map_InsertOrFind style insert

   Inserts category cooldown node {key, startTick, duration} on miss only.
   Shared pattern with Map_InsertOrFind_IntKey. */

// Out pair: { node* it @ +0, uint8_t inserted @ +4 }
// Value:    { int32 key, uint32 startTick, int32 durationMs }

void __thiscall Skill_CategoryCooldownMap_Insert(
    int thisMap,
    uint32_t /* width from decompiler */ *pOutPair,
    int *pValue)
{
  uint32_t /* width from decompiler */ uVar1;
  bool goLeft;
  int *pValueSaved;
  uint32_t /* width from decompiler */ *child;
  uint32_t /* width from decompiler */ *node;

  pValueSaved = pValue;
  node = *(uint32_t /* width from decompiler */ **)(thisMap + 4); // head
  goLeft = true;
  if (*(char *)((int)node[1] + 0x19) == '\0') { // root isnil?
    child = (uint32_t /* width from decompiler */ *)node[1];
    do {
      node = child;
      goLeft = *pValue < (int)node[3]; // key < node.key (+0x0C)
      if (goLeft) {
        child = (uint32_t /* width from decompiler */ *)*node; // left
      } else {
        child = (uint32_t /* width from decompiler */ *)node[2]; // right
      }
    } while (*(char *)((int)child + 0x19) == '\0');
  }
  pValue = (int *)node; // decomp: parent candidate in pValue slot
  if (goLeft) {
    if (node == (uint32_t /* width from decompiler */ *)**(int **)(thisMap + 4)) {
      // insert as new leftmost
      node = (uint32_t /* width from decompiler */ *)FUN_0051c1c0(&pValue, 1, node, pValueSaved);
      uVar1 = *node;
      *(uint8_t *)((int)pOutPair + 4) = 1;
      *pOutPair = uVar1;
      return;
    }
    FUN_005ae050(); // Tree_Predecessor(&parent)
  }
  if (pValue[3] < *pValueSaved) {
    // parent.key < key → insert on chosen side
    node = (uint32_t /* width from decompiler */ *)FUN_0051c1c0(&pValue, goLeft, node, pValueSaved);
    *pOutPair = *node;
    *(uint8_t *)((int)pOutPair + 4) = 1;
    return;
  }
  // equal key — find only; do not rewrite start/duration
  *(uint8_t *)((int)pOutPair + 4) = 0;
  *pOutPair = (uint32_t)pValue;
  return;
}
