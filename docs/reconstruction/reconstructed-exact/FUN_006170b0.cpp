// =============================================================================
// FUN_006170b0  (scaffold / Ghidra leave-name)
// Canonical: Skill_HB_SpawnEntities_Precheck_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_006170b0
// Address:   0x006170b0 – 0x00617399  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / HB spawn effect (PTR_FUN_009d0ec4 vtbl+0x1c)
// Generated: 2026-07-29 W20-N OWN-ONLY dual (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte-sealed returns.
//            Named twin: Skill_HB_SpawnEntities_Precheck_Inferred.cpp
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * See Skill_HB_SpawnEntities_Precheck_Inferred.cpp for annotated named clean.
 * Scaffold keeps FUN_* symbol for leave-name callers/docs.
 */

#include <stdint.h>

extern int __cdecl __RTDynamicCast(void *obj, int, void *from, void *to, int);
extern int __thiscall FUN_004c3f10(void *creature, char flag);
extern int __thiscall FUN_004c2e60(void *creature);
extern void *FUN_00439770(void);
extern int *Object_ResolveFromTFID(void *tfid16);
extern void Map_LowerBoundFindByIntKey(void *mapShell, void **outIt, void *key, void *unused);
extern void __thiscall FUN_006178d0(void *map, void *key, void *kv);
extern void *FUN_005001f0(void);
extern void __thiscall FUN_00617990(void *map, void *first, void *last);
extern void operator_delete(void *p);
extern void CVOGClonedObjectBase_RTTI;
extern void CVOGCreature_RTTI;
extern float DAT_00aaa7ac;
extern float g_flZero;
extern uint8_t DAT_009e1c58[];

uint32_t FUN_006170b0(void *param_1, int param_2)
{
  int iVar1;
  int iVar2;
  uint32_t uVar3;
  int iVar4;
  int *piVar5;
  uint32_t *puVar6;
  void *pTfid;
  uint32_t uVar7;
  int iStack_44;
  uint32_t auStack_40[2];
  uint32_t uStack_38;
  uint32_t *puStack_34;
  uint32_t local_30;
  uint32_t uStack_2c;
  uint32_t uStack_28;
  uint8_t local_24[4];
  uint32_t *puStack_20;

  (void)local_24;

  iVar1 = __RTDynamicCast(param_1, 0, &CVOGClonedObjectBase_RTTI, &CVOGCreature_RTTI, 0);
  if (iVar1 == 0)
    return 2;

  iVar2 = FUN_004c3f10((void *)(intptr_t)iVar1, 0);
  uVar3 = (uint32_t)FUN_004c3f10((void *)(intptr_t)iVar1, 1);

  if (*(float *)(param_2 + 0x16c) == DAT_00aaa7ac)
    return 0;

  local_30 = uVar3;
  if (*(float *)(param_2 + 0x16c) == g_flZero) {
    int base = *(int *)(iVar1 + 4);
    int mid = *(int *)(base + 4);
    int *plant = (int *)(mid + 4 + iVar1);
    iVar4 = (*(int(__thiscall **)(int *, int))(*plant + 0x210))(plant, 0);
    if (iVar4 != 0) {
      (*(int(__thiscall **)(int *, int))(*plant + 0x210))(plant, 0);
      iVar4 = FUN_004c2e60((void *)(intptr_t)iVar1);
      if (iVar4 <= iVar2)
        return 0x10;
    }
  }

  puStack_20 = (uint32_t *)FUN_00439770();
  *(uint8_t *)((char *)puStack_20 + 0x15) = 1;
  puStack_20[1] = (uint32_t)(uintptr_t)puStack_20;
  *puStack_20 = (uint32_t)(uintptr_t)puStack_20;
  puStack_20[2] = (uint32_t)(uintptr_t)puStack_20;

  uStack_38 = 0;
  if (uVar3 != 0) {
    iStack_44 = 0;
    do {
      iVar2 = *(int *)(iVar1 + 0x1bc);
      if ((iVar2 == 0) ||
          ((uint32_t)(*(int *)(iVar1 + 0x1c0) - iVar2) >> 4) <= uStack_38) {
        pTfid = &DAT_009e1c58;
      } else {
        pTfid = (void *)(iStack_44 + iVar2);
      }

      piVar5 = Object_ResolveFromTFID(pTfid);
      if (piVar5 != 0) {
        uVar7 = *(uint32_t *)(piVar5[0x2a] + 0x34);
        if (*(char *)(param_2 + 0x22) != '\0') {
          auStack_40[0] = uVar7;
          iVar2 = (*(int(__thiscall **)(int *))(*piVar5 + 0x1d8))(piVar5);
          if ((iVar2 == 0) || (*(int *)(iVar2 + 0x250) == 0))
            goto LAB_next;
          iVar2 = *(int *)(iVar2 + 0x250);
          piVar5 = (int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2);
          if (piVar5 == 0)
            goto LAB_next;
          (*(void(__thiscall **)(int *))(*piVar5 + 0x1d4))(piVar5);
          puVar6 = (uint32_t *)FUN_005001f0();
          uVar7 = *puVar6;
        }
        auStack_40[0] = uVar7;
        if ((*(uint8_t *)(piVar5 + 0x5f) & 1) == 0) {
          Map_LowerBoundFindByIntKey(local_24, (void **)&puStack_34, auStack_40, 0);
          if (puStack_34 == puStack_20) {
            uStack_28 = 1;
            uStack_2c = uVar7;
            FUN_006178d0((void *)&puStack_20, auStack_40, &uStack_2c);
          } else {
            puStack_34[4] = puStack_34[4] + 1;
          }
        }
      }
    LAB_next:
      iStack_44 += 0x10;
      uStack_38++;
    } while (uStack_38 < local_30);
  }

  local_30 = *(uint32_t *)(param_2 + 0x14c);
  Map_LowerBoundFindByIntKey(local_24, (void **)&puStack_34, &local_30, 0);
  if ((puStack_34 != puStack_20) &&
      ((uint32_t)*(uint8_t *)(param_2 + 0xda) <= (uint32_t)puStack_34[4])) {
    FUN_00617990((void *)&local_30, (void *)(uintptr_t)*puStack_20, puStack_20);
    operator_delete(puStack_20);
    return 8;
  }

  FUN_00617990((void *)&local_30, (void *)(uintptr_t)*puStack_20, puStack_20);
  operator_delete(puStack_20);
  return 0;
}
