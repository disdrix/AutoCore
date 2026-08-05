# Annotated low-level: FUN_005dbc20

| Field | Value |
|---|---|
| Stable ID | `aa_005dbc20` |
| VA | `0x005dbc20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005dbc20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005dbc20(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x168);
  if (puVar2 != *(undefined4 **)(param_1 + 0x16c)) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
      FUN_005b04b0(*puVar2,*(undefined4 *)(iVar1 + param_1 + 0x164),
                   *(undefined4 *)(iVar1 + 0x168 + param_1));
      iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
      FUN_005b04b0(puVar2[1],*(undefined4 *)(iVar1 + param_1 + 0x164),
                   *(undefined4 *)(iVar1 + 0x168 + param_1));
      puVar2 = puVar2 + 3;
    } while (puVar2 != *(undefined4 **)(param_1 + 0x16c));
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
