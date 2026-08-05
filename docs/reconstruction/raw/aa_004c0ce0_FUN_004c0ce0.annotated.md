# Annotated low-level: FUN_004c0ce0

| Field | Value |
|---|---|
| Stable ID | `aa_004c0ce0` |
| VA | `0x004c0ce0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004c0ce0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
uint __fastcall FUN_004c0ce0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  
  if (*(int *)(param_1 + 0xc0) == 0) {
    uVar5 = *(uint *)(param_1 + 0xb0);
    *(undefined4 *)(uVar5 + 0xa8) = 0;
    return uVar5 & 0xffffff00;
  }
  iVar1 = *(int *)(param_1 + 0xb0);
  *(uint *)(iVar1 + 0xbc) = *(uint *)(iVar1 + 0xbc) | 1;
  iVar6 = *(int *)(iVar1 + 0x14);
  iVar2 = *(int *)(param_1 + 0xc0) * 4;
  if (*(int *)(iVar6 + 0x10) != 0) {
    if (iVar2 < 1) {
      iVar2 = *(int *)(iVar6 + 0x18);
    }
    puVar3 = (undefined4 *)FUN_00746520(*(undefined4 *)(iVar6 + 0x14),iVar2,1);
    if (puVar3 != (undefined4 *)0x0) {
      puVar7 = *(undefined4 **)(param_1 + 0xb4);
      for (uVar5 = (uint)(*(int *)(param_1 + 0xc0) * 0x70) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar3 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar3 = puVar3 + 1;
      }
      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(undefined1 *)puVar3 = *(undefined1 *)puVar7;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        puVar3 = (undefined4 *)((int)puVar3 + 1);
      }
    }
  }
  if (*(int *)(*(int *)(iVar1 + 0x14) + 0x10) != 0) {
    FUN_007464e0();
  }
  *(int *)(*(int *)(param_1 + 0xb0) + 0xa8) = *(int *)(param_1 + 0xc0) * 6 + -4;
  puVar4 = (uint *)(*(int *)(param_1 + 0xb0) + 0xbc);
  *puVar4 = *puVar4 & 0xfffffffe;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  return CONCAT31((int3)((uint)puVar4 >> 8),1);
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
