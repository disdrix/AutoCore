// =============================================================================
// Map_InsertOrFind_IntKey
// -----------------------------------------------------------------------------
// Stable ID: aa_005d2360
// Address:   0x005d2360  (autoassault.exe, image base 0x400000)
// System:    skills-abilities (NPC AI post-cast timer map)
// Generated: 2026-07-23 scaffold; dual seal refine 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual:      reviews/A_aa_005d2360_Map_InsertOrFind_IntKey.md
//            reviews/B_aa_005d2360_Map_InsertOrFind_IntKey.md
// =============================================================================

/*
 * Behavioral notes:
 * - MSVC std::map insert-or-find: int key -> int mapped (node size 0x18).
 * - ABI: __thiscall; RET 0x8 (two stack args). Ghidra phantom third stack param unused.
 * - Args: this=map shell; pOut={node*,inserted@+4}; pVal={key, mapped} (2 dwords).
 * - Node: left+0 parent+4 right+8 key+0xC mapped+0x10 color+0x14 isnil+0x15.
 * - Equal key: return existing, inserted=0, mapped NOT rewritten.
 * - Callees: FUN_005d20b0 insert+rebalance; FUN_005a2850 predecessor.
 * - Only static caller: NPC_TryCastSkillFromSet @ 0x005d18f7 (map @ AI+0x98).
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 * - Parameter names kept as raw decompiler labels for body fidelity; see dual for sealed ABI.
 */

/* Map_InsertOrFind_IntKey / shared pattern with Skill_CategoryCooldownMap_Insert
   (different node: isnil+0x15 size 0x18 vs category CD isnil+0x19 size 0x1C). */

void __thiscall Map_InsertOrFind_IntKey(void *this,void *pMap,void *pOutPair,int *pKey)

{
  uint32_t /* width from decompiler */ uVar1;
  bool bVar2;
  void *pvVar3;
  uint32_t /* width from decompiler */ *puVar4;
  uint32_t /* width from decompiler */ *puVar5;
  
  pvVar3 = pOutPair;
  puVar5 = *(uint32_t /* width from decompiler */ **)((int)this + 4);
  bVar2 = true;
  if (*(char *)((int)puVar5[1] + 0x15) == '\0') {
    puVar4 = (uint32_t /* width from decompiler */ *)puVar5[1];
    do {
      puVar5 = puVar4;
      bVar2 = *(int *)pOutPair < (int)puVar5[3];
      if (bVar2) {
        puVar4 = (uint32_t /* width from decompiler */ *)*puVar5;
      }
      else {
        puVar4 = (uint32_t /* width from decompiler */ *)puVar5[2];
      }
    } while (*(char *)((int)puVar4 + 0x15) == '\0');
  }
  pOutPair = puVar5;
  if (bVar2) {
    if (puVar5 == (uint32_t /* width from decompiler */ *)**(int **)((int)this + 4)) {
      puVar5 = (uint32_t /* width from decompiler */ *)FUN_005d20b0(&pOutPair,1,puVar5,pvVar3);
      uVar1 = *puVar5;
      *(uint8_t *)((int)pMap + 4) = 1;
      *(uint32_t /* width from decompiler */ *)pMap = uVar1;
      return;
    }
    FUN_005a2850();
  }
  if (*(int *)((int)pOutPair + 0xc) < *(int *)pvVar3) {
    puVar5 = (uint32_t /* width from decompiler */ *)FUN_005d20b0(&pOutPair,bVar2,puVar5,pvVar3);
    *(uint32_t /* width from decompiler */ *)pMap = *puVar5;
    *(uint8_t *)((int)pMap + 4) = 1;
    return;
  }
  *(uint8_t *)((int)pMap + 4) = 0;
  *(void **)pMap = pOutPair;
  return;
}
