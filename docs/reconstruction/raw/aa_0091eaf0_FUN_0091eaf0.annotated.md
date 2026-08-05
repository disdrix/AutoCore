# Annotated low-level: FUN_0091eaf0

| Field | Value |
|---|---|
| Stable ID | `aa_0091eaf0` |
| VA | `0x0091eaf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0091eaf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0091eaf0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_007fef20(0x1b,1,0);
  FUN_007fef20(0x1c,1,0);
  if (DAT_00d1a8e4 == '\0') {
    FUN_007fef20(0x1e,1,0);
    uVar2 = 0x21;
  }
  else {
    uVar2 = 0x1d;
  }
  FUN_007fef20(uVar2,1,0);
  FUN_007fef20(0x1f,1,0);
  FUN_007fef20(0x16,1,0);
  FUN_007fef20(0x22,1,0);
  FUN_007fef20(0x23,1,0);
  FUN_007fef20(0x2f,1,0);
  FUN_007fe1d0(1);
  FUN_007fef20(0x30,1,0);
  if (DAT_00d1b6d8 != 0) {
    iVar1 = FUN_004c3f10(1);
    if (iVar1 != 0) {
      FUN_007fef20(0x32,1,0);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
