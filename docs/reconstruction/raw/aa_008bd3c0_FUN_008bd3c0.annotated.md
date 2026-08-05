# Annotated low-level: FUN_008bd3c0

| Field | Value |
|---|---|
| Stable ID | `aa_008bd3c0` |
| VA | `0x008bd3c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008bd3c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_008bd3c0(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  FUN_007916e0(param_2);
  if (((char)param_2 != '\0') &&
     ((*(int *)(param_1 + 0x550) == 0 ||
      ((uint)(*(int *)(param_1 + 0x554) - *(int *)(param_1 + 0x550) >> 2) < 4)))) {
    if (*(int *)(param_1 + 0x550) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x554) - *(int *)(param_1 + 0x550) >> 2;
      if (3 < iVar1) {
        return;
      }
    }
    piVar2 = (int *)(param_1 + 0x56c + iVar1 * 4);
    iVar1 = 4 - iVar1;
    do {
      if (piVar2[-4] != 0) {
        (**(code **)(*(int *)piVar2[-4] + 0xcc))(0);
      }
      if (*piVar2 != 0) {
        (**(code **)(*(int *)*piVar2 + 0xcc))(0);
      }
      if (piVar2[4] != 0) {
        (**(code **)(*(int *)piVar2[4] + 0xcc))(0);
      }
      if (piVar2[8] != 0) {
        (**(code **)(*(int *)piVar2[8] + 0xcc))(0);
      }
      if (piVar2[0xc] != 0) {
        (**(code **)(*(int *)piVar2[0xc] + 0xcc))(0);
      }
      piVar2 = piVar2 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
