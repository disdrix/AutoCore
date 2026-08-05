# Annotated low-level: FUN_006a2ec0

| Field | Value |
|---|---|
| Stable ID | `aa_006a2ec0` |
| VA | `0x006a2ec0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006a2ec0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_006a2ec0(int param_1,uint param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (param_2 != 0) {
    if (0x3fffffff < param_2) {
      FUN_004540b0();
    }
    puVar1 = operator_new(param_2 * 4);
    *(undefined4 **)(param_1 + 0xc) = puVar1 + param_2;
    *(undefined4 **)(param_1 + 4) = puVar1;
    *(undefined4 **)(param_1 + 8) = puVar1;
    puVar2 = puVar1;
    for (uVar3 = param_2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar2 = *param_3;
      puVar2 = puVar2 + 1;
    }
    *(undefined4 **)(param_1 + 8) = puVar1 + param_2;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
