# Annotated low-level: CVOGCharacter_LevelDown

| Field | Value |
|---|---|
| Stable ID | `aa_005330e0` |
| VA | `0x005330e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005330e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* CVOGCharacter_LevelDown — reverse one level + clamp pools >= 0
   
   Parameters: this = Character* (fastcall)
   
   Subtracts skill/attrib/research granted for the level being left
   (lookup tExperienceLevel row for current level before decrement).
   Re-searches auto missions if local player.
   Returns: void */

void __fastcall CVOGCharacter_LevelDown(void *this)

{
  uint *pKey;
  byte *pbVar1;
  void *pvVar2;
  int *extraout_EAX;
  uint uVar3;
  void *local_4;
  int pLevelRow;
  
  local_4 = this;
  if (g_nExperienceLevelTableReady == 0) {
    Experience_EnsureLevelTableLoaded_INFERRED();
  }
  pKey = (uint *)((int)this + 0x6c8);
  StdMap_LowerBoundByIntKey_INFERRED(&g_pExperienceLevelMap_INFERRED,&local_4,(int *)pKey);
  pvVar2 = (void *)*extraout_EAX;
  if (g_nExperienceLevelTableReady == 0) {
    Experience_EnsureLevelTableLoaded_INFERRED();
  }
  if (pvVar2 != g_pExperienceLevelMapEnd) {
    pLevelRow = *(int *)(*(int *)((int)this + 4) + 4);
    pbVar1 = (byte *)(pLevelRow + 0x180 + (int)this);
    *pbVar1 = *pbVar1 | 0x80;
    *pKey = *pKey - 1;
    *(short *)((int)this + 0x6ce) = *(short *)((int)this + 0x6ce) - *(short *)((int)pvVar2 + 0x16);
    if (*(short *)((int)this + 0x6ce) < 0) {
      *(undefined2 *)((int)this + 0x6ce) = 0;
    }
    *(short *)((int)this + 0x6cc) = *(short *)((int)this + 0x6cc) - *(short *)((int)pvVar2 + 0x14);
    if (*(short *)((int)this + 0x6cc) < 0) {
      *(undefined2 *)((int)this + 0x6cc) = 0;
    }
    uVar3 = *pKey & 0x80000001;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffffe) + 1;
    }
    if (uVar3 == 1) {
      FUN_004c2ef0(CONCAT22((short)((uint)pLevelRow >> 0x10),*(short *)((int)this + 0x13e) + -1));
      FUN_004c2ee0(*(short *)((int)this + 0x13c) + -1);
      FUN_004c2f00(*(short *)((int)this + 0x140) + -1);
      FUN_004c2f10(*(short *)((int)this + 0x142) + -1);
    }
    if (*(void **)((int)this + 0x250) != (void *)0x0) {
      Vehicle_RecalcCombatPools(*(void **)((int)this + 0x250));
    }
    (**(code **)(*(int *)this + 0x5c))();
    *(undefined2 *)((int)this + 300) = *(undefined2 *)((int)this + 0x12e);
    *(undefined1 *)((int)this + 0x4f2) = 1;
    if (*(char *)(*(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xa8 + (int)this) + 0x7e) != '\0'
       ) {
      CVOGCharacter_SearchAutoMissions(this);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
