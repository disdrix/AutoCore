# Annotated low-level: FUN_0041ace0

| Field | Value |
|---|---|
| Stable ID | `aa_0041ace0` |
| VA | `0x0041ace0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0041ace0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_0041ace0(int param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_3 == 0) {
    return 0x80004003;
  }
  puVar2 = (undefined4 *)FUN_00416ff0();
  puVar2[2] = param_3;
  puVar2[3] = 0;
  *puVar2 = &PTR_FUN_00a86174;
  puVar2[5] = 0;
  puVar2[6] = 0;
  *(undefined1 *)(puVar2 + 1) = 0;
  puVar2[4] = param_2;
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + (*(uint *)(param_1 + 8) & param_2) * 4);
  puVar2[3] = *(undefined4 *)(iVar1 + 4);
  *(undefined4 **)(iVar1 + 4) = puVar2;
  FUN_00429310();
  if (*(int *)(param_1 + 0x18) != 0) {
    *(undefined4 **)(*(int *)(param_1 + 0x18) + 0x14) = puVar2;
    puVar2[5] = 0;
    puVar2[6] = *(undefined4 *)(param_1 + 0x18);
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    *(undefined4 **)(param_1 + 0x18) = puVar2;
    return 0;
  }
  *(undefined4 **)(param_1 + 0x18) = puVar2;
  *(undefined4 **)(param_1 + 0x14) = puVar2;
  puVar2[6] = 0;
  puVar2[5] = 0;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
