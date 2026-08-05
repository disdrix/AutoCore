# Annotated low-level: FUN_004d3ae0

| Field | Value |
|---|---|
| Stable ID | `aa_004d3ae0` |
| VA | `0x004d3ae0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004d3ae0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004d3ae0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if ((*(char *)(param_1 + 0x82) != '\0') && (param_2 != 0)) {
    local_20 = *(undefined4 *)(param_2 + 0x160);
    local_1c = *(undefined4 *)(param_2 + 0x164);
    if (param_3 == 0) {
      local_30 = DAT_009cbf68;
      local_2c = DAT_009cbf6c;
      local_24 = DAT_009cbf74;
      local_28 = DAT_009cbf70;
    }
    else {
      local_30 = *(undefined4 *)(param_3 + 0x160);
      local_2c = *(undefined4 *)(param_3 + 0x164);
      local_24 = *(undefined4 *)(param_3 + 0x16c);
      local_28 = *(undefined4 *)(param_3 + 0x168);
    }
    iVar1 = *(int *)(param_1 + 0xe8e8);
    iVar2 = FUN_004e29c0(iVar1,*(undefined4 *)(iVar1 + 4),&local_30);
    FUN_004e29f0(1);
    *(int *)(iVar1 + 4) = iVar2;
    **(int **)(iVar2 + 4) = iVar2;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
