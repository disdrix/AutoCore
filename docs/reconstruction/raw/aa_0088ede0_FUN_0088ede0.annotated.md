# Annotated low-level: FUN_0088ede0

| Field | Value |
|---|---|
| Stable ID | `aa_0088ede0` |
| VA | `0x0088ede0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0088ede0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
uint __fastcall FUN_0088ede0(int *param_1)

{
  char cVar1;
  uint uVar2;
  
  if (param_1[0x16c] != 0) {
    cVar1 = (**(code **)(*(int *)param_1[0x16c] + 0x3d8))();
    if (cVar1 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0088ee07. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(*(int *)param_1[0x16c] + 0x39c))();
      return uVar2;
    }
  }
  uVar2 = (**(code **)(*param_1 + 0x3d8))();
  if (((char)uVar2 != '\0') && (param_1[0x12e] != 0)) {
                    /* WARNING: Could not recover jumptable at 0x0088ee2d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*(int *)param_1[0x12e] + 0x39c))();
    return uVar2;
  }
  return uVar2 & 0xffffff00;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
