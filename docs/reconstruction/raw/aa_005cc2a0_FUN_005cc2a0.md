# Raw capture: FUN_005cc2a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cc2a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005cc2a0` |
| **Canonical name** | `FUN_005cc2a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005cc2a0(undefined2 param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  void *pSkillData;
  undefined4 *puVar4;
  char cStack00000006;
  undefined4 uSkillID;
  undefined2 *puVar5;
  
  uVar2 = param_1;
  cStack00000006 = '\0';
  iVar3 = FUN_004ce940();
  if (iVar3 != 0) {
    iVar3 = FUN_00404d70(uVar2);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 0x3c) != 0)) {
      uSkillID = 1;
      pSkillData = (void *)FUN_00509940(*(undefined4 *)(*(int *)(iVar3 + 0x3c) + 0x4c0));
      puVar4 = CVOGReaction_ResolveSkillTargets(pSkillData,uSkillID);
      if ((puVar4 != (undefined4 *)0x0) && (*(char *)(puVar4 + 0x17d) != '\0')) {
        iVar3 = CVOGReaction_RandomUnitScalar();
        if (0xfffff < *(int *)(iVar3 + 0xc)) {
          *(undefined4 *)(iVar3 + 0xc) = 0;
        }
        uVar1 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);
        *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;
        cStack00000006 =
             (char)((int)((float)uVar1 * _DAT_009cdcc0) % (int)(uint)*(byte *)(puVar4 + 0x17d)) +
             '\x01';
      }
                    /* WARNING: Subroutine does not return */
      operator_delete(puVar4);
    }
  }
  puVar5 = &param_1;
  FUN_005c9c50(puVar5);
  FUN_005cb3d0(puVar5);
  return 0;
}
```
