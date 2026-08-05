# Annotated low-level: FUN_008bfbd0

| Field | Value |
|---|---|
| Stable ID | `aa_008bfbd0` |
| VA | `0x008bfbd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008bfbd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008bfbd0(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = (**(code **)(*param_1 + 0x3d8))();
  if (cVar1 != '\0') {
    if (param_1[0x168] != 0) {
      (**(code **)(*(int *)param_1[0x168] + 0xd4))(1);
      if ((*(char *)((int)param_1 + 0x50d) == '\0') || ((char)param_1[0x145] == '\0')) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
      (**(code **)(*(int *)param_1[0x168] + 0x3c8))(uVar2,1);
      (**(code **)(*(int *)param_1[0x168] + 0xd4))((char)param_1[0x145]);
      (**(code **)(*(int *)param_1[0x168] + 0x34c))();
    }
    if (param_1[0x169] != 0) {
      (**(code **)(*(int *)param_1[0x169] + 0xd4))(1);
      if ((*(char *)((int)param_1 + 0x50e) == '\0') || (*(char *)((int)param_1 + 0x515) == '\0')) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
      (**(code **)(*(int *)param_1[0x169] + 0x3c8))(uVar2,1);
      (**(code **)(*(int *)param_1[0x169] + 0xd4))(*(undefined1 *)((int)param_1 + 0x515));
      (**(code **)(*(int *)param_1[0x169] + 0x34c))();
    }
    if (param_1[0x16a] != 0) {
      (**(code **)(*(int *)param_1[0x16a] + 0xd4))(1);
      if ((*(char *)((int)param_1 + 0x50f) == '\0') || (*(char *)((int)param_1 + 0x516) == '\0')) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
      (**(code **)(*(int *)param_1[0x16a] + 0x3c8))(uVar2,1);
      (**(code **)(*(int *)param_1[0x16a] + 0xd4))(*(undefined1 *)((int)param_1 + 0x516));
      (**(code **)(*(int *)param_1[0x16a] + 0x34c))();
    }
    if (param_1[0x16b] != 0) {
      (**(code **)(*(int *)param_1[0x16b] + 0xd4))(1);
      if (((char)param_1[0x144] == '\0') || (*(char *)((int)param_1 + 0x517) == '\0')) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
      (**(code **)(*(int *)param_1[0x16b] + 0x3c8))(uVar2,1);
      (**(code **)(*(int *)param_1[0x16b] + 0xd4))(*(undefined1 *)((int)param_1 + 0x517));
      (**(code **)(*(int *)param_1[0x16b] + 0x34c))();
    }
    if (param_1[0x16c] != 0) {
      (**(code **)(*(int *)param_1[0x16c] + 0xd4))(1);
      if ((*(char *)((int)param_1 + 0x511) == '\0') || ((char)param_1[0x146] == '\0')) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
      (**(code **)(*(int *)param_1[0x16c] + 0x3c8))(uVar2,1);
      (**(code **)(*(int *)param_1[0x16c] + 0xd4))((char)param_1[0x146]);
      (**(code **)(*(int *)param_1[0x16c] + 0x34c))();
    }
    if (param_1[0x16d] != 0) {
      (**(code **)(*(int *)param_1[0x16d] + 0xd4))(1);
      if ((*(char *)((int)param_1 + 0x512) == '\0') || (*(char *)((int)param_1 + 0x519) == '\0')) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
      (**(code **)(*(int *)param_1[0x16d] + 0x3c8))(uVar2,1);
      (**(code **)(*(int *)param_1[0x16d] + 0xd4))(*(undefined1 *)((int)param_1 + 0x519));
      (**(code **)(*(int *)param_1[0x16d] + 0x34c))();
    }
    if (param_1[0x16e] != 0) {
      (**(code **)(*(int *)param_1[0x16e] + 0xd4))(1);
      if ((*(char *)((int)param_1 + 0x513) == '\0') || (*(char *)((int)param_1 + 0x51a) == '\0')) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
      (**(code **)(*(int *)param_1[0x16e] + 0x3c8))(uVar2,1);
      (**(code **)(*(int *)param_1[0x16e] + 0xd4))(*(undefined1 *)((int)param_1 + 0x51a));
                    /* WARNING: Could not recover jumptable at 0x008bfea1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*(int *)param_1[0x16e] + 0x34c))();
      return;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
