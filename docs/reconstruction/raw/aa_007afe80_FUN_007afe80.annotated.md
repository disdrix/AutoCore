# Annotated low-level: FUN_007afe80

| Field | Value |
|---|---|
| Stable ID | `aa_007afe80` |
| VA | `0x007afe80` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007afe80`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_007afe80(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xc0) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0xc4) - *(int *)(param_1 + 0xc0) >> 2;
    }
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        if (*(int *)(*(int *)(param_1 + 0xc0) + iVar2 * 4) != 0) {
          FUN_004246a0();
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
