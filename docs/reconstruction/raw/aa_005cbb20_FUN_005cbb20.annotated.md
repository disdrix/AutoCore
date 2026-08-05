# Annotated low-level: FUN_005cbb20

| Field | Value |
|---|---|
| Stable ID | `aa_005cbb20` |
| VA | `0x005cbb20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005cbb20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005cbb20(undefined2 param_1)

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
  FUN_005c9a60(puVar5);
  FUN_005cb3d0(puVar5);
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
