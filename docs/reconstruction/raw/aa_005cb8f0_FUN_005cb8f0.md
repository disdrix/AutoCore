# Raw capture: FUN_005cb8f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cb8f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005cb8f0` |
| **Canonical name** | `FUN_005cb8f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x005cba86) */
/* WARNING: Removing unreachable block (ram,0x005cba9a) */
/* WARNING: Removing unreachable block (ram,0x005cbaa7) */
/* WARNING: Removing unreachable block (ram,0x005cbaad) */
/* WARNING: Removing unreachable block (ram,0x005cbabd) */
/* WARNING: Removing unreachable block (ram,0x005cbae0) */
/* WARNING: Removing unreachable block (ram,0x005cbae5) */
/* WARNING: Removing unreachable block (ram,0x005cbaed) */
/* WARNING: Removing unreachable block (ram,0x005cbb03) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_005cb8f0(int param_1,undefined4 param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  void *pSkillData;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  ushort unaff_retaddr;
  undefined4 uSkillID;
  undefined1 auStack_4 [4];
  
  auStack_4 = (undefined1  [4])param_1;
  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) + 0x60))();
  uVar6 = 0;
  iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) + 0x60))
                    ();
  uVar1 = (ushort)param_2;
  if (iVar2 != 0) {
    do {
      uVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) +
                          0x5c))(uVar6);
      if (uVar1 == unaff_retaddr) {
        return 0x80004005;
      }
      uVar6 = uVar6 + 1;
      uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) +
                          0x60))();
      uVar1 = unaff_retaddr;
    } while (uVar6 < uVar3);
  }
  auStack_4[2] = 0;
  auStack_4._0_2_ = uVar1;
  iVar2 = FUN_004ce940();
  if (iVar2 == 0) {
    iVar5 = FUN_005c9a00();
    iVar2 = *(int *)(iVar5 + 4);
    if ((iVar2 == 0) ||
       ((uint)(*(int *)(iVar5 + 0xc) - iVar2 >> 2) <= (uint)(*(int *)(iVar5 + 8) - iVar2 >> 2))) {
      FUN_005c9cc0(*(undefined4 *)(iVar5 + 8),1,auStack_4);
    }
    else {
      iVar2 = *(int *)(iVar5 + 8);
      FUN_005c96c0(iVar2,1,auStack_4,iVar5,param_2);
      *(int *)(iVar5 + 8) = iVar2 + 4;
    }
    return 0;
  }
  uSkillID = 1;
  pSkillData = (void *)FUN_00509940(uVar1);
  puVar4 = CVOGReaction_ResolveSkillTargets(pSkillData,uSkillID);
  if ((puVar4 != (undefined4 *)0x0) && (*(char *)(puVar4 + 0x17d) != '\0')) {
    iVar2 = CVOGReaction_RandomUnitScalar();
    if (0xfffff < *(int *)(iVar2 + 0xc)) {
      *(undefined4 *)(iVar2 + 0xc) = 0;
    }
    uVar1 = *(ushort *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);
    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;
    auStack_4[2] = (char)((int)((float)uVar1 * _DAT_009cdcc0) % (int)(uint)*(byte *)(puVar4 + 0x17d)
                         ) + '\x01';
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(puVar4);
}
```
