# Annotated low-level: CVOGPhysics_ApplyImpulseVector

| Field | Value |
|---|---|
| Stable ID | `aa_0040d260` |
| VA | `0x0040d260` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0040d260`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall CVOGPhysics_ApplyImpulseVector(int param_1,undefined4 param_2)

{
  char *pcVar1;
  undefined4 uStack_4;
  
  uStack_4 = param_1;
  pcVar1 = (char *)FUN_005070b0((int)&uStack_4 + 3);
  if ((*pcVar1 == '\0') && (*(int *)(param_1 + 0x44) != 0)) {
    FUN_005070d0();
  }
  (**(code **)(**(int **)(param_1 + 0x3c) + 0x50))(param_2);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
