# Annotated low-level: FUN_0056add0

| Field | Value |
|---|---|
| Stable ID | `aa_0056add0` |
| VA | `0x0056add0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0056add0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined1 __fastcall FUN_0056add0(int param_1)

{
  short sVar1;
  undefined1 uVar2;
  short sVar3;
  short sVar4;
  
  sVar3 = 0;
  if (0 < *(short *)(param_1 + 0x130)) {
    sVar3 = *(short *)(param_1 + 0x130);
  }
  sVar1 = *(short *)(param_1 + 0x132);
  sVar4 = sVar3;
  if (sVar3 < sVar1) {
    sVar4 = sVar1;
  }
  uVar2 = sVar3 < sVar1;
  if (sVar4 < *(short *)(param_1 + 0x134)) {
    uVar2 = 2;
    sVar4 = *(short *)(param_1 + 0x134);
  }
  if (sVar4 < *(short *)(param_1 + 0x136)) {
    uVar2 = 3;
    sVar4 = *(short *)(param_1 + 0x136);
  }
  if (sVar4 < *(short *)(param_1 + 0x138)) {
    uVar2 = 4;
    sVar4 = *(short *)(param_1 + 0x138);
  }
  if (sVar4 < *(short *)(param_1 + 0x13a)) {
    uVar2 = 5;
  }
  return uVar2;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
