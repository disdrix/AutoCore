# Raw capture: FUN_004fdcb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fdcb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004fdcb0` |
| **Canonical name** | `FUN_004fdcb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004fdcb0(int param_1,int *param_2)

{
  int *piVar1;
  undefined1 uVar2;
  short sVar3;
  undefined2 uVar4;
  void *pvVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  
  piVar1 = param_2;
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 4) + param_1;
  uVar11 = 0;
  if ((((*(int *)(iVar6 + 0xb0) != 0) && (*(int *)(iVar6 + 0xa8) != 0)) && (param_2 != (int *)0x0))
     && (pvVar5 = Object_ResolveFromTFID
                            ((TFID_16 *)
                             (*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) + 0x160
                             )), pvVar5 != (void *)0x0)) {
    if (piVar1[0x1c] != 0) {
      param_2 = (int *)0x0;
      FUN_00402c40();
      iVar6 = FUN_00411900(&param_2);
      while (iVar6 != 0) {
        if ((*(uint *)(iVar6 + 0x614) & 0x100) != 0) {
          if (*(int *)(param_1 + 8) == 0) {
            iVar10 = *(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1;
          }
          else {
            iVar10 = *(int *)(*(int *)(param_1 + 8) + 0x3c) + 0xb0;
          }
          CVOGReaction_CastSkillOnTarget
                    (iVar6,piVar1,
                     *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1),1,0,
                     iVar10,0,0xffffffff,0,0);
        }
        iVar6 = FUN_00411900(&param_2);
      }
      *(undefined1 *)(piVar1[0x1c] + 0x1d) = 0;
    }
    param_2 = (int *)FUN_004ce940();
    if (param_2 != (int *)0x0) {
      iVar6 = (**(code **)(*piVar1 + 0x60))();
      if (iVar6 != 0) {
        do {
          sVar3 = (**(code **)(*piVar1 + 0x5c))(uVar11);
          if (sVar3 != 0) {
            uVar2 = (**(code **)(*piVar1 + 0x70))(uVar11);
            uVar4 = (**(code **)(*piVar1 + 0x5c))(uVar11,uVar2);
            pvVar5 = (void *)FUN_00509940(uVar4);
            puVar7 = CVOGReaction_ResolveSkillTargets(pvVar5,uVar11);
            if (puVar7 != (undefined4 *)0x0) {
              CVOGReaction_CastSkillOnTarget
                        (puVar7,piVar1,
                         *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1),0,0,
                         &DAT_00b041b0,0,0xffffffff,0,0);
            }
                    /* WARNING: Subroutine does not return */
            operator_delete(puVar7);
          }
          uVar11 = uVar11 + 1;
          uVar8 = (**(code **)(*piVar1 + 0x60))();
        } while (uVar11 < uVar8);
      }
      uVar11 = 0;
      iVar6 = (**(code **)(*piVar1 + 0x80))();
      if (iVar6 != 0) {
        do {
          sVar3 = (**(code **)(*piVar1 + 0x7c))(uVar11);
          if (sVar3 != 0) {
            uVar4 = (**(code **)(*piVar1 + 0x7c))(uVar11);
            iVar6 = FUN_00404d70(uVar4);
            if ((iVar6 != 0) && (iVar6 = *(int *)(iVar6 + 0x3c), iVar6 != 0)) {
              uVar9 = (**(code **)(*piVar1 + 0x94))(uVar11);
              uVar9 = CONCAT22((short)((uint)uVar9 >> 0x10),(ushort)(byte)uVar9);
              pvVar5 = (void *)FUN_00509940(*(undefined4 *)(iVar6 + 0x4c0));
              puVar7 = CVOGReaction_ResolveSkillTargets(pvVar5,uVar9);
              if (puVar7 != (undefined4 *)0x0) {
                CVOGReaction_CastSkillOnTarget
                          (puVar7,piVar1,
                           *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1),0,0
                           ,&DAT_00b041b0,0,0xffffffff,0,0);
              }
                    /* WARNING: Subroutine does not return */
              operator_delete(puVar7);
            }
          }
          uVar11 = uVar11 + 1;
          uVar8 = (**(code **)(*piVar1 + 0x80))();
        } while (uVar11 < uVar8);
      }
    }
  }
  return;
}
```
