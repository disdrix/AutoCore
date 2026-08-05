# Annotated low-level: FUN_004febe0

| Field | Value |
|---|---|
| Stable ID | `aa_004febe0` |
| VA | `0x004febe0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004febe0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_004febe0(int param_1,int param_2)

{
  int *piVar1;
  undefined1 local_18 [4];
  int *local_14;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a2d79;
  local_c = ExceptionList;
  if ((param_2 != 0) && (*(int *)(param_1 + 0x2b0) != 0)) {
    ExceptionList = &local_c;
    local_14 = (int *)FUN_0040fb90();
    local_10 = 0;
    local_4 = 0;
    FUN_00572110(0x10,local_18);
    if (local_10 != 0) {
      piVar1 = (int *)*local_14;
      if (piVar1 != local_14) {
        do {
          if (*(uint *)(*(int *)(*(int *)(piVar1[2] + 0xa8) + 0x3c) + 0x3d4) ==
              (uint)*(byte *)(param_2 + 9)) {
            FUN_00403430();
            ExceptionList = local_c;
            return 1;
          }
          piVar1 = (int *)*piVar1;
        } while (piVar1 != local_14);
      }
    }
    FUN_00403430();
  }
  ExceptionList = local_c;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
