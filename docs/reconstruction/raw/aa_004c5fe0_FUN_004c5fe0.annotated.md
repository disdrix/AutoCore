# Annotated low-level: FUN_004c5fe0

| Field | Value |
|---|---|
| Stable ID | `aa_004c5fe0` |
| VA | `0x004c5fe0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004c5fe0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004c5fe0(uint param_1)

{
  int iVar1;
  float10 fVar2;
  undefined4 uStack_4;
  
  uStack_4 = param_1 & 0xffffff;
  if (*(char *)(*(int *)(*(int *)(*(int *)(param_1 - 0x4fc) + 4) + -0x458 + param_1) + 0x7e) == '\0'
     ) {
    fVar2 = (float10)FUN_004c55e0();
    if ((float10)g_flZero != fVar2) {
      iVar1 = 0;
      if (param_1 != 0x500) {
        iVar1 = *(int *)(*(int *)(param_1 - 0x4fc) + 4) + -0x4fc + param_1;
      }
      CVOGSpawnPoint_SetObjectActiveState(iVar1,(int)&uStack_4 + 3,0);
    }
  }
  if ((*(int *)(param_1 - 0x2a8) != 0) && (*(int *)(*(int *)(param_1 - 0x2a8) + 0xe0) != 0)) {
    iVar1 = *(int *)(*(int *)(param_1 - 0x4fc) + 4);
    if (*(char *)(*(int *)(iVar1 + -0x458 + param_1) + 0x7e) != '\0') {
      if (param_1 == 0x500) {
        iVar1 = 0;
      }
      else {
        iVar1 = iVar1 + param_1 + -0x4fc;
      }
      CVOGSpawnPoint_SetObjectActiveState(iVar1,(int)&uStack_4 + 3,0);
    }
    (**(code **)(**(int **)(param_1 - 0x2a8) + 0x44))();
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
