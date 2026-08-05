# Annotated low-level: FUN_006c2fb0

| Field | Value |
|---|---|
| Stable ID | `aa_006c2fb0` |
| VA | `0x006c2fb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006c2fb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006c2fb0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)param_2[1];
  uVar2 = *param_2;
  uVar3 = param_1[1];
  puVar1[3] = *param_1;
  puVar1[2] = param_3;
  puVar1[4] = uVar3;
  puVar1[5] = param_4;
  *puVar1 = 0x11801;
  puVar1[1] = uVar2;
  param_2[1] = puVar1 + 6;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
