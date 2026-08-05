# Annotated low-level: FUN_006f3ec0

| Field | Value |
|---|---|
| Stable ID | `aa_006f3ec0` |
| VA | `0x006f3ec0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006f3ec0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_006f3ec0(int *param_1,float param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *param_1 + -1;
  if (3 < *param_1) {
    do {
      piVar1 = (int *)(param_1[2] + iVar2 * 4);
      if (*piVar1 == 0) {
        return;
      }
      if (param_2 <= *(float *)(*piVar1 + 0xc)) {
        return;
      }
      param_1[3] = *piVar1;
      *piVar1 = 0;
      *param_1 = *param_1 + -1;
      piVar1 = (int *)(param_1[2] + -4 + iVar2 * 4);
      if (*piVar1 == 0) {
        return;
      }
      if (param_2 <= *(float *)(*piVar1 + 0xc)) {
        return;
      }
      param_1[3] = *piVar1;
      *piVar1 = 0;
      *param_1 = *param_1 + -1;
      piVar1 = (int *)(param_1[2] + -8 + iVar2 * 4);
      if (*piVar1 == 0) {
        return;
      }
      if (param_2 <= *(float *)(*piVar1 + 0xc)) {
        return;
      }
      param_1[3] = *piVar1;
      *piVar1 = 0;
      *param_1 = *param_1 + -1;
      piVar1 = (int *)(param_1[2] + -0xc + iVar2 * 4);
      if (*piVar1 == 0) {
        return;
      }
      if (param_2 <= *(float *)(*piVar1 + 0xc)) {
        return;
      }
      param_1[3] = *piVar1;
      *piVar1 = 0;
      iVar2 = iVar2 + -4;
      *param_1 = *param_1 + -1;
    } while (2 < iVar2);
  }
  while( true ) {
    if (iVar2 < 0) {
      return;
    }
    piVar1 = (int *)(param_1[2] + iVar2 * 4);
    if (*piVar1 == 0) break;
    if (param_2 <= *(float *)(*piVar1 + 0xc)) {
      return;
    }
    param_1[3] = *piVar1;
    *piVar1 = 0;
    iVar2 = iVar2 + -1;
    *param_1 = *param_1 + -1;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
