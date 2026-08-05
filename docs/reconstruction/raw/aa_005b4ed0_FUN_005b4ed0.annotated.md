# Annotated low-level: FUN_005b4ed0

| Field | Value |
|---|---|
| Stable ID | `aa_005b4ed0` |
| VA | `0x005b4ed0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005b4ed0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005b4ed0(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_0068a4d0(*(undefined4 *)(param_1 + 0x50),2,0xffffffff,0xffffffff,0xffffffff);
  if (g_flZero < *(float *)(*(int *)(param_1 + 0x50) + 0x74)) {
    FUN_005b4a30();
    (**(code **)(*DAT_00d1f610 + 0x1c))
              (DAT_00d1f610,0x18,(int)ROUND(*(float *)(*(int *)(param_1 + 0x50) + 0x74)));
    iVar1 = *(int *)(param_1 + 0x70);
    if (((iVar1 != 0) && (iVar2 = *(int *)(*(int *)(param_1 + 0x50) + 0x3c), -1 < iVar2)) &&
       (*(short *)(iVar1 + iVar2 * 2) != 0)) {
      (**(code **)(*DAT_00b05340 + 0x148))
                (DAT_00b05340,5,0,0,*(undefined2 *)(*(int *)(param_1 + 0x50) + 0x4c),0,
                 *(ushort *)(iVar1 + *(int *)(*(int *)(param_1 + 0x50) + 0x3c) * 2) - 2);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
