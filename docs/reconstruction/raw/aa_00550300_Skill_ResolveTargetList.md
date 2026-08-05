# Raw capture: Skill_ResolveTargetList

| Field | Value |
|---|---|
| **Stable ID** | `aa_00550300` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00550300` |
| **Canonical name** | `Skill_ResolveTargetList` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Residual append 2026-07-29 (do not replace body)

- Ghidra live names: `Skill_FilterTargetForResolveList_Inferred` @ call site (was `FUN_0054ff00`); `Skill_RangeCheckTargetForResolveList_Inferred` (was `FUN_0058c0a0`).
- CF unchanged vs body below. Scratch: `reviews/a_00550300.md`.
- outFlags: this body writes **1** and **2** only; Filter writes **4/8/0x10**.

---

## Raw pseudocode (authoritative decompile)

```c
/* Skill_ResolveTargetList — build TFID list for cast from skill targeting flags
   
   Fills up to 100 TFID slots. Sets outFlags bits: 1=no target, 2=out of range (inferred).
   Uses skill+0x614 flags and skill+0x624 targeting mode bits. */

int __thiscall
Skill_ResolveTargetList
          (int param_1,int *param_2,undefined4 param_3,int *param_4,uint param_5,uint param_6,
          undefined4 param_7,undefined4 param_8,int *param_9,uint *param_10)

{
  bool bVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  float10 fVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  undefined4 uVar13;
  char local_32;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  
  iVar5 = 100;
  piVar3 = param_2;
  do {
    *piVar3 = DAT_009d1ca8;
    piVar3[1] = DAT_009d1cac;
    piVar3[2] = DAT_009d1cb0;
    iVar5 = iVar5 + -1;
    piVar3[3] = DAT_009d1cb4;
    piVar3 = piVar3 + 4;
  } while (iVar5 != 0);
  local_32 = '\0';
  bVar1 = true;
  if (((param_5 & param_6) == 0xffffffff) && ((char)param_7 == '\0')) {
    bVar1 = false;
  }
  uVar2 = CVOGReaction_ResolveObjectTarget(param_7,param_5,param_6);
  piVar3 = (int *)FUN_0054ff00(uVar2,param_4,param_10);
  if (piVar3 == (int *)0x0) {
LAB_005504d7:
    if ((*(uint *)(param_1 + 0x614) & 1) == 0) {
      if ((bVar1) && ((*(uint *)(param_1 + 0x614) & 0x20) == 0)) {
        *param_10 = *param_10 | 1;
        return 0;
      }
    }
    else {
      param_9 = (int *)(**(code **)(*param_4 + 0x1a0))();
    }
LAB_0055050c:
    iStack_20 = *param_9;
    iStack_1c = param_9[1];
    iStack_18 = param_9[2];
    iStack_14 = param_9[3];
  }
  else {
    if ((*(int *)(piVar3[0x2a] + 0x38) == 0x12) ||
       (piVar6 = piVar3, *(int *)(piVar3[0x2a] + 0x38) == 0x14)) {
      iVar5 = (**(code **)(*piVar3 + 0x1d8))();
      iVar5 = *(int *)(iVar5 + 0x250);
      if ((iVar5 == 0) ||
         ((piVar6 = (int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5), piVar6 == (int *)0x0 ||
          (iVar5 = (**(code **)(*piVar3 + 0x1d8))(), *(char *)(iVar5 + 0x30c) == '\0')))) {
        piVar6 = piVar3;
      }
    }
    fVar7 = (float10)FUN_0058c0a0(piVar6,param_4,*(undefined4 *)(param_1 + 0x2c),
                                  *(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x34),
                                  *(undefined1 *)(param_1 + 0x5e7));
    if ((float10)g_flZero == fVar7) {
      *param_10 = *param_10 | 2;
      goto LAB_005504d7;
    }
    *param_2 = piVar3[0x58];
    param_2[1] = piVar3[0x59];
    param_2[2] = piVar3[0x5a];
    param_2[3] = piVar3[0x5b];
    local_32 = '\x01';
    if (((uint)piVar6[0x5f] >> 5 & 1) != 0) {
      iVar5 = (**(code **)(*piVar6 + 0x1c8))();
      if (*(int *)(iVar5 + 8) == 0) {
        param_9 = (int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0x84 + iVar5);
      }
      else {
        param_9 = (int *)(*(int *)(*(int *)(iVar5 + 8) + 0x3c) + 0xb0);
      }
      goto LAB_0055050c;
    }
    iStack_20 = piVar6[0x20];
    iStack_1c = piVar6[0x21];
    iStack_18 = piVar6[0x22];
    iStack_14 = piVar6[0x23];
  }
  uVar4 = *(uint *)(param_1 + 0x624);
  if (((uVar4 & 0x20) == 0) && ((uVar4 & 0x4000) == 0)) {
    if ((uVar4 & 1) == 0) goto LAB_00550622;
    if ((uint)*(byte *)(param_1 + 0xde) <= (uint)(int)local_32) goto LAB_00550622;
    uVar13 = *(undefined4 *)(param_1 + 0x34);
    uVar8 = *(undefined4 *)(param_1 + 0x28);
    uVar10 = *(undefined4 *)(param_1 + 0x610);
    uVar9 = *(undefined4 *)(param_1 + 0x60c);
    uVar2 = 0;
    uVar12 = 0;
    uVar11 = 0;
    uVar4 = (uint)*(byte *)(param_1 + 0xde) - (int)local_32;
  }
  else {
    if ((uVar4 == 0) || (uVar4 == 0x20)) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
    uVar13 = 0xbf800000;
    uVar8 = *(undefined4 *)(param_1 + 0x38);
    uVar12 = *(uint *)(param_1 + 0x624) >> 5 & 0xffffff01;
    uVar11 = *(uint *)(param_1 + 0x624) >> 0xe & 0xffffff01;
    uVar9 = *(undefined4 *)(param_1 + 0x60c);
    uVar10 = *(undefined4 *)(param_1 + 0x610);
    uVar4 = (uint)*(byte *)(param_1 + 0xde);
  }
  local_32 = Skill_GatherTargetsInArea
                       (param_2,local_32,param_3,param_4,&iStack_20,uVar8,uVar4,uVar9,uVar10,uVar11,
                        uVar12,1,uVar2,0,uVar13);
LAB_00550622:
  return (int)local_32;
}
```
