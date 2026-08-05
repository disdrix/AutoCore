# Annotated low-level: FUN_0080cbf0

| Field | Value |
|---|---|
| Stable ID | `aa_0080cbf0` |
| VA | `0x0080cbf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0080cbf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0080cbf0(int param_1)

{
  char cVar1;
  int unaff_ESI;
  
  FUN_007fef20(0x39,1,0);
  if (*(int **)(param_1 + 0x1114) != (int *)0x0) {
    cVar1 = (**(code **)(**(int **)(param_1 + 0x1114) + 0x3d8))();
    if (cVar1 != '\0') {
      FUN_0086d580(*(undefined4 *)(unaff_ESI + 0x10),*(undefined4 *)(unaff_ESI + 8),
                   *(undefined4 *)(unaff_ESI + 0xc),unaff_ESI + 0x14,unaff_ESI + 0x1c,
                   unaff_ESI + 0x30);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
