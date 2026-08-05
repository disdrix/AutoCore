# Annotated low-level: FUN_006bacf0

| Field | Value |
|---|---|
| Stable ID | `aa_006bacf0` |
| VA | `0x006bacf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006bacf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006bacf0(int param_1,int param_2,int param_3,code *param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  char *pcVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  undefined1 local_2a;
  undefined1 uStack_29;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  do {
    local_28 = param_2;
    puVar1 = (undefined4 *)((param_2 + param_3 >> 1) * 0x10 + param_1);
    local_20 = *puVar1;
    uStack_1c = puVar1[1];
    uStack_18 = puVar1[2];
    uStack_14 = puVar1[3];
    iVar13 = param_3;
    do {
      local_24 = local_28 * 0x10 + param_1;
      pcVar11 = (char *)(*param_4)(&local_2a,local_24,&local_20);
      cVar3 = *pcVar11;
      iVar14 = local_24;
      while (cVar3 != '\0') {
        local_28 = local_28 + 1;
        iVar14 = iVar14 + 0x10;
        pcVar11 = (char *)(*param_4)(&local_2a,iVar14,&local_20);
        cVar3 = *pcVar11;
      }
      local_24 = iVar13 * 0x10 + param_1;
      pcVar11 = (char *)(*param_4)(&uStack_29,&local_20,local_24);
      cVar3 = *pcVar11;
      iVar14 = local_24;
      while (cVar3 != '\0') {
        iVar14 = iVar14 + -0x10;
        iVar13 = iVar13 + -1;
        pcVar11 = (char *)(*param_4)(&uStack_29,&local_20,iVar14);
        cVar3 = *pcVar11;
      }
      if (iVar13 < local_28) break;
      if (iVar13 != local_28) {
        puVar1 = (undefined4 *)(iVar13 * 0x10 + param_1);
        uVar4 = *puVar1;
        uVar5 = puVar1[1];
        uVar6 = puVar1[2];
        uVar7 = puVar1[3];
        puVar1 = (undefined4 *)(iVar13 * 0x10 + param_1);
        puVar2 = (undefined4 *)(local_28 * 0x10 + param_1);
        uVar8 = puVar2[1];
        uVar9 = puVar2[2];
        uVar10 = puVar2[3];
        puVar12 = (undefined4 *)(local_28 * 0x10 + param_1);
        *puVar1 = *puVar2;
        puVar1[1] = uVar8;
        puVar1[2] = uVar9;
        puVar1[3] = uVar10;
        *puVar12 = uVar4;
        puVar12[1] = uVar5;
        puVar12[2] = uVar6;
        puVar12[3] = uVar7;
      }
      iVar13 = iVar13 + -1;
      local_28 = local_28 + 1;
    } while (local_28 <= iVar13);
    if (param_2 < iVar13) {
      FUN_006bacf0(param_1,param_2,iVar13,param_4);
    }
    param_2 = local_28;
    if (param_3 <= local_28) {
      return;
    }
  } while( true );
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
