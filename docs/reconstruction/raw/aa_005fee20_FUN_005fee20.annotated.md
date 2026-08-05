# Annotated low-level: FUN_005fee20

| Field | Value |
|---|---|
| Stable ID | `aa_005fee20` |
| VA | `0x005fee20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fee20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005fee20(int param_1,float param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  
  sVar1 = *(short *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c)
                    + 0x4c4);
  ceil((double)((float)(int)sVar1 * param_2));
  sVar2 = FUN_006a3db0();
  sVar3 = *(short *)(param_1 + 0xb4);
  sVar2 = sVar2 - sVar1;
  if (sVar2 == sVar3) {
    if (param_2 <= _DAT_00aaac14) {
      if (_DAT_009dd778 <= param_2) goto LAB_005fee9c;
      sVar3 = sVar3 + -1;
    }
    else {
      sVar3 = sVar3 + 1;
    }
  }
  else {
    sVar3 = sVar3 + sVar2;
  }
  *(short *)(param_1 + 0xb4) = sVar3;
LAB_005fee9c:
  if (*(short *)(param_1 + 0xb4) < 10) {
    *(undefined2 *)(param_1 + 0xb4) = 10;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
