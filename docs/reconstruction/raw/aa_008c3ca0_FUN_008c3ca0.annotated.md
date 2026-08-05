# Annotated low-level: FUN_008c3ca0

| Field | Value |
|---|---|
| Stable ID | `aa_008c3ca0` |
| VA | `0x008c3ca0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008c3ca0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall FUN_008c3ca0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((0x9c46 < param_3) && (param_3 < 0x9c4f)) {
    if (param_2 == 5) {
      if ((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0xcd0) != 0)) {
        FUN_008c3140();
      }
      return 1;
    }
    if (param_2 == 8) {
      FUN_007fbbb0();
      FUN_008c3140();
      return 1;
    }
  }
  switch(param_3 + -40000) {
  case 0:
    if (param_2 == 8) {
      if (*(int *)(param_1 + 0x50c) == 1) {
        FUN_007fca10();
      }
      else if (*(int *)(param_1 + 0x50c) == 3) {
        FUN_007fca10();
        return 1;
      }
      return 1;
    }
    break;
  case 1:
    if (param_2 == 8) {
      return 1;
    }
    break;
  case 2:
    if (param_2 == 8) {
      *(undefined1 *)(param_1 + 0x521) = 0;
      *(bool *)(param_1 + 0x520) = *(char *)(param_1 + 0x520) == '\0';
      FUN_008c3080();
      return 1;
    }
    break;
  case 3:
    if (param_2 == 8) {
      *(undefined1 *)(param_1 + 0x520) = 0;
      *(bool *)(param_1 + 0x521) = *(char *)(param_1 + 0x521) == '\0';
      FUN_008c2fe0();
      return 1;
    }
    break;
  case 4:
    if (param_2 == 8) {
      FUN_008c2f50();
    }
    break;
  case 5:
    if (param_2 == 8) {
      FUN_0093bac0(&DAT_00d1a840,0);
      return 1;
    }
  }
  uVar1 = FUN_0087b500(param_2,param_3);
  return uVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
