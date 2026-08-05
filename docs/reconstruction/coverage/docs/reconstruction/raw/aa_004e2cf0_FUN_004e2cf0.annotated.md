# Annotated low-level: FUN_004e2cf0

| Field | Value |
|---|---|
| Stable ID | `aa_004e2cf0` |
| VA | `0x004e2cf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004e2cf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004e2cf0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    puVar3 = *(undefined4 **)(*(int *)(*(int *)(param_1 + 0x10) + uVar4 * 4) + 4);
    while (puVar3 != (undefined4 *)0x0) {
      puVar2 = (undefined4 *)puVar3[3];
      *puVar3 = &PTR_FUN_009cc1f8;
      if ((undefined4 *)puVar3[2] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)puVar3[2])(1);
      }
      puVar3[2] = 0;
      *puVar3 = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 **)(param_1 + 0x20) = puVar3;
      puVar3 = puVar2;
    }
    iVar1 = uVar4 * 4;
    uVar4 = uVar4 + 1;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x10) + iVar1) + 4) = 0;
  } while (uVar4 <= *(uint *)(param_1 + 8));
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
